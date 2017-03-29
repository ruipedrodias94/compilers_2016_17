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
  Node* aux_node2 = NULL;
  Node* aux_node3 = NULL;


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

%token STRING
%token COMMA
%token <token> BOOLLIT
%token <token> REALLIT
%token <token> DECLIT
%token <token> ID
%token <token> STRLIT
%token <token> VOID

%type <_node> Program ProgramCycle FieldDecl FieldDeclCycle MethodDecl MethodHeader MethodBody MethodBodyCycle FormalParams FormalParamsCycle VarDecl VarDeclCycle Type StatementCycle Assignment MethodInvocation MethodInvocationCycle ParseArgs Expr ExprAux Statement

%right ASSIGN
%left OR
%left AND
%left EQ NEQ
%left LT LEQ GT GEQ
%left PLUS MINUS
%left STAR DIV MOD
%right NOT SIGN
%left OCURV CCURV OSQUARE CSQUARE
%nonassoc IFX
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


  FieldDecl: PUBLIC STATIC FieldDeclCycle SEMI                                  {$$=$3;}
            | error SEMI                                                        {aux_node = createNode(type_Error,NULL,NULL,NULL);$$ = aux_node;}
            ;
  FieldDeclCycle: FieldDeclCycle COMMA ID                                       {aux_node = createNode(aux_node2->node_type,NULL,NULL,createNode(type_Id,$3,NULL,NULL)); insertBrother($1,createNode(type_FieldDecl,NULL,aux_node,NULL)); $$ = $1;}
                | Type ID                                                       {aux_node2 = $1;aux_node = createNode(type_Id,$2,NULL,NULL);insertBrother($1,aux_node); $$ = createNode(type_FieldDecl,NULL,$1,NULL);}
                ;

  MethodDecl: PUBLIC STATIC MethodHeader MethodBody                             {insertBrother($3,$4); $$ = createNode(type_MethodDecl,NULL,$3,NULL);}
            ;

  MethodHeader: Type ID OCURV FormalParams CCURV                                {aux_node = createNode(type_Id,$2,NULL,NULL);insertBrother($1,aux_node);insertBrother($1,createNode(type_MethodParams,NULL,$4,NULL));$$ = createNode(type_MethodHeader,NULL,$1,NULL);}
              | Type ID OCURV CCURV                                             {aux_node = createNode(type_Id,$2,NULL,NULL);insertBrother($1,aux_node);insertBrother($1,createNode(type_MethodParams,NULL,NULL,NULL));$$ = createNode(type_MethodHeader,NULL,$1,NULL);}
              | VOID ID OCURV FormalParams CCURV                                {aux_node = createNode(type_Void,$1,NULL,createNode(type_Id,$2,NULL,createNode(type_MethodParams,NULL,$4,NULL)));$$ = createNode(type_MethodHeader,NULL,aux_node,NULL);}
              | VOID ID OCURV CCURV                                             {aux_node = createNode(type_Void,$1,NULL,createNode(type_Id,$2,NULL,NULL));insertBrother(aux_node,createNode(type_MethodParams,NULL,NULL,NULL));$$ = createNode(type_MethodHeader,NULL,aux_node,NULL);}
              ;

  MethodBody: OBRACE MethodBodyCycle CBRACE                                     {aux_node = createNode(type_MethodBody,NULL,$2,NULL);$$ = aux_node;}
            ;
  MethodBodyCycle: MethodBodyCycle VarDecl                                      {insertBrother($1,$2);$$ = $1;}
                  | MethodBodyCycle Statement                                   {insertBrother($1,$2);$$ = $1;}
                  | %empty                                                      {$$ = createNode(type_Null,NULL,NULL,NULL);}
                  ;

  FormalParams: Type ID FormalParamsCycle                                       {aux_node = createNode(type_Id,$2,NULL,NULL);insertBrother($1,aux_node); $$ = createNode(type_ParamDecl,NULL,$1,$3);}
              | STRING OSQUARE CSQUARE ID                                       {aux_node = createNode(type_StringArray,NULL,NULL,createNode(type_Id,$4,NULL,NULL)); $$ = createNode(type_ParamDecl,NULL,aux_node,NULL);}
              ;
  FormalParamsCycle: FormalParamsCycle COMMA Type ID                            {aux_node = createNode(type_ParamDecl,NULL,$3,NULL);insertBrother($3,createNode(type_Id,$4,NULL,NULL));insertBrother($1,aux_node);$$ = $1;}
                    | %empty                                                    {$$ = createNode(type_Null,NULL,NULL,NULL);}
                    ;

  VarDecl: VarDeclCycle SEMI                                                    {$$ = $1;}
          ;

  VarDeclCycle: VarDeclCycle COMMA ID                                           {aux_node = createNode(aux_node2->node_type,NULL,NULL,createNode(type_Id,$3,NULL,NULL)); insertBrother($1,createNode(type_VarDecl,NULL,aux_node,NULL)); $$ = $1;}
              | Type ID                                                         {aux_node2 = $1;aux_node = createNode(type_Id,$2,NULL,NULL);insertBrother($1,aux_node); $$ = createNode(type_VarDecl,NULL,$1,NULL);}
              ;

  Type: BOOL                                                                    {$$ = createNode(type_Bool,$1,NULL,NULL);}
      | INT                                                                     {$$ = createNode(type_Int,$1,NULL,NULL);}
      | DOUBLE                                                                  {$$ = createNode(type_Double,$1,NULL,NULL);}
      ;

  Statement: OBRACE StatementCycle CBRACE                                       {if(checkBlock($2)==1){$$=createNode(type_Block,NULL,$2,NULL);}else{$$ = $2;}}
            | IF OCURV Expr CCURV Statement %prec IFX                           {if(checkBlock($5)==1){insertBrother($3,createNode(type_Block,NULL,$5,NULL));}else{insertBrother($3,$5);};$$ = createNode(type_If,NULL,$3,NULL);}
            | IF OCURV Expr CCURV Statement ELSE Statement                      {if(checkBlock($7)==1){aux_node = createNode(type_Block,NULL,$7,NULL);}else{aux_node = $7;} if(checkBlock($5)==1){aux_node3 = createNode(type_Block,NULL,$5,NULL);}else{aux_node3 = $5;};insertBrother(aux_node,aux_node3);insertBrother(aux_node3,$3); $$ = createNode(type_If,NULL,aux_node,NULL);}
            | WHILE OCURV Expr CCURV Statement                                  {if(checkBlock($5)==1){aux_node = createNode(type_Block,NULL,$5,NULL);}else{aux_node=$5;};insertBrother(aux_node,$3);$$ = createNode(type_While,NULL,aux_node,NULL);}
            | DO Statement WHILE OCURV Expr CCURV SEMI                          {if(checkBlock($2)==1){aux_node = createNode(type_Block,NULL,$2,NULL);}else{aux_node=$2;};insertBrother(aux_node,$5);$$ = createNode(type_DoWhile,NULL,aux_node,NULL);}
            | PRINT OCURV Expr CCURV SEMI                                       {$$ = createNode(type_Print,NULL,$3,NULL);}
            | PRINT OCURV STRLIT CCURV SEMI                                     {aux_node = createNode(type_StrLit,$3,NULL,NULL);$$ = createNode(type_Print,NULL,aux_node,NULL);}
            | SEMI                                                              {$$ = createNode(type_Null,NULL,NULL,NULL);}
            | Assignment SEMI                                                   {$$ = $1;}
            | MethodInvocation SEMI                                             {$$ = $1;}
            | ParseArgs SEMI                                                    {$$ = $1;}
            | RETURN SEMI                                                       {$$ = createNode(type_Return,NULL,NULL,NULL);}
            | RETURN Expr SEMI                                                  {$$ = createNode(type_Return,NULL,$2,NULL);}
            | error SEMI                                                        {$$ = createNode(type_Error,NULL,NULL,NULL);}
            ;

 StatementCycle: StatementCycle Statement                                       {if(checkBlock($2)==1){aux_node = createNode(type_Block,NULL,$2,NULL);}else{aux_node = $2;};insertBrother(aux_node,$1);$$ = aux_node;}
              |%empty                                                           {$$ = createNode(type_Null,NULL,NULL,NULL);}
              ;

  Assignment: ID ASSIGN Expr                                                    {aux_node = createNode(type_Id,$1,NULL,NULL);insertBrother(aux_node,$3);$$ = createNode(type_Assign,NULL,aux_node,NULL);}
            ;

  MethodInvocation: ID OCURV CCURV                                              {$$ = createNode(type_Null,NULL,NULL,NULL);}
                  | ID OCURV Expr MethodInvocationCycle CCURV                   {$$ = createNode(type_Null,NULL,NULL,NULL);}
                  | ID OCURV error CCURV                                        {$$ = createNode(type_Null,NULL,NULL,NULL);}
                  ;

  MethodInvocationCycle: MethodInvocationCycle COMMA Expr                       {$$ = createNode(type_Null,NULL,NULL,NULL);}
                      |%empty                                                   {$$ = createNode(type_Null,NULL,NULL,NULL);}
                      ;

  ParseArgs: PARSEINT OCURV ID OSQUARE Expr CSQUARE CCURV                       {aux_node = createNode(type_Id,$3,NULL,$5);$$ = createNode(type_ParseArgs,NULL,aux_node,NULL);}
           | PARSEINT OCURV error CCURV                                         {$$ = createNode(type_Error,NULL,NULL,NULL);}
            ;

  Expr: Assignment                                                              {$$ = $1;}
      | MethodInvocation                                                        {$$ = $1;}
      | ParseArgs                                                               {$$ = $1;}
      | Expr AND ExprAux                                                        {insertBrother($1, $3); aux_node = createNode(type_And, NULL, $1, NULL);  $$ = aux_node;}
      | Expr OR ExprAux                                                         {insertBrother($1, $3); aux_node = createNode(type_Or, NULL, $1, NULL);  $$ = aux_node;}
      | Expr EQ ExprAux                                                         {insertBrother($1, $3); aux_node = createNode(type_Eq, NULL, $1, NULL);  $$ = aux_node;}
      | Expr GEQ ExprAux                                                        {insertBrother($1, $3); aux_node = createNode(type_Geq, NULL, $1, NULL);  $$ = aux_node;}
      | Expr GT ExprAux                                                         {insertBrother($1, $3); aux_node = createNode(type_Gt, NULL, $1, NULL);  $$ = aux_node;}
      | Expr LT ExprAux                                                         {insertBrother($1, $3); aux_node = createNode(type_Lt, NULL, $1, NULL);  $$ = aux_node;}
      | Expr LEQ ExprAux                                                        {insertBrother($1, $3); aux_node = createNode(type_Leq, NULL, $1, NULL);  $$ = aux_node;}
      | Expr NEQ ExprAux                                                        {insertBrother($1, $3); aux_node = createNode(type_Neq, NULL, $1, NULL);  $$ = aux_node;}
      | Expr PLUS ExprAux                                                       {insertBrother($1, $3); aux_node = createNode(type_Add, NULL, $1, NULL);  $$ = aux_node;}
      | Expr MINUS ExprAux                                                      {insertBrother($1, $3); aux_node = createNode(type_Sub, NULL, $1, NULL);  $$ = aux_node;}
      | Expr STAR ExprAux                                                       {insertBrother($1, $3); aux_node = createNode(type_Mul, NULL, $1, NULL);  $$ = aux_node;}
      | Expr DIV ExprAux                                                        {insertBrother($1, $3); aux_node = createNode(type_Div, NULL, $1, NULL);  $$ = aux_node;}
      | Expr MOD ExprAux                                                        {insertBrother($1, $3); aux_node = createNode(type_Mod, NULL, $1, NULL);  $$ = aux_node;}
      | PLUS ExprAux %prec NOT                                                  {aux_node = createNode(type_Add, NULL, $2, NULL); $$ = aux_node;}
      | MINUS ExprAux %prec NOT                                                 {aux_node = createNode(type_Sub, NULL, $2, NULL); $$ = aux_node;}
      | NOT ExprAux                                                             {aux_node = createNode(type_Not, NULL, $2, NULL); $$ = aux_node;}
      | ID                                                                      {aux_node = createNode(type_Id, $1, NULL, NULL); $$ = aux_node;}
      | ID DOTLENGTH                                                            {aux_node = createNode(type_Id, $1, NULL, NULL); $$ = createNode(type_Length, NULL, aux_node, NULL);}
      | BOOLLIT                                                                 {aux_node = createNode(type_BoolLit, $1, NULL, NULL); $$ = aux_node;}
      | DECLIT                                                                  {aux_node = createNode(type_DecLit, $1, NULL, NULL); $$ = aux_node;}
      | REALLIT                                                                 {aux_node = createNode(type_RealLit, $1, NULL, NULL); $$ = aux_node;}
      | OCURV error CCURV                                                       {aux_node = createNode(type_Error, NULL, NULL, NULL); $$ = aux_node;}
      | OCURV Expr CCURV                                                        {$$ = $2;}
      ;

  ExprAux: MethodInvocation                                                     {$$ = $1;}
      | ParseArgs                                                               {$$ = $1;}
      | ExprAux AND ExprAux                                                     {insertBrother($1, $3); aux_node = createNode(type_And, NULL, $1, NULL);  $$ = aux_node;}
      | ExprAux OR ExprAux                                                      {insertBrother($1, $3); aux_node = createNode(type_Or, NULL, $1, NULL);  $$ = aux_node;}
      | ExprAux EQ ExprAux                                                      {insertBrother($1, $3); aux_node = createNode(type_Eq, NULL, $1, NULL);  $$ = aux_node;}
      | ExprAux GEQ ExprAux                                                     {insertBrother($1, $3); aux_node = createNode(type_Geq, NULL, $1, NULL);  $$ = aux_node;}
      | ExprAux GT ExprAux                                                      {insertBrother($1, $3); aux_node = createNode(type_Gt, NULL, $1, NULL);  $$ = aux_node;}
      | ExprAux LEQ ExprAux                                                     {insertBrother($1, $3); aux_node = createNode(type_Lt, NULL, $1, NULL);  $$ = aux_node;}
      | ExprAux LT ExprAux                                                      {insertBrother($1, $3); aux_node = createNode(type_Leq, NULL, $1, NULL);  $$ = aux_node;}
      | ExprAux NEQ ExprAux                                                     {insertBrother($1, $3); aux_node = createNode(type_Neq, NULL, $1, NULL);  $$ = aux_node;}
      | ExprAux PLUS ExprAux                                                    {insertBrother($1, $3); aux_node = createNode(type_Add, NULL, $1, NULL);  $$ = aux_node;}
      | ExprAux MINUS ExprAux                                                   {insertBrother($1, $3); aux_node = createNode(type_Sub, NULL, $1, NULL);  $$ = aux_node;}
      | ExprAux STAR ExprAux                                                    {insertBrother($1, $3); aux_node = createNode(type_Mul, NULL, $1, NULL);  $$ = aux_node;}
      | ExprAux DIV ExprAux                                                     {insertBrother($1, $3); aux_node = createNode(type_Div, NULL, $1, NULL);  $$ = aux_node;}
      | ExprAux MOD ExprAux                                                     {insertBrother($1, $3); aux_node = createNode(type_Mod, NULL, $1, NULL);  $$ = aux_node;}
      | PLUS ExprAux %prec NOT                                                  {aux_node = createNode(type_Add, NULL, $2, NULL); $$ = aux_node;}
      | MINUS ExprAux %prec NOT                                                 {aux_node = createNode(type_Sub, NULL, $2, NULL); $$ = aux_node;}
      | NOT ExprAux                                                             {aux_node = createNode(type_Not, NULL, $2, NULL); $$ = aux_node;}
      | ID                                                                      {aux_node = createNode(type_Id, $1, NULL, NULL); $$ = aux_node;}
      | ID DOTLENGTH                                                            {aux_node = createNode(type_Id, $1, NULL, NULL); $$ = createNode(type_Length, NULL, aux_node, NULL);}
      | BOOLLIT                                                                 {aux_node = createNode(type_BoolLit, $1, NULL, NULL); $$ = aux_node;}
      | DECLIT                                                                  {aux_node = createNode(type_DecLit, $1, NULL, NULL); $$ = aux_node;}
      | REALLIT                                                                 {aux_node = createNode(type_RealLit, $1, NULL, NULL); $$ = aux_node;}
      | OCURV error CCURV                                                       {aux_node = createNode(type_Error, NULL, NULL, NULL); $$ = aux_node;}
      | OCURV ExprAux CCURV                                                     {$$ = $2;}
      ;

%%

int main(int argc, char** argv){
	if(argc>1){
		if(strcmp(argv[1],"-l")==0){
			erro = 1;
      syntax_flag = 0;
			yylex();
		}
    else if(strcmp(argv[1],"-t")==0){
    syntax_flag = 1;
    yyparse();
    printList(root,0);
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
	}
	return 0;
}
