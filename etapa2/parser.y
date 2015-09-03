%{
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
%}

%token<symbol> UNDEFINED     1
%token<symbol> TK_IDENTIFIER 2
%token<symbol> LIT_INTEGER   3
%token<symbol> LIT_FALSE     4
%token<symbol> LIT_TRUE	     5
%token<symbol> LIT_CHAR      6
%token<symbol> LIT_STRING    7

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
}


%%

program: declaracao_funcao ';' program
	|declaracao_variaveis_globais
	| ;

declaracao_variaveis_globais: declaracao_variavel ';' declaracao_variaveis_globais
	| declaracao_vetor ';' declaracao_variaveis_globais
	| ;

declaracao_variavel: tipo TK_IDENTIFIER ':' literal ;

declaracao_vetor: tipo TK_IDENTIFIER '[' LIT_INTEGER ']' 
		| tipo TK_IDENTIFIER '[' LIT_INTEGER ']' ':' inicializacao_vetor ;

inicializacao_vetor: literal inicializacao_vetor ;
	        | ;

declaracao_funcao: tipo TK_IDENTIFIER '(' parametros ')' variaveis_locais comando  
		|  tipo TK_IDENTIFIER '(' ')' variaveis_locais comando ;


variaveis_locais: declaracao_variavel ';' variaveis_locais 
		| ;


tipo: KW_INT | KW_CHAR | KW_REAL | KW_BOOL ;

literal: LIT_INTEGER | LIT_CHAR | LIT_STRING | LIT_TRUE | LIT_FALSE ;

bloco: '{' lista_comandos '}' ;

lista_comandos: comando resto_comandos ;
	 | ;
resto_comandos: ';' lista_comandos
	| ;

comando: TK_IDENTIFIER ':''=' expressao
	 | expressao '='':' TK_IDENTIFIER 
	 | TK_IDENTIFIER '['expressao']' ':''=' expressao
	 | expressao '='':' TK_IDENTIFIER '['expressao']' 
	 | KW_INPUT TK_IDENTIFIER
	 | KW_OUTPUT lista_output
	 | KW_RETURN expressao
	 | controle_fluxo
	 | bloco 
	 | ;

controle_fluxo: KW_IF '('expressao')' comando
	 | KW_IF '('expressao')' comando KW_ELSE comando
	 | KW_IF '('expressao')' comando KW_LOOP ;

parametros: tipo TK_IDENTIFIER resto_parametros ;
resto_parametros: ',' parametros
	 | ;



lista_output: expressao resto_output ;
resto_output: ',' lista_output
	 | ;

expressao: TK_IDENTIFIER
	 | TK_IDENTIFIER '['expressao']'
	 | literal
	 | expressao '+' expressao
	 | expressao '-' expressao
	 | expressao '*' expressao
	 | expressao '/' expressao
	 | expressao OPERATOR_LE expressao
	 | expressao OPERATOR_GE expressao
	 | expressao OPERATOR_EQ expressao
	 | expressao OPERATOR_NE expressao
	 | expressao OPERATOR_AND expressao
	 | expressao OPERATOR_OR expressao 
	 | expressao '<' expressao
	 | expressao '>' expressao 
	 | '(' expressao ')'
	 | TK_IDENTIFIER '(' parametros_passados ')' ;

parametros_passados: expressao resto_parametros_passados ;
		| ;
resto_parametros_passados: ',' parametros_passados
		| ;


%%


int yyerror(char * str){

	printf("Erro sintatico na linha %d!\n", getLineNumber());
	printf("-----------------\n");
	exit(3);
}


