
#include <stdio.h>
#include <stdlib.h>
#include "tac.h"


tac_node_t* tacCreate(int type, hash_node_t *res, hash_node_t *op1, hash_node_t* op2) {

	tac_note_t* newTAC = 0;
	newTAC = (tac_node_t*) calloc(1,sizeof(tac_node_t*);

	newTAC->type = type;
	newTAC->op1 = op1;
	newTAC->op2 = op2;
	newTAC->prev = 0;

	return newTAC;
}


tac_node_t* tacJoin(tac_node_t* TAC1, tac_node_t* TAC2){

	tac_node_t* aux;
	
	if(TAC1 == 0)return TAC2;
	if(TAC2 == 0)return TAC1;

	for(aux=TAC2; aux->prev!=0; aux=aux->prev);

	aux->prev = TAC1;
	
	return TAC2;
}

