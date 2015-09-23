#include "generator.h"

void generate_code(FILE       *output,
                   ast_node_t *node) {
	ast_node_t * aux, * son;

	aux = node;
	if(aux != NULL) {
		//printf("[%d]", node->type);
		fflush(stdout);

		switch(aux->type) {

		case FUNDEC: // 1
			generate_code(output, ast_son_get(aux, 0)); // declaracao_funcao
			fprintf (output, ";\n");
			generate_code(output, ast_son_get(aux, 1)); // program
			break;

		case GLOBAL_VAR: // 2
			generate_code(output, ast_son_get(aux, 0)); // declaracao_variavel
			generate_code(output, ast_son_get(aux, 1)); // declaracao_variaveis_globais
			break;

		case GLOBAL_VEC: // 3
			generate_code(output, ast_son_get(aux, 0)); // declaracao_vetor
			fprintf (output, ";\n");
			generate_code(output, ast_son_get(aux, 1)); // declaracao_variaveis_globais
			break;

		case VARDEC: // 4
			generate_code(output, ast_son_get(aux, 0)); // tipo
			fprintf(output, " ");
			generate_code(output, ast_son_get(aux, 1)); // id
			fprintf(output, ":");
			generate_code(output, ast_son_get(aux, 2)); // literal
			fprintf(output, ";\n");
			break;

		case VECDEC_NOINIT: // 5
			generate_code(output, ast_son_get(aux, 0)); // tipo
			fprintf (output, " ");
			generate_code(output, ast_son_get(aux, 1)); // id
			fprintf (output, "[");
			generate_code(output, ast_son_get(aux, 2)); // tamanho
			fprintf (output, "]");
			break;

		case VECDEC_INIT: // 6
			generate_code(output, ast_son_get(aux, 0)); // tipo
			fprintf (output, " ");
			generate_code(output, ast_son_get(aux, 1)); // id
			fprintf (output, "[");
			generate_code(output, ast_son_get(aux, 2)); // tamanho
			fprintf (output, "] : ");
			generate_code(output, ast_son_get(aux, 3)); // inicializacao_vetor
			break;

		case VECINIT: // 7
			generate_code(output, ast_son_get(aux, 0)); // literal
			fprintf (output, " ");
			generate_code(output, ast_son_get(aux, 1)); // inicializacao_vetor
			break;

		case FUNDEC_PARAMS: // 8
			//printf("/*FUNDEC_PARAMS*/");
			generate_code (output, ast_son_get(aux, 0)); // tipo
			fprintf(output, " ");
			generate_code (output, ast_son_get(aux, 1)); // id
			fprintf (output, "( ");
			generate_code (output, ast_son_get(aux, 2)); // parametros
			fprintf (output, " )\n");
			generate_code (output, ast_son_get(aux, 3)); // variaveis_locais
			generate_code (output, ast_son_get(aux, 4)); // comando
			break;

		case FUNDEC_NOPARAMS: // 9
			generate_code (output, ast_son_get(aux, 0)); // tipo
			fprintf(output, " ");
			generate_code (output, ast_son_get(aux, 1)); // id
			fprintf (output, "( ");
			fprintf (output, " )\n");
			generate_code (output, ast_son_get(aux, 2)); // variaveis_locais
			generate_code (output, ast_son_get(aux, 3)); // comando
			break;

		case LOCAL_VAR: // 10
			generate_code (output, ast_son_get(aux, 0)); // declaracao_variavel
			generate_code (output, ast_son_get(aux, 1)); // variaveis_locais
			break;

		case INT: // 11
			//printf("/*INT*/");
			fprintf(output, "int");
			break;

		case CHAR: // 12
			//printf("/*CHAR*/");
			fprintf(output, "char");
			break;

		case REAL: // 13
			//printf("/*REAL*/");
			fprintf(output, "real");
			break;

		case BOOL: // 14
			fprintf(output, "bool");
			break;

		case SYMBOL: // 15
			if (!aux->hash_node)
				fprintf(output, "[error-node]");
			else if (!aux->hash_node->data)
				fprintf(output, "[error-data]");
			else
				fprintf(output, "%s", aux->hash_node->data);
			break;

		case BLOCK: // 16
			fprintf (output, "{\n");
			generate_code (output, ast_son_get(aux, 0)); // lista_comandos
			fprintf (output, "}");
			break;

		case CMDLIST: // 17
			generate_code (output, ast_son_get(aux, 0)); // comando
			if (ast_son_get(aux, 0)) {
				if (ast_son_get(aux, 0)->type != CMDLIST) {
					fprintf (output, ";\n");
					generate_code (output, ast_son_get(aux, 1)); // lista_comandos
				}
			}
			break;

		case ATTR: // 18
			generate_code (output, ast_son_get(aux, 0)); // id
			fprintf (output, " := ");
			generate_code (output, ast_son_get(aux, 1)); // expressao
			break;

		case ATTR_REV: // 19
			generate_code (output, ast_son_get(aux, 0)); // expressao
			fprintf (output, " =: ");
			generate_code (output, ast_son_get(aux, 1)); // id
			break;

		case VEC_ATTR: // 20
			generate_code (output, ast_son_get(aux, 0)); // id
			fprintf (output, "[");
			generate_code (output, ast_son_get(aux, 1)); // expressao
			fprintf (output, "] := ");
			generate_code (output, ast_son_get(aux, 2)); // expressao
			break;

		case VEC_ATTR_REV: // 21
			generate_code (output, ast_son_get(aux, 0)); // expressao
			fprintf (output, " =: ");
			generate_code (output, ast_son_get(aux, 1)); // id
			fprintf (output, "[");
			generate_code (output, ast_son_get(aux, 2)); // expressao
			fprintf (output, "]");
			break;

		case INPUT: // 22
			fprintf (output, "input ");
			generate_code (output, ast_son_get(aux, 0)); // id
			break;

		case OUTPUT: // 23
			fprintf (output, "output ");
			generate_code (output, ast_son_get(aux, 0)); // id
			break;

		case RETURN: // 24
			fprintf (output, "return ");
			generate_code (output, ast_son_get(aux, 0)); // id
			break;

		case IF: // 25
			fprintf (output, "if (");
			generate_code (output, ast_son_get(aux, 0)); // expressao
			fprintf (output, ")");
			generate_code (output, ast_son_get(aux, 1)); // comando
			break;

		case IF_ELSE: // 26
			fprintf (output, "if (");
			generate_code (output, ast_son_get(aux, 0)); // expressao
			fprintf (output, ")\n");
			generate_code (output, ast_son_get(aux, 1)); // comando
			fprintf (output, "else\n");
			generate_code (output, ast_son_get(aux, 2)); // comando
			break;

		case IF_LOOP: // 27
			fprintf (output, "if (");
			generate_code (output, ast_son_get(aux, 0)); // expressao
			fprintf (output, ")\n");
			generate_code (output, ast_son_get(aux, 1)); // comando
			fprintf (output, "loop");
			break;

		case FUNC_DEC_PARAMS: // 28
			generate_code (output, ast_son_get(aux, 0)); // tipo
			fprintf(output, " ");
			generate_code (output, ast_son_get(aux, 1)); // id
			generate_code (output, ast_son_get(aux, 2)); // resto_parametros
			break;

		case OUTPUT_LIST: // 29
			generate_code (output, ast_son_get(aux, 0)); // expressao
			generate_code (output, ast_son_get(aux, 1)); // resto_output
			break;

		case VECTOR: // 30
			generate_code (output, ast_son_get(aux, 0)); // id
			fprintf (output, "[");
			generate_code (output, ast_son_get(aux, 1)); // expressao
			fprintf (output, "]");
			break;

		case ADD: // 31
			generate_code (output, ast_son_get(aux, 0)); // expressao
			fprintf (output, " + ");
			generate_code (output, ast_son_get(aux, 1)); // expressao
			break;

		case SUB: // 32
			generate_code (output, ast_son_get(aux, 0)); // expressao
			fprintf (output, " - ");
			generate_code (output, ast_son_get(aux, 1)); // expressao
			break;

		case MUL: // 33
			generate_code (output, ast_son_get(aux, 0)); // expressao
			fprintf (output, " * ");
			generate_code (output, ast_son_get(aux, 1)); // expressao
			break;

		case DIV: // 34
			generate_code (output, ast_son_get(aux, 0)); // expressao
			fprintf (output, " / ");
			generate_code (output, ast_son_get(aux, 1)); // expressao
			break;

		case LE: // 35
			generate_code (output, ast_son_get(aux, 0)); // expressao
			fprintf (output, " <= ");
			generate_code (output, ast_son_get(aux, 1)); // expressao
			break;

		case GE: // 36
			generate_code (output, ast_son_get(aux, 0)); // expressao
			fprintf (output, " >= ");
			generate_code (output, ast_son_get(aux, 1)); // expressao
			break;

		case EQ: // 37
			generate_code (output, ast_son_get(aux, 0)); // expressao
			fprintf (output, " == ");
			generate_code (output, ast_son_get(aux, 1)); // expressao
			break;

		case NE: // 38
			generate_code (output, ast_son_get(aux, 0)); // expressao
			fprintf (output, " != ");
			generate_code (output, ast_son_get(aux, 1)); // expressao
			break;

		case AND: // 39
			generate_code (output, ast_son_get(aux, 0)); // expressao
			fprintf (output, " && ");
			generate_code (output, ast_son_get(aux, 1)); // expressao
			break;

		case OR: // 40
			generate_code (output, ast_son_get(aux, 0)); // expressao
			fprintf (output, " || ");
			generate_code (output, ast_son_get(aux, 1)); // expressao
			break;

		case LESS: // 41
			generate_code (output, ast_son_get(aux, 0)); // expressao
			fprintf (output, " < ");
			generate_code (output, ast_son_get(aux, 1)); // expressao
			break;

		case GREATER: // 42
			generate_code (output, ast_son_get(aux, 0)); // expressao
			fprintf (output, " > ");
			generate_code (output, ast_son_get(aux, 1)); // expressao
			break;

		case EXP: // 43
			fprintf(output, "(");
			generate_code (output, ast_son_get(aux, 0)); // expressao
			fprintf (output, ")");
			break;

		case FUNC_CALL: // 44
			generate_code (output, ast_son_get(aux, 0)); // id
			fprintf (output, " (");
			generate_code (output, ast_son_get(aux, 1)); // parametros_passados
			fprintf(output, ")");
			break;

		case FUNC_CALL_PARAMS: // 45
			generate_code (output, ast_son_get(aux, 0)); // expressao
			generate_code (output, ast_son_get(aux, 1)); // resto_parametros_passados
			break;

		case ID_WORD: // 46
			generate_code (output, ast_son_get (aux, 0));
			break;

		case FUNC_CALL_PARAMS_REST: // 47
			fprintf(output, ", ");
			generate_code (output, ast_son_get (aux, 0));
			break;

		case OUTPUT_LIST_REST:
			fprintf(output, ",");
			generate_code (output, ast_son_get (aux, 0));
			break;

		case FUNC_DEC_PARAMS_REST:
			fprintf(output, ", ");
			generate_code(output, ast_son_get(aux, 0));

		default:
			break;
		}
	}
}
