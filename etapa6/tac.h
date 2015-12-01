#ifndef TAC_H
#define TAC_H

#include "hash.h"
#include "ast.h"

enum {
    TAC_SYMBOL,
    TAC_MOVE,
    TAC_ADD,
    TAC_SUB,
    TAC_MUL,
    TAC_DIV,
    TAC_LABEL,
    TAC_JMP,
    TAC_RET,
    TAC_EQ,
    TAC_NE,
    TAC_LE,
    TAC_GE,
    TAC_LESS,
    TAC_GREATER,
    TAC_AND,
    TAC_OR,
    TAC_VARDEC,
    TAC_VECDEC,
    TAC_TOVECMOVE,
    TAC_FROMVECMOVE,
    TAC_INPUT,
    TAC_OUTPUT,
    TAC_RETURN,
    TAC_IF,
    TAC_CALL,
    TAC_PUSHARG,
    TAC_POPARG,
    TAC_FUNDEC,
    TAC_INITVAR,
    TAC_TEMPVARDEC,
    TAC_FUNLABEL
};

typedef struct tac_node
{
	int type;
	hash_node_t *res;
	hash_node_t *op1;
	hash_node_t *op2;
	struct tac_node *prev;
	struct tac_node *next;
}tac_node_t;

tac_node_t* tacInvert(tac_node_t* node);

tac_node_t* tacGenerateInit(ast_node_t * root, hash_map_t * hash);
tac_node_t* tacGenerate(ast_node_t * node);
tac_node_t* tacCreate(int type, hash_node_t *res, hash_node_t *op1, hash_node_t* op2);
tac_node_t* tacJoin(tac_node_t* TAC1, tac_node_t* TAC2);

void tacPrintSingle(tac_node_t* TAC);
void tacPrint(tac_node_t* TAC);
tac_node_t* tacOperation(int type, tac_node_t* TAC1, tac_node_t* TAC2);

#endif
