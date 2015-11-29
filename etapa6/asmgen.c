#include "asmgen.h"

void asmgen_gennode(tac_node_t * node, FILE * out);

void asmgen_run(tac_node_t * root, FILE * out) {
	tac_node_t * node = root;
	while(node != NULL) {
		asmgen_gennode(node, out);
		node = node->prev;
	}
}

void asmgen_gennode(tac_node_t * node, FILE * out) {
  if (!node) return;

  switch(node->type) {
  case TAC_SYMBOL:
    break;
  case TAC_MOVE:
	
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
	switch(node->res->dataType) {
	case DATATYPE_INT:
		fprintf(out, "	.comm %s,4\n", node->res->data);
		break;
	case DATATYPE_CHAR:
		fprintf(out, "	.comm %s,1\n", node->res->data);
		break;
	case DATATYPE_REAL:
		fprintf(out, "	.comm %s,4\n", node->res->data);
		break;
	case DATATYPE_BOOL:
		fprintf(out, "	.comm %s,1\n", node->res->data);
		break;
	}
    break;
  case TAC_VECDEC:
	switch(node->res->dataType) {
	case DATATYPE_INT:
		fprintf(out, "	.comm %s,%d\n", node->res->data, atoi(node->op1->data) * 4);
		break;
	case DATATYPE_CHAR:
		fprintf(out, "	.comm %s,%d\n", node->res->data, atoi(node->op1->data));
		break;
	case DATATYPE_REAL:
		fprintf(out, "	.comm %s,%d\n", node->res->data, atoi(node->op1->data) * 4);
		break;
	case DATATYPE_BOOL:
		fprintf(out, "	.comm %s,%d\n", node->res->data, atoi(node->op1->data));
		break;
	}
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
