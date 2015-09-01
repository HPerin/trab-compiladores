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

program: KW_INPUT



%%


int yyerror(char * str){

	printf("yyerror\n");
	exit(3);
}


