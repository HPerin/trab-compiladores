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

    ast_node->son = NULL;
    ast_node->next = NULL;

    return ast_node;
}

void ast_node_add_son(ast_node_t *ast_node, ast_node_t *son) {
    ast_node_t * aux;

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
        printf(" ");

    if (ast_node->hash_node)
        if (ast_node->hash_node->data)
            printf("%s\n", ast_node->hash_node->data);
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
