#include <stdio.h>
#include "lex.yy.h"
#include "hash.h"
#include "y.tab.h"


int main(int argc, char ** argv){

	FILE* file;

	initMe();

	if(!(file=fopen("teste.txt", "r"))){
		printf("erro ao abrir teste.txt\n");
	        exit(1);
	}
	
	yyin = file;

	printf("starting\n");

	yyparse();
	
	printf("success\n");

	exit(0);
	


}
