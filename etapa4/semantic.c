#include <stdio.h>
#include <stdlib.h>
#include "semantic.h"
#include "hash.h"
#include "ast.h"

#define TK_IDENTIFIER 2

bool has_semantic_errors = false;
ast_node_t* root = NULL;

int combineTypes(int type1, int type2) {
	switch(type1) {
		case DATATYPE_INT:
			switch(type2) {
				case DATATYPE_INT:
					return DATATYPE_INT;
				case DATATYPE_CHAR:
					return DATATYPE_INT;
				case DATATYPE_REAL:
					return DATATYPE_REAL;
				case DATATYPE_BOOL:
					return DATATYPE_UNDEFINED;
					//return DATATYPE_INT;
				case DATATYPE_UNDEFINED:
					return DATATYPE_UNDEFINED;
			}
			return DATATYPE_UNDEFINED;
		case DATATYPE_CHAR:
			switch(type2) {
				case DATATYPE_INT:
					return DATATYPE_INT;
				case DATATYPE_CHAR:
					return DATATYPE_CHAR;
				case DATATYPE_REAL:
					return DATATYPE_REAL;
				case DATATYPE_BOOL:
					return DATATYPE_UNDEFINED;
					//return DATATYPE_CHAR;
				case DATATYPE_UNDEFINED:
					return DATATYPE_UNDEFINED;
			}
			return DATATYPE_UNDEFINED;
		case DATATYPE_REAL:
			switch(type2) {
				case DATATYPE_INT:
					return DATATYPE_REAL;
				case DATATYPE_CHAR:
					return DATATYPE_REAL;
				case DATATYPE_REAL:
					return DATATYPE_REAL;
				case DATATYPE_BOOL:
					return DATATYPE_UNDEFINED;
					//return DATATYPE_REAL;
				case DATATYPE_UNDEFINED:
					return DATATYPE_UNDEFINED;
			}
			return DATATYPE_UNDEFINED;
		case DATATYPE_BOOL:
			switch(type2) {
				case DATATYPE_INT:
					return DATATYPE_UNDEFINED;
					//return DATATYPE_INT;
				case DATATYPE_CHAR:
					return DATATYPE_UNDEFINED;
					//return DATATYPE_CHAR;
				case DATATYPE_REAL:
					return DATATYPE_UNDEFINED;
					//return DATATYPE_REAL;
				case DATATYPE_BOOL:
					return DATATYPE_BOOL;
				case DATATYPE_UNDEFINED:
					return DATATYPE_UNDEFINED;
			}
		 	return DATATYPE_UNDEFINED;
		case DATATYPE_UNDEFINED:
			return DATATYPE_UNDEFINED;
	}
}

int getExpType(ast_node_t * node) {
	switch(node->type) {
		case ID_WORD:
			return ast_son_get(node, 0)->hash_node->dataType;
		case VECTOR:
			if (node->hash_node->type != SYMBOL_VECTOR) has_semantic_errors = true;
			int op1 = ast_son_get(node, 0)->hash_node->dataType;
			int op2 = getExpType (ast_son_get (node, 1));
			if (op2 != DATATYPE_INT) has_semantic_errors = true;
			return op1;
		case ADD:
		case SUB:
		case MUL:
		case DIV:
		case LE:
		case GE:
		case EQ:
		case NE:
		case AND:
		case OR:
		case LESS:
		case GREATER:
			int op1 = getExpType (ast_son_get (node, 0));
			int op2 = getExpType (ast_son_get (node, 1));
			return combineTypes (op1, op2);
		case EXP:
			return ast_son_get(node, 0)->hash_node->dataType;
		case FUNC_CALL:
			if (node->hash_node->type != SYMBOL_FUNCTION) has_semantic_errors = true;
			return DATATYPE_UNDEFINED; // TODO
	}
}

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
	} else if (node->type == ATTR) {
		ast_node_t * id = ast_son_get(aux, 0);
		ast_node_t * exp = ast_son_get(aux, 1);
		int dataType = getExpType(exp);
		if (dataType == DATATYPE_UNDEFINED) has_semantic_errors = true;

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

