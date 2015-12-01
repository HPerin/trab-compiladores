#include "asmgen.h"

#define LIT_INTEGER 3
#define LIT_FALSE 4
#define LIT_TRUE 5
#define LIT_CHAR 6
#define LIT_STRING 7
#define SYMBOL_VARIABLE 9

int popArg = 0;
int stringNum = 0;

void asmgen_gennode(tac_node_t * node, FILE * out);

void asmgen_run(tac_node_t * root, FILE * out) {
	tac_node_t * node = root;

	fprintf(out, "\t.data\n");

	while(node != NULL) {
		asmgen_genvars(node, out);
		node = node->next;
	}

	fprintf(out, "\t.text\n");

	node = root;
	while(node != NULL) {
		asmgen_gennode(node, out);
		node = node->next;
	}
}

void asmgen_genvars(tac_node_t * node, FILE * out) {
   if (!node) return;

   switch(node->type) {
   case TAC_VARDEC:
	fprintf(out, "\t.globl %s\n%s:\n", node->res->data, node->res->data);
    break;
   case TAC_VECDEC:
	fprintf(out, "\t.globl %s\n%s:\n", node->res->data, node->res->data);
    break;
   case TAC_INITVAR:
	fprintf(out, "\t.long %s\n", node->res->data);
	break;
   case TAC_TEMPVARDEC:
	fprintf(out, "\t.comm %s,4\n", node->res->data);
    	break;
   case TAC_VECFILL:
	fprintf(out, "\t.zero %s\n", node->res->data);
	break;
   }
}

void asmgen_gennode(tac_node_t * node, FILE * out) {
  if (!node) return;

  switch(node->type) {
  case TAC_SYMBOL:
	
    break;
 case TAC_MOVE:
	if (node->op1->type == SYMBOL_VARIABLE)
		fprintf(out, "\tmovq %s(%rip), %rax\n", node->res->data);
	else
		fprintf(out, "\tmovq $%s, %rax\n", node->res->data);
	fprintf(out, "\tmovq %rax, %s(%rip)\n", node->res->data);
    break;
 case TAC_ADD:
	
    break;
  case TAC_SUB:
	
    break;
  case TAC_MUL:
	
    break;
  case TAC_DIV:
	
    break;
  case TAC_LABEL:
	fprintf(out, "\t%s:\n", node->res->data);
    break;
  case TAC_FUNLABEL:
	if (!strcmp(node->res->data, "main")) {
		fprintf(out, "\t.globl main\n");
		fprintf(out, "main:\n");
		fprintf(out, "\tpushq %rbp\n");
		fprintf(out, "\tmovq %rsp, %rbp\n");
	} else {
		fprintf(out, "\t.globl %s\n");
		fprintf(out, "%s:\n");
		fprintf(out, "\tpushq %rbp\n");
		fprintf(out, "\tmovq %rsp, %rbp\n");
	}
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
  case TAC_OR:
		
    break;
  case TAC_AND:
		
    break;
  case TAC_TOVECMOVE:
	
    break;
  case TAC_FROMVECMOVE:
	
    break;
  case TAC_INPUT:
	
    break;
  case TAC_OUTPUT:
	
    break;
  case TAC_RETURN:
	if (node->res->type == SYMBOL_VARIABLE)
		fprintf(out, "\tmovq %s, %rax\n", node->res->data);
	else
		fprintf(out, "\tmovq $%s, %rax\n", node->res->data);
	fprintf(out, "\tpopq %rbp\n");
	fprintf(out, "\tret\n");
    break;
  case TAC_IF:
	
    break;
  case TAC_CALL:
        
    break;
  case TAC_PUSHARG:
	
    break;
  case TAC_POPARG:
	
    break;
  case TAC_FUNDEC:
	
	break;
  }
}
