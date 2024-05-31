%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG	0

#define	 MAXSYM	100
#define	 MAXSYMLEN	20
#define	 MAXTSYMLEN	15
#define	 MAXTSYMBOL	MAXSYM/2

#define STMTLIST 500

typedef struct nodeType {
	int token;
	int tokenval;
	struct nodeType *son;
	struct nodeType *brother;
	} Node;

#define YYSTYPE Node*
	
int tsymbolcnt=0;
int errorcnt=0;
int iflabel=0;
int Rlabel=0;
int modlabel=0;
int arrsize=0;
char ch;

FILE *yyin;
FILE *fp;

extern char symtbl[MAXSYM][MAXSYMLEN];
extern int maxsym;
extern int lineno;

void DFSTree(Node*);
Node * MakeOPTree(int, Node*, Node*);
Node * MakeNode(int, int);
Node * MakeListTree(Node*, Node*);
Node * MakeIFTree(int, int, Node*, Node*);
Node * MakeIFELSETree(int, int, int, Node*, Node*, Node*);
Node * MakeWHILETree(int, int, Node*, Node*);
Node * MakeAATree(int, int, Node*, Node*);
Node * MakeINPUTTree(int,int, Node*);
void codegen(Node* );
void prtcode(int, int, Node * n);

void	dwgen(Node*);
void 	finish();
int	gentemp();
void	assgnstmt(int, int);
void	numassgn(int, int);
void	addstmt(int, int, int);
void	substmt(int, int, int);
void	ifstmt(Node*, Node*);;
int		insertsym(char *);
%}

%token	STRING IF IF2 THEN ELSE WHILE LOOP CONTINUE BREAK LT GT LE GE EQ NE AND OR ADD SUB MUL DIV MOD MOD2 
%token	ADDASSGN SUBASSGN MULASSGN DIVASSGN ARRASSGN ASSGN ID NUM CHAR STMTEND START END ID2 ID3 VAR INPUT PRINTNUM PRINTCH
%left AND OR
%left LT GT LE GE EQ NE
%left ADD SUB
%left MUL DIV MOD
%right ASSGN
%nonassoc IFX
%nonassoc ELSE


%%
program	: START stmt_list END	{ if (errorcnt==0) {codegen($2); finish();} }
		;

stmt_list: 	stmt_list stmt 	{$$=MakeListTree($1, $2);}
		|	stmt			{$$=MakeListTree(NULL, $1);}
		| 	error STMTEND	{ errorcnt++; yyerrok;}
		;

stmt	: 	ID ASSGN expr STMTEND	{ $1->token = ID2; $$=MakeOPTree(ASSGN, $1, $3); }
		|	ID ADDASSGN expr STMTEND	{ $1->token = ID3; $$=MakeAATree(ASSGN, ADD, $1, $3); }
		|	ID SUBASSGN expr STMTEND	{ $1->token = ID3; $$=MakeAATree(ASSGN, SUB, $1, $3); }
		|	ID MULASSGN expr STMTEND	{ $1->token = ID3; $$=MakeAATree(ASSGN, MUL, $1, $3); }
		|	ID DIVASSGN expr STMTEND	{ $1->token = ID3; $$=MakeAATree(ASSGN, DIV, $1, $3); }
		|	INPUT ID STMTEND	{ $2->token = ID2; $$ = MakeINPUTTree(ASSGN,INPUT, $2); }
		|	PRINTNUM expr STMTEND	{ $$=MakeNode(PRINTNUM,PRINTNUM); $$->son = $2;}
		|	PRINTCH expr STMTEND	{ $$=MakeNode(PRINTCH,PRINTCH); $$->son = $2;}
		|   VAR ID STMTEND	{dwgen($2); $$=$2; }
		|	VAR ID ASSGN expr STMTEND	{ dwgen($2); $2->token = ID2; $$=MakeOPTree(ASSGN, $2, $4); }
		|	BREAK STMTEND	{ $$=MakeNode(BREAK, BREAK); }
		|	CONTINUE STMTEND	{ $$=MakeNode(CONTINUE, CONTINUE); }
		|	IF expr THEN stmt %prec IFX	{ $$=MakeIFTree(IF, THEN, $2, $4); }
		|	IF expr THEN stmt ELSE stmt	{ $$=MakeIFELSETree(IF, THEN, ELSE, $2, $4, $6); }
		|	WHILE expr THEN stmt	{ $$=MakeWHILETree(WHILE, THEN, $2, $4); }
		|	'{' stmt_list '}'	{ $$=$2; }
		;

expr	: 	expr ADD expr	{ $$=MakeOPTree(ADD, $1, $3); }
		|	expr SUB expr	{ $$=MakeOPTree(SUB, $1, $3); }
		|	expr MUL expr	{ $$=MakeOPTree(MUL, $1, $3); }
		|	expr DIV expr	{ $$=MakeOPTree(DIV, $1, $3); }
		|	expr MOD expr	{ $$=MakeOPTree(MOD, $1, $3); }
		|	expr LT	expr	{ $$=MakeOPTree(LT, $1, $3); }
		|	expr GT	expr	{ $$=MakeOPTree(GT, $1, $3); }
		|	expr LE	expr	{ $$=MakeOPTree(LE, $1, $3); }
		|	expr GE	expr	{ $$=MakeOPTree(GE, $1, $3); }
		|	expr EQ expr	{ $$=MakeOPTree(EQ, $1, $3); }
		|	expr NE expr	{ $$=MakeOPTree(NE, $1, $3); }
		|	expr AND expr	{ $$=MakeOPTree(AND, $1, $3); }
		|	expr OR expr	{ $$=MakeOPTree(OR, $1, $3); }
		|	'(' expr ')'	{ $$=$2; }
		|	term { $$=$1; }
		;

term	:	ID		{ $$=$1; }
		|	NUM		{ $$=$1; }
		|	CHAR	{ $$=$1; }
		;


%%
int main(int argc, char *argv[]) 
{
	printf("\nsample CBU compiler v2.0\n");
	printf("(C) Copyright by Jae Sung Lee (jasonlee@cbnu.ac.kr), 2022.\n");
	
	if (argc == 2)
		yyin = fopen(argv[1], "r");
	else {
		printf("Usage: cbu2 inputfile\noutput file is 'a.asm'\n");
		return(0);
		}
		
	fp=fopen("a.asm", "w");
	
	yyparse();
	
	fclose(yyin);
	fclose(fp);

	if (errorcnt==0) 
		{ printf("Successfully compiled. Assembly code is in 'a.asm'.\n");}
}

yyerror(s)
char *s;
{
	printf("%s (line %d)\n", s, lineno);
}

Node * MakeOPTree(int op, Node* operand1, Node* operand2)
{
Node * newnode;
Node * mod2;

	newnode = (Node *)malloc(sizeof (Node));
	newnode->token = op;
	newnode->tokenval = op;
	newnode->son = operand1;
	newnode->brother = NULL;
	operand1->brother = operand2;
	if(op==MOD){
		mod2 = (Node *)malloc(sizeof (Node));
		mod2->token=MOD2;
		mod2->tokenval=MOD2;
		mod2->son = NULL;
		mod2->brother = operand1;
		newnode->son = mod2;
	}
	return newnode;
}

Node * MakeNode(int token, int operand)
{
Node * newnode;

	newnode = (Node *) malloc(sizeof (Node));
	newnode->token = token;
	newnode->tokenval = operand; 
	newnode->son = newnode->brother = NULL;
	return newnode;
}

Node * MakeListTree(Node* operand1, Node* operand2)
{
Node * newnode;
Node * node;

	if (operand1 == NULL){
		newnode = (Node *)malloc(sizeof (Node));
		newnode->token = newnode-> tokenval = STMTLIST;
		newnode->son = operand2;
		newnode->brother = NULL;
		return newnode;
		}
	else {
		node = operand1->son;
		while (node->brother != NULL) node = node->brother;
		node->brother = operand2;
		return operand1;
		}
}

Node * MakeIFTree(int op1, int op2, Node* operand1, Node* operand2)
{
Node * newnode;
Node * condition;
	newnode = (Node *)malloc(sizeof (Node));
	condition = (Node *)malloc(sizeof (Node));
	newnode->token = op1;
	newnode->tokenval = op1;
	newnode->son = operand1;
	newnode->brother = NULL;
	condition->token = op2;
	condition->tokenval = op2;
	condition->son = NULL;
	operand1->brother = condition;
	condition->brother = operand2;
	return newnode;
}

Node * MakeIFELSETree(int op1, int op2, int op3, Node* operand1, Node* operand2, Node* operand3)
{
Node * newnode;
Node * condition;
Node * newnode2;
	newnode = (Node *)malloc(sizeof (Node));
	condition = (Node *)malloc(sizeof (Node));
	newnode2 = (Node *)malloc(sizeof(Node));
	newnode->token = op1;
	newnode->tokenval = op1;
	newnode->son = operand1;
	newnode->brother = NULL;
	condition->token = op2;
	condition->tokenval = op2;
	condition->son = NULL;
	condition->brother = operand2;
	newnode2->token=op3;
	newnode2->token=op3;
	newnode2->son = NULL;
	newnode2->brother = operand3;
	operand1->brother = condition;
	operand2->brother = newnode2;
	
	return newnode;
}

Node * MakeWHILETree(int op1, int op2, Node* operand1, Node* operand2)
{
Node * newnode;
Node * condition;
Node * back;
	newnode = (Node *)malloc(sizeof (Node));
	condition = (Node *)malloc(sizeof (Node));
	back = (Node *)malloc(sizeof (Node));
	newnode->token = op1;
	newnode->tokenval = op1;
	newnode->son = back;
	newnode->brother = NULL;
	
	back->token = LOOP;
	back->tokenval = LOOP;
	back->son = NULL;
	back->brother = operand1;

	condition->token = op2;
	condition->tokenval = op2;
	condition->son = NULL;
	condition->brother = operand2;
	operand1->brother = condition;
	return newnode;
}

Node * MakeAATree(int op1, int op2, Node* operand1, Node* operand2){
Node * newnode;
Node * assgn;
Node * add;
	newnode = (Node *)malloc(sizeof (Node));
	assgn = (Node *)malloc(sizeof (Node));
	add = (Node *)malloc(sizeof (Node));
	assgn->token = ASSGN;
	assgn->tokenval = ASSGN;
	add->token = op2;
	add->tokenval = op2;
	newnode->token = op1;
	newnode->tokenval = op1;
	newnode->son = operand1;
	operand1->brother = operand2;
	newnode->brother = NULL;
	operand2->brother = add;
	add->brother = NULL;
	add->son = NULL;
	return newnode;
}

Node * MakeINPUTTree(int op1,int op2, Node * id){
Node * newnode;
Node * newnode2;
	newnode = (Node *)malloc(sizeof (Node));
	newnode->token = op1;
	newnode->tokenval = op1;
	newnode->brother = NULL;
	newnode2 = (Node *)malloc(sizeof (Node));
	newnode2->token = op2;
	newnode2->tokenval = op2;
	newnode2->son = NULL;
	newnode2->brother = NULL;
	newnode->son = id;
	id->brother=newnode2;
	return newnode;
}

void codegen(Node * root)
{
	DFSTree(root);
}

void DFSTree(Node * n)
{
	if (n==NULL) return;
	if (n->token == MOD) DFSTree(n->son);
	DFSTree(n->son);
	prtcode(n->token, n->tokenval, n);
	DFSTree(n->brother);
}

void prtcode(int token, int val, Node* n)
{
	switch (token) {
	case ID:
		fprintf(fp,"RVALUE %s\n", symtbl[val]);
		break;
	case ID2:
		fprintf(fp, "LVALUE %s\n", symtbl[val]);
		break;
	case ID3:
		fprintf(fp, "LVALUE %s\n", symtbl[val]);
		fprintf(fp, "RVALUE %s\n", symtbl[val]);
		break;
	case PRINTNUM:
		fprintf(fp, "OUTNUM\n");
		break;
	case PRINTCH:
		fprintf(fp, "OUTCH\n");
		break;
	case INPUT:
		fprintf(fp, "INNUM\n");
		break;
	case NUM:
		fprintf(fp, "PUSH %d\n", val);
		break;
	case CHAR:
		fprintf(fp, "PUSH %d\n" , symtbl[val][1]);
		break;
	case IF:
		fprintf(fp, "LABEL iflabel%d\n",iflabel);
		iflabel++;
		break;
	case THEN:
		fprintf(fp, "GOFALSE iflabel%d\n",iflabel);
		break;
	case ELSE:
		fprintf(fp, "GOTO iflabel%d\n", iflabel);
		fprintf(fp, "LABEL iflabel%d\n",iflabel);
		iflabel++;
		break;
	case WHILE:
		iflabel = iflabel - 1;
		fprintf(fp, "GOTO iflabel%d\n", iflabel);
		iflabel++;
		fprintf(fp, "LABEL iflabel%d\n",iflabel);
		iflabel++;
		break;
	case LOOP:
		fprintf(fp, "LABEL iflabel%d\n",iflabel);
		iflabel++;
		break;
	case CONTINUE:
		iflabel--;
		fprintf(fp, "GOTO iflabel%d\n",iflabel);
		iflabel++;
		break;
	case BREAK:
		fprintf(fp, "GOTO iflabel%d\n",iflabel);
		break;
	case ADD:
		fprintf(fp, "+\n");
		break;
	case SUB:
		fprintf(fp, "-\n");
		break;
	case MUL:
		fprintf(fp, "*\n");
		break;
	case DIV:
		fprintf(fp, "/\n");
		break;
	case MOD:
		fprintf(fp, "/\n");
		fprintf(fp, "*\n");
		fprintf(fp, "-\n");
		break;
	case AND:
		fprintf(fp, "GOFALSE Rlabel%d\n",Rlabel);
		fprintf(fp, "GOFALSE Rlabel%d\n",Rlabel);
		fprintf(fp, "PUSH 1\n");
		fprintf(fp, "GOTO Routlabel%d\n",Rlabel);
		fprintf(fp, "LABEL Rlabel%d\n",Rlabel);
		fprintf(fp, "PUSH 0\n");
		fprintf(fp, "LABEL Routlabel%d\n",Rlabel);
		Rlabel++;
		break;
	case OR:
		fprintf(fp, "GOTRUE Rlabel%d\n",Rlabel);
		fprintf(fp, "GOTRUE Rlabel%d\n",Rlabel);
		fprintf(fp, "PUSH 0\n");
		fprintf(fp, "GOTO Routlabel%d\n",Rlabel);
		fprintf(fp, "LABEL Rlabel%d\n",Rlabel);
		fprintf(fp, "PUSH 1\n");
		fprintf(fp, "LABEL Routlabel%d\n",Rlabel);
		Rlabel++;
		break;
	case LT:
		fprintf(fp, "-\n");
		fprintf(fp, "GOMINUS Rlabel%d\n",Rlabel);
		fprintf(fp, "PUSH 0\n");
		fprintf(fp, "GOTO Routlabel%d\n",Rlabel);
		fprintf(fp, "LABEL Rlabel%d\n",Rlabel);
		fprintf(fp, "PUSH 1\n");
		fprintf(fp, "LABEL Routlabel%d\n",Rlabel);
		Rlabel++;
		break;
	case GT:
		fprintf(fp, "-\n");
		fprintf(fp, "GOPLUS Rlabel%d\n",Rlabel);
		fprintf(fp, "PUSH 0\n");
		fprintf(fp, "GOTO Routlabel%d\n",Rlabel);
		fprintf(fp, "LABEL Rlabel%d\n",Rlabel);
		fprintf(fp, "PUSH 1\n");
		fprintf(fp, "LABEL Routlabel%d\n",Rlabel);
        Rlabel++;
		break;
	case LE:
		fprintf(fp, "-\n");
		fprintf(fp, "GOPLUS Rlabel%d\n",Rlabel);
		fprintf(fp, "PUSH 1\n");
		fprintf(fp, "GOTO Routlabel%d\n",Rlabel);
		fprintf(fp, "LABEL Rlabel%d\n",Rlabel);
		fprintf(fp, "PUSH 0\n");
		fprintf(fp, "LABEL Routlabel%d\n",Rlabel);
        Rlabel++;
		break;
	case GE:
		fprintf(fp, "-\n");
		fprintf(fp, "GOMINUS Rlabel%d\n",Rlabel);
		fprintf(fp, "PUSH 1\n");
		fprintf(fp, "GOTO Routlabel%d\n",Rlabel);
		fprintf(fp, "LABEL Rlabel%d\n",Rlabel);
		fprintf(fp, "PUSH 0\n");
		fprintf(fp, "LABEL Routlabel%d\n",Rlabel);
		Rlabel++;
		break;
	case EQ:
		fprintf(fp, "-\n");
		fprintf(fp, "GOTRUE Rlabel%d\n",Rlabel);
		fprintf(fp, "PUSH 1\n");
		fprintf(fp, "GOTO Routlabel%d\n",Rlabel);
		fprintf(fp, "LABEL Rlabel%d\n",Rlabel);
		fprintf(fp, "PUSH 0\n");
		fprintf(fp, "LABEL Routlabel%d\n",Rlabel);
		Rlabel++;
		break;
	case NE:
		fprintf(fp, "-\n");
		fprintf(fp, "GOFALSE Rlabel%d\n",Rlabel);
		fprintf(fp, "PUSH 1\n");
		fprintf(fp, "GOTO Routlabel%d\n",Rlabel);
		fprintf(fp, "LABEL Rlabel%d\n",Rlabel);
		fprintf(fp, "PUSH 0\n");
		fprintf(fp, "LABEL Routlabel%d\n",Rlabel);
		Rlabel++;
		break;
	case ASSGN:
		fprintf(fp, ":=\n");
        break;
	case ARRASSGN:
		fprintf(fp, ":=\n");
		break;
	case STMTLIST:
	default:
		break;
	};
}


/*
int gentemp()
{
char buffer[MAXTSYMLEN];
char tempsym[MAXSYMLEN]="TTCBU";

	tsymbolcnt++;
	if (tsymbolcnt > MAXTSYMBOL) printf("temp symbol overflow\n");
	itoa(tsymbolcnt, buffer, 10);
	strcat(tempsym, buffer);
	return( insertsym(tempsym) ); // Warning: duplicated symbol is not checked for lazy implementation
}
*/
void dwgen(Node * i)
{
// Warning: this code should be different if variable declaration is supported in the language 
	fprintf(fp, "DW %s\n", symtbl[i->tokenval]);
	
}

void finish()
{
	fprintf(fp, "HALT\n");
	fprintf(fp, "$ -- END OF EXECUTION CODE AND START OF VAR DEFINITIONS --\n");
	fprintf(fp, "END\n");
}
