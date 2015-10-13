#include <stdio.h>
#include "lex.yy.h"
#include "ast.h"
#include "y.tab.h"

int main(int argc, char ** argv){

	if(argc!=3){
		printf("-----------------\n");
		printf("Usage: etapa3 <input> <output>\n");
		printf("-----------------\n");
		exit(1);

	}
	
	FILE* input;
	FILE* output;

	initMe();

	if(!(input=fopen(argv[1], "r"))){
		printf("-----------------\n");
		printf("Error opening input file: %s !\n", argv[1]);
		printf("-----------------\n");
	        exit(2);
	}

	if(!(output=fopen(argv[2], "w"))){
		printf("-----------------\n");
		printf("Erro opening output file: %s !\n", argv[2]);
		printf("-----------------\n");
	        exit(2);
	}
	
	yyin = input;
  	setoutput(output);
	
	printf("-----------------\n");
	printf("Started!\n");

	yyparse();
	
	printf("Success!\n");
	printf("-----------------\n");
	exit(0);
	


}
