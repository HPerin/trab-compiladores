
#include <stdio.h>
#include <stdlib.h>
#include "tac.h"
#include "ast.h"

static hash_map_t * hash = NULL;

tac_node_t* tacGenerateInit(ast_node_t * node, hash_map_t * hash_map) {
    hash = hash_map;
    return tacGenerate(node);
}

tac_node_t* tacGenerate(ast_node_t *aux) {
    tac_node_t * tac_aux1;
    tac_node_t * tac_aux2;
    hash_node_t * hash_aux1;
    hash_node_t * hash_aux2;
    hash_node_t * hash_aux3;

    if (aux) {
		switch(aux->type) {

		case FUNDEC: // 1
            return tacJoin(
                    tacGenerate(
                        ast_son_get(aux, 0)),
                    tacGenerate(
                        ast_son_get(aux, 1)));
            //generate_code(output, ast_son_get(aux, 0)); // declaracao_funcao
			//fprintf (output, ";\n");
			//generate_code(output, ast_son_get(aux, 1)); // program
			break;

		case GLOBAL_VAR: // 2
            return tacJoin(
                    tacGenerate(
                        ast_son_get(aux, 0)),
                    tacGenerate(
                        ast_son_get(aux, 1)));
			//generate_code(output, ast_son_get(aux, 0)); // declaracao_variavel
			//generate_code(output, ast_son_get(aux, 1)); // declaracao_variaveis_globais
			break;

		case GLOBAL_VEC: // 3
            return tacJoin(
                    tacGenerate(
                        ast_son_get(aux, 0)),
                    tacGenerate(
                        ast_son_get(aux, 1)));
			//generate_code(output, ast_son_get(aux, 0)); // declaracao_vetor
			//fprintf (output, ";\n");
			//generate_code(output, ast_son_get(aux, 1)); // declaracao_variaveis_globais
			break;

		case VARDEC: // 4
            return tacJoin(
                    tacCreate(
                        TAC_VARDEC,
                        ast_son_get(aux, 1)->hash_node,
                        0,
                        0),
                    tacCreate(
                        TAC_MOVE,
                        ast_son_get(aux, 1)->hash_node,
                        ast_son_get(aux, 2)->hash_node,
                        0));
			//generate_code(output, ast_son_get(aux, 0)); // tipo
			//fprintf(output, " ");
			//generate_code(output, ast_son_get(aux, 1)); // id
			//fprintf(output, ":");
			//generate_code(output, ast_son_get(aux, 2)); // literal
			//fprintf(output, ";\n");
			break;

		case VECDEC_NOINIT: // 5
            return tacCreate(
                        TAC_VECDEC,
                        ast_son_get(aux, 1)->hash_node,
                        0,
                        0);
			//generate_code(output, ast_son_get(aux, 0)); // tipo
			//fprintf (output, " ");
			//generate_code(output, ast_son_get(aux, 1)); // id
			//fprintf (output, "[");
			//generate_code(output, ast_son_get(aux, 2)); // tamanho
			//fprintf (output, "]");
			break;

		case VECDEC_INIT: // 6
            return tacJoin(
                    tacCreate(
                        TAC_VECDEC,
                        ast_son_get(aux, 1)->hash_node,
                        0,
                        0),
                    tacCreate(
                        TAC_MOVE,
                        ast_son_get(aux, 1)->hash_node,
                        0,
                        0)); // TODO
			//generate_code(output, ast_son_get(aux, 0)); // tipo
			//fprintf (output, " ");
			//generate_code(output, ast_son_get(aux, 1)); // id
			//fprintf (output, "[");
			//generate_code(output, ast_son_get(aux, 2)); // tamanho
			//fprintf (output, "] : ");
			//generate_code(output, ast_son_get(aux, 3)); // inicializacao_vetor
			break;

		case VECINIT: // 7
			//generate_code(output, ast_son_get(aux, 0)); // literal
			//fprintf (output, " ");
			//generate_code(output, ast_son_get(aux, 1)); // inicializacao_vetor
			break;

		case FUNDEC_PARAMS: // 8
            return tacJoin(
                    tacCreate(TAC_LABEL,
                        ast_son_get(aux, 1)->hash_node,
                        0,
                        0),
                    tacJoin(
                        tacGenerate(ast_son_get(aux, 3)),
                        tacJoin(
                            tacGenerate(ast_son_get(aux, 4)),
                            tacCreate(TAC_RET, 0, 0, 0))));
			//generate_code (output, ast_son_get(aux, 0)); // tipo
			//fprintf(outpu), " ");
			//generate_code (output, ast_son_get(aux, 1)); // id
			//fprintf (output, "( ");
			//generate_code (output, ast_son_get(aux, 2)); // parametros
			//fprintf (output, " )\n");
			//generate_code (output, ast_son_get(aux, 3)); // variaveis_locais
			//generate_code (output, ast_son_get(aux, 4)); // comando
			break;

		case FUNDEC_NOPARAMS: // 9
            return tacJoin(
                    tacCreate(TAC_LABEL,
                        ast_son_get(aux, 1)->hash_node,
                        0,
                        0),
                    tacJoin(
                        tacGenerate(ast_son_get(aux, 2)),
                        tacJoin(
                            tacGenerate(ast_son_get(aux, 3)),
                            tacCreate(TAC_RET, 0, 0, 0))));
			//generate_code (output, ast_son_get(aux, 0)); // tipo
			//fprintf(output, " ");
			//generate_code (output, ast_son_get(aux, 1)); // id
			//fprintf (output, "( ");
			//fprintf (output, " )\n");
			//generate_code (output, ast_son_get(aux, 2)); // variaveis_locais
			//generate_code (output, ast_son_get(aux, 3)); // comando
			break;

		case LOCAL_VAR: // 10
            return tacJoin(
                    tacGenerate(ast_son_get(aux, 0)),
                    tacGenerate(ast_son_get(aux, 1)));
			//generate_code (output, ast_son_get(aux, 0)); // declaracao_variavel
			//generate_code (output, ast_son_get(aux, 1)); // variaveis_locais
			break;

		case INT: // 11
			fprintf(stderr, "---------- ERROR! - %3d ----------\n", aux->type);
            return 0;
            //fprintf(output, "int");
			break;

		case CHAR: // 12
	        fprintf(stderr, "---------- ERROR! - %3d ----------\n", aux->type);
            return 0;
            //fprintf(output, "char");
			break;

		case REAL: // 13
            fprintf(stderr, "---------- ERROR! - %3d ----------\n", aux->type);
            return 0;
            //fprintf(output, "real");
			break;

		case BOOL: // 14
            fprintf(stderr, "---------- ERROR! - %3d ----------\n", aux->type);
            return 0;
			//fprintf(output, "bool");
			break;

		case SYMBOL: // 15
            return tacCreate(TAC_MOVE, hash_map_maketemp(hash), aux->hash_node, 0);
			//if (!aux->hash_node)
			//	fprintf(output, "[error-node]");
			//else if (!aux->hash_node->data)
			//	fprintf(output, "[error-data]");
			//else
			//	fprintf(output, "%s", aux->hash_node->data);
			break;

		case BLOCK: // 16
            return tacGenerate(
                    ast_son_get(aux, 0));
			//fprintf (output, "{\n");
			//generate_code (output, ast_son_get(aux, 0)); // lista_comandos
			//fprintf (output, "}");
			break;

		case CMDLIST: // 17
            return tacJoin(
                    tacGenerate(
                        ast_son_get(aux, 0)),
                    tacGenerate(
                        ast_son_get(aux, 1)));
			//generate_code (output, ast_son_get(aux, 0)); // comando
			//if (ast_son_get(aux, 0)) {
			//	if (ast_son_get(aux, 0)->type != CMDLIST) {
			//		fprintf (output, ";\n");
			//		generate_code (output, ast_son_get(aux, 1)); // lista_comandos
			//	}
			//}
			break;

		case ATTR: // 18
            tac_aux1 = tacGenerate(ast_son_get(aux, 1));

            if (!tac_aux1) return NULL;

            return tacJoin(
                    tac_aux1,
                    tacCreate(
                        TAC_MOVE,
                        ast_son_get(aux, 0)->hash_node,
                        tac_aux1->res,
                        0));
			//generate_code (output, ast_son_get(aux, 0)); // id
			//fprintf (output, " := ");
			//generate_code (output, ast_son_get(aux, 1)); // expressao
			break;

		case ATTR_REV: // 19
            tac_aux1 = tacGenerate(ast_son_get(aux, 0));

            return tacJoin(
                    tac_aux1,
                    tacCreate(
                        TAC_MOVE,
                        ast_son_get(aux, 1)->hash_node,
                        tac_aux1->res,
                        0));
			//generate_code (output, ast_son_get(aux, 0)); // expressao
			//fprintf (output, " =: ");
			//generate_code (output, ast_son_get(aux, 1)); // id
			break;

		case VEC_ATTR: // 20
            tac_aux1 = tacGenerate(ast_son_get(aux, 1));
            tac_aux2 = tacGenerate(ast_son_get(aux, 2));

            return tacJoin(
                    tacJoin(
                        tac_aux1,
                        tac_aux2),
                    tacCreate(
                        TAC_TOVECMOVE,
                        ast_son_get(aux, 0)->hash_node,
                        tac_aux1->res,
                        tac_aux2->res));
			//generate_code (output, ast_son_get(aux, 0)); // id
			//fprintf (output, "[");
			//generate_code (output, ast_son_get(aux, 1)); // expressao
			//fprintf (output, "] := ");
			//generate_code (output, ast_son_get(aux, 2)); // expressao
			break;

		case VEC_ATTR_REV: // 21
            tac_aux1 = tacGenerate(ast_son_get(aux, 0));
            tac_aux2 = tacGenerate(ast_son_get(aux, 2));

            return tacJoin(
                tacJoin(
                    tac_aux1,
                    tac_aux2),
                tacCreate(
                    TAC_TOVECMOVE,
                    ast_son_get(aux, 1)->hash_node,
                    tac_aux2->res,
                    tac_aux1->res));
			//generate_code (output, ast_son_get(aux, 0)); // expressao
			//fprintf (output, " =: ");))
			//generate_code (output, ast_son_get(aux, 1)); // id
			//fprintf (output, "[");
			//generate_code (output, ast_son_get(aux, 2)); // expressao
			//fprintf (output, "]");
			break;

		case INPUT: // 22

            return tacCreate(TAC_INPUT,
                    ast_son_get(aux, 0)->hash_node,
                    0,
                    0);
			//fprintf (output, "input ");
			//generate_code (output, ast_son_get(aux, 0)); // id
			break;

		case OUTPUT: // 23

            return tacCreate(TAC_OUTPUT,
                    ast_son_get(aux, 0)->hash_node,
                    0,
                    0); // TODO
			//fprintf (output, "output ");
			//generate_code (output, ast_son_get(aux, 0)); // id
			break;

		case RETURN: // 24

            return tacCreate(TAC_RETURN,
                    ast_son_get(aux, 0)->hash_node,
                    0,
                    0);
			//fprintf (output, "return ");
			//generate_code (output, ast_son_get(aux, 0)); // id
			break;

		case IF: // 25
            hash_aux1 = hash_map_makelabel(hash); // label inicio
            hash_aux2 = hash_map_makelabel(hash); // label fim

            tac_aux1 = tacGenerate(ast_son_get(aux, 0));

            return tacJoin(
                    tac_aux1,
                    tacJoin(
                        tacJoin(
                            tacCreate(TAC_IF, tac_aux1->res, hash_aux1, hash_aux2),
                            tacCreate(TAC_LABEL, hash_aux1, 0, 0)),
                        tacJoin(
                            tacGenerate(ast_son_get(aux, 1)),
                            tacCreate(TAC_LABEL, hash_aux2, 0, 0))));

			//fprintf (output, "if (");
			//generate_code (output, ast_son_get(aux, 0)); // expressao
			//fprintf (output, ")");
			//generate_code (output, ast_son_get(aux, 1)); // comando
			break;

		case IF_ELSE: // 26
            hash_aux1 = hash_map_makelabel(hash); // if
            hash_aux2 = hash_map_makelabel(hash); // else

            tac_aux1 = tacGenerate(ast_son_get(aux, 0));

            return tacJoin(
                    tac_aux1,
                    tacJoin(
                        tacJoin(
                            tacCreate(TAC_IF, tac_aux1->res, hash_aux1, hash_aux2),
                            tacCreate(TAC_LABEL, hash_aux1, 0, 0)),
                        tacJoin(
                            tacGenerate(ast_son_get(aux, 1)),
                            tacJoin(
                                tacCreate(TAC_LABEL, hash_aux2, 0, 0),
                                tacGenerate(ast_son_get(aux, 2))))));

			//fprintf (output, "if (");
			//generate_code (output, ast_son_get(aux, 0)); // expressao
			//fprintf (output, ")\n");
			//generate_code (output, ast_son_get(aux, 1)); // comando
			//fprintf (output, "else\n");
			//generate_code (output, ast_son_get(aux, 2)); // comando
			break;

		case IF_LOOP: // 27
            hash_aux1 = hash_map_makelabel(hash); // if
            hash_aux2 = hash_map_makelabel(hash); // inicio
            hash_aux3 = hash_map_makelabel(hash); // fim

            tac_aux1 = tacGenerate(ast_son_get(aux, 0));

            return tacJoin(
                    tacCreate(TAC_LABEL, hash_aux1, 0, 0),
                    tacJoin(
                        tac_aux1,
                        tacJoin(
                            tacCreate(TAC_IF, tac_aux1->res, hash_aux2, hash_aux3),
                            tacJoin(
                                tacCreate(TAC_LABEL, hash_aux2, 0, 0),
                                tacJoin(
                                    tacGenerate(ast_son_get(aux, 1)),
                                    tacJoin(
                                        tacCreate(TAC_JMP, hash_aux1, 0, 0),
                                        tacCreate(TAC_LABEL, hash_aux3, 0, 0)))))));

			//fprintf (output, "if (");
			//generate_code (output, ast_son_get(aux, 0)); // expressao
			//fprintf (output, ")\n");
			//generate_code (output, ast_son_get(aux, 1)); // comando
			//fprintf (output, "loop");
			break;

		case FUNC_DEC_PARAMS: // 28
			//generate_code (output, ast_son_get(aux, 0)); // tipo
			//fprintf(output, " ");
			//generate_code (output, ast_son_get(aux, 1)); // id
			//generate_code (output, ast_son_get(aux, 2)); // resto_parametros
			break;

		case OUTPUT_LIST: // 29
			//generate_code (output, ast_son_get(aux, 0)); // expressao
			//generate_code (output, ast_son_get(aux, 1)); // resto_output
			break;

		case VECTOR: // 30
            tac_aux1 = tacGenerate(ast_son_get(aux, 1));
            hash_aux1 = hash_map_maketemp(hash);

            return tacJoin(
                    tac_aux1,
                    tacCreate(TAC_FROMVECMOVE, hash_aux1, ast_son_get(aux, 0)->hash_node, tac_aux1->res));
			//generate_code (output, ast_son_get(aux, 0)); // id
			//fprintf (output, "[");
			//generate_code (output, ast_son_get(aux, 1)); // expressao
			//fprintf (output, "]");
			break;

		case ADD: // 31
			tac_aux1 = tacGenerate(ast_son_get(aux, 0));
			tac_aux2 = tacGenerate(ast_son_get(aux, 1));
			return tacOperation(TAC_ADD, tac_aux1, tac_aux2);
			//generate_code (output, ast_son_get(aux, 0)); // expressao
			//fprintf (output, " + ");
			//generate_code (output, ast_son_get(aux, 1)); // expressao
			break;

		case SUB: // 32
			tac_aux1 = tacGenerate(ast_son_get(aux, 0));
			tac_aux2 = tacGenerate(ast_son_get(aux, 1));
			return tacOperation(TAC_SUB, tac_aux1, tac_aux2);
			//generate_code (output, ast_son_get(aux, 0)); // expressao
			//fprintf (output, " - ");
			//generate_code (output, ast_son_get(aux, 1)); // expressao
			break;

		case MUL: // 33
			tac_aux1 = tacGenerate(ast_son_get(aux, 0));
			tac_aux2 = tacGenerate(ast_son_get(aux, 1));
			return tacOperation(TAC_MUL, tac_aux1, tac_aux2);
			//generate_code (output, ast_son_get(aux, 0)); // expressao
			//fprintf (output, " * ");
			//generate_code (output, ast_son_get(aux, 1)); // expressao
			break;

		case DIV: // 34
			tac_aux1 = tacGenerate(ast_son_get(aux, 0));
			tac_aux2 = tacGenerate(ast_son_get(aux, 1));
			return tacOperation(TAC_DIV, tac_aux1, tac_aux2);
			//generate_code (output, ast_son_get(aux, 0)); // expressao
			//fprintf (output, " / ");
			//generate_code (output, ast_son_get(aux, 1)); // expressao
			break;

		case LE: // 35
			tac_aux1 = tacGenerate(ast_son_get(aux, 0));
			tac_aux2 = tacGenerate(ast_son_get(aux, 1));
			return tacOperation(TAC_LE, tac_aux1, tac_aux2);
			//generate_code (output, ast_son_get(aux, 0)); // expressao
			//fprintf (output, " <= ");
			//generate_code (output, ast_son_get(aux, 1)); // expressao
			break;

		case GE: // 36
			tac_aux1 = tacGenerate(ast_son_get(aux, 0));
			tac_aux2 = tacGenerate(ast_son_get(aux, 1));
			return tacOperation(TAC_GE, tac_aux1, tac_aux2);
			//generate_code (output, ast_son_get(aux, 0)); // expressao
			//fprintf (output, " >= ");
			//generate_code (output, ast_son_get(aux, 1)); // expressao
			break;

		case EQ: // 37
			tac_aux1 = tacGenerate(ast_son_get(aux, 0));
			tac_aux2 = tacGenerate(ast_son_get(aux, 1));
			return tacOperation(TAC_EQ, tac_aux1, tac_aux2);
			//generate_code (output, ast_son_get(aux, 0)); // expressao
			//fprintf (output, " == ");
			//generate_code (output, ast_son_get(aux, 1)); // expressao
			break;

		case NE: // 38
			tac_aux1 = tacGenerate(ast_son_get(aux, 0));
			tac_aux2 = tacGenerate(ast_son_get(aux, 1));
			return tacOperation(TAC_NE, tac_aux1, tac_aux2);
			//generate_code (output, ast_son_get(aux, 0)); // expressao
			//fprintf (output, " != ");
			//generate_code (output, ast_son_get(aux, 1)); // expressao
			break;

		case AND: // 39
			tac_aux1 = tacGenerate(ast_son_get(aux, 0));
			tac_aux2 = tacGenerate(ast_son_get(aux, 1));
			return tacOperation(TAC_AND, tac_aux1, tac_aux2);
			//generate_code (output, ast_son_get(aux, 0)); // expressao
			//fprintf (output, " && ");
			//generate_code (output, ast_son_get(aux, 1)); // expressao
			break;

		case OR: // 40
			tac_aux1 = tacGenerate(ast_son_get(aux, 0));
			tac_aux2 = tacGenerate(ast_son_get(aux, 1));
			return tacOperation(TAC_OR, tac_aux1, tac_aux2);
			//generate_code (output, ast_son_get(aux, 0)); // expressao
			//fprintf (output, " || ");
			//generate_code (output, ast_son_get(aux, 1)); // expressao
			break;

		case LESS: // 41
			tac_aux1 = tacGenerate(ast_son_get(aux, 0));
			tac_aux2 = tacGenerate(ast_son_get(aux, 1));
			return tacOperation(TAC_LESS, tac_aux1, tac_aux2);
			//generate_code (output, ast_son_get(aux, 0)); // expressao
			//fprintf (output, " < ");
			//generate_code (output, ast_son_get(aux, 1)); // expressao
			break;

		case GREATER: // 42
            		tac_aux1 = tacGenerate(ast_son_get(aux, 0));
            		tac_aux2 = tacGenerate(ast_son_get(aux, 1));
            		return tacOperation(TAC_GREATER, tac_aux1, tac_aux2);
			//generate_code (output, ast_son_get(aux, 0)); // expressao
			//fprintf (output, " > ");
			//generate_code (output, ast_son_get(aux, 1)); // expressao
			break;

		case EXP: // 43
            return tacGenerate(ast_son_get(aux, 0));
			//fprintf(output, "(");
			//generate_code (output, ast_son_get(aux, 0)); // expressao
			//fprintf (output, ")");
			break;

		case FUNC_CALL: // 44
			hash_aux1 = hash_map_maketemp(hash);

			return tacJoin(
                    tacGenerate(ast_son_get(aux, 1)),
                    tacJoin(
                        tacCreate(TAC_CALL, ast_son_get(aux, 0)->hash_node, hash_aux1, 0),
                        tacCreate(TAC_LABEL, hash_aux1, 0, 0)));

			//generate_code (output, ast_son_get(aux, 0)); // id
			//fprintf (output, " (");
			//generate_code (output, ast_son_get(aux, 1)); // parametros_passados
			//fprintf(output, ")");
			break;

		case FUNC_CALL_PARAMS: // 45
            tac_aux1 = tacGenerate(ast_son_get(aux, 0));

            return tacJoin(
                    tacJoin(
                        tac_aux1,
                        tacCreate(TAC_PUSH, tac_aux1->res, 0, 0)),
                    tacGenerate(ast_son_get(aux, 1)));
			//generate_code (output, ast_son_get(aux, 0)); // expressao
			//generate_code (output, ast_son_get(aux, 1)); // resto_parametros_passados
			break;

		case ID_WORD: // 46
            return tacCreate(TAC_MOVE, hash_map_maketemp(hash), ast_son_get(aux, 0)->hash_node, 0);
			//generate_code (output, ast_son_get (aux, 0));
			break;

		case FUNC_CALL_PARAMS_REST: // 47
            return tacGenerate(ast_son_get(aux, 0));
			//fprintf(output, ", ");
			//generate_code (output, ast_son_get (aux, 0));
			break;

		case OUTPUT_LIST_REST:
            return tacGenerate(ast_son_get(aux, 0));
			//fprintf(output, ",");
			//generate_code (output, ast_son_get (aux, 0));
			break;

		case FUNC_DEC_PARAMS_REST:
            return tacGenerate(ast_son_get(aux, 0));
			//fprintf(output, ", ");
			//generate_code(output, ast_son_get(aux, 0));
            break;

		default:
			break;
        }
    }

    return NULL;
}

tac_node_t* tacCreate(int type, hash_node_t *res, hash_node_t *op1, hash_node_t* op2) {

	tac_node_t* newTAC = 0;
	newTAC = (tac_node_t*) calloc(1,sizeof(tac_node_t));

	newTAC->type = type;
    newTAC->res = res;
	newTAC->op1 = op1;
	newTAC->op2 = op2;
	newTAC->prev = 0;

	return newTAC;
}


tac_node_t* tacJoin(tac_node_t* TAC1, tac_node_t* TAC2){

	tac_node_t* aux;

	if(TAC1 == 0)return TAC2;
	if(TAC2 == 0)return TAC1;

	for(aux=TAC2; aux->prev!=0; aux=aux->prev);

	aux->prev = TAC1;

	return TAC2;
}

void tacPrintSingle(tac_node_t* TAC){

	if(TAC!=0)
		{
		switch(TAC->type)
			{
			case TAC_SYMBOL: printf("TAC_SYMBOL "); break;
			case TAC_MOVE: printf("TAC_MOVE "); break;
			case TAC_ADD: printf("TAC_ADD "); break;
			case TAC_SUB: printf("TAC_SUB "); break;
			case TAC_MUL: printf("TAC_MUL "); break;
			case TAC_DIV: printf("TAC_DIV "); break;
			case TAC_LABEL: printf("TAC_LABEL "); break;
			case TAC_JMP: printf("TAC_JMP "); break;
			case TAC_RET: printf("TAC_RET "); break;
			case TAC_EQ: printf("TAC_EQ "); break;
			case TAC_NE: printf("TAC_NE "); break;
			case TAC_LE: printf("TAC_LE "); break;
			case TAC_GE: printf("TAC_GE "); break;
			case TAC_LESS: printf("TAC_LESS "); break;
			case TAC_GREATER: printf("TAC_GREATER "); break;
			case TAC_AND: printf("TAC_AND "); break;
			case TAC_OR: printf("TAC_OR "); break;
			case TAC_VARDEC: printf("TAC_VARDEC "); break;
			case TAC_VECDEC: printf("TAC_VECDEC "); break;
            case TAC_TOVECMOVE: printf("TAC_TOVECMOVE"); break;
			case TAC_FROMVECMOVE: printf("TAC_FROMVECMOVE "); break;
			case TAC_INPUT: printf("TAC_INPUT "); break;
			case TAC_OUTPUT: printf("TAC_OUTPUT "); break;
			case TAC_RETURN: printf("TAC_RETURN "); break;
			case TAC_IF: printf("TAC_IF "); break;
			case TAC_CALL: printf("TAC_CALL "); break;
			case TAC_PUSH: printf("TAC_PUSH "); break;
			}
		if(TAC->res)
			printf("res(%s)", TAC->res->data);
		if(TAC->op1)
			printf("op1(%s)", TAC->op1->data);
		if(TAC->op2)
			printf("op2(%s)", TAC->op2->data);
		printf("\n");
		}
}

tac_node_t* tacOperation(int type, tac_node_t* TAC1, tac_node_t* TAC2){

	return tacJoin(tacJoin(TAC1, TAC2), tacCreate(type, hash_map_maketemp(hash), TAC1 ? TAC1->res : 0, TAC2 ? TAC2->res : 0));
}

void tacPrint(tac_node_t* TAC){

	if(TAC){
		tacPrint(TAC->prev);
		tacPrintSingle(TAC);
	}
}

