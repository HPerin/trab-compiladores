

#include "hash.h"
#include "ast.h"


typedef struct tac_node
{
	int type;
	hash_note_t *res;
	hash_note_t *op1;
	hash_note_t *op2;
	struct tac_node *prev
}tac_note_t

tac_note_t* tacCreate(int type, hash_node_t *res, hash_note_t *op1, hash_note_t* op2)
tac_note_t* tacJoin(tac_node_t* TAC1, tac_node_t* TAC2);
