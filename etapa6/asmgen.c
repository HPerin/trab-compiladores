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
	fprintf(out, ".intprint:\n\t.string \"%%d\"\n");

	while(node != NULL) {
		asmgen_genvars(node, out);
		node = node->next;
	}

	fprintf(out, "\n\n\t.text\n");
	stringNum = 0;

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
	fprintf(out, "\t.quad %s\n", node->res->data);
	break;
   case TAC_TEMPVARDEC:
	fprintf(out, "\t.comm %s,8\n", node->res->data);
    	break;
   case TAC_VECFILL:
	fprintf(out, "\t.zero %d\n", atoi(node->res->data) * 8);
	break;
   case TAC_OUTPUT:
	if (node->res->type == LIT_STRING)
		fprintf(out, ".str%d:\n\t.string %s\n", stringNum++, node->res->data);
   }
}

void asmgen_gennode(tac_node_t * node, FILE * out) {
  if (!node) return;

  switch(node->type) {
  case TAC_SYMBOL:
	
    break;
 case TAC_MOVE:
	printf("%s - %d\n", node->op1->data, node->op1->type);
	if (node->op1->type == SYMBOL_VARIABLE || node->op1->type == SYMBOL_VECTOR)
		fprintf(out, "\tmovq %s(%rip), %rax\n", node->op1->data);
	else
		fprintf(out, "\tmovq $%s, %rax\n", node->op1->data);
	fprintf(out, "\tmovq %rax, %s(%rip)\n", node->res->data);
    break;
 case TAC_ADD:
	if (node->op1->type == SYMBOL_VARIABLE || node->op1->type == SYMBOL_VECTOR)
		fprintf(out, "\tmovq %s(%rip), %rax\n", node->op1->data);
	else
		fprintf(out, "\tmovq $%s, %rax\n", node->op1->data);

	if (node->op2->type == SYMBOL_VARIABLE || node->op2->type == SYMBOL_VECTOR)
		fprintf(out, "\tmovq %s(%rip), %rbx\n", node->op2->data);
	else
		fprintf(out, "\tmovq $%s, %rbx\n", node->op2->data);

	fprintf(out, "\taddq %rbx, %rax\n");
	fprintf(out, "\tmovq %rax, %s(%rip)\n", node->res->data);
    break;
  case TAC_SUB:
	if (node->op1->type == SYMBOL_VARIABLE || node->op1->type == SYMBOL_VECTOR)
		fprintf(out, "\tmovq %s(%rip), %rax\n", node->op1->data);
	else
		fprintf(out, "\tmovq $%s, %rax\n", node->op1->data);

	if (node->op2->type == SYMBOL_VARIABLE || node->op2->type == SYMBOL_VECTOR)
		fprintf(out, "\tmovq %s(%rip), %rbx\n", node->op2->data);
	else
		fprintf(out, "\tmovq $%s, %rbx\n", node->op2->data);

	fprintf(out, "\tsubq %rbx, %rax\n");
	fprintf(out, "\tmovq %rax, %s(%rip)\n", node->res->data);
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
		fprintf(out, "\n\t.globl main\n");
		fprintf(out, "main:\n");
		fprintf(out, "\tpushq %rbp\n");
		fprintf(out, "\tmovq %rsp, %rbp\n");
	} else {
		fprintf(out, "\n\t.globl %s\n");
		fprintf(out, "%s:\n");
		fprintf(out, "\tpushq %rbp\n");
		fprintf(out, "\tmovq %rsp, %rbp\n");
	}
    break;
  case TAC_JMP:
	fprintf(out, "\tjmp %s\n", node->res->data);
    break;
  case TAC_RET:
	
    break;
  case TAC_EQ:
	if (node->op1->type == SYMBOL_VARIABLE || node->op1->type == SYMBOL_VECTOR)
		fprintf(out, "\tmovq %s(%rip), %rax\n", node->op1->data);
	else
		fprintf(out, "\tmovq $%s, %rax\n", node->op1->data);

	if (node->op2->type == SYMBOL_VARIABLE || node->op2->type == SYMBOL_VECTOR)
		fprintf(out, "\tmovq %s(%rip), %rbx\n", node->op2->data);
	else
		fprintf(out, "\tmovq $%s, %rbx\n", node->op2->data);

	fprintf(out, "\tcmpq %rax, %rbx\n");
	fprintf(out, "\tsete %%al\n");
	fprintf(out, "\tmovzbq %%al, %rax\n");
	fprintf(out, "\tmov %rax, %s(%rip)\n", node->res->data);
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
	if (node->op1->type == SYMBOL_VARIABLE || node->op1->type == SYMBOL_VECTOR)
		fprintf(out, "\tmovq %s(%rip), %rax\n", node->op1->data);
	else
		fprintf(out, "\tmovq $%s, %rax\n", node->op1->data);

	if (node->op1->type == SYMBOL_VARIABLE || node->op2->type == SYMBOL_VECTOR)
		fprintf(out, "\tmovq %s(%rip), %rbx\n", node->op2->data);
	else
		fprintf(out, "\tmovq $%s, %rbx\n", node->op2->data);

	fprintf(out, "\tmovq %rbx, %s(,%rax,4)\n", node->res->data);
    break;
  case TAC_FROMVECMOVE:
	if (node->op2->type == SYMBOL_VARIABLE || node->op2->type == SYMBOL_VECTOR)
		fprintf(out, "\tmovq %s(%rip), %rax\n", node->op2->data);
	else
		fprintf(out, "\tmovq $%s, %rax\n", node->op2->data);

	fprintf(out, "\tmovq %s(,%rax,8), %rax\n", node->op1->data);
	fprintf(out, "\tmovq %rax, %s(%rip)\n", node->res->data);
    break;
  case TAC_INPUT:
	
    break;
  case TAC_OUTPUT:
	if (node->res->type == SYMBOL_VARIABLE && node->res->dataType == DATATYPE_INT) {
		fprintf(out, "\tmovq %s(%rip), %rax\n", node->res->data);
		fprintf(out, "\tmovq %rax, %rsi\n");
		fprintf(out, "\tmovq $.intprint, %rdi\n");
		fprintf(out, "\tmovq $0, %rax\n");
		fprintf(out, "\tcall printf\n");
	} else if (node->res->type == LIT_STRING) {
		fprintf(out, "\tmovq $.str%d, %rdi\n", stringNum++);
		fprintf(out, "\tcall puts\n");
	}
    break;
  case TAC_RETURN:
	if (node->res->type == SYMBOL_VARIABLE || node->res->type == SYMBOL_VECTOR)
		fprintf(out, "\tmovq %s(%rip), %rax\n", node->res->data);
	else
		fprintf(out, "\tmovq $%s, %rax\n", node->res->data);
	fprintf(out, "\tpopq %rbp\n");
	fprintf(out, "\tret\n");
    break;
  case TAC_IF:
	if (node->res->type == SYMBOL_VARIABLE || node->res->type == SYMBOL_VECTOR)
		fprintf(out, "\tmovq %s(%rip), %rax\n", node->res->data);
	else
		fprintf(out, "\tmovq $%s, %rax\n", node->res->data);

	fprintf(out, "\tmovq $0, %rbx\n");
	fprintf(out, "\tcmpq %rax, %rbx\n");
	fprintf(out, "\tje %s\n", node->op2->data);
	fprintf(out, "\tjne %s\n", node->op1->data);
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
