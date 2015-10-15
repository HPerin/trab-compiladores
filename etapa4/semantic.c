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

int getFuncType(ast_node_t * node, ast_node_t * func_id) {
  	if ((node->type == FUNDEC_PARAMS || node->type == FUNDEC_NOPARAMS) &&
	  	!strcmp(ast_son_get(node, 1)->hash_node->data, func_id->hash_node->data)) {
		int func_type = ast_son_get(node, 0)->type;
	  	switch(func_type) {
			case INT:
				return DATATYPE_INT;
			case CHAR:
				return DATATYPE_CHAR;
			case REAL:
				return DATATYPE_REAL;
			case BOOL:
				return DATATYPE_BOOL;
		}
	}


  	ast_node_t* aux_son;
	if (node->son) {
        	aux_son = node->son;
           	 while (aux_son != NULL) {
               		int result = getFuncType (aux_son, func_id);
		   	if (result != -1) return result;
                	aux_son = aux_son->next;
	   	}
	}

	return -1;
}

int getExpType(ast_node_t * node) {
	ast_node_t *son0, *son1;
	int op1, op2;
	switch(node->type) {
		case ID_WORD:
			return ast_son_get(node, 0)->hash_node->dataType;
		case VECTOR:
			/*if (node->hash_node->type != SYMBOL_VECTOR) has_semantic_errors = true; --
			op1 = ast_son_get(node, 0)->hash_node->dataType;
			op2 = getExpType (ast_son_get (node, 1));
			if (op2 != DATATYPE_INT) has_semantic_errors = true;
			return op1;*/
			return ast_son_get(node,0)->hash_node->dataType;
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
			op1 = getExpType (ast_son_get (node, 0));
			op2 = getExpType (ast_son_get (node, 1));
			return combineTypes (op1, op2);
		case EXP:
			return getExpType (ast_son_get (node, 0));
		case FUNC_CALL:
			if (ast_son_get(node, 0)->hash_node->type != SYMBOL_FUNCTION) has_semantic_errors = true;
			return getFuncType (root, ast_son_get(node, 0));
		case SYMBOL: return node->hash_node->dataType;
	}
}

int isFuncCallValid(ast_node_t *node, ast_node_t *root) {
  	ast_node_t * aux;

  	if (root->type == FUNDEC) {
		ast_node_t *son = ast_son_get(root, 0);
	  	ast_node_t * id_dec = ast_son_get(son, 1);
	  	ast_node_t * id_call = ast_son_get(node, 0);
	  	if (!strcmp(id_call->hash_node->data, id_dec->hash_node->data)) {

	  	if (son->type == FUNDEC_PARAMS) {
			ast_node_t *params_call = ast_son_get(node, 1);
			if (params_call == NULL) return false;
			ast_node_t *params_dec = ast_son_get(son, 2);

			while(params_call != NULL && params_dec != NULL) {
				int tipo = ast_son_get(params_dec, 0)->type;

				switch(tipo) {
					case INT: tipo = DATATYPE_INT; break;
					case CHAR: tipo = DATATYPE_CHAR; break;
					case REAL: tipo = DATATYPE_REAL; break;
					case BOOL: tipo = DATATYPE_BOOL; break;
					default: tipo = DATATYPE_UNDEFINED; break;
				}

				int expType = getExpType (ast_son_get(params_call, 0));
				if (combineTypes (tipo, expType) == DATATYPE_UNDEFINED)
					return false;


				params_call = ast_son_get (params_call, 1);
				params_dec = ast_son_get (params_dec, 2);
				if ((params_call == NULL || params_dec == NULL) && params_dec != params_call) return false;
				else return true;

				params_call = ast_son_get (params_call, 0);
				if (params_call == NULL) return false;
				params_dec = ast_son_get (params_dec, 0);
			}
		} else if (son->type == FUNDEC_NOPARAMS) {
			if (ast_son_get(node, 1) == NULL) return true;
			else return false;
		}

		}
	}


	ast_node_t* aux_son;
	if (root->son) {
        	aux_son = root->son;
           	 while (aux_son != NULL) {
               		if (isFuncCallValid(node, aux_son)) return true;
                	aux_son = aux_son->next;
	   	}
	}

	return false;
}

void checkDeclarations(ast_node_t* node, bool first_run) {

	if (node == 0) return;
	if(root == NULL) root = node;
	if(first_run) 
	if (node->type == FUNDEC_PARAMS || node->type == FUNDEC_NOPARAMS || node->type == VARDEC || node->type == VECDEC_NOINIT || node->type == VECDEC_INIT ||node->type == FUNC_DEC_PARAMS) {
		ast_node_t* id_node = ast_son_get(node, 1);
		if(id_node->hash_node->type != TK_IDENTIFIER) {
			printf("ERROR: '%s' previously declared.\n", id_node->hash_node->data);
			has_semantic_errors = true;
		} else {
			ast_node_t* exp_node;
			switch(node->type) {
				case FUNDEC_PARAMS:
				case FUNDEC_NOPARAMS: id_node->hash_node->type = SYMBOL_FUNCTION; break;
				case FUNC_DEC_PARAMS: id_node->hash_node->type = SYMBOL_VARIABLE; break;
				case VARDEC: 	exp_node = ast_son_get(node, 2);
						if(combineTypes(id_node->hash_node->dataType, getExpType(exp_node)) !=DATATYPE_UNDEFINED)
					     		id_node->hash_node->type = SYMBOL_VARIABLE;
					        else {
						 	printf("ERROR: Invalid initialization of '%s'.\n", id_node->hash_node->data);
						 	has_semantic_errors = true;
						} break;
				case VECDEC_NOINIT: id_node->hash_node->type = SYMBOL_VECTOR; break;
				case VECDEC_INIT:   exp_node = ast_son_get(node, 3);
						    while(exp_node != NULL) {
							if(combineTypes(id_node->hash_node->dataType, ast_son_get(exp_node,0)->hash_node->dataType) == DATATYPE_UNDEFINED) {
								printf("%d\n", getExpType(exp_node));
								printf("ERROR: Invalid initialization of '%s'.\n", id_node->hash_node->data);
								has_semantic_errors = true; break;
							}
						    	exp_node = ast_son_get(exp_node, 1);
						    }
						    id_node->hash_node->type = SYMBOL_VECTOR; break;					 				      			      
				default: break;
			}	
		}	
	}
	if(!first_run) {
	if(node->type == VECTOR) {
		ast_node_t* id_node = ast_son_get(node, 0);
		if(id_node->hash_node->dataType == DATATYPE_UNDEFINED) {
			printf("ERROR: Vector '%s' undeclared.\n", id_node->hash_node->data);
			has_semantic_errors = true;
		}
		else if(id_node->hash_node->type !=  SYMBOL_VECTOR) {
			printf("ERROR: Wrong usage of '%s'.\n", id_node->hash_node->data);
			has_semantic_errors = true;
			}
		

	}

	if(node->type == ID_WORD) { 
		ast_node_t* id_node = ast_son_get(node, 0);
		if(id_node->hash_node->dataType == DATATYPE_UNDEFINED) {
			printf("ERROR: Variable '%s' undeclared.\n", id_node->hash_node->data); 
			has_semantic_errors = true;
		}
		
        	else if(id_node->hash_node->type !=  SYMBOL_VARIABLE) {
			printf("ERROR: Wrong usage of '%s'.\n", id_node->hash_node->data);
			has_semantic_errors = true;
			}
	}

	if(node->type == FUNC_CALL) {
		ast_node_t* id_node = ast_son_get(node, 0);
		if(id_node->hash_node->dataType == DATATYPE_UNDEFINED) {
			printf("ERROR: Function '%s' undeclared.\n", id_node->hash_node->data);
			has_semantic_errors = true;
		}

        	else if(id_node->hash_node->type !=  SYMBOL_FUNCTION) {
			printf("ERROR: Wrong usage of '%s'.\n", id_node->hash_node->data);
			has_semantic_errors = true;
			}		 
	} 

	if(node->type == ATTR) {
		ast_node_t* id_node = ast_son_get(node, 0);
		ast_node_t * exp_node = ast_son_get(node, 1);
		int expType = getExpType(exp_node);
		int dataType = combineTypes(id_node->hash_node->dataType, expType);

		if(id_node->hash_node->dataType == DATATYPE_UNDEFINED) {
			printf("ERROR: Variable '%s' undeclared.\n", id_node->hash_node->data); 
			has_semantic_errors = true;
		}

		else if (dataType == DATATYPE_UNDEFINED) {
				printf("ERROR: Attribution with wrong datatypes.\n");
				has_semantic_errors = true;
			}

        	        if(id_node->hash_node->type !=  SYMBOL_VARIABLE) {
			printf("ERROR: Wrong usage of '%s'.\n", id_node->hash_node->data);
			has_semantic_errors = true;
			}
	}
	

	if(node->type == ATTR_REV) {
		ast_node_t* id_node = ast_son_get(node, 1);
		ast_node_t * exp_node = ast_son_get(node, 0);
		int expType = getExpType(exp_node);
		int dataType = combineTypes(id_node->hash_node->dataType, expType);

		
		if(id_node->hash_node->dataType == DATATYPE_UNDEFINED) {
			printf("ERROR: Variable '%s' undeclared.\n", id_node->hash_node->data); 
			has_semantic_errors = true;
		}
		else if (dataType == DATATYPE_UNDEFINED) {
		     		printf("ERROR: Reverse attribution with wrong datatypes.\n");
				has_semantic_errors = true;
			}

        	        if(id_node->hash_node->type !=  SYMBOL_VARIABLE) {
			printf("ERROR: Wrong usage of '%s'.\n", id_node->hash_node->data);
			has_semantic_errors = true;
			}
	}

	if(node->type == VEC_ATTR) { 
		ast_node_t* id_node = ast_son_get(node, 0);
		ast_node_t* index_node = ast_son_get(node, 1);
		ast_node_t* exp_node = ast_son_get(node, 2);
		int indexType = getExpType(index_node);
		int expType = getExpType(exp_node);
		int dataType = combineTypes(id_node->hash_node->dataType, expType);
		if((indexType != DATATYPE_INT && indexType != DATATYPE_CHAR)) {
			printf("Invlid vector index.\n");
			has_semantic_errors = true;
		}

		else if (dataType == DATATYPE_UNDEFINED) {
			printf("ERROR: Attribution with wrong datatypes.\n");
			has_semantic_errors = true;
		}

        	        if(id_node->hash_node->type !=  SYMBOL_VECTOR) {
			printf("ERROR: Wrong usage of '%s'.\n", id_node->hash_node->data);
			has_semantic_errors = true;
			}
		
	}

	if(node->type == VEC_ATTR_REV) { //expressao '='':' id '['expressao']' 
		ast_node_t* id_node = ast_son_get(node,1);
		ast_node_t* index_node = ast_son_get(node, 2);
		ast_node_t* exp_node = ast_son_get(node, 0);
		int indexType = getExpType(index_node);
		int expType = getExpType(exp_node);
		int dataType = combineTypes(id_node->hash_node->dataType, expType);
		if((indexType != DATATYPE_INT && indexType != DATATYPE_CHAR)) {
			printf("Invlid vector index.\n");
			has_semantic_errors = true;
		}

		else if (dataType == DATATYPE_UNDEFINED) {
			printf("ERROR: Reverse attribution with wrong datatypes.\n");
			has_semantic_errors = true;

		}
	}	

	if(node->type == INPUT) {
		ast_node_t* id_node = ast_son_get(node, 0);
		if(id_node->hash_node->dataType == DATATYPE_UNDEFINED) {
			printf("ERROR: Variable '%s' undeclared.\n", id_node->hash_node->data); 
			has_semantic_errors = true;
		}
	}

	if (node->type == FUNC_CALL) {
		if (!isFuncCallValid (node, root)) {
			printf("ERROR: invalid function call.\n");
			has_semantic_errors = true;
		}
	}	
      } 	
      
	ast_node_t* aux_son;
	if (node->son) {
        	aux_son = node->son;
           	 while (aux_son != NULL) {
               		checkDeclarations(aux_son, first_run);
                	aux_son = aux_son->next;
	   	}
	}
}    

int hasSemanticErrors() {
	if(has_semantic_errors) {
		return 1;
	}
	return 0;
}
