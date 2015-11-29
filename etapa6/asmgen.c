#include "asmgen.h"

void asmgen_run(tac_node_t * node, FILE * out) {
  if (!node) return;

  switch() {
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
    break;
  case TAC_VECDEC:
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
