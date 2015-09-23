#include "generator.h"

void generate_code(FILE       *output,
                   ast_node_t *node) {
	ast_node_t * aux, * son;

	aux = node;
	while(aux != NULL) {
		switch(aux->type) {

		case FUNDEC:
			//printf("/*FUNDEC*/");
			generate_code(output, ast_son_get(aux, 0)); // declaracao_funcao
			fprintf (output, ";\n");
			break;

		case GLOBAL_VAR:
			break;

		case GLOBAL_VEC:
			break;

		case VARDEC:
			break;

		case VECDEC_NOINIT:
			break;

		case VECDEC_INIT:
			break;

		case VECINIT:
			break;

		case FUNDEC_PARAMS:
			//printf("/*FUNDEC_PARAMS*/");
			generate_code (output, ast_son_get(aux, 0));
			generate_code (output, ast_son_get(aux, 1));
			fprintf (output, "( ");
			generate_code (output, ast_son_get(aux, 2));
			fprintf (output, " )");
			break;

		case FUNDEC_NOPARAMS:
			break;

		case LOCAL_VAR:
			break;

		case INT:
			//printf("/*INT*/");
			fprintf(output, "int ");
			break;

		case CHAR:
			//printf("/*CHAR*/");
			fprintf(output, "char ");
			break;

		case REAL:
			//printf("/*REAL*/");
			fprintf(output, "real ");
			break;

		case BOOL:
			fprintf(output, "bool ");
			break;

		case SYMBOL:
			fprintf(output, "%s ", aux->hash_node->data);
			break;

		case BLOCK:
			break;

		case CMDLIST:
			break;

		case ATTR:
			break;

		case ATTR_REV:
			break;

		case VEC_ATTR:
			break;

		case VEC_ATTR_REV:
			break;

		case INPUT:
			break;

		case OUTPUT:
			break;

		case RETURN:
			break;

		case IF:
			break;

		case IF_ELSE:
			break;

		case IF_LOOP:
			break;

		case FUNC_DEC_PARAMS:
			generate_code (output, ast_son_get(aux, 0)); // tipo
			generate_code (output, ast_son_get(aux, 1)); // id
			break;

		case OUTPUT_LIST:
			break;

		case VECTOR:
			break;

		case ADD:
			break;

		case SUB:
			break;

		case MUL:
			break;

		case DIV:
			break;

		case LE:
			break;

		case GE:
			break;

		case EQ:
			break;

		case NE:
			break;

		case AND:
			break;

		case OR:
			break;

		case LESS:
			break;

		case GREATER:
			break;

		case EXP:
			break;

		case FUNC_CALL:
			break;

		case FUNC_CALL_PARAMS:
			break;

		default:
			break;
		}

		aux = aux->next;
	}
}
