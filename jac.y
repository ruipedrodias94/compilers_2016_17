%{
   #include <stdio.h>
   #include <string.h>
   #include "estruturas.h"
  int yylex(void);
  void yyerror(char *s);
  int erro=0;
  int syntax_flag = 0;

  Node* root = NULL ;
  Node* aux_node = NULL;


%}

%union{
    char* token;
    struct node* _node;
}


%token IF
%token AND
%token ASSIGN
%token <token> BOOL
%token CLASS
%token CCURV
%token CBRACE
%token CSQUARE
%token DIV
%token DO
%token DOTLENGTH
%token <token> DOUBLE
%token ELSE
%token EQ
%token GEQ
%token GT
%token <token> INT
%token LT
%token LEQ
%token MINUS
%token MOD
%token NEQ
%token NOT
%token OBRACE
%token OCURV
%token OR
%token OSQUARE
%token PARSEINT
%token PLUS
%token PRINT
%token PUBLIC
%token RESERVED
%token RETURN
%token SEMI
%token STAR
%token STATIC
%token WHILE
%token ESCAPESEQUENCE

%token <token> STRING
%token <token> COMMA
%token <token> BOOLLIT
%token <token> REALLIT
%token <token> DECLIT
%token <token> ID
%token <token> STRLIT
%token <token> VOID

%type <_node> Program ProgramCycle FieldDecl FieldDeclCycle MethodDecl MethodHeader MethodBody MethodBodyCycle FormalParams FormalParamsCycle VarDecl VarDeclCycle Type Statement StatementCycle Assignment MethodInvocation MethodInvocationCycle ParseArgs Expr

%right ASSIGN
%left OR
%left AND
%left EQ NEQ
%left LT LEQ GT GEQ
%left PLUS MINUS
%left STAR DIV MOD
%right NOT SIGN
%left OCURV CCURV OSQUARE CSQUARE
%nonassoc IF
%nonassoc ELSE

%%
  /*Given grammar in EBNF form*/

  /*Ciclos é 0 ou mais ocorrências e são representados por {}*/
  Program: CLASS ID OBRACE ProgramCycle CBRACE                                  {aux_node = createNode(type_Id,$2,NULL,$4);root = createNode(type_Program,NULL,aux_node,NULL);}
          ;
  ProgramCycle: ProgramCycle FieldDecl                                          {insertBrother($1,$2);$$=$1;}
              | ProgramCycle MethodDecl                                         {insertBrother($1,$2);$$=$1;}
              | ProgramCycle SEMI                                               {$$ = $1;}
              | %empty                                                          {$$ = createNode(type_Null,NULL,NULL,NULL);}
              ;


  FieldDecl: PUBLIC STATIC Type ID FieldDeclCycle SEMI                          {aux_node = createNode(type_FieldDecl,NULL,$5,NULL);insertBrother($5,createNode(type_Id,$4,NULL,$3)); $$ = aux_node;}
            | error SEMI                                                        {aux_node = createNode(type_Error,NULL,NULL,NULL);$$ = aux_node;}
            ;
  FieldDeclCycle: FieldDeclCycle COMMA ID                                       {aux_node = createNode(type_Id,$3,NULL,$1);$$=aux_node;}
                | %empty                                                        {$$ = createNode(type_Null,NULL,NULL,NULL);}
                ;

  MethodDecl: PUBLIC STATIC MethodHeader MethodBody                             {insertBrother($3,$4); $$ = createNode(type_MethodDecl,NULL,$3,NULL);}
            ;

  MethodHeader: Type ID OCURV FormalParams CCURV                                {aux_node = createNode(type_Id,$2,NULL,$1);insertBrother(aux_node,createNode(type_MethodParams,NULL,$4,NULL));$$ = createNode(type_MethodHeader,NULL,aux_node,NULL);}
              | Type ID OCURV CCURV                                             {aux_node = createNode(type_Id,$2,NULL,$1);$$ = createNode(type_MethodHeader,NULL,aux_node,NULL);}
              | VOID ID OCURV FormalParams CCURV                                {aux_node = createNode(type_Void,$1,NULL,createNode(type_Id,$2,NULL,createNode(type_MethodParams,NULL,$4,NULL)));$$ = createNode(type_MethodHeader,NULL,aux_node,NULL);}
              | VOID ID OCURV CCURV                                             {aux_node = createNode(type_Void,$1,NULL,createNode(type_Id,$2,NULL,NULL));$$ = createNode(type_MethodHeader,NULL,aux_node,NULL);}
              ;

  MethodBody: OBRACE MethodBodyCycle CBRACE                                     {aux_node = createNode(type_MethodBody,NULL,$2,NULL);$$ = aux_node;}
            ;
  MethodBodyCycle: MethodBodyCycle VarDecl                                      {insertBrother($1,$2);$$ = $1;}
                  | MethodBodyCycle Statement                                   {insertBrother($1,$2);$$ = $1;}
                  | %empty                                                      {$$ = createNode(type_Null,NULL,NULL,NULL);}
                  ;

  FormalParams: Type ID FormalParamsCycle                                       {aux_node = createNode(type_Id,$2,NULL,$1);insertBrother(aux_node,$3); $$ = createNode(type_ParamDecl,NULL,aux_node,NULL);}
              | STRING OSQUARE CSQUARE ID                                       {aux_node = createNode(type_StringArray,$1,NULL,createNode(type_Id,$4,NULL,NULL)); $$ = createNode(type_ParamDecl,NULL,aux_node,NULL);}
              ;
  FormalParamsCycle: FormalParamsCycle COMMA Type ID                            {insertBrother($1,$3);aux_node = createNode(type_Id,$4,NULL,$1);$$ = aux_node;}
                    | %empty                                                    {$$ = createNode(type_Null,NULL,NULL,NULL);}
                    ;

  VarDecl: Type ID VarDeclCycle SEMI                                            {aux_node = createNode(type_Id,$2,NULL,$1);insertBrother(aux_node,$3);$$ = createNode(type_VarDecl,NULL,aux_node,NULL);}
          ;
  VarDeclCycle: VarDeclCycle COMMA ID                                           {aux_node = createNode(type_Id,$3,NULL,$1); $$ = aux_node;}
              | %empty                                                          {$$ = createNode(type_Null,NULL,NULL,NULL);}
              ;

  Type: BOOL                                                                    {$$ = createNode(type_Bool,$1,NULL,NULL);}
      | INT                                                                     {$$ = createNode(type_Int,$1,NULL,NULL);}
      | DOUBLE                                                                  {$$ = createNode(type_Double,$1,NULL,NULL);}
      ;

  Statement: OBRACE StatementCycle CBRACE                                       {;}
            | IF OCURV Expr CCURV Statement %prec IF                            {;}
            | IF OCURV Expr CCURV Statement ELSE Statement                      {;}
            | WHILE OCURV Expr CCURV Statement                                  {;}
            | DO Statement WHILE OCURV Expr CCURV SEMI                          {;}
            | PRINT OCURV Expr CCURV SEMI                                       {;}
            | PRINT OCURV STRLIT CCURV SEMI                                     {;}
            | SEMI                                                              {;}
            | Assignment SEMI                                                   {;}
            | MethodInvocation SEMI                                             {;}
            | ParseArgs SEMI                                                    {;}
            | RETURN SEMI                                                       {;}
            | RETURN Expr SEMI                                                  {;}
            | error SEMI                                                        {;}
            ;
 StatementCycle: StatementCycle Statement                                       {;}
              |%empty                                                           {;}
              ;

  Assignment: ID ASSIGN Expr                                                    {;}
            ;

  MethodInvocation: ID OCURV CCURV                                              {;}
                  | ID OCURV Expr MethodInvocationCycle CCURV                   {;}
                  | ID OCURV error CCURV                                        {;}
                  ;

  MethodInvocationCycle: MethodInvocationCycle COMMA Expr                       {;}
                      |%empty                                                   {;}
                      ;

  ParseArgs: PARSEINT OCURV ID OSQUARE Expr CSQUARE CCURV                       {;}
           | PARSEINT OCURV error CCURV                                         {;}
            ;

  Expr: Assignment                                                              {;}
      | MethodInvocation                                                        {;}
      | ParseArgs                                                               {;}
      | Expr AND Expr                                                           {;}
      | Expr OR Expr                                                            {;}
      | Expr EQ Expr                                                            {;}
      | Expr GEQ Expr                                                           {;}
      | Expr GT Expr                                                            {;}
      | Expr LEQ Expr                                                           {;}
      | Expr LT Expr                                                            {;}
      | Expr NEQ Expr                                                           {;}
      | Expr PLUS Expr                                                          {;}
      | Expr MINUS Expr                                                         {;}
      | Expr STAR Expr                                                          {;}
      | Expr DIV Expr                                                           {;}
      | Expr MOD Expr                                                           {;}
      | PLUS Expr %prec NOT                                                     {;}
      | MINUS Expr %prec NOT                                                    {;}
      | NOT Expr                                                                {;}
      | ID                                                                      {;}
      | ID DOTLENGTH                                                            {;}
      | BOOLLIT                                                                 {;}
      | DECLIT                                                                  {;}
      | REALLIT                                                                 {;}
      | OCURV error CCURV                                                       {;}
      ;

%%

int main(int argc, char** argv){
	if(argc>1){
		if(strcmp(argv[1],"-l")==0){
			erro = 1;
      syntax_flag = 0;
			yylex();
		}
		else
		{
      syntax_flag = 0;
			yylex();
		}
	}
	else{
   syntax_flag = 1;
   yyparse();
   printList(root,0);
	}
	return 0;
}
