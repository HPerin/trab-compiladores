#include "asmgen.h"

#define LIT_INTEGER 3
#define SYMBOL_VARIABLE 9

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
			"\tmov DWORD PTR %s, %d\n"
					, node->res->data, atoi(node->op1->data));
	else if (node->op1->type == 9) {
		fprintf(out, 
			"\tmov eax, DWORT PTR %s\n"
			"\tmov DWORD PTR %s, eax\n"
					, node->op1->data, node->res->data);
	}
    break;
 case TAC_ADD:
	if (node->op1->type == LIT_INTEGER && node->op2->type == LIT_INTEGER) { //1+1
			fprintf(out,            
				"\tmov DWORD PTR %s, %d\n"  //1+1 em temp 
					,node->res->data, (atoi(node->op1->data) + atoi(node->op2->data)));

	} else if(node->op1->type == LIT_INTEGER && node->op2->type == SYMBOL_VARIABLE) { //1+a
		fprintf(out, 
			"\tmov eax, DWORD PTR %s\n" // a no eax
			"\tadd eax, %d\n" 	    // 1 + a no eax
			"\tmov DWORD PTR %s, eax\n"   // eax em temp
					, node->op2->data, atoi(node->op1->data), node->res->data);

	} else if(node->op1->type == SYMBOL_VARIABLE && node->op2->type == LIT_INTEGER) {//a+1
		fprintf(out, 
			"\tmov eax, DWORD PTR %s\n" 
			"\tadd eax, %d\n" 	    
			"\tmov DWORD PTR %s, eax\n"   
					, node->op1->data, atoi(node->op2->data), node->res->data);
	}
	 else if(node->op1->type == SYMBOL_VARIABLE && node->op2->type == SYMBOL_VARIABLE) { //a+b
		fprintf(out, 
			"\tmov edx, DWORD PTR %s\n"    		 // a em edx
			"\tmov eax, DWORD PTR %s\n"  		 // b em eax
			"\tadd eax, edx\n" 	                 // eax = eax + edx
			"\tmov DWORD PTR %s, eax\n"              // eax em temp
					, node->op1->data, node->op2->data, node->res->data);
	}
    break;
  case TAC_SUB:
	if (node->op1->type == LIT_INTEGER && node->op2->type == LIT_INTEGER) { 
			fprintf(out,            
				"\tmov DWORD PTR %s, %d\n"   
					,node->res->data, (atoi(node->op1->data) - atoi(node->op2->data)));

	} else if(node->op1->type == LIT_INTEGER && node->op2->type == SYMBOL_VARIABLE) {
		fprintf(out, 
			"\tmov eax, DWORD PTR %s\n"
			"\tsub eax, %d\n" 	    
			"\tmov DWORD PTR %s, eax\n"
					, node->op2->data, atoi(node->op1->data), node->res->data);
	} else if(node->op1->type == SYMBOL_VARIABLE && node->op2->type == LIT_INTEGER) {
		fprintf(out, 
			"\tmov eax, DWORD PTR %s\n" 
			"\tsub eax, %d\n" 	    
			"\tmov DWORD PTR %s, eax\n"   
					, node->op1->data, atoi(node->op2->data), node->res->data);
	}
	 else if(node->op1->type == SYMBOL_VARIABLE && node->op2->type == SYMBOL_VARIABLE) { 
		fprintf(out, 
			"\tmov edx, DWORD PTR %s\n"    		 
			"\tmov eax, DWORD PTR %s\n"  		 
			"\tsub eax, edx\n" 	                 
			"\tmov DWORD PTR %s, eax\n"              
					, node->op1->data, node->op2->data, node->res->data);
	}
    break;
  case TAC_MUL:
	if (node->op1->type == LIT_INTEGER && node->op2->type == 3) { 
		fprintf(out,
			"\tmov DWORD PTR %s, %d\n"  
					,node->res->data, (atoi(node->op1->data) * atoi(node->op2->data)));

	} else if(node->op1->type == LIT_INTEGER && node->op2->type == SYMBOL_VARIABLE) {
		fprintf(out, 
			"\tmov eax, DWORD PTR %s\n"
			"\timul eax, eax, %d\n" 	
			"\tmov DWORD PTR %s, eax\n"
					, node->op2->data, atoi(node->op1->data), node->res->data);
	} else if(node->op1->type == SYMBOL_VARIABLE && node->op2->type == LIT_INTEGER) {
		fprintf(out, 
			"\tmov eax, DWORD PTR %s\n" 
			"\timul eax, eax, %d\n" 	    
			"\tmov DWORD PTR %s, eax\n"   
					, node->op1->data, atoi(node->op2->data), node->res->data);
	}
	 else if(node->op1->type == SYMBOL_VARIABLE && node->op2->type == SYMBOL_VARIABLE) { 
		fprintf(out, 
			"\tmov edx, DWORD PTR %s\n"    		 
			"\tmov eax, DWORD PTR %s\n"  		 
			"\timul eax, edx\n" 	                
			"\tmov DWORD PTR %s, eax\n"              
					, node->op1->data, node->op2->data, node->res->data);
	}
    break;
  case TAC_DIV:
	if (node->op1->type == LIT_INTEGER && node->op2->type == 3) { 
		fprintf(out,
			"\tmov DWORD PTR %s, %d\n"  
					,node->res->data, (atoi(node->op1->data) / atoi(node->op2->data)));

	} else if(node->op1->type == LIT_INTEGER && node->op2->type == SYMBOL_VARIABLE) {
		fprintf(out, 
			"\tmov ecx, DWORD PTR %s\n"
			"\tmov eax, %d\n" 
			"\tcdq\n" 	
			"\tidiv ecx\n"
			"\tmov DWORT PTR %s, eax\n"
					, node->op2->data, atoi(node->op1->data), node->res->data);
	} else if(node->op1->type == SYMBOL_VARIABLE && node->op2->type == LIT_INTEGER) {
		fprintf(out, 
			"\tmov ecx, DWORD PTR %s\n"
			"\tmov eax, %d\n" 
			"\tcdq\n" 	
			"\tidiv ecx\n"
			"\tmov DWORT PTR %s, eax\n" 
					, node->op1->data, atoi(node->op2->data), node->res->data);
	}
	 else if(node->op1->type == SYMBOL_VARIABLE && node->op2->type == SYMBOL_VARIABLE) { 
		fprintf(out, 
			"\tmov eax, DWORD PTR %s\n"    		 
			"\tmov ecx, DWORD PTR %s\n"  
			"\tcdq\n"		 
			"\tidiv ecx\n" 	                
			"\tmov DWORD PTR %s, eax\n"              
					, node->op1->data, node->op2->data, node->res->data);
	}
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
	if (node->op2->type == 3) {
		fprintf(out, "	mov eax, %s\n", node->op2->data);
		fprintf(out, "	mov DWORD PTR %s+%d, eax\n", node->res->data, atoi(node->op1->data)*4);
	} else if (node->op2->type == 9) {
		fprintf(out, "	mov eax, DWORD PTR %s\n", node->op2->data);
		fprintf(out, "	mov DWORD PTR %s+%d, eax\n", node->res->data, atoi(node->op1->data)*4);
	}
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
