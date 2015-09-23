%{
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
%}

%token<symbol> UNDEFINED     1
%token<symbol> TK_IDENTIFIER 2
%token<symbol> LIT_INTEGER   3
%token<symbol> LIT_FALSE     4
%token<symbol> LIT_TRUE	     5
%token<symbol> LIT_CHAR      6
%token<symbol> LIT_STRING    7

%type<node> program
%type<node> declaracao_variaveis_globais
%type<node> declaracao_variavel
%type<node> declaracao_vetor
%type<node> inicializacao_vetor
%type<node> declaracao_funcao
%type<node> variaveis_locais
%type<node> tipo
%type<node> literal
%type<node> bloco
%type<node> lista_comandos
%type<node> resto_comandos
%type<node> comando
%type<node> controle_fluxo
%type<node> parametros
%type<node> resto_parametros
%type<node> lista_output
%type<node> resto_output
%type<node> expressao
%type<node> parametros_passados
%type<node> resto_parametros_passados
%type<node> tamanho


%token KW_INT        256
%token KW_REAL       257
%token KW_BOOL       258
%token KW_CHAR       259
%token KW_IF         261
%token KW_ELSE       263
%token KW_LOOP       264
%token KW_INPUT      266
%token KW_RETURN     267
%token KW_OUTPUT     268

%token OPERATOR_LE   270
%token OPERATOR_GE   271
%token OPERATOR_EQ   272
%token OPERATOR_NE   273
%token OPERATOR_AND  274
%token OPERATOR_OR   275

%token TOKEN_ERROR   290

%right '='
%left  '<' '>' OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_NE OPERATOR_AND OPERATOR_OR
%left '+' '-'
%left '*' '%'

%union
{
	hash_node_t* symbol;
	ast_node_t* node;
}


%%

program: declaracao_funcao ';' program						   {$$ = ast_node_new(FUNDEC, 0); ast_node_add_son($$, $1); ast_node_add_son($$, $3);}
	|declaracao_variaveis_globais						   {$$ = $1; ast_print($$);}
	|									   {$$ = 0;}
	;
declaracao_variaveis_globais: declaracao_variavel ';' declaracao_variaveis_globais {$$ = ast_node_new(GLOBAL_VAR, 0); ast_node_add_son($$, $1); ast_node_add_son($$, $3);}
	| declaracao_vetor ';' declaracao_variaveis_globais			   {$$ = ast_node_new(GLOBAL_VEC, 0); ast_node_add_son($$, $1); ast_node_add_son($$, $3);}
	|									   {$$ = 0;}
	;
declaracao_variavel: tipo TK_IDENTIFIER ':' literal				   {$$ = ast_node_new(VARDEC, $2); ast_node_add_son($$, $1); ast_node_add_son($$, $4);}
			;
declaracao_vetor: tipo TK_IDENTIFIER '[' tamanho ']' 			 	   {$$ = ast_node_new(VECDEC_NOINIT, $2); ast_node_add_son($$, $1); ast_node_add_son($$, $4);}
		| tipo TK_IDENTIFIER '[' tamanho ']' ':' inicializacao_vetor   	   {$$ = ast_node_new(VECDEC_INIT, $2); ast_node_add_son($$, $1); ast_node_add_son($$, $4); ast_node_add_son($$, $7);}
		;

tamanho: LIT_INTEGER								   {$$ = ast_node_new(SYMBOL, $1);}	
	;

inicializacao_vetor: literal inicializacao_vetor 				   {$$ = ast_node_new(VECINIT, 0); ast_node_add_son($$, $1); ast_node_add_son($$, $2);}
	        |								   {$$ = 0;}
		;

declaracao_funcao: tipo TK_IDENTIFIER '(' parametros ')' variaveis_locais comando  {$$ = ast_node_new(FUNDEC_PARAMS, $2); ast_node_add_son($$, $1); ast_node_add_son($$, $4); ast_node_add_son($$, $6); 																					       ast_node_add_son($$, $7);}
		|  tipo TK_IDENTIFIER '(' ')' variaveis_locais comando 	   	   {$$ = ast_node_new(FUNDEC_NOPARAMS, $2); ast_node_add_son($$, $1); ast_node_add_son($$, $5); ast_node_add_son($$, $6);}
		;

variaveis_locais: declaracao_variavel ';' variaveis_locais 			   {$$ = ast_node_new(LOCAL_VAR,0); ast_node_add_son($$, $1); ast_node_add_son($$, $3);}		  
		| 								   {$$ = 0;}
		;

tipo: KW_INT									   {$$=ast_node_new(INT, 0);}
      | KW_CHAR 								   {$$=ast_node_new(CHAR, 0);}
      | KW_REAL 								   {$$=ast_node_new(REAL, 0);}
      | KW_BOOL									   {$$=ast_node_new(BOOL, 0);}
      ;

literal: LIT_INTEGER								   {$$ = ast_node_new(SYMBOL, $1);}
	| LIT_CHAR 								   {$$ = ast_node_new(SYMBOL, $1);}
	| LIT_STRING 							   	   {$$ = ast_node_new(SYMBOL, $1);}
	| LIT_TRUE 								   {$$ = ast_node_new(SYMBOL, $1);}
	| LIT_FALSE								   {$$ = ast_node_new(SYMBOL, $1);}
	;

bloco: '{' lista_comandos '}'							   {$$ = ast_node_new(BLOCK, 0); ast_node_add_son($$, $2);}
	;

lista_comandos: comando resto_comandos 						   {$$ = ast_node_new(CMDLIST, 0); ast_node_add_son($$, $1); ast_node_add_son($$, $2);}
	 | 									   {$$ = 0;}
	 ;

resto_comandos: ';' lista_comandos						   {$$ = $2;}
	| 									   {$$ = 0;}
	;

comando: TK_IDENTIFIER ':''=' expressao						   {$$ = ast_node_new(ATTR, $1); ast_node_add_son($$, $4);}					
	 | expressao '='':' TK_IDENTIFIER 					   {$$ = ast_node_new(ATTR_REV,$4); ast_node_add_son($$, $1);}
	 | TK_IDENTIFIER '['expressao']' ':''=' expressao			   {$$ = ast_node_new(VEC_ATTR, $1); ast_node_add_son($$, $3); ast_node_add_son($$, $7);}
	 | expressao '='':' TK_IDENTIFIER '['expressao']' 			   {$$ = ast_node_new(VEC_ATTR_REV, $4); ast_node_add_son($$, $6); ast_node_add_son($$, $1);}
	 | KW_INPUT TK_IDENTIFIER						   {$$ = ast_node_new(INPUT, $2);}
	 | KW_OUTPUT lista_output						   {$$ = ast_node_new(OUTPUT, 0); ast_node_add_son($$, $2);}
	 | KW_RETURN expressao							   {$$ = ast_node_new(RETURN, 0); ast_node_add_son($$, $2);}
	 | controle_fluxo							   {$$ = $1;}
	 | bloco 								   {$$ = $1;}
	 | 									   {$$ = 0;}
	 ;

controle_fluxo: KW_IF '('expressao')' comando					   {$$ = ast_node_new(IF, 0); ast_node_add_son($$, $3); ast_node_add_son($$, $5);}
	 | KW_IF '('expressao')' comando KW_ELSE comando			   {$$ = ast_node_new(IF_ELSE, 0); ast_node_add_son($$,$3); ast_node_add_son($$, $5); ast_node_add_son($$, $7);} 
	 | KW_IF '('expressao')' comando KW_LOOP 				   {$$ = ast_node_new(IF_LOOP, 0); ast_node_add_son($$, $3); ast_node_add_son($$,$5);}
	 ;
parametros: tipo TK_IDENTIFIER resto_parametros 				   {$$ = ast_node_new(FUNC_DEC_PARAMS, $2); ast_node_add_son($$, $1); ast_node_add_son($$, $3);}
	;
		
resto_parametros: ',' parametros						   {$$ = $2;}
	 | 									   {$$ = 0;}
	 ;


lista_output: expressao resto_output 						   {$$ = ast_node_new(OUTPUT_LIST, 0); ast_node_add_son($$, $1); ast_node_add_son($$, $2);}
	;
resto_output: ',' lista_output							   {$$ = $2;}
	 | 									   {$$ = 0;}
	 ;

expressao: TK_IDENTIFIER							   {$$ = ast_node_new(SYMBOL, $1);}
	 | TK_IDENTIFIER '['expressao']'					   {$$ = ast_node_new(VECTOR, $1); ast_node_add_son($$, $3);}
	 | literal								   {$$ = $1;}
	 | expressao '+' expressao						   {$$ = ast_node_new(ADD, 0); ast_node_add_son($$, $1); ast_node_add_son($$, $3);}
	 | expressao '-' expressao						   {$$ = ast_node_new(SUB, 0); ast_node_add_son($$, $1); ast_node_add_son($$, $3);}
	 | expressao '*' expressao						   {$$ = ast_node_new(MUL, 0); ast_node_add_son($$, $1); ast_node_add_son($$, $3);}
	 | expressao '/' expressao						   {$$ = ast_node_new(DIV, 0); ast_node_add_son($$, $1); ast_node_add_son($$, $3);}
	 | expressao OPERATOR_LE expressao					   {$$ = ast_node_new(LE, 0); ast_node_add_son($$, $1); ast_node_add_son($$, $3);}
	 | expressao OPERATOR_GE expressao					   {$$ = ast_node_new(GE, 0); ast_node_add_son($$, $1); ast_node_add_son($$, $3);}
	 | expressao OPERATOR_EQ expressao					   {$$ = ast_node_new(EQ, 0); ast_node_add_son($$, $1); ast_node_add_son($$, $3);}
	 | expressao OPERATOR_NE expressao					   {$$ = ast_node_new(NE, 0); ast_node_add_son($$, $1); ast_node_add_son($$, $3);}
	 | expressao OPERATOR_AND expressao					   {$$ = ast_node_new(AND, 0); ast_node_add_son($$, $1); ast_node_add_son($$, $3);}
	 | expressao OPERATOR_OR expressao 					   {$$ = ast_node_new(OR, 0); ast_node_add_son($$, $1); ast_node_add_son($$, $3);}
	 | expressao '<' expressao						   {$$ = ast_node_new(LESS, 0); ast_node_add_son($$, $1); ast_node_add_son($$, $3);}
	 | expressao '>' expressao 						   {$$ = ast_node_new(GREATER, 0); ast_node_add_son($$, $1); ast_node_add_son($$, $3);}
	 | '(' expressao ')'							   {$$ = ast_node_new(EXP, 0); ast_node_add_son($$, $2);}
	 | TK_IDENTIFIER '(' parametros_passados ')' 				   {$$ = ast_node_new(FUNC_CALL, $1); ast_node_add_son($$, $3);}
	 ;

parametros_passados: expressao resto_parametros_passados 			   {$$ = ast_node_new(FUNC_CALL_PARAMS, 0); ast_node_add_son($$, $1); ast_node_add_son($$, $2);}
		| 								   {$$ = 0;}
	        ;
resto_parametros_passados: ',' parametros_passados				   {$$ = $2;}
		| 								   {$$ = 0;}
	   	;


%%


int yyerror(char * str){

	printf("Erro sintatico na linha %d!\n", getLineNumber());
	printf("-----------------\n");
	exit(3);
}


