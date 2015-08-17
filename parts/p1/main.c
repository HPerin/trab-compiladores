
#include "lex.yy.h"
#include <stdio.h>
#include "tokens.h"

extern int getLineNumber();
extern void initMe();
extern int isRunning();

int main(int argc, char ** argv) {
	FILE* file;
	if (!(file = fopen("teste.txt", "r")))
		printf ("Erro na abertura.");
	yyin = file;
	initMe();
	while(isRunning()) {
		switch (yylex()) {
			case TOKEN_ERROR: printf("error |%s| @ linha %d \n", yytext, getLineNumber()); break;
			case KW_INT: printf("int @ linha %d \n", getLineNumber()); break;
			case KW_REAL: printf("real @ linha %d \n", getLineNumber()); break;
			case KW_BOOL: printf("bool @ linha %d \n", getLineNumber()); break;
			case KW_CHAR: printf("char @ linha %d \n", getLineNumber()); break;
			case KW_IF: printf("if @ linha %d \n", getLineNumber()); break;
			case KW_ELSE: printf("else @ linha %d \n", getLineNumber()); break;
			case KW_LOOP: printf("loop @ linha %d \n", getLineNumber()); break;
			case KW_INPUT: printf("input @ linha %d \n", getLineNumber()); break;
			case KW_OUTPUT: printf("output @ linha %d \n", getLineNumber()); break;
			case KW_RETURN: printf("return @ linha %d \n", getLineNumber()); break;
			default: printf("token |%s| @ linha %d \n", yytext, getLineNumber()); break;
		}
	}
}
