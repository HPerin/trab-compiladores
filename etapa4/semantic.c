#include <stdio.h>
#include "semantic.h"
#include "hash.h"
#include "ast.h"

#define TK_IDENTIFIER 2

void checkDeclarations(ast_node_t* node) {


	if (node == 0) return;

	if (node->type == FUNDEC_PARAMS || node->type == FUNDEC_NOPARAMS || node->type == VARDEC || node->type == VECDEC_NOINIT || node->type == VECDEC_INIT) {
		if(node->hash_node == NULL)
			printf("Declaration missing identifier.\n");
		else {
			if(node->hash_node->type != TK_IDENTIFIER)
				printf("Symbol %s already declared.\n", node->hash_node->data);
			else {
				switch(node->type) {
					case FUNDEC_PARAMS:
					case FUNDEC_NOPARAMS: node->hash_node->type = SYMBOL_FUNCTION; break;
					case VARDEC: node->hash_node->type = SYMBOL_VARIABLE; break;
					case VECDEC_NOINIT:
					case VECDEC_INIT: node->hash_node->type = SYMBOL_VECTOR; break;
					default: break;
				}	
			}
		}
	}

	ast_node_t* aux_son;

        if (node->son) {
        	aux_son = node->son;
           	 while (aux_son != NULL) {
               		checkDeclarations(aux_son);
                	aux_son = aux_son->next;
	   	}
	}
}
