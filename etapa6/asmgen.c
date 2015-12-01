#include "asmgen.h"

#define LIT_INTEGER 3
#define LIT_FALSE 4
#define LIT_TRUE 5
#define LIT_CHAR 6
#define SYMBOL_VARIABLE 9

int popArg = 0;

void asmgen_gennode(tac_node_t * node, FILE * out);

void asmgen_run(tac_node_t * root, FILE * out) {
	tac_node_t * node = root;

	fprintf(out, "\t.intel_syntax noprefix\n");

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
	if (node->op1->type == LIT_INTEGER || node->op1->type == LIT_CHAR)
		fprintf(out, 
			"\tmov DWORD PTR %s, %s\n"
					, node->res->data, node->op1->data);
	else if (node->op1->type == SYMBOL_VARIABLE) {
		fprintf(out, 
			"\tmov eax, DWORD PTR %s\n"
			"\tmov DWORD PTR %s, eax\n"
					, node->op1->data, node->res->data);
	}
    break;
 case TAC_ADD:
	if (node->op1->type == LIT_INTEGER && node->op2->type == LIT_INTEGER) { //1+1
		fprintf(out,            
			"\tmov DWORD PTR %s, %d\n"  //1+1 em temp 
				,node->res->data, (atoi(node->op1->data) + atoi(node->op2->data)));
	} else if ((node->op1->type == LIT_CHAR && node->op2->type == LIT_CHAR) || (node->op1->type == LIT_CHAR && node->op2->type == LIT_INTEGER) || (node->op1->type == LIT_INTEGER && node->op2->type == LIT_CHAR)) {
		fprintf(out,
			"\tmov eax, %s\n"
			"\tadd eax, %s\n"
			"\tmov DWORD PTR %s, eax\n"
				, node->op1->data, node->op2->data, node->res->data);
				
	} else if((node->op1->type == LIT_INTEGER || node->op1->type == LIT_CHAR) && node->op2->type == SYMBOL_VARIABLE) { //1+a
		fprintf(out, 
			"\tmov eax, DWORD PTR %s\n" // a no eax
			"\tadd eax, %s\n" 	    // 1 + a no eax
			"\tmov DWORD PTR %s, eax\n"   // eax em temp
					, node->op2->data, node->op1->data, node->res->data);

	} else if(node->op1->type == SYMBOL_VARIABLE && (node->op2->type == LIT_INTEGER || node->op2->type == LIT_CHAR)) {//a+1
		fprintf(out, 
			"\tmov eax, DWORD PTR %s\n" 
			"\tadd eax, %s\n" 	    
			"\tmov DWORD PTR %s, eax\n"   
					, node->op1->data, node->op2->data, node->res->data);
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

	} else if ((node->op1->type == LIT_CHAR && node->op2->type == LIT_CHAR) || (node->op1->type == LIT_CHAR && node->op2->type == LIT_INTEGER) || (node->op1->type == LIT_INTEGER && node->op2->type == LIT_CHAR)) {
		fprintf(out,
			"\tmov eax, %s\n"
			"\tsub eax, %s\n"
			"\tmov DWORD PTR %s, eax\n"
				, node->op1->data, node->op2->data, node->res->data);
	} else if((node->op1->type == LIT_INTEGER || node->op1->type == LIT_CHAR) && node->op2->type == SYMBOL_VARIABLE) {
		fprintf(out, 
			"\tmov eax, DWORD PTR %s\n"
			"\tsub eax, %s\n" 	    
			"\tmov DWORD PTR %s, eax\n"
					, node->op2->data, node->op1->data, node->res->data);
	} else if(node->op1->type == SYMBOL_VARIABLE && (node->op2->type == LIT_INTEGER || node->op2->type == LIT_CHAR)) {
		fprintf(out, 
			"\tmov eax, DWORD PTR %s\n" 
			"\tsub eax, %s\n" 	    
			"\tmov DWORD PTR %s, eax\n"   
					, node->op1->data, node->op2->data, node->res->data);
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
	if (node->op1->type == LIT_INTEGER && node->op2->type == LIT_INTEGER) { 
		fprintf(out,
			"\tmov DWORD PTR %s, %d\n"  
					,node->res->data, (atoi(node->op1->data) * atoi(node->op2->data)));

	} else if ((node->op1->type == LIT_CHAR && node->op2->type == LIT_CHAR) || (node->op1->type == LIT_CHAR && node->op2->type == LIT_INTEGER) || (node->op1->type == LIT_INTEGER && node->op2->type == LIT_CHAR)) {
		fprintf(out,
			"\tmov eax, %s\n"
			"\timul eax, %s\n"
			"\tmov DWORD PTR %s, eax\n"
				, node->op1->data, node->op2->data, node->res->data);

	} else if((node->op1->type == LIT_INTEGER || node->op1->type == LIT_CHAR) && node->op2->type == SYMBOL_VARIABLE) {
		fprintf(out, 
			"\tmov eax, DWORD PTR %s\n"
			"\timul eax, eax, %s\n" 	
			"\tmov DWORD PTR %s, eax\n"
					, node->op2->data, node->op1->data, node->res->data);
	} else if(node->op1->type == SYMBOL_VARIABLE && (node->op2->type == LIT_INTEGER || node->op2->type == LIT_CHAR)) {
		fprintf(out, 
			"\tmov eax, DWORD PTR %s\n" 
			"\timul eax, eax, %s\n" 	    
			"\tmov DWORD PTR %s, eax\n"   
					, node->op1->data, node->op2->data, node->res->data);
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
	if (node->op1->type == LIT_INTEGER && node->op2->type == LIT_INTEGER) { 
		fprintf(out,
			"\tmov DWORD PTR %s, %d\n"  
					,node->res->data, (atoi(node->op1->data) / atoi(node->op2->data)));

	} else if ((node->op1->type == LIT_CHAR && node->op2->type == LIT_CHAR) || (node->op1->type == LIT_CHAR && node->op2->type == LIT_INTEGER) || (node->op1->type == LIT_INTEGER && node->op2->type == LIT_CHAR)) {
		fprintf(out,
			"\tmov ecx, %s\n"
			"\tmov eax, %s\n"
			"\tcdq\n"
			"\tidiv ecx\n"
			"\tmov DWORD PTR %s, eax\n"
				, node->op1->data, node->op2->data, node->res->data);

	} else if((node->op1->type == LIT_INTEGER || node->op1->type == LIT_CHAR) && node->op2->type == SYMBOL_VARIABLE) {
		fprintf(out, 
			"\tmov ecx, DWORD PTR %s\n"
			"\tmov eax, %s\n" 
			"\tcdq\n" 	
			"\tidiv ecx\n"
			"\tmov DWORD PTR %s, eax\n"
					, node->op2->data, node->op1->data, node->res->data);
	} else if(node->op1->type == SYMBOL_VARIABLE && (node->op2->type == LIT_INTEGER || node->op2->type == LIT_CHAR)) {
		fprintf(out, 
			"\tmov ecx, DWORD PTR %s\n"
			"\tmov eax, %s\n" 
			"\tcdq\n" 	
			"\tidiv ecx\n"
			"\tmov DWORD PTR %s, eax\n" 
					, node->op1->data, node->op2->data, node->res->data);
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
  case TAC_FUNLABEL:
	fprintf(out, "\t.globl %s\n\t.type %s, @function\n", node->res->data, node->res->data);
	fprintf(out, "%s:\n", node->res->data);
    break;
  case TAC_JMP:
    break;
  case TAC_RET:
    break;
  case TAC_EQ:
	if(node->op1->type == LIT_INTEGER && node->op2->type == LIT_INTEGER) {
		if(atoi(node->op1->data) == atoi(node->op2->data))
			fprintf(out,
				"\tmov DWORD PTR %s, 1\n"
					,node->res->data);
		else 
			fprintf(out,
				"\tmov DWORD PTR %s, 0\n"
						,node->res->data);

	} else if ((node->op1->type == LIT_CHAR && node->op2->type == LIT_CHAR) || (node->op1->type == LIT_CHAR && node->op2->type == LIT_INTEGER) || (node->op1->type == LIT_INTEGER && node->op2->type == LIT_CHAR)) {
		fprintf(out,
			"\tmov eax, %s\n"
			"\tcmp eax, %s\n"
			"\tsete al\n"
			"\txor ebx, ebx\n"
			"\tmov bl, al\n"
			"\tmov DWORD PTR %s, ebx\n"
				, node->op1->data, node->op2->data, node->res->data);
	
	} else if(node->op1->type == SYMBOL_VARIABLE && (node->op2->type == LIT_INTEGER || node->op2->type == LIT_CHAR)) {
		fprintf(out, 
				"\tmov eax, DWORD PTR %s\n"
				"\tcmp eax, %s\n"
				"\tsete al\n"
				"\txor ebx, ebx\n"
				"\tmov bl, al\n"
				"\tmov DWORD PTR %s, ebx\n"
						, node->op1->data, node->op2->data, node->res->data);
	} else if((node->op1->type == LIT_INTEGER || node->op1->type == LIT_CHAR) && node->op2->type == SYMBOL_VARIABLE) {
		fprintf(out, 
				"\tmov eax, DWORD PTR %s\n"
				"\tcmp eax, %s\n"
				"\tsete al\n"
				"\txor ebx, ebx\n"
				"\tmov bl, al\n"
				"\tmov DWORD PTR %s, ebx\n"
						, node->op2->data, node->op1->data, node->res->data);
	}else if(node->op1->type == SYMBOL_VARIABLE && node->op2->type == SYMBOL_VARIABLE) {
		fprintf(out, 
				"\tmov edx, DWORD PTR %s\n"
				"\tmov eax, DWORD PTR %s\n"
				"\tcmp edx, eax\n"
				"\tsete al\n"
				"\txor ebx, ebx\n"
				"\tmov bl, al\n"
				"\tmov DWORD PTR %s, ebx\n"
						, node->op1->data, node->op2->data, node->res->data);
	}
    break;
  case TAC_NE:
	if(node->op1->type == LIT_INTEGER && node->op2->type == LIT_INTEGER) {
		if(atoi(node->op1->data) != atoi(node->op2->data))
			fprintf(out,
				"\tmov DWORD PTR %s, 1\n"
					,node->res->data);
		else 
			fprintf(out,
				"\tmov DWORD PTR %s, 0\n"
						,node->res->data);

	} else if ((node->op1->type == LIT_CHAR && node->op2->type == LIT_CHAR) || (node->op1->type == LIT_CHAR && node->op2->type == LIT_INTEGER) || (node->op1->type == LIT_INTEGER && node->op2->type == LIT_CHAR)) {
		fprintf(out,
			"\tmov eax, %s\n"
			"\tcmp eax, %s\n"
			"\tsetne al\n"
			"\txor ebx, ebx\n"
			"\tmov bl, al\n"
			"\tmov DWORD PTR %s, ebx\n"
				, node->op1->data, node->op2->data, node->res->data);
	
	} else if(node->op1->type == SYMBOL_VARIABLE && (node->op2->type == LIT_INTEGER || node->op2->type == LIT_CHAR)) {
		fprintf(out, 
				"\tmov eax, DWORD PTR %s\n"
				"\tcmp eax, %s\n"
				"\tsetne al\n"
				"\txor ebx, ebx\n"
				"\tmov bl, al\n"
				"\tmov DWORD PTR %s, ebx\n"
						, node->op1->data, node->op2->data, node->res->data);
	} else if((node->op1->type == LIT_INTEGER || node->op1->type == LIT_CHAR) && node->op2->type == SYMBOL_VARIABLE) {
		fprintf(out, 
				"\tmov eax, DWORD PTR %s\n"
				"\tcmp eax, %s\n"
				"\tsetne al\n"
				"\txor ebx, ebx\n"
				"\tmov bl, al\n"
				"\tmov DWORD PTR %s, ebx\n"
						, node->op2->data, node->op1->data, node->res->data);
	}else if(node->op1->type == SYMBOL_VARIABLE && node->op2->type == SYMBOL_VARIABLE) {
		fprintf(out, 
				"\tmov edx, DWORD PTR %s\n"
				"\tmov eax, DWORD PTR %s\n"
				"\tcmp edx, eax\n"
				"\tsetne al\n"
				"\txor ebx, ebx\n"
				"\tmov bl, al\n"
				"\tmov DWORD PTR %s, ebx\n"
						, node->op1->data, node->op2->data, node->res->data);
	}
    break;
  case TAC_LE:
	if(node->op1->type == LIT_INTEGER && node->op2->type == LIT_INTEGER) {
		if(atoi(node->op1->data) <= atoi(node->op2->data))
			fprintf(out,
				"\tmov DWORD PTR %s, 1\n"
					,node->res->data);
		else 
			fprintf(out,
				"\tmov DWORD PTR %s, 0\n"
						,node->res->data);

	} else if ((node->op1->type == LIT_CHAR && node->op2->type == LIT_CHAR) || (node->op1->type == LIT_CHAR && node->op2->type == LIT_INTEGER) || (node->op1->type == LIT_INTEGER && node->op2->type == LIT_CHAR)) {
		fprintf(out,
			"\tmov eax, %s\n"
			"\tcmp eax, %s\n"
			"\tsetle al\n"
			"\txor ebx, ebx\n"
			"\tmov bl, al\n"
			"\tmov DWORD PTR %s, ebx\n"
				, node->op1->data, node->op2->data, node->res->data);
	
	} else if(node->op1->type == SYMBOL_VARIABLE && (node->op2->type == LIT_INTEGER || node->op2->type == LIT_CHAR)) {
		fprintf(out, 
				"\tmov eax, DWORD PTR %s\n"
				"\tcmp eax, %s\n"
				"\tsetle al\n"
				"\txor ebx, ebx\n"
				"\tmov bl, al\n"
				"\tmov DWORD PTR %s, ebx\n"
						, node->op1->data, node->op2->data, node->res->data);
	} else if((node->op1->type == LIT_INTEGER || node->op1->type == LIT_CHAR) && node->op2->type == SYMBOL_VARIABLE) {
		fprintf(out, 
				"\tmov eax, DWORD PTR %s\n"
				"\tcmp eax, %s\n"
				"\tsetge al\n"
				"\txor ebx, ebx\n"
				"\tmov bl, al\n"
				"\tmov DWORD PTR %s, ebx\n"
						, node->op2->data, node->op1->data, node->res->data);
	}else if(node->op1->type == SYMBOL_VARIABLE && node->op2->type == SYMBOL_VARIABLE) {
		fprintf(out, 
				"\tmov edx, DWORD PTR %s\n"
				"\tmov eax, DWORD PTR %s\n"
				"\tcmp edx, eax\n"
				"\tsetle al\n"
				"\txor ebx, ebx\n"
				"\tmov bl, al\n"
				"\tmov DWORD PTR %s, ebx\n"
						, node->op1->data, node->op2->data, node->res->data);
	}
    break;
  case TAC_GE:
	if(node->op1->type == LIT_INTEGER && node->op2->type == LIT_INTEGER) {
		if(atoi(node->op1->data) >= atoi(node->op2->data))
			fprintf(out,
				"\tmov DWORD PTR %s, 1\n"
					,node->res->data);
		else 
			fprintf(out,
				"\tmov DWORD PTR %s, 0\n"
						,node->res->data);
	} else if ((node->op1->type == LIT_CHAR && node->op2->type == LIT_CHAR) || (node->op1->type == LIT_CHAR && node->op2->type == LIT_INTEGER) || (node->op1->type == LIT_INTEGER && node->op2->type == LIT_CHAR)) {
		fprintf(out,
			"\tmov eax, %s\n"
			"\tcmp eax, %s\n"
			"\tsetge al\n"
			"\txor ebx, ebx\n"
			"\tmov bl, al\n"
			"\tmov DWORD PTR %s, ebx\n"
				, node->op1->data, node->op2->data, node->res->data);

	} else if(node->op1->type == SYMBOL_VARIABLE && (node->op2->type == LIT_INTEGER || node->op2->type == LIT_CHAR)) {
		fprintf(out, 
				"\tmov eax, DWORD PTR %s\n"
				"\tcmp eax, %s\n"
				"\tsetge al\n"
				"\txor ebx, ebx\n"
				"\tmov bl, al\n"
				"\tmov DWORD PTR %s, ebx\n"
						, node->op1->data, node->op2->data, node->res->data);
	} else if((node->op1->type == LIT_INTEGER || node->op1->type == LIT_CHAR) && node->op2->type == SYMBOL_VARIABLE) {
		fprintf(out, 
				"\tmov eax, DWORD PTR %s\n"
				"\tcmp eax, %s\n"
				"\tsetle al\n"
				"\txor ebx, ebx\n"
				"\tmov bl, al\n"
				"\tmov DWORD PTR %s, ebx\n"
						, node->op2->data, node->op1->data, node->res->data);
	}else if(node->op1->type == SYMBOL_VARIABLE && node->op2->type == SYMBOL_VARIABLE) {
		fprintf(out, 
				"\tmov edx, DWORD PTR %s\n"
				"\tmov eax, DWORD PTR %s\n"
				"\tcmp edx, eax\n"
				"\tsetge al\n"
				"\txor ebx, ebx\n"
				"\tmov bl, al\n"
				"\tmov DWORD PTR %s, ebx\n"
						, node->op1->data, node->op2->data, node->res->data);
	}
    break;
  case TAC_LESS:
	if(node->op1->type == LIT_INTEGER && node->op2->type == LIT_INTEGER) {
		if(atoi(node->op1->data) < atoi(node->op2->data))
			fprintf(out,
				"\tmov DWORD PTR %s, 1\n"
					,node->res->data);
		else 
			fprintf(out,
				"\tmov DWORD PTR %s, 0\n"
						,node->res->data);



	} else if ((node->op1->type == LIT_CHAR && node->op2->type == LIT_CHAR) || (node->op1->type == LIT_CHAR && node->op2->type == LIT_INTEGER) || (node->op1->type == LIT_INTEGER && node->op2->type == LIT_CHAR)) {
		fprintf(out,
			"\tmov eax, %s\n"
			"\tcmp eax, %s\n"
			"\tsetl al\n"
			"\txor ebx, ebx\n"
			"\tmov bl, al\n"
			"\tmov DWORD PTR %s, ebx\n"
				, node->op1->data, node->op2->data, node->res->data);
	
	} else if(node->op1->type == SYMBOL_VARIABLE && (node->op2->type == LIT_INTEGER || node->op2->type == LIT_CHAR)) {
		fprintf(out, 
				"\tmov eax, DWORD PTR %s\n"
				"\tcmp eax, %s\n"
				"\tsetl al\n"
				"\txor ebx, ebx\n"
				"\tmov bl, al\n"
				"\tmov DWORD PTR %s, ebx\n"
						, node->op1->data, node->op2->data, node->res->data);
	} else if((node->op1->type == LIT_INTEGER || node->op1->type == LIT_CHAR) && node->op2->type == SYMBOL_VARIABLE) {
		fprintf(out, 
				"\tmov eax, DWORD PTR %s\n"
				"\tcmp eax, %s\n"
				"\tsetg al\n"
				"\txor ebx, ebx\n"
				"\tmov bl, al\n"
				"\tmov DWORD PTR %s, ebx\n"
						, node->op2->data, node->op1->data, node->res->data);
	}else if(node->op1->type == SYMBOL_VARIABLE && node->op2->type == SYMBOL_VARIABLE) {
		fprintf(out, 
				"\tmov edx, DWORD PTR %s\n"
				"\tmov eax, DWORD PTR %s\n"
				"\tcmp edx, eax\n"
				"\tsetl al\n"
				"\txor ebx, ebx\n"
				"\tmov bl, al\n"
				"\tmov DWORD PTR %s, ebx\n"
						, node->op1->data, node->op2->data, node->res->data);
	}
    break;
  case TAC_GREATER:
	if(node->op1->type == LIT_INTEGER && node->op2->type == LIT_INTEGER) {
		if(atoi(node->op1->data) > atoi(node->op2->data))
			fprintf(out,
				"\tmov DWORD PTR %s, 1\n"
					,node->res->data);
		else 
			fprintf(out,
				"\tmov DWORD PTR %s, 0\n"
						,node->res->data);

	} else if ((node->op1->type == LIT_CHAR && node->op2->type == LIT_CHAR) || (node->op1->type == LIT_CHAR && node->op2->type == LIT_INTEGER) || (node->op1->type == LIT_INTEGER && node->op2->type == LIT_CHAR)) {
		fprintf(out,
			"\tmov eax, %s\n"
			"\tcmp eax, %s\n"
			"\tsetg al\n"
			"\txor ebx, ebx\n"
			"\tmov bl, al\n"
			"\tmov DWORD PTR %s, ebx\n"
				, node->op1->data, node->op2->data, node->res->data);
	
	} else if(node->op1->type == SYMBOL_VARIABLE && (node->op2->type == LIT_INTEGER || node->op2->type == LIT_CHAR)) {
		fprintf(out, 
				"\tmov eax, DWORD PTR %s\n"
				"\tcmp eax, %s\n"
				"\tsetg al\n"
				"\txor ebx, ebx\n"
				"\tmov bl, al\n"
				"\tmov DWORD PTR %s, ebx\n"
						, node->op1->data, node->op2->data, node->res->data);
	} else if((node->op1->type == LIT_INTEGER || node->op1->type == LIT_CHAR) && node->op2->type == SYMBOL_VARIABLE) {
		fprintf(out, 
				"\tmov eax, DWORD PTR %s\n"
				"\tcmp eax, %s\n"
				"\tsetl al\n"
				"\txor ebx, ebx\n"
				"\tmov bl, al\n"
				"\tmov DWORD PTR %s, ebx\n"
						, node->op2->data, node->op1->data, node->res->data);
	}else if(node->op1->type == SYMBOL_VARIABLE && node->op2->type == SYMBOL_VARIABLE) {
		fprintf(out, 
				"\tmov edx, DWORD PTR %s\n"
				"\tmov eax, DWORD PTR %s\n"
				"\tcmp edx, eax\n"
				"\tsetg al\n"
				"\txor ebx, ebx\n"
				"\tmov bl, al\n"
				"\tmov DWORD PTR %s, ebx\n"
						, node->op1->data, node->op2->data, node->res->data);
	}
  case TAC_OR:
	if(node->op1->type == LIT_TRUE)  {node->op1->data = "1"; node->op1->type = LIT_INTEGER; }
	if(node->op1->type == LIT_FALSE) {node->op1->data = "0"; node->op1->type = LIT_INTEGER; }
	if(node->op2->type == LIT_TRUE)  {node->op2->data = "1"; node->op2->type = LIT_INTEGER; }
	if(node->op2->type == LIT_FALSE) {node->op2->data = "0"; node->op2->type = LIT_INTEGER; }

	if(node->op1->type == LIT_INTEGER && node->op2->type == LIT_INTEGER) {
		if(atoi(node->op1->data) || atoi(node->op2->data))
			fprintf(out,
				"\tmov DWORD PTR %s, 1\n"
					,node->res->data);
		else 
			fprintf(out,
				"\tmov DWORD PTR %s, 0\n"
						,node->res->data);

	} else if ((node->op1->type == LIT_CHAR && node->op2->type == LIT_CHAR) || (node->op1->type == LIT_CHAR && node->op2->type == LIT_INTEGER) || (node->op1->type == LIT_INTEGER && node->op2->type == LIT_CHAR)) {
		fprintf(out,
			"\tmov eax, %s\n"
			"\tor eax, %s\n"
			"\tmov DWORD PTR %s, eax\n"
				, node->op1->data, node->op2->data, node->res->data);
	
	} else if(node->op1->type == SYMBOL_VARIABLE && (node->op2->type == LIT_INTEGER || node->op2->type == LIT_CHAR)) {
		fprintf(out, 
				"\tmov eax, DWORD PTR %s\n"
				"\tor eax,  %s\n"
				"\tmov DWORD PTR %s, eax\n"
						, node->op1->data, node->op2->data, node->res->data);
	} else if((node->op1->type == LIT_INTEGER || node->op1->type == LIT_CHAR) && node->op2->type == SYMBOL_VARIABLE) {
		fprintf(out, 
				"\tmov eax, DWORD PTR %s\n"
				"\tor eax,  %s\n"
				"\tmov DWORD PTR %s, eax\n"
						, node->op2->data, node->op1->data, node->res->data);
	}else if(node->op1->type == SYMBOL_VARIABLE && node->op2->type == SYMBOL_VARIABLE) {
		fprintf(out, 
				"\tmov eax, DWORD PTR %s\n"
				"\tmov ebx, DWORD PTR %s\n"
				"\tor eax,  ebx\n"
				"\tmov DWORD PTR %s, eax\n"
						, node->op1->data, node->op2->data, node->res->data);
	}	
    break;
  case TAC_AND:
	if(node->op1->type == LIT_TRUE)  {node->op1->data = "1"; node->op1->type = LIT_INTEGER; }
	if(node->op1->type == LIT_FALSE) {node->op1->data = "0"; node->op1->type = LIT_INTEGER; }
	if(node->op2->type == LIT_TRUE)  {node->op2->data = "1"; node->op2->type = LIT_INTEGER; }
	if(node->op2->type == LIT_FALSE) {node->op2->data = "0"; node->op2->type = LIT_INTEGER; }

	if(node->op1->type == LIT_INTEGER && node->op2->type == LIT_INTEGER) {
		if(atoi(node->op1->data) && atoi(node->op2->data))
			fprintf(out,
				"\tmov DWORD PTR %s, 1\n"
					,node->res->data);
		else 
			fprintf(out,
				"\tmov DWORD PTR %s, 0\n"
						,node->res->data);

	} else if ((node->op1->type == LIT_CHAR && node->op2->type == LIT_CHAR) || (node->op1->type == LIT_CHAR && node->op2->type == LIT_INTEGER) || (node->op1->type == LIT_INTEGER && node->op2->type == LIT_CHAR)) {
		fprintf(out,
			"\tmov eax, %s\n"
			"\tand eax, %s\n"
			"\tmov DWORD PTR %s, eax\n"
				, node->op1->data, node->op2->data, node->res->data);
	
	} else if(node->op1->type == SYMBOL_VARIABLE && (node->op2->type == LIT_INTEGER || node->op2->type == LIT_CHAR)) {
		fprintf(out, 
				"\tmov eax, DWORD PTR %s\n"
				"\tand eax,  %s\n"
				"\tmov DWORD PTR %s, eax\n"
						, node->op1->data, node->op2->data, node->res->data);
	} else if((node->op1->type == LIT_INTEGER || node->op1->type == LIT_CHAR) && node->op2->type == SYMBOL_VARIABLE) {
		fprintf(out, 
				"\tmov eax, DWORD PTR %s\n"
				"\tand eax,  %s\n"
				"\tmov DWORD PTR %s, eax\n"
						, node->op2->data, node->op1->data, node->res->data);
	}else if(node->op1->type == SYMBOL_VARIABLE && node->op2->type == SYMBOL_VARIABLE) {
		fprintf(out, 
				"\tmov eax, DWORD PTR %s\n"
				"\tmov ebx, DWORD PTR %s\n"
				"\tand eax,  ebx\n"
				"\tmov DWORD PTR %s, eax\n"
						, node->op1->data, node->op2->data, node->res->data);
	}	
    break;
  case TAC_VARDEC:
	fprintf(out, "%s:\n", node->res->data);
    break;
  case TAC_VECDEC:
	fprintf(out, "\t.globl %s\n\t.align 4\n\t.type %s, @object\n\t.size %s, %d\n%s:\n", node->res->data, node->res->data, node->res->data, atoi(node->op1->data) * 4, node->res->data);
    break;
  case TAC_TOVECMOVE:
	if (node->op2->type == LIT_INTEGER) {
		fprintf(out, "\tmov eax, %s\n", node->op2->data);
		fprintf(out, "\tmov DWORD PTR %s+%d, eax\n", node->res->data, atoi(node->op1->data)*4);
	} else if (node->op2->type == SYMBOL_VARIABLE) {
		fprintf(out, "\tmov eax, DWORD PTR %s\n", node->op2->data);
		fprintf(out, "\tmov DWORD PTR %s+%d, eax\n", node->res->data, atoi(node->op1->data)*4);
	}
    break;
  case TAC_FROMVECMOVE:
    break;
  case TAC_INPUT:
    break;
  case TAC_OUTPUT:
    break;
  case TAC_RETURN:
	if (node->res->type == LIT_INTEGER)
        	fprintf(out, "\tmov eax, %s\n", node->res->data);
	else if (node->res->type == SYMBOL_VARIABLE)
		fprintf(out, "\tmov eax, DWORD PTR %s\n", node->res->data);
        fprintf(out, "\tpop ebp\n");
    break;
  case TAC_IF:
	if (node->res->type == LIT_INTEGER)
		fprintf(out, "\tmov eax, %s\n", node->res->data);
	else if (node->res->type == SYMBOL_VARIABLE)
		fprintf(out, "\tmov eax, DWORD PTR %s\n", node->res->data);
	fprintf(out, "\ttest eax, 0x00000000\n");
	fprintf(out, "\tjne %s\n", node->op1->data);
	fprintf(out, "\tje %s\n", node->op2->data);
    break;
  case TAC_CALL:
        fprintf(out, "\tcall %s\n", node->res->data);
    break;
  case TAC_PUSHARG:
	fprintf(out, "\tmov eax, %s\n", node->res->data);
	fprintf(out, "\tpush eax\n");
    break;
  case TAC_POPARG:
	fprintf(out, "\t.comm %s,4\n", node->res->data);
	fprintf(out, "\tmov eax, DWORD PTR [ebp+%d]\n", popArg * 4);
	fprintf(out, "\tmov %s, eax\n", node->res->data);
	popArg++;
    break;
  case TAC_FUNDEC:
	popArg = 2;
	fprintf(out, "\tpush ebp\n");
        fprintf(out, "\tmov ebp, esp\n");
	break;
  case TAC_INITVAR:
	fprintf(out, "\t.long %s\n", node->res->data);
	break;
  case TAC_TEMPVARDEC:
	fprintf(out, "\t.comm %s,4\n", node->res->data);
    	break;
  }
}
