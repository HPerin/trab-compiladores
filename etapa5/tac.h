

#include "hash.h"
#include "ast.h"


typedef struct tac_node
{
	int type;
	hash_node_t *res;
	hash_node_t *op1;
	hash_node_t *op2;
	struct tac_node *prev
}tac_node_t

tac_node_t* tacCreate(int type, hash_node_t *res, hash_node_t *op1, hash_node_t* op2);
tac_node_t* tacJoin(tac_node_t* TAC1, tac_node_t* TAC2);
