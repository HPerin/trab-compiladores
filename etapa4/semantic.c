#include <stdio.h>
#include <stdlib.h>
#include "semantic.h"
#include "hash.h"
#include "ast.h"

#define TK_IDENTIFIER 2

bool has_semantic_errors = false;
ast_node_t* root = NULL;
void checkDeclarations(ast_node_t* node) {

	if (node == 0) return;
	if(root = NULL) root = node;

	if (node->type == FUNDEC_PARAMS || node->type == FUNDEC_NOPARAMS || node->type == VARDEC || node->type == VECDEC_NOINIT || node->type == VECDEC_INIT) {
		ast_node_t* id_node = ast_son_get(node, 1);
		if(id_node->hash_node->type != TK_IDENTIFIER) {
			printf("ERROR: '%s' previously declared.\n", id_node->hash_node->data);
			if(!has_semantic_errors) has_semantic_errors = true;
		} else {
			switch(node->type) {
				case FUNDEC_PARAMS:
				case FUNDEC_NOPARAMS: id_node->hash_node->type = SYMBOL_FUNCTION; break;
				case VARDEC: id_node->hash_node->type = SYMBOL_VARIABLE; break;
				case VECDEC_NOINIT:
				case VECDEC_INIT: id_node->hash_node->type = SYMBOL_VECTOR; break;
				default: break;
			}	
		}	
	}
	/*else { ---------- nao funcionando ainda
		if(node->type == VECTOR) {
			ast_node_t* id_node = ast_son_get(node, 0);
			if(!(ast_has(root, VECDEC_NOINIT, id_node->hash_node->data) || ast_has(root, VECDEC_INIT, id_node->hash_node->data)))
				printf("ERROR: Vector '%s' undeclared.\n", id_node->hash_node->data);


		}

		if(node->type == ID_WORD) {
			ast_node_t* id_node = ast_son_get(node, 0);
			if(!ast_has(root, VARDEC, id_node->hash_node->data))
				printf("ERROR: Variable '%s' undeclared.\n", id_node->hash_node->data);


		}

		if(node->type == FUNC_CALL) {
			ast_node_t* id_node = ast_son_get(node, 0);
			if(id_node->hash_node->type == TK_IDENTIFIER)
				printf("ERROR: Function '%s' undeclared.\n", id_node->hash_node->data);


		} 		
	


	}*/
	ast_node_t* aux_son;
	if (node->son) {
        	aux_son = node->son;
           	 while (aux_son != NULL) {
               		checkDeclarations(aux_son);
                	aux_son = aux_son->next;
	   	}
	}
}

int hasSemanticErrors() {
	if(has_semantic_errors) {
		/*printf("Failed!\n");
		printf("-----------------\n");
		exit(4);*/
		return 1;
	}
	return 0;
}

