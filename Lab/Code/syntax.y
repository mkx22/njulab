//#include "lex.yy.c"
%locations
%{
 #include "lex.yy.c"
 #include <stdio.h>
 #include "string.h"
 void yyerror(const char* s);
 enum NodeType {Variable, Terminal, Number, Type, Id};
 struct Node{
	char* name;
	enum NodeType nodeType;
	int lineNum;
	char stringValue[300];
	int numValue;
	float numValueF;
	int childNum;
	struct Node* child[8];
 };
 struct Node* root;
 char IdString[300];
 struct Node* CreateTerminal(char* nameF, enum NodeType typeF,
		char* content, int numContent, int lineF, float fn);
 struct Node* CreateVariable(char* nameF, int numOfChild, 
		struct Node** childNode,int lineF);	
%}

 /* declared types */
%union {
 int type_int;
 float type_float;
 double type_double;
 struct Node* type_node;
 char* type_char;
}

 /* declared tokens */
%token <type_int>INT
%token <type_float> FLOAT
%token <type_double> DOUBLE
%token <type_node> PLUS MINUS STAR DIV
%token <type_node> AND OR
%token <type_node> DOT NOT LP RP LB RB LC RC
%token <type_node> STRUCT RETURN IF ELSE WHILE BLANK
%token <type_node> SEMI COMMA RELOP ASSIGNOP
%token <type_char> ID TYPE
%token <type_node> CM LCM RCM
//%token <type_node> error

/* declared non-terminals */
%type <type_node> Program ExtDefList ExtDef ExtDecList Specifier
%type <type_node> StructSpecifier OptTag Tag VarDec FunDec VarList
%type <type_node> ParamDec CompSt StmtList Stmt DefList Def DecList
%type <type_node> Dec Exp Args
%type <type_node> Com1 Com2

/* priority and combination*/

%%
 /* High-level Definitions */
Program	: ExtDefList 
	{
		$$ = CreateVariable("Program", 1, &$1, @$.first_line);
		root = $$;
	}
	;
ExtDefList : ExtDef ExtDefList 
	   {
		struct Node* child[2];
		child[0] = $1;
		child[1] = $2;
		$$ = CreateVariable("ExtDefList", 2, child, @$.first_line);
	   }
	   | { $$ = NULL; }
	   ;
ExtDef	: Specifier ExtDecList SEMI 
        {
		struct Node* child[3];
		child[0] = $1;
		child[1] = $2;
		child[2] = CreateTerminal("SEMI", Terminal, yytext, 0,
				@3.first_line, 0);
		$$ = CreateVariable("ExtDef", 3, child, @$.first_line);
	}
        | Specifier SEMI
	{
		struct Node* child[2];
		child[0] = $1;
		child[1] = CreateTerminal("SEMI", Terminal, yytext, 0,
			@2.first_line, 0);
		$$ = CreateVariable("ExtDef", 2, child, @$.first_line);
	}
	| Specifier FunDec CompSt
	{
		struct Node* child[3];
		child[0] = $1;
		child[1] = $2;
		child[2] = $3;
		$$ = CreateVariable("ExtDef", 3, child, @$.first_line);
	}
	| Com1
	{
		$$ = CreateVariable("Com1", 1, &$1, @$.first_line);
	}
	| Com2
	{
		$$ = CreateVariable("Com2", 1, &$1, @$.first_line);
	}
	| error SEMI
	{
	}
	;
ExtDecList : VarDec 
	   {
		$$ = CreateVariable("ExtDecList", 1, &$1, @$.first_line);
	   }
	   | VarDec COMMA ExtDecList
	   {
		struct Node* child[3];
		child[0] = $1;
		child[1] = CreateTerminal("COMMA", Terminal, ",", 0,
				@2.first_line, 0);
		child[2] = $3;
		$$ = CreateVariable("ExtDecList", 3, child, 
				@$.first_line);
	   }
	   ;

 /* Specifiers */
Specifier : TYPE
	  {
		struct Node*p = (struct Node*)malloc(sizeof(struct Node));
		p = CreateTerminal("TYPE", Type, $1, 0,
				@1.first_line, 0);
		$$ = CreateVariable("Specifier", 1, &p, @$.first_line);
	  }
	  | StructSpecifier
	  {
		$$ = CreateVariable("Specifier", 1, &$1, @$.first_line);
	  }
	  ;
StructSpecifier : STRUCT OptTag LC DefList RC
		{
			struct Node* child[5];
			child[0] = CreateTerminal("STRUCT", Terminal,
					"STRUCT", 0, @1.first_line, 0);
			child[1] = $2;
			child[2] = CreateTerminal("LC", Terminal,
					"{", 0, @3.first_line, 0);
			child[3] = $4;
			child[4] = CreateTerminal("RC", Terminal,
					"}", 0, @5.first_line, 0);
			$$ = CreateVariable("StructSpecifier", 5, child,
					@$.first_line);
		}
		| STRUCT Tag
		{
			struct Node* child[2];
			child[0] = CreateTerminal("STRUCT", Terminal,
					"STRUCT", 0, @1.first_line, 0);
			child[1] = $2;
			$$ = CreateVariable("StructSpecifier", 2, child,
					@$.first_line);
		}
		| error RC
		{
		}
		;
OptTag	: ID
	{
		struct Node* p = (struct Node*)malloc(sizeof(struct Node));
		p = CreateTerminal("ID", Id, IdString, 0,
				@1.first_line, 0);
		$$ = CreateVariable("OptTag", 1, &p, @$.first_line);
	}
        | { $$ = NULL; }
	;
Tag	: ID
	{
		struct Node* p = (struct Node*)malloc(sizeof(struct Node));
		p = CreateTerminal("ID", Id, IdString, 0,
				@1.first_line, 0);
		$$ = CreateVariable("Tag", 1, &p, @$.first_line);
	}
    	;

 /* Declarators */
VarDec	: ID 
        {
		struct Node* p = (struct Node*)malloc(sizeof(struct Node));
		p = CreateTerminal("ID", Id, IdString, 0,
				@1.first_line, 0);
		$$ = CreateVariable("VarDec", 1, &p, @$.first_line);
	}
        | VarDec LB INT RB
	{
		struct Node* child[4];
		child[0] = $1;
		child[1] = CreateTerminal("LB", Terminal,
				"[", 0, @2.first_line, 0);
		child[2] = CreateTerminal("INT", Number,
				"INT", $3, @3.first_line, 0);
		child[3] = CreateTerminal("RB", Terminal,
				"]", 0, @4.first_line, 0);
		$$ = CreateVariable("VarDec", 4, child,
				@$.first_line);
	}
	| error RB
	{
	}
	;
FunDec	: ID LP VarList RP
	{
		struct Node* child[4];
		child[0] = CreateTerminal("ID", Id,
				IdString, 0, @1.first_line, 0);
		child[1] = CreateTerminal("LP", Terminal,
				"(", 0, @2.first_line, 0);
		child[2] = $3;
		child[3] = CreateTerminal("RP", Terminal,
				")", 0, @4.first_line, 0);
		$$ = CreateVariable("FunDec", 4, child,
				@$.first_line);
	}
        | ID LP RP
	{
		struct Node* child[3];
		child[0] = CreateTerminal("ID", Id,
				IdString, 0, @1.first_line, 0);
		child[1] = CreateTerminal("LP", Terminal,
				"(", 0, @2.first_line, 0);
		child[2] = CreateTerminal("RP", Terminal,
				")", 0, @3.first_line, 0);
		$$ = CreateVariable("FunDec", 3, child,
				@$.first_line);
	}
	| error RP
	{
	}
	;
VarList : ParamDec COMMA VarList
	{
		struct Node* child[3];
		child[0] = $1;
		child[1] = CreateTerminal("COMMA", Terminal,
				",", 0, @2.first_line, 0);
		child[2] = $3;
		$$ = CreateVariable("VarList", 3, child,
				@$.first_line);
	}
	| ParamDec
	{
		$$ = CreateVariable("VarList", 1, &$1, @$.first_line);
	}
	;
ParamDec: Specifier VarDec
	{
		struct Node* child[2];
		child[0] = $1;
		child[1] = $2;
		$$ = CreateVariable("ParamDec", 2, child,
				@$.first_line);
	}
	;

 /* Statements */
CompSt	: LC DefList StmtList RC
	{
		struct Node* child[4];
		child[0] = CreateTerminal("LC", Terminal,
				"{", 0, @1.first_line, 0);
		child[1] = $2;
		child[2] = $3;
		child[3] = CreateTerminal("RC", Terminal,
				"}", 0, @2.first_line, 0);
		$$ = CreateVariable("CompSt", 4, child,
				@$.first_line);
	}
	| error RC
	{
	}
        ;
StmtList: Stmt StmtList
	{
		struct Node* child[2];
		child[0] = $1;
		child[1] = $2;
		$$ = CreateVariable("StmtList", 2, child,
				@$.first_line);
	}
	| { $$ = NULL; }
	;
Stmt	: Exp SEMI
	{
		struct Node* child[2];
		child[0] = $1;
		child[1] = CreateTerminal("SEMI", Terminal,
				";", 0, @2.first_line, 0);
		$$ = CreateVariable("Stmt", 2, child,
				@$.first_line);
	}
     	| CompSt
	{
		$$ = CreateVariable("Stmt", 1, &$1,
				@$.first_line);
	}
	| RETURN Exp SEMI
	{
		struct Node* child[3];
		child[0] = CreateTerminal("RETURN", Terminal,
				"RETURN", 0, @1.first_line, 0);
		child[1] = $1;
		child[2] = CreateTerminal("SEMI", Terminal,
				";", 0, @3.first_line, 0);
		$$ = CreateVariable("Stmt", 3, child,
				@$.first_line);
	}
	| IF LP Exp RP Stmt
	{
		struct Node* child[5];
		child[0] = CreateTerminal("IF", Terminal,
				"IF", 0, @1.first_line, 0);
		child[1] = CreateTerminal("LP", Terminal,
				"(", 0, @2.first_line, 0);
		child[2] = $3;
		child[3] = CreateTerminal("RP", Terminal,
				")", 0, @4.first_line, 0);
		child[4] = $5;
		$$ = CreateVariable("Stmt", 5, child,
				@$.first_line);
	}
	| IF LP Exp RP Stmt ELSE Stmt
	{
		struct Node* child[7];
		child[0] = CreateTerminal("IF", Terminal,
				"IF", 0, @1.first_line, 0);
		child[1] = CreateTerminal("LP", Terminal,
				"(", 0, @2.first_line, 0);
		child[2] = $3;
		child[3] = CreateTerminal("RP", Terminal,
				")", 0, @4.first_line, 0);
		child[4] = $5;
		child[5] = CreateTerminal("ELSE", Terminal,
				"ELSE", 0, @5.first_line, 0);
		child[6] = $7;
		$$ = CreateVariable("Stmt", 7, child,
				@$.first_line);
	}
	| WHILE LP Exp RP Stmt
	{
		struct Node* child[5];
		child[0] = CreateTerminal("WHILE", Terminal,
				"WHILE", 0, @1.first_line, 0);
		child[1] = CreateTerminal("LP", Terminal,
				"(", 0, @2.first_line, 0);
		child[2] = $3;
		child[3] = CreateTerminal("RP", Terminal,
				")", 0, @4.first_line, 0);
		child[4] = $5;
		$$ = CreateVariable("Stmt", 5, child,
				@$.first_line);
	}
	| Com1
	{
		$$ = CreateVariable("Com1", 1, &$1, @$.first_line);
	}
	| Com2
	{
		$$ = CreateVariable("Com2", 1, &$1, @$.first_line);
	}
	| error RP
	{
	}
	;

 /* Local Definitions */
DefList : Def DefList
	{
		struct Node* child[2];
		child[0] = $1;
		child[1] = $2;
		$$ = CreateVariable("DefList", 2, child,
				@$.first_line);
	}
	| { $$ = NULL; }
	;
Def	: Specifier DecList SEMI
	{
		struct Node* child[3];
		child[0] = $1;
		child[1] = $2;
		child[2] = CreateTerminal("SEMI", Terminal,
				yytext, 0, @3.first_line, 0);
		$$ = CreateVariable("Def", 3, child,
				@$.first_line);
	}
	| Com1
	{
		$$ = CreateVariable("Com1", 1, &$1, @$.first_line);
	}
	| Com2
	{
		$$ = CreateVariable("Com2", 1, &$1, @$.first_line);
	}
	| error SEMI
	{
	}
    	;
DecList : Dec
	{
		$$ = CreateVariable("DecList", 1, &$1, @$.first_line);
	}
	| Dec COMMA DecList
	{
		struct Node* child[3];
		child[0] = $1;
		child[1] = CreateTerminal("COMMA", Terminal,
				",", 0, @2.first_line, 0);
		child[2] = $3;
		$$ = CreateVariable("DecList", 3, child,
				@$.first_line);
	}
	;
Dec	: VarDec
	{
		$$ = CreateVariable("Dec", 1, &$1, @$.first_line);
	}
    	| VarDec ASSIGNOP Exp
	{
		struct Node* child[3];
		child[0] = $1;
		child[1] = CreateTerminal("ASSIGNOP", Terminal,
				"=", 0, @2.first_line, 0);
		child[2] = $3;
		$$ = CreateVariable("Dec", 3, child,
				@$.first_line);
	}
Com1	: CM
     	{
		struct Node* child[1];
		child[0] = CreateTerminal("CM", Terminal, "//", 0, @1.first_line, 0);
		$$ = CreateVariable("Com1", 1, child, @$.first_line);
	
	}
Com2	: LCM RCM
     	{
		struct Node* child[2];
		child[0] = CreateTerminal("LCM", Terminal, "", 0, @1.first_line, 0);
		child[1] = CreateTerminal("RCM", Terminal, "", 0, @2.first_line, 0);
		$$ = CreateVariable("Com2", 2, child, @$.first_line);
	
	}
	;

 /* Expressions */
Exp	: Exp ASSIGNOP Exp
	{
		struct Node* child[3];
		child[0] = $1;
		child[1] = CreateTerminal("ASSIGNOP", Terminal,
				"=", 0, @2.first_line, 0);
		child[2] = $3;
		$$ = CreateVariable("Exp", 3, child,
				@$.first_line);
	}
    	| Exp AND Exp
	{
		struct Node* child[3];
		child[0] = $1;
		child[1] = CreateTerminal("AND", Terminal,
				"&&", 0, @2.first_line, 0);
		child[2] = $3;
		$$ = CreateVariable("Exp", 3, child,
				@$.first_line);
	}
	| Exp OR Exp
	{
		struct Node* child[3];
		child[0] = $1;
		child[1] = CreateTerminal("OR", Terminal,
				"||", 0, @2.first_line, 0);
		child[2] = $3;
		$$ = CreateVariable("Exp", 3, child,
				@$.first_line);
	}
    	| Exp RELOP Exp
	{
		struct Node* child[3];
		child[0] = $1;
		child[1] = CreateTerminal("RELOP", Terminal,
				yytext, 0, @2.first_line, 0);
		child[2] = $3;
		$$ = CreateVariable("Exp", 3, child,
				@$.first_line);
	}
    	| Exp PLUS Exp
	{
		struct Node* child[3];
		child[0] = $1;
		child[1] = CreateTerminal("PLUS", Terminal,
				"+", 0, @2.first_line, 0);
		child[2] = $3;
		$$ = CreateVariable("Exp", 3, child,
				@$.first_line);
	}
    	| Exp MINUS Exp
	{
		struct Node* child[3];
		child[0] = $1;
		child[1] = CreateTerminal("MINUS", Terminal,
				"-", 0, @2.first_line, 0);
		child[2] = $3;
		$$ = CreateVariable("Exp", 3, child,
				@$.first_line);
	}
    	| Exp STAR Exp
	{
		struct Node* child[3];
		child[0] = $1;
		child[1] = CreateTerminal("STAR", Terminal,
				"*", 0, @2.first_line, 0);
		child[2] = $3;
		$$ = CreateVariable("Exp", 3, child,
				@$.first_line);
	}
    	| Exp DIV Exp
	{
		struct Node* child[3];
		child[0] = $1;
		child[1] = CreateTerminal("DIV", Terminal,
				"/", 0, @2.first_line, 0);
		child[2] = $3;
		$$ = CreateVariable("Exp", 3, child,
				@$.first_line);
	}
    	| LP Exp RP
	{
		struct Node* child[3];
		child[0] = CreateTerminal("LP", Terminal,
				"(", 0, @1.first_line, 0);
		child[1] = $2;
		child[2] = CreateTerminal("RP", Terminal,
				")", 0, @3.first_line, 0);
		$$ = CreateVariable("Exp", 3, child,
				@$.first_line);
	}
	| MINUS Exp
	{
		struct Node* child[2];
		child[0] = CreateTerminal("MINUS", Terminal,
				"-", 0, @1.first_line, 0);
		child[1] = $2;
		$$ = CreateVariable("Exp", 2, child,
				@$.first_line);
	}
	| NOT Exp
	{
		struct Node* child[2];
		child[0] = CreateTerminal("NOT", Terminal,
				"~", 0, @1.first_line, 0);
		child[1] = $2;
		$$ = CreateVariable("Exp", 2, child,
				@$.first_line);
	}
	| ID LP Args RP
	{
		struct Node* child[4];
		child[0] = CreateTerminal("ID", Id,
				IdString, 0, @1.first_line, 0);
		child[1] = CreateTerminal("LP", Terminal,
				"(", 0, @2.first_line, 0);
		child[2] = $3;
		child[3] = CreateTerminal("RP", Terminal,
				")", 0, @4.first_line, 0);
		$$ = CreateVariable("Exp", 4, child,
				@$.first_line);
	}
	| ID LP RP
	{
		struct Node* child[3];
		child[0] = CreateTerminal("ID", Id,
				IdString, 0, @1.first_line, 0);
		child[1] = CreateTerminal("LP", Terminal,
				"(", 0, @2.first_line, 0);
		child[2] = CreateTerminal("RP", Terminal,
				")", 0, @3.first_line, 0);
		$$ = CreateVariable("Exp", 3, child,
				@$.first_line);
	}
	| Exp LB Exp RB
	{
		struct Node* child[4];
		child[0] = $1;
		child[1] = CreateTerminal("LB", Terminal,
				"[", 0, @2.first_line, 0);
		child[2] = $3;
		child[3] = CreateTerminal("RB", Terminal,
				"]", 0, @4.first_line, 0);
		$$ = CreateVariable("Exp", 4, child,
				@$.first_line);
	}
	| Exp DOT ID
	{
		struct Node* child[3];
		child[0] = $1;
		child[1] = CreateTerminal("DOT", Terminal,
				".", 0, @2.first_line, 0);
		child[2] = CreateTerminal("ID", Id,
				IdString, 0, @3.first_line, 0);
		$$ = CreateVariable("Exp", 3, child,
				@$.first_line);
	}
	| ID
	{
		struct Node* p = (struct Node*)malloc(sizeof(struct Node));
		p = CreateTerminal("ID", Id,
				IdString, 0, @1.first_line, 0);
		$$ = CreateVariable("Exp", 1, &p,
				@$.first_line);
	}
	| INT
	{
		struct Node* tempNode = (struct Node*)malloc(
				sizeof(struct Node));
		tempNode = CreateTerminal("INT", Number,
				"INT", $1, @1.first_line, 0);
		$$ = CreateVariable("Exp", 1, &tempNode,
				@$.first_line);
	}
	| FLOAT
	{
		struct Node* tempNode = (struct Node*)malloc(
				sizeof(struct Node));
		tempNode = CreateTerminal("FLOAT", Number,
				"FLOAT", 0, @1.first_line, $1);
		$$ = CreateVariable("Exp", 1, &tempNode,
				@$.first_line);
	}
	;
Args	: Exp COMMA Args
	{
		struct Node* child[3];
		child[0] = $1;
		child[1] = CreateTerminal("COMMA", Terminal,
				",", 0, @2.first_line, 0);
		child[2] = $3;
		$$ = CreateVariable("Args", 3, child,
				@$.first_line);
	}
     	| Exp
	{
		$$ = CreateVariable("Args", 1, &$1, @$.first_line);
	}
	;
%%
struct Node* CreateTerminal(char* nameF, enum NodeType typeF,
		char* content, int numContent, int lineF, float fn) {
	struct Node* p = (struct Node*)malloc(sizeof(struct Node));
	p->name = nameF;
	p->nodeType = typeF;
	p->lineNum = lineF;
	p->childNum = 0;
	if(typeF == Type | typeF == Id)
		strcpy(p->stringValue, content);
	else if(typeF == Number) {
		if(p->name == "INT")
			p->numValue = numContent;
		else
			p->numValueF = fn;
	}
	return p;
}
struct Node* CreateVariable(char* nameF, int numOfChild, 
		struct Node** childNode,int lineF) {
	int i;
	struct Node* p = (struct Node*)malloc(sizeof(struct Node));
	p->name = nameF;
	p->nodeType = Variable;
	p->lineNum = lineF;
	p->childNum = numOfChild;
	for(i = 0;i < numOfChild;i++) {
		p->child[i] = childNode[i];
	}
	return p;
}
void preTraverse(struct Node* root, int blankNum) {
	int i;
	for(i = 0;i < blankNum;i++)
		printf(" ");
	if(root->nodeType == Variable)
		printf("%s (%d)\n", root->name, root->lineNum);
	else if(root->nodeType == Id || root->nodeType == Type) {
		printf("%s: %s\n", root->name, root->stringValue);
	}
	else if(root->nodeType == Number) {
		if(root->name == "INT")
			printf("%s: %d\n", root->name, root->numValue);
		else
			printf("%s: %f\n", root->name, root->numValueF);
	}
	else
		printf("%s\n", root->name);
	for(i = 0;i < root->childNum;i++) {
		if(root->child[i] != NULL) {
			preTraverse(root->child[i], blankNum + 2);
		}
	}
}
void printSytaxTree() {
	if(root == NULL) {
		printf("This is an empty syntax tree, but acceptable\n");
		return;
	}
	preTraverse(root, 0);	
}
