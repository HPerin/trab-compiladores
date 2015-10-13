//
// Created by lucas on 9/22/15.
//

#include <stdlib.h>
#include <stdio.h>
#include "ast.h"

ast_node_t *ast_node_new(int type, hash_node_t *hash_node) {
    ast_node_t * ast_node;

    ast_node = calloc(1, sizeof(ast_node_t));
    ast_node->hash_node = hash_node;
    ast_node->type = type;

    printf("ast included: %d", type);
    if(hash_node) {
        printf(" / %s", hash_node->data);
    }
    printf("\n");

    ast_node->son = NULL;
    ast_node->next = NULL;

    return ast_node;
}

void ast_node_add_son(ast_node_t *ast_node, ast_node_t *son) {
    ast_node_t * aux;

    if (son == NULL)
        return;

    if (ast_node->son == NULL) {
        ast_node->son = son;
        ast_node->son->next = NULL;
    } else {
        aux = ast_node->son;
        while(aux->next != NULL)
            aux = aux->next;

        aux->next = son;
        aux->next->next = NULL;
    }
}

void ast_print_node(ast_node_t * ast_node, int level) {
    int i;

    for(i = 0; i < level; i++)
        printf("|   ");

    printf("ITEM(");

    if (ast_node->hash_node)
        if (ast_node->hash_node->data)
            printf("%s", ast_node->hash_node->data);

    printf(", %d", ast_node->type);

    printf(")\n");
}

void ast_print_level(ast_node_t *ast_node, int level) {
    ast_node_t * aux_son;

    if (ast_node != NULL) {
        ast_print_node(ast_node, level);
        if (ast_node->son) {
            aux_son = ast_node->son;
            while (aux_son != NULL) {
                ast_print_level(aux_son, level + 1);
                aux_son = aux_son->next;
            }
        }
    }
}

void ast_print(ast_node_t * ast_node) {
    ast_print_level(ast_node, 0);
}

ast_node_t * ast_son_get(ast_node_t * ast_node, int index) {
    ast_node_t * son = ast_node->son;

    while(index > 0 && ast_node != NULL) {
        son = son->next;
      	index--;
    }

    return son;
}


void dataTypeSet(hash_node_t * hash_node, int type) {

	if(hash_node->dataType != DATATYPE_UNDEFINED) return;

	switch(type) {

		case INT: hash_node->dataType = DATATYPE_INT; break;
		case REAL: hash_node->dataType = DATATYPE_REAL; break;
		case CHAR: hash_node->dataType = DATATYPE_CHAR; break;
		case BOOL: hash_node->dataType = DATATYPE_BOOL; break;
		default: hash_node->dataType = DATATYPE_UNDEFINED; break;
	}
}
