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

%type <_node> Program ProgramCycle FieldDecl FieldDeclCycle MethodDecl MethodHeader MethodBody MethodBodyCycle FormalParams FormalParamsCycle VarDecl VarDeclCycle Type Statement StatementCycle Assignment MethodInvocation MethodInvocationCycle ParseArgs Expr ExprAux

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
              | STRING OSQUARE CSQUARE ID                                       {aux_node = createNode(type_StringArray,$1,NULL,createNode(type_Id,$4,NULL,NULL)); $$ = createNode(type_ParamDecl,NULL,aux_node,NULL);}
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

  Statement: OBRACE StatementCycle CBRACE                                       {$$ = createNode(type_Null,NULL,NULL,NULL);}
            | IF OCURV Expr CCURV Statement %prec IFX                           {$$ = createNode(type_Null,NULL,NULL,NULL);}
            | IF OCURV Expr CCURV Statement ELSE Statement                      {$$ = createNode(type_Null,NULL,NULL,NULL);}
            | WHILE OCURV Expr CCURV Statement                                  {$$ = createNode(type_Null,NULL,NULL,NULL);}
            | DO Statement WHILE OCURV Expr CCURV SEMI                          {$$ = createNode(type_Null,NULL,NULL,NULL);}
            | PRINT OCURV Expr CCURV SEMI                                       {$$ = createNode(type_Null,NULL,NULL,NULL);}
            | PRINT OCURV STRLIT CCURV SEMI                                     {$$ = createNode(type_Null,NULL,NULL,NULL);}
            | SEMI                                                              {$$ = createNode(type_Null,NULL,NULL,NULL);}
            | Assignment SEMI                                                   {$$ = createNode(type_Null,NULL,NULL,NULL);}
            | MethodInvocation SEMI                                             {$$ = createNode(type_Null,NULL,NULL,NULL);}
            | ParseArgs SEMI                                                    {$$ = createNode(type_Null,NULL,NULL,NULL);}
            | RETURN SEMI                                                       {$$ = createNode(type_Null,NULL,NULL,NULL);}
            | RETURN Expr SEMI                                                  {$$ = createNode(type_Null,NULL,NULL,NULL);}
            | error SEMI                                                        {$$ = createNode(type_Null,NULL,NULL,NULL);}
            ;

 StatementCycle: StatementCycle Statement                                       {$$ = createNode(type_Null,NULL,NULL,NULL);}
              |%empty                                                           {$$ = createNode(type_Null,NULL,NULL,NULL);}
              ;

  Assignment: ID ASSIGN Expr                                                    {$$ = createNode(type_Null,NULL,NULL,NULL);}
            ;

  MethodInvocation: ID OCURV CCURV                                              {$$ = createNode(type_Null,NULL,NULL,NULL);}
                  | ID OCURV Expr MethodInvocationCycle CCURV                   {$$ = createNode(type_Null,NULL,NULL,NULL);}
                  | ID OCURV error CCURV                                        {$$ = createNode(type_Null,NULL,NULL,NULL);}
                  ;

  MethodInvocationCycle: MethodInvocationCycle COMMA Expr                       {$$ = createNode(type_Null,NULL,NULL,NULL);}
                      |%empty                                                   {$$ = createNode(type_Null,NULL,NULL,NULL);}
                      ;

  ParseArgs: PARSEINT OCURV ID OSQUARE Expr CSQUARE CCURV                       {$$ = createNode(type_Null,NULL,NULL,NULL);}
           | PARSEINT OCURV error CCURV                                         {$$ = createNode(type_Null,NULL,NULL,NULL);}
            ;

  Expr: Assignment                                                              {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | MethodInvocation                                                        {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | ParseArgs                                                               {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | Expr AND ExprAux                                                             {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | Expr OR ExprAux                                                              {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | Expr EQ ExprAux                                                              {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | Expr GEQ ExprAux                                                             {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | Expr GT ExprAux                                                              {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | Expr LEQ ExprAux                                                             {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | Expr LT ExprAux                                                              {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | Expr NEQ ExprAux                                                             {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | Expr PLUS ExprAux                                                            {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | Expr MINUS ExprAux                                                           {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | Expr STAR ExprAux                                                            {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | Expr DIV ExprAux                                                             {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | Expr MOD ExprAux                                                             {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | PLUS ExprAux %prec NOT                                                     {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | MINUS ExprAux %prec NOT                                                    {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | NOT ExprAux                                                                {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | ID                                                                      {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | ID DOTLENGTH                                                            {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | BOOLLIT                                                                 {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | DECLIT                                                                  {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | REALLIT                                                                 {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | OCURV error CCURV                                                       {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | OCURV Expr CCURV                                                        {$$ = createNode(type_Null,NULL,NULL,NULL);}
      ;

  ExprAux: MethodInvocation                                                        {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | ParseArgs                                                               {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | ExprAux AND ExprAux                                                           {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | ExprAux OR ExprAux                                                            {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | ExprAux EQ ExprAux                                                            {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | ExprAux GEQ ExprAux                                                           {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | ExprAux GT ExprAux                                                            {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | ExprAux LEQ ExprAux                                                           {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | ExprAux LT ExprAux                                                            {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | ExprAux NEQ ExprAux                                                           {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | ExprAux PLUS ExprAux                                                          {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | ExprAux MINUS ExprAux                                                         {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | ExprAux STAR ExprAux                                                          {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | ExprAux DIV ExprAux                                                           {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | ExprAux MOD ExprAux                                                           {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | PLUS ExprAux %prec NOT                                                     {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | MINUS ExprAux %prec NOT                                                    {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | NOT ExprAux                                                                {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | ID                                                                      {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | ID DOTLENGTH                                                            {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | BOOLLIT                                                                 {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | DECLIT                                                                  {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | REALLIT                                                                 {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | OCURV error CCURV                                                       {$$ = createNode(type_Null,NULL,NULL,NULL);}
      | OCURV ExprAux CCURV                                                     {$$ = createNode(type_Null,NULL,NULL,NULL);}
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
