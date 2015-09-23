//
// Created by lucas on 9/22/15.
//

#ifndef AST_TREE_AST_H
#define AST_TREE_AST_H

#include "hash.h"


#define FUNDEC 			1
#define GLOBAL_VAR 		2
#define GLOBAL_VEC 		3
#define VARDEC 			4
#define VECDEC_NOINIT		5
#define VECDEC_INIT	        6
#define VECINIT		        7
#define FUNDEC_PARAMS 		8
#define FUNDEC_NOPARAMS	        9
#define LOCAL_VAR 		10
#define INT 			11
#define CHAR 			12
#define REAL 			13
#define BOOL 			14
#define SYMBOL		        15
#define BLOCK 			16
#define CMDLIST		        17
#define ATTR 			18
#define ATTR_REV 		19
#define VEC_ATTR 		20
#define VEC_ATTR_REV 		21
#define INPUT 			22
#define OUTPUT 			23
#define RETURN 			24
#define IF 			25
#define IF_ELSE 		26
#define IF_LOOP 		27
#define FUNC_DEC_PARAMS 	28
#define OUTPUT_LIST	        29
#define VECTOR 			30
#define ADD 			31
#define SUB 			32
#define MUL 			33
#define DIV 			34
#define LE 			35
#define GE 			36
#define EQ 			37
#define NE 			38
#define AND 			39
#define OR 			40
#define LESS 			41
#define GREATER 		42
#define EXP 			43
#define FUNC_CALL 		44
#define FUNC_CALL_PARAMS 	45
#define ID_WORD			46

#define FUNC_CALL_PARAMS_REST	47
#define OUTPUT_LIST_REST	48
#define FUNC_DEC_PARAMS_REST	49



typedef struct s_ast_node {
    int type;
    hash_node_t * hash_node;

    struct s_ast_node * son;
    struct s_ast_node * next;
} ast_node_t;

ast_node_t * ast_node_new(int type, hash_node_t * hash_node);
void ast_node_add_son(ast_node_t * ast_node, ast_node_t * son);
void ast_print(ast_node_t * ast_node);
ast_node_t * ast_son_get(ast_node_t * ast_node, int index);

#endif //AST_TREE_AST_H
