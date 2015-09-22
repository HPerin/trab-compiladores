#include <stdio.h>
#include "lex.yy.h"
#include "hash.h"
#include "y.tab.h"


int main(int argc, char ** argv){

	if(argc!=2){
		printf("-----------------\n");
		printf("Usage: etapa2 <arquivo>\n");
		printf("-----------------\n");
		exit(1);

	}
	
	FILE* file;

	initMe();

	if(!(file=fopen(argv[1], "r"))){
		printf("-----------------\n");
		printf("Erro ao abrir %s!\n", argv[1]);
		printf("-----------------\n");
	        exit(1);
	}
	
	yyin = file;
	
	printf("-----------------\n");
	printf("Iniciando parse!\n");

	yyparse();
	
	printf("Sucesso!\n");
	printf("-----------------\n");

	exit(0);
	


}
