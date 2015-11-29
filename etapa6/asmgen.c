#include "asmgen.h"

void asmgen_gennode(tac_node_t * node, FILE * out);

void asmgen_run(tac_node_t * root, FILE * out) {
	tac_node_t * node = root;
	while(node != NULL) {
		asmgen_gennode(node, out);
		node = node->next;
	}
}

void asmgen_gennode(tac_node_t * node, FILE * out) {
  if (!node) return;

  switch(node->type) {
  case TAC_SYMBOL:
    break;
 case TAC_MOVE:
	if (node->op1->type == 3)
		fprintf(out, 
			"\tand eax, 00h\n"
			"\tadd eax, %d\n"
			"\tmov DWORD PTR %s\n"
					, atoi(node->op1->data), node->res->data);
	else if (node->op1->type == 9) {
		fprintf(out, 
			"\tmov eax, DWORD PTR %s\n"
			"\tmov DWORD PTR %s, eax\n"
					, node->op1->data, node->res->data);
	}
    break;
  case TAC_ADD:
	if (node->op1->type == 3 && node->op2->type == 3) { //1+1
		fprintf(out,
			"\tand eax, 00h\n"	     // zera eax
			"\tadd eax, %d\n"            // 1+1 em eax
			"\tmov DWORD PTR %s, eax\n"  // eax em temp
					,(atoi(node->op1->data) + atoi(node->op2->data)), node->res->data);
	} else if(node->op1->type == 3 && node->op2->type == 9) { //1+a
		fprintf(out, 
			"\tmov eax, DWORD PTR %s\n" // a no eax
			"\tadd eax, %d\n" 	    // 1 + a no eax
			"\tmov DWORD PTR %s, eax\n"   // eax em temp
					, node->op2->data, atoi(node->op1->data), node->res->data);
	} else if(node->op1->type == 9 && node->op2->type == 3) {//a+1
		fprintf(out, 
			"\tmov eax, DWORD PTR %s\n" 
			"\tadd eax, %d\n" 	    
			"\tmov DWORD PTR %s, eax\n"   
					, node->op1->data, atoi(node->op2->data), node->res->data);
	}
	 else if(node->op1->type == 9 && node->op2->type == 9) { //a+b
		fprintf(out, 
			"\tmov edx, DWORD PTR %s\n"    		 // a em edx
			"\tmov eax, DWORD PTR %s\n"  		 // b em eax
			"\tadd eax, edx\n" 	                 // eax = eax + edx
			"\tmov DWORD PTR %s, eax\n"              // eax em temp
					, node->op1->data, node->op2->data, node->res->data);
	}
    break;
  case TAC_SUB:
	fprintf(out, "	SUB %s, %s\n", node->res->data, node->op1->data);
    break;
  case TAC_MUL:
	fprintf(out, "	MUL %s, %s\n", node->res->data, node->op1->data);
    break;
  case TAC_DIV:
	fprintf(out, "	DIV %s, %s\n", node->res->data, node->op1->data);
    break;
  case TAC_LABEL:
	fprintf(out, "%s:\n", node->res->data);
    break;
  case TAC_JMP:
    break;
  case TAC_RET:
    break;
  case TAC_EQ:
    break;
  case TAC_NE:
    break;
  case TAC_LE:
    break;
  case TAC_GE:
    break;
  case TAC_LESS:
    break;
  case TAC_GREATER:
    break;
  case TAC_AND:
    break;
  case TAC_OR:
    break;
  case TAC_VARDEC:
	fprintf(out, "	.comm %s,4\n", node->res->data);
    break;
  case TAC_VECDEC:
	fprintf(out, "	.comm %s,%d\n", node->res->data, atoi(node->op1->data) * 4);
    break;
  case TAC_TOVECMOVE:
	fprintf(out, "	MOV eax, DWORD PTR %s\n", node->op2->data);
	fprintf(out, "	MOV DWORD PTR %s+%d, eax\n", node->res->data, atoi(node->op1->data)*4);
    break;
  case TAC_FROMVECMOVE:
	
    break;
  case TAC_INPUT:
    break;
  case TAC_OUTPUT:
    break;
  case TAC_RETURN:
    break;
  case TAC_IF:
    break;
  case TAC_CALL:
    break;
  case TAC_PUSHARG:
    break;
  case TAC_POPARG:
    break;
  }
}
