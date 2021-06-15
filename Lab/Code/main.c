#include "stdio.h"
#include "syntax.tab.h"
extern int yylex();
extern int yyrestart(FILE* f);
extern void printSytaxTree();
extern int yylineno;

void yyerror(char* s) {
	fprintf(stderr, "Error type B at Line %d\n", yylineno);
	return;
}

int main(int argc, char** argv) {
	if(argc <= 1) return 1;
	FILE *f = fopen(argv[1], "r");
       	if(!f) {
		perror(argv[1]);
		return 1;
	}
	yyrestart(f);
	if(yyparse() == 0)
		printSytaxTree();
	return 0;
}
