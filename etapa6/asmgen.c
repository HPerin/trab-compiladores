#include "asmgen.h"

#define LIT_INTEGER 3
#define LIT_FALSE 4
#define LIT_TRUE 5
#define LIT_CHAR 6
#define LIT_STRING 7
#define SYMBOL_VARIABLE 9

int popArg = 0;
int stringNum = 0;
int rl = 0;

void asmgen_gennode(tac_node_t * node, FILE * out);

void asmgen_run(tac_node_t * root, FILE * out) {
	tac_node_t * node = root;

	fprintf(out, "\t.data\n");
	fprintf(out, ".formatint:\n\t.string \"%%d\"\n");
	fprintf(out, ".formatdouble:\n\t.string \"%%lf\"\n");
	fprintf(out, ".formatstring:\n\t.string \"%s\"\n", "%s");

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
	fprintf(out, "%s:\n", node->res->data, node->res->data);
    break;
   case TAC_VECDEC:
	fprintf(out, "%s:\n", node->res->data, node->res->data);
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
	fprintf(out, "\t\t#MOV TYPE = %d || %d\n", node->op1->dataType, node->res->dataType);

	if (node->res->dataType == DATATYPE_UNDEFINED)
		node->res->dataType = node->op1->dataType;

	if (node->op1->type == SYMBOL_VARIABLE)
		fprintf(out, "\tmovq %s(%rip), %rax\n", node->op1->data);
	else
		fprintf(out, "\tmovq $%s, %rax\n", node->op1->data);

	if (node->op1->dataType == DATATYPE_REAL && node->res->dataType != DATATYPE_REAL) {
		fprintf(out, "\tmovsd %rax, %%xmm0\n");
		fprintf(out, "\tcvttsd2siq %%xmm0, %s(%rip)\n", node->op1->data);
	} else if (node->res->dataType == DATATYPE_REAL && node->op1->dataType != DATATYPE_REAL) {
		fprintf(out, "\tcvtsi2sdq %rax, %%xmm0\n");
		fprintf(out, "\tmovsd %%xmm0, %s(%rip)\n", node->res->data);
	} else {
		fprintf(out, "\tmovq %rax, %s(%rip)\n", node->res->data);
	}
    break;
 case TAC_ADD:
	fprintf(out, "\t\t#ADD TYPE = %d || %d\n", node->op1->dataType, node->op2->dataType);
	if (node->op1->dataType == DATATYPE_REAL || node->op2->dataType == DATATYPE_REAL) {
		node->res->dataType = DATATYPE_REAL;

		if (node->op1->type == SYMBOL_VARIABLE) {
			if (node->op1->dataType == DATATYPE_REAL)
				fprintf(out, "\tmovsd %s(%rip), %%xmm1\n", node->op1->data);
			else {
				fprintf(out, "\tmovq %s(%rip), %rax\n", node->op1->data);
				fprintf(out, "\tcvtsi2sdq %rax, %%xmm1\n", node->op1->data);
			}
		} else {
			fprintf(out, "\tmovq $%s, %rax\n", node->op1->data);
			fprintf(out, "\tcvtsi2sdq %rax, %%xmm1\n", node->op1->data);
		}

		if (node->op2->type == SYMBOL_VARIABLE) {
			if (node->op2->dataType == DATATYPE_REAL)
				fprintf(out, "\tmovsd %s(%rip), %%xmm0\n", node->op2->data);
			else {
				fprintf(out, "\tmovq %s(%rip), %rax\n", node->op2->data);
				fprintf(out, "\tcvtsi2sdq %rax, %%xmm0\n", node->op2->data);
			}
		} else {
			fprintf(out, "\tmovq $%s, %rax\n", node->op2->data);
			fprintf(out, "\tcvtsi2sdq %rax, %%xmm0\n", node->op2->data);
		}

		fprintf(out, "\taddsd %%xmm1, %%xmm0\n");
		fprintf(out, "\tmovsd %%xmm0, %s(%rip)\n", node->res->data);
	} else {
		if (node->op1->type == SYMBOL_VARIABLE || node->op1->type == SYMBOL_VECTOR) {
			fprintf(out, "\tmovq %s(%rip), %rax\n", node->op1->data);
		} else
			fprintf(out, "\tmovq $%s, %rax\n", node->op1->data);

		if (node->op2->type == SYMBOL_VARIABLE || node->op2->type == SYMBOL_VECTOR)
			fprintf(out, "\tmovq %s(%rip), %rbx\n", node->op2->data);
		else
			fprintf(out, "\tmovq $%s, %rbx\n", node->op2->data);

		fprintf(out, "\taddq %rbx, %rax\n");
		fprintf(out, "\tmovq %rax, %s(%rip)\n", node->res->data);
	}
    break;
  case TAC_SUB:	
	fprintf(out, "\t\t#SUB TYPE = %d || %d\n", node->op1->dataType, node->op2->dataType);
	if (node->op1->dataType == DATATYPE_REAL || node->op2->dataType == DATATYPE_REAL) {
		node->res->dataType = DATATYPE_REAL;

		if (node->op1->type == SYMBOL_VARIABLE) {
			if (node->op1->dataType == DATATYPE_REAL)
				fprintf(out, "\tmovsd %s(%rip), %%xmm1\n", node->op1->data);
			else {
				fprintf(out, "\tmovq %s(%rip), %rax\n", node->op1->data);
				fprintf(out, "\tcvtsi2sdq %rax, %%xmm1\n", node->op1->data);
			}
		} else {
			fprintf(out, "\tmovq $%s, %rax\n", node->op1->data);
			fprintf(out, "\tcvtsi2sdq %rax, %%xmm1\n", node->op1->data);
		}

		if (node->op2->type == SYMBOL_VARIABLE) {
			if (node->op2->dataType == DATATYPE_REAL)
				fprintf(out, "\tmovsd %s(%rip), %%xmm0\n", node->op2->data);
			else {
				fprintf(out, "\tmovq %s(%rip), %rax\n", node->op2->data);
				fprintf(out, "\tcvtsi2sdq %rax, %%xmm0\n", node->op2->data);
			}
		} else {
			fprintf(out, "\tmovq $%s, %rax\n", node->op2->data);
			fprintf(out, "\tcvtsi2sdq %rax, %%xmm0\n", node->op2->data);
		}

		fprintf(out, "\tsubsd %%xmm0, %%xmm1\n");
		fprintf(out, "\tmovsd %%xmm1, %s(%rip)\n", node->res->data);

	} else {
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
	}
    break;
  case TAC_MUL:
	fprintf(out, "\t\t#MUL TYPE = %d || %d\n", node->op1->dataType, node->op2->dataType);
	if (node->op1->dataType == DATATYPE_REAL || node->op2->dataType == DATATYPE_REAL) {
		node->res->dataType = DATATYPE_REAL;

		if (node->op1->type == SYMBOL_VARIABLE) {
			if (node->op1->dataType == DATATYPE_REAL)
				fprintf(out, "\tmovsd %s(%rip), %%xmm1\n", node->op1->data);
			else {
				fprintf(out, "\tmovq %s(%rip), %rax\n", node->op1->data);
				fprintf(out, "\tcvtsi2sdq %rax, %%xmm1\n", node->op1->data);
			}
		} else {
			fprintf(out, "\tmovq $%s, %rax\n", node->op1->data);
			fprintf(out, "\tcvtsi2sdq %rax, %%xmm1\n", node->op1->data);
		}

		if (node->op2->type == SYMBOL_VARIABLE) {
			if (node->op2->dataType == DATATYPE_REAL)
				fprintf(out, "\tmovsd %s(%rip), %%xmm0\n", node->op2->data);
			else {
				fprintf(out, "\tmovq %s(%rip), %rax\n", node->op2->data);
				fprintf(out, "\tcvtsi2sdq %rax, %%xmm0\n", node->op2->data);
			}
		} else {
			fprintf(out, "\tmovq $%s, %rax\n", node->op2->data);
			fprintf(out, "\tcvtsi2sdq %rax, %%xmm0\n", node->op2->data);
		}

		fprintf(out, "\tmulsd %%xmm0, %%xmm1\n");
		fprintf(out, "\tmovsd %%xmm1, %s(%rip)\n", node->res->data);

	} else {
		if (node->op1->type == SYMBOL_VARIABLE || node->op1->type == SYMBOL_VECTOR)
			fprintf(out, "\tmovq %s(%rip), %rax\n", node->op1->data);
		else
			fprintf(out, "\tmovq $%s, %rax\n", node->op1->data);

		if (node->op2->type == SYMBOL_VARIABLE || node->op2->type == SYMBOL_VECTOR)
			fprintf(out, "\tmovq %s(%rip), %rdx\n", node->op2->data);
		else
			fprintf(out, "\tmovq $%s, %rdx\n", node->op2->data);

		fprintf(out, "\timulq %rdx, %rax\n");
		fprintf(out, "\tmovq %rax, %s(%rip)\n", node->res->data);
	}
    break;
  case TAC_DIV:
	fprintf(out, "\t\t#DIV TYPE = %d || %d\n", node->op1->dataType, node->op2->dataType);
	if (node->op1->dataType == DATATYPE_REAL || node->op2->dataType == DATATYPE_REAL) {
		node->res->dataType = DATATYPE_REAL;

		if (node->op1->type == SYMBOL_VARIABLE) {
			if (node->op1->dataType == DATATYPE_REAL)
				fprintf(out, "\tmovsd %s(%rip), %%xmm1\n", node->op1->data);
			else {
				fprintf(out, "\tmovq %s(%rip), %rax\n", node->op1->data);
				fprintf(out, "\tcvtsi2sdq %rax, %%xmm1\n", node->op1->data);
			}
		} else {
			fprintf(out, "\tmovq $%s, %rax\n", node->op1->data);
			fprintf(out, "\tcvtsi2sdq %rax, %%xmm1\n", node->op1->data);
		}

		if (node->op2->type == SYMBOL_VARIABLE) {
			if (node->op2->dataType == DATATYPE_REAL)
				fprintf(out, "\tmovsd %s(%rip), %%xmm0\n", node->op2->data);
			else {
				fprintf(out, "\tmovq %s(%rip), %rax\n", node->op2->data);
				fprintf(out, "\tcvtsi2sdq %rax, %%xmm0\n", node->op2->data);
			}
		} else {
			fprintf(out, "\tmovq $%s, %rax\n", node->op2->data);
			fprintf(out, "\tcvtsi2sdq %rax, %%xmm0\n", node->op2->data);
		}

		fprintf(out, "\tdivsd %%xmm0, %%xmm1\n");
		fprintf(out, "\tmovsd %%xmm1, %s(%rip)\n", node->res->data);

	} else {
		if (node->op1->type == SYMBOL_VARIABLE || node->op1->type == SYMBOL_VECTOR)
			fprintf(out, "\tmovq %s(%rip), %rax\n", node->op1->data);
		else
			fprintf(out, "\tmovq $%s, %rax\n", node->op1->data);

		if (node->op2->type == SYMBOL_VARIABLE || node->op2->type == SYMBOL_VECTOR)
			fprintf(out, "\tmovq %s(%rip), %rcx\n", node->op2->data);
		else
			fprintf(out, "\tmovq $%s, %rcx\n", node->op2->data);

		fprintf(out, "\tcqto\n");
		fprintf(out, "\tidivq %rcx\n");
		fprintf(out, "\tmovq %rax, %s(%rip)\n", node->res->data);
	}
    break;
  case TAC_LABEL:
	fprintf(out, "%s:\n", node->res->data);
    break;
  case TAC_FUNLABEL:
	fprintf(out, "\n\t.globl %s\n", node->res->data);
	fprintf(out, "%s:\n", node->res->data);
	fprintf(out, "\tpushq %rbp\n");
	fprintf(out, "\tmovq %rsp, %rbp\n");
    break;
  case TAC_JMP:
	fprintf(out, "\tjmp %s\n", node->res->data);
    break;
  case TAC_RET:
	
    break;
  case TAC_EQ:
	fprintf(out, "\t\t#EQ TYPE = %d || %d\n", node->op1->dataType, node->op2->dataType);

	if ((node->op1->dataType == DATATYPE_REAL || node->op1->dataType == DATATYPE_REAL) && (node->op1->dataType != node->op2->dataType)) {

		int rl1 = rl++;
		int rl2 = rl++;

		if (node->op1->dataType == DATATYPE_REAL) {
			fprintf(out, "\tmovsd %s(%rip), %%xmm1\n", node->op1->data);
			if (node->op2->type == SYMBOL_VARIABLE) fprintf(out, "\tmovq %s(%rip), %rax\n", node->op2->data);
			else fprintf(out, "\tmovq $%s, %rax\n", node->op2->data);
			fprintf(out, "\tcvtsi2sdq %rax, %%xmm0\n");
		} else {
			fprintf(out, "\tmovsd %s(%rip), %%xmm1\n", node->op2->data);
			if (node->op2->type == SYMBOL_VARIABLE) fprintf(out, "\tmovq %s(%rip), %rax\n", node->op1->data);
			else fprintf(out, "\tmovq $%s, %rax\n", node->op1->data);
			fprintf(out, "\tcvtsi2sdq %rax, %%xmm0\n");
		}

		fprintf(out, "\tucomisd %%xmm0, %%xmm1\n");
		fprintf(out, "\tjp .rl%d\n", rl1);
		fprintf(out, "\tucomisd %%xmm0, %%xmm1\n");
		fprintf(out, "\tjne .rl%d\n", rl1);
		fprintf(out, "\tmovq $1, %rax\n");
		fprintf(out, "\tjmp .rl%d\n", rl2);
		fprintf(out, ".rl%d:\n", rl1);
		fprintf(out, "\tmovq $0, %rax\n");
		fprintf(out, ".rl%d:\n", rl2);
		fprintf(out, "\tmovq %rax, %s(%rip)\n", node->res->data);
		

	} else if (node->op1->dataType == node->op2->dataType && node->op2->dataType == DATATYPE_REAL) {
		int rl1 = rl++;
		int rl2 = rl++;

		fprintf(out, "\tmovsd %s(%rip), %%xmm0\n", node->op2->data);
		fprintf(out, "\tmovsd %s(%rip), %%xmm1\n", node->op1->data);
		fprintf(out, "\tucomisd %%xmm0, %%xmm1\n");
		fprintf(out, "\tjp .rl%d\n", rl1);
		fprintf(out, "\tucomisd %%xmm0, %%xmm1\n");
		fprintf(out, "\tjne .rl%d\n", rl1);
		fprintf(out, "\tmovq $1, %rax\n");
		fprintf(out, "\tjmp .rl%d\n", rl2);
		fprintf(out, ".rl%d:\n", rl1);
		fprintf(out, "\tmovq $0, %rax\n");
		fprintf(out, ".rl%d:\n", rl2);
		fprintf(out, "\tmovq %rax, %s(%rip)\n", node->res->data);
	
	} else {
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
		fprintf(out, "\tmovq %rax, %s(%rip)\n", node->res->data);
	}
    break;
  case TAC_NE:
	fprintf(out, "\t\t#NE TYPE = %d || %d\n", node->op1->dataType, node->op2->dataType);

	if ((node->op1->dataType == DATATYPE_REAL || node->op1->dataType == DATATYPE_REAL) && (node->op1->dataType != node->op2->dataType)) {

		int rl1 = rl++;
		int rl2 = rl++;
		int rl3 = rl++;

		if (node->op1->dataType == DATATYPE_REAL) {
			fprintf(out, "\tmovsd %s(%rip), %%xmm1\n", node->op1->data);
			if (node->op2->type == SYMBOL_VARIABLE) fprintf(out, "\tmovq %s(%rip), %rax\n", node->op2->data);
			else fprintf(out, "\tmovq $%s, %rax\n", node->op2->data);
			fprintf(out, "\tcvtsi2sdq %rax, %%xmm0\n");
		} else {
			fprintf(out, "\tmovsd %s(%rip), %%xmm1\n", node->op2->data);
			if (node->op2->type == SYMBOL_VARIABLE) fprintf(out, "\tmovq %s(%rip), %rax\n", node->op1->data);
			else fprintf(out, "\tmovq $%s, %rax\n", node->op1->data);
			fprintf(out, "\tcvtsi2sdq %rax, %%xmm0\n");
		}

		fprintf(out, "\tucomisd %%xmm0, %%xmm1\n");
		fprintf(out, "\tjp .rl%d\n", rl3);
		fprintf(out, "\tucomisd %%xmm0, %%xmm1\n");
		fprintf(out, "\tje .rl%d\n", rl1);
		fprintf(out, ".rl%d:\n", rl3);
		fprintf(out, "\tmovq $1, %rax\n");
		fprintf(out, "\tjmp .rl%d\n", rl2);
		fprintf(out, ".rl%d:\n", rl1);
		fprintf(out, "\tmovq $0, %rax\n");
		fprintf(out, ".rl%d:\n", rl2);
		fprintf(out, "\tmovq %rax, %s(%rip)\n", node->res->data);
		

	} else if (node->op1->dataType == node->op2->dataType && node->op2->dataType == DATATYPE_REAL) {
		int rl1 = rl++;
		int rl2 = rl++;
		int rl3 = rl++;

		fprintf(out, "\tmovsd %s(%rip), %%xmm0\n", node->op2->data);
		fprintf(out, "\tmovsd %s(%rip), %%xmm1\n", node->op1->data);
		fprintf(out, "\tucomisd %%xmm0, %%xmm1\n");
		fprintf(out, "\tjp .rl%d\n", rl3);
		fprintf(out, "\tucomisd %%xmm0, %%xmm1\n");
		fprintf(out, "\tje .rl%d\n", rl1);
		fprintf(out, ".rl%d:\n", rl3);
		fprintf(out, "\tmovq $1, %rax\n");
		fprintf(out, "\tjmp .rl%d\n", rl2);
		fprintf(out, ".rl%d:\n", rl1);
		fprintf(out, "\tmovq $0, %rax\n");
		fprintf(out, ".rl%d:\n", rl2);
		fprintf(out, "\tmovq %rax, %s(%rip)\n", node->res->data);
	
	} else {
		if (node->op1->type == SYMBOL_VARIABLE || node->op1->type == SYMBOL_VECTOR)
			fprintf(out, "\tmovq %s(%rip), %rax\n", node->op1->data);
		else
			fprintf(out, "\tmovq $%s, %rax\n", node->op1->data);

		if (node->op2->type == SYMBOL_VARIABLE || node->op2->type == SYMBOL_VECTOR)
			fprintf(out, "\tmovq %s(%rip), %rbx\n", node->op2->data);
		else
			fprintf(out, "\tmovq $%s, %rbx\n", node->op2->data);
	
		fprintf(out, "\tcmpq %rax, %rbx\n");
		fprintf(out, "\tsetne %%al\n");
		fprintf(out, "\tmovzbq %%al, %rax\n");
		fprintf(out, "\tmovq %rax, %s(%rip)\n", node->res->data);
	}
    break;
  case TAC_LE:
	fprintf(out, "\t\t#LE TYPE = %d || %d\n", node->op1->dataType, node->op2->dataType);
	
    break;
  case TAC_GE:	
	fprintf(out, "\t\t#GE TYPE = %d || %d\n", node->op1->dataType, node->op2->dataType);
	
    break;
  case TAC_LESS:
	fprintf(out, "\t\t#LESS TYPE = %d || %d\n", node->op1->dataType, node->op2->dataType);
    
    break;
  case TAC_OR:
	fprintf(out, "\t\t#OR TYPE = %d || %d\n", node->op1->dataType, node->op2->dataType);
		
    break;
  case TAC_AND:
	fprintf(out, "\t\t#AND TYPE = %d || %d\n", node->op1->dataType, node->op2->dataType);
		
    break;
  case TAC_TOVECMOVE:
	fprintf(out, "\t\t#TOVECMOVE TYPE = %d || %d\n", node->res->dataType, node->op2->dataType);

	if ((node->op2->dataType == DATATYPE_REAL || node->res->dataType == DATATYPE_REAL) && (node->op2->dataType != node->res->dataType)) {
		if (node->op1->type == SYMBOL_VARIABLE || node->op1->type == SYMBOL_VECTOR)
			fprintf(out, "\tmovq %s(%rip), %rax\n", node->op1->data);
		else
			fprintf(out, "\tmovq $%s, %rax\n", node->op1->data);

		if (node->res->dataType == DATATYPE_REAL) {
			fprintf(out, "\tmovq %s(%rip), %rbx\n", node->op2->data);
			fprintf(out, "\tcvtsi2sdq %rbx, %%xmm0\n");
			fprintf(out, "\tmovsd %%xmm0, %s(%rip)\n", node->res->data);
			fprintf(out, "\tmovsd %s(%rip), %rbx\n", node->res->data);
		} else {
			fprintf(out, "\tmovsd %s(%rip), %%xmm0\n", node->op2->data);
			fprintf(out, "\tcvttsd2siq %%xmm0, %rbx\n");
		}

		fprintf(out, "\tmovq %rbx, %s(,%rax,8)\n", node->res->data);
	} else {
		if (node->op1->type == SYMBOL_VARIABLE || node->op1->type == SYMBOL_VECTOR)
			fprintf(out, "\tmovq %s(%rip), %rax\n", node->op1->data);
		else
			fprintf(out, "\tmovq $%s, %rax\n", node->op1->data);

		if (node->op1->type == SYMBOL_VARIABLE || node->op2->type == SYMBOL_VECTOR)
			fprintf(out, "\tmovq %s(%rip), %rbx\n", node->op2->data);
		else
			fprintf(out, "\tmovq $%s, %rbx\n", node->op2->data);

		fprintf(out, "\tmovq %rbx, %s(,%rax,8)\n", node->res->data);
	}
    break;
  case TAC_FROMVECMOVE:
	if (node->res->dataType == DATATYPE_UNDEFINED)
		node->res->dataType = node->op1->dataType;

	fprintf(out, "\t\t#FROMVECMOVE TYPE = %d || %d\n", node->res->dataType, node->op1->dataType);
	if ((node->op1->dataType == DATATYPE_REAL || node->res->dataType == DATATYPE_REAL) && (node->op1->dataType != node->res->dataType)) {
		fprintf(out, "\t\t#FROMVECMOVE (not implemented)", node->op1->dataType, node->op2->dataType);

		if (node->op2->type == SYMBOL_VARIABLE)
			fprintf(out, "\tmovq %s(%rip), %rax\n", node->op2->data);
		else
			fprintf(out, "\tmovq $%s, %rax\n", node->op2->data);

		if (node->res->dataType == DATATYPE_REAL) {
			fprintf(out, "\tmovq %s(,%rax,8), %rbx\n", node->op1->data);
			fprintf(out, "\tcvtsi2sdq %rbx, %%xmm0\n");
			fprintf(out, "\tmovsd %%xmm0, %s(%rip)\n", node->res->data);
		} else {
			fprintf(out, "\tmovsd %s(,%rax,8), %%xmm0\n", node->op1->data);
			fprintf(out, "\tcvttsd2siq %%xmm0, %rbx\n");
			fprintf(out, "\tcvttsd2siq %rbx, %s(%rip)\n", node->res->data);
		}

		
	} else {
		if (node->op2->type == SYMBOL_VARIABLE || node->op2->type == SYMBOL_VECTOR)
			fprintf(out, "\tmovq %s(%rip), %rax\n", node->op2->data);
		else
			fprintf(out, "\tmovq $%s, %rax\n", node->op2->data);

		fprintf(out, "\tmovq %s(,%rax,8), %rax\n", node->op1->data);
		fprintf(out, "\tmovq %rax, %s(%rip)\n", node->res->data);
	}
    break;
  case TAC_INPUT:
	fprintf(out, "\t\t#INPUT TYPE = %d (%d)\n", node->res->dataType, node->res->type);
	
    break;
  case TAC_OUTPUT:
	fprintf(out, "\t\t#OUTPUT TYPE = %d (%d)\n", node->res->dataType, node->res->type);
	if (node->res->type == SYMBOL_VARIABLE && node->res->dataType == DATATYPE_INT) {
		fprintf(out, "\tmovq %s(%rip), %rsi\n", node->res->data);
		fprintf(out, "\tmovq $.formatint, %rdi\n");
		fprintf(out, "\tmovq $0, %rax\n");
		fprintf(out, "\tcall printf\n");
	} else if (node->res->type == LIT_STRING) {
		fprintf(out, "\tmovq $.str%d, %rsi\n", stringNum++);
		fprintf(out, "\tmovq $.formatstring, %rdi\n");
		fprintf(out, "\tmovq $0, %rax\n");
		fprintf(out, "\tcall printf\n");
	} else if (node->res->type == SYMBOL_VARIABLE && node->res->dataType == DATATYPE_REAL) {
		fprintf(out, "\tmovsd %s(%rip), %%xmm0\n", node->res->data);
		fprintf(out, "\tmovq $.formatdouble, %rdi\n");
		fprintf(out, "\tmovq $1, %rax\n");
		fprintf(out, "\tcall printf\n");
	} else if (node->res->type == SYMBOL_VARIABLE && node->res->dataType == DATATYPE_CHAR) {
		fprintf(out, "\tmovq %s(%rip), %rdi\n", node->res->data);
		fprintf(out, "\tcall putchar\n");
	} else if (node->res->type == SYMBOL_VARIABLE && node->res->dataType == DATATYPE_BOOL) { // TODO
		fprintf(out, "\tmovq %s(%rip), %rsi\n", node->res->data);
		fprintf(out, "\tmovq $.formatint, %rdi\n");
		fprintf(out, "\tmovq $0, %rax\n");
		fprintf(out, "\tcall printf\n");
	}
    break;
  case TAC_RETURN:
	fprintf(out, "\t\t#RETURN TYPE = %d (%d)\n", node->res->dataType, node->res->type);

	if (node->res->type == SYMBOL_VARIABLE || node->res->type == SYMBOL_VECTOR)
		fprintf(out, "\tmovq %s(%rip), %rax\n", node->res->data);
	else
		fprintf(out, "\tmovq $%s, %rax\n", node->res->data);

	fprintf(out, "\tpopq %rbp\n");
	fprintf(out, "\tret\n");
    break;
  case TAC_IF:
	fprintf(out, "\t\t#IF TYPE = %d (%d)\n", node->res->dataType, node->res->type);

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
	fprintf(out, "\t\t#CALL TYPE = %d (%d)\n", node->res->dataType, node->res->type);

	fprintf(out, "\tcall %s\n", node->res->data);
    break;
  case TAC_PUSHARG:
	if (node->res->type == SYMBOL_VARIABLE || node->res->type == SYMBOL_VECTOR)
		fprintf(out, "\tmovq %s(%rip), %rax\n", node->res->data);
	else
		fprintf(out, "\tmovq $%s, %rax\n", node->res->data);

	fprintf(out, "\tpush %rax\n");
    break;
  case TAC_POPARG:
	fprintf(out, "\t\t#POPARG TYPE = %d (%d)\n", node->res->dataType, node->res->type);

	fprintf(out, "\t.comm %s,8\n", node->res->data);
	fprintf(out, "\tpop %rbx\n");
	fprintf(out, "\tpop %rcx\n");
	fprintf(out, "\tpop %rax\n");
	fprintf(out, "\tmovq %rax, %s\n", node->res->data);
	fprintf(out, "\tpush %rcx\n");
	fprintf(out, "\tpush %rbx\n");
    break;
  case TAC_FUNDEC:
	
	break;
  case TAC_ENDCALL:
	fprintf(out, "\t\t#ENDCALL	 TYPE = %d (%d)\n", node->res->dataType, node->res->type);

	fprintf(out, "\tmovq %rax, %s(%rip)\n", node->res->data);
	break;
  }
}
