//
// Created by lucas on 9/22/15.
//

#ifndef AST_TREE_AST_H
#define AST_TREE_AST_H

#include "hash.h"

typedef struct s_ast_node {
    int type;
    hash_node_t * hash_node;

    struct s_ast_node * son;
    struct s_ast_node * next;
} ast_node_t;

ast_node_t * ast_node_new(int type, hash_node_t * hash_node);
void ast_node_add_son(ast_node_t * ast_node, ast_node_t * son);
void ast_print(ast_node_t * ast_node);

#endif //AST_TREE_AST_H
