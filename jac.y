%{
   #include <stdio.h>
   #include <string.h>
   #include "estruturas.h"
   #include "semantics.h"
   #include "sym_tab.h"


  int yylex(void);
  void yyerror(char *s);
  int erro=0;
  int syntax_flag = 0;
  extern int flag_error;

  Node* root = NULL ;
  Node* aux_node = NULL;
  Node* aux_node2 = NULL;
  Node* aux_node3 = NULL;
  Node* aux_node4 = NULL;



%}

%union{
    char* token;
    struct node* _node;
}


%token IF
%token AND
%token ASSIGN
%token BOOL
%token CLASS
%token CCURV
%token CBRACE
%token CSQUARE
%token DIV
%token DO
%token DOTLENGTH
%token DOUBLE
%token ELSE
%token EQ
%token GEQ
%token GT
%token INT
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
%token VOID

%type <_node> Program ProgramCycle FieldDecl FieldDeclCycle MethodDecl MethodHeader MethodBody MethodBodyCycle FormalParams FormalParamsCycle VarDecl VarDeclCycle Type StatementCycle Assignment MethodInvocation MethodInvocationCycle ParseArgs Expr ExprAux Statement

%start Program
%right ASSIGN
%left OR
%left AND
%left EQ NEQ
%left LT LEQ GT GEQ
%left PLUS MINUS
%left STAR DIV MOD
%right NOT
%right PRECEDENCE
%left OBRACE OCURV CCURV OSQUARE CSQUARE CBRACE
%nonassoc IFX
%nonassoc ELSE

%%
  /*Given grammar in EBNF form*/

  /*Ciclos é 0 ou mais ocorrências e são representados por {}*/
  Program: CLASS ID OBRACE ProgramCycle CBRACE                                  {if(flag_error == 0) {aux_node = createNode(type_Id,$2,NULL,$4);free($2);root = createNode(type_Program,NULL,aux_node,NULL);}}
          ;
  ProgramCycle: ProgramCycle FieldDecl                                          {if(flag_error == 0) {insertBrother($1,$2);$$=$1;}}
              | ProgramCycle MethodDecl                                         {if(flag_error == 0) {insertBrother($1,$2);$$=$1;}}
              | ProgramCycle SEMI                                               {if(flag_error == 0) {$$ = $1;}}
              | %empty                                                          {if(flag_error == 0) {$$ = createNode(type_Null,NULL,NULL,NULL);}}
              ;


  FieldDecl: PUBLIC STATIC FieldDeclCycle SEMI                                  {if(flag_error == 0) {$$=$3;}}
            | error SEMI                                                        {if(flag_error == 0) {aux_node = createNode(type_Error,NULL,NULL,NULL);$$ = aux_node;}}
            ;
  FieldDeclCycle: FieldDeclCycle COMMA ID                                       {if(flag_error == 0) {aux_node = createNode(aux_node2->node_type,NULL,NULL,createNode(type_Id,$3,NULL,NULL));free($3);insertBrother($1,createNode(type_FieldDecl,NULL,aux_node,NULL)); $$ = $1;}}
                | Type ID                                                       {if(flag_error == 0) {aux_node2 = $1;aux_node = createNode(type_Id,$2,NULL,NULL);insertBrother($1,aux_node);free($2);$$ = createNode(type_FieldDecl,NULL,$1,NULL);}}
                ;

  MethodDecl: PUBLIC STATIC MethodHeader MethodBody                             {if(flag_error == 0) {insertBrother($3,$4); $$ = createNode(type_MethodDecl,NULL,$3,NULL);}}
            ;

  MethodHeader: Type ID OCURV FormalParams CCURV                                {if(flag_error == 0) {aux_node = createNode(type_Id,$2,NULL,NULL);free($2);insertBrother($1,aux_node);insertBrother($1,createNode(type_MethodParams,NULL,$4,NULL));$$ = createNode(type_MethodHeader,NULL,$1,NULL);}}
              | Type ID OCURV CCURV                                             {if(flag_error == 0) {aux_node = createNode(type_Id,$2,NULL,NULL);free($2);insertBrother($1,aux_node);insertBrother($1,createNode(type_MethodParams,NULL,NULL,NULL));$$ = createNode(type_MethodHeader,NULL,$1,NULL);}}
              | VOID ID OCURV FormalParams CCURV                                {if(flag_error == 0) {aux_node = createNode(type_Void,NULL,NULL,createNode(type_Id,$2,NULL,createNode(type_MethodParams,NULL,$4,NULL)));free($2);$$ = createNode(type_MethodHeader,NULL,aux_node,NULL);}}
              | VOID ID OCURV CCURV                                             {if(flag_error == 0) {aux_node = createNode(type_Void,NULL,NULL,createNode(type_Id,$2,NULL,NULL));insertBrother(aux_node,createNode(type_MethodParams,NULL,NULL,NULL));free($2);$$ = createNode(type_MethodHeader,NULL,aux_node,NULL);}}
              ;

  MethodBody: OBRACE MethodBodyCycle CBRACE                                     {if(flag_error == 0) {aux_node = createNode(type_MethodBody,NULL,$2,NULL);$$ = aux_node;}}
            ;
  MethodBodyCycle: MethodBodyCycle VarDecl                                      {if(flag_error == 0) {insertBrother($1,$2);$$ = $1;}}
                  | MethodBodyCycle Statement                                   {if(flag_error == 0) { if(checkBlock($2)>=2){aux_node = createNode(type_Block,NULL,$2,NULL);}else{aux_node = $2;}insertBrother($1,aux_node);$$ = $1;}}
                  | %empty                                                      {if(flag_error == 0) {$$ = createNode(type_Null,NULL,NULL,NULL);}}
                  ;

  FormalParams: Type ID FormalParamsCycle                                       {if(flag_error == 0) {aux_node = createNode(type_Id,$2,NULL,NULL);free($2);insertBrother($1,aux_node); $$ = createNode(type_ParamDecl,NULL,$1,$3);}}
              | STRING OSQUARE CSQUARE ID                                       {if(flag_error == 0) {aux_node = createNode(type_StringArray,NULL,NULL,createNode(type_Id,$4,NULL,NULL));free($4); $$ = createNode(type_ParamDecl,NULL,aux_node,NULL);}}
              ;
  FormalParamsCycle: FormalParamsCycle COMMA Type ID                            {if(flag_error == 0) {aux_node = createNode(type_ParamDecl,NULL,$3,NULL);insertBrother($3,createNode(type_Id,$4,NULL,NULL));free($4);insertBrother($1,aux_node);$$ = $1;}}
                    | %empty                                                    {if(flag_error == 0) {$$ = createNode(type_Null,NULL,NULL,NULL);}}
                    ;

  VarDecl: VarDeclCycle SEMI                                                    {if(flag_error == 0) {$$ = $1;}}
          ;

  VarDeclCycle: VarDeclCycle COMMA ID                                           {if(flag_error == 0) {aux_node = createNode(aux_node2->node_type,NULL,NULL,createNode(type_Id,$3,NULL,NULL));free($3);insertBrother($1,createNode(type_VarDecl,NULL,aux_node,NULL)); $$ = $1;}}
              | Type ID                                                         {if(flag_error == 0) {aux_node2 = $1;aux_node = createNode(type_Id,$2,NULL,NULL);free($2);insertBrother($1,aux_node); $$ = createNode(type_VarDecl,NULL,$1,NULL);}}
              ;

  Type: BOOL                                                                    {if(flag_error == 0) {$$ = createNode(type_Bool,NULL,NULL,NULL);}}
      | INT                                                                     {if(flag_error == 0) {$$ = createNode(type_Int,NULL,NULL,NULL);}}
      | DOUBLE                                                                  {if(flag_error == 0) {$$ = createNode(type_Double,NULL,NULL,NULL);}}
      ;

      Statement: OBRACE StatementCycle CBRACE                                       {if(flag_error == 0) {$$ = $2;}}
                 | IF OCURV Expr CCURV Statement %prec IFX                           {if(flag_error == 0) {aux_node = createNode(type_Block,NULL,NULL,NULL);if(checkBlock($5)>=2){aux_node3 = createNode(type_Block,NULL,$5,NULL);}else if(checkBlock($5)==0){aux_node3 = createNode(type_Block,NULL,NULL,NULL);}else{aux_node3 = $5;};insertBrother(aux_node3,aux_node);insertBrother($3,aux_node3);$$ = createNode(type_If,NULL,$3,NULL);}}
                 | IF OCURV Expr CCURV Statement ELSE Statement                      {if(flag_error == 0) {if(checkBlock($7)>=2){aux_node3 = createNode(type_Block,NULL,$7,NULL);}else if(checkBlock($7)==0){aux_node3 = createNode(type_Block,NULL,NULL,NULL);}else{aux_node3 = $7;}if(checkBlock($5)>=2){aux_node = createNode(type_Block,NULL,$5,NULL);}else if(checkBlock($5)==0){aux_node = createNode(type_Block,NULL,NULL,NULL);}else{aux_node = $5;} insertBrother(aux_node,aux_node3);insertBrother($3,aux_node);$$ = createNode(type_If,NULL,$3,NULL);}}
                 | WHILE OCURV Expr CCURV Statement                                  {if(flag_error == 0) {if(checkBlock($5)>=2){aux_node = createNode(type_Block,NULL,$5,NULL);}else if(checkBlock($5)==0){aux_node = createNode(type_Block,NULL,NULL,NULL);}else{aux_node = $5;};insertBrother($3,aux_node);$$ = createNode(type_While,NULL,$3,NULL);}}
                 | DO Statement WHILE OCURV Expr CCURV SEMI                          {if(flag_error == 0) {if(checkBlock($2)>=2){aux_node = createNode(type_Block,NULL,$2,NULL);}else if(checkBlock($2)==0){aux_node = createNode(type_Block,NULL,NULL,NULL);}else{aux_node=$2;};insertBrother(aux_node,$5);$$ = createNode(type_DoWhile,NULL,aux_node,NULL);}}
                 | PRINT OCURV Expr CCURV SEMI                                       {if(flag_error == 0) {$$ = createNode(type_Print,NULL,$3,NULL);}}
                 | PRINT OCURV STRLIT CCURV SEMI                                     {if(flag_error == 0) {aux_node = createNode(type_StrLit,$3,NULL,NULL);$$ = createNode(type_Print,NULL,aux_node,NULL);}}
                 | SEMI                                                              {if(flag_error == 0) {$$ = createNode(type_Null,NULL,NULL,NULL);}}
                 | Assignment SEMI                                                   {if(flag_error == 0) {$$ = $1;}}
                 | MethodInvocation SEMI                                             {if(flag_error == 0) {$$ = $1;}}
                 | ParseArgs SEMI                                                    {if(flag_error == 0) {$$ = $1;}}
                 | RETURN SEMI                                                       {if(flag_error == 0) {$$ = createNode(type_Return,NULL,NULL,NULL);}}
                 | RETURN Expr SEMI                                                  {if(flag_error == 0) {$$ = createNode(type_Return,NULL,$2,NULL);}}
                 | error SEMI                                                        {if(flag_error == 0) {$$ = createNode(type_Error,NULL,NULL,NULL);}}
                  ;
 StatementCycle: StatementCycle Statement                                       {if(flag_error == 0) {insertBrother($1,$2);$$ = $1;}}
              |%empty                                                           {if(flag_error == 0) {$$ = createNode(type_Null,NULL,NULL,NULL);}}
              ;

  Assignment: ID ASSIGN Expr                                                    {if(flag_error == 0) {aux_node = createNode(type_Id,$1,NULL,NULL);free($1);insertBrother(aux_node,$3);$$ = createNode(type_Assign,NULL,aux_node,NULL);}}
            ;

  MethodInvocation: ID OCURV CCURV                                              {if(flag_error == 0) {aux_node = createNode(type_Id,$1,NULL,NULL);free($1);$$ = createNode(type_Call,NULL,aux_node,NULL);}}
                  | ID OCURV Expr MethodInvocationCycle CCURV                   {if(flag_error == 0) {aux_node = createNode(type_Id,$1,NULL,NULL);free($1);insertBrother(aux_node, $3); insertBrother($3, $4); $$ = createNode(type_Call, NULL, aux_node, NULL);}}
                  | ID OCURV error CCURV                                        {free($1);if(flag_error == 0) {$$ = createNode(type_Error,NULL,NULL,NULL);}}
                  ;

  MethodInvocationCycle: MethodInvocationCycle COMMA Expr                       {if(flag_error == 0) {insertBrother($1,$3); $$ = $1;}}
                      |%empty                                                   {if(flag_error == 0) {$$ = createNode(type_Null,NULL,NULL,NULL);}}
                      ;

  ParseArgs: PARSEINT OCURV ID OSQUARE Expr CSQUARE CCURV                       {if(flag_error == 0) {aux_node = createNode(type_Id,$3,NULL,NULL);free($3);insertBrother(aux_node,$5);$$ = createNode(type_ParseArgs,NULL,aux_node,NULL);}}
           | PARSEINT OCURV error CCURV                                         {if(flag_error == 0) {$$ = createNode(type_Error,NULL,NULL,NULL);}}
            ;

  Expr: Assignment                                                              {if(flag_error == 0) {$$ = $1;}}
      | ExprAux                                                                 {if(flag_error == 0) {$$ = $1;}}
      ;

  ExprAux: MethodInvocation                                                     {if(flag_error == 0) {$$ = $1;}}
      | ParseArgs                                                               {if(flag_error == 0) {$$ = $1;}}
      | ExprAux AND ExprAux                                                     {if(flag_error == 0) {insertBrother($1, $3); aux_node = createNode(type_And, NULL, $1, NULL);  $$ = aux_node;}}
      | ExprAux OR ExprAux                                                      {if(flag_error == 0) {insertBrother($1, $3); aux_node = createNode(type_Or, NULL, $1, NULL);  $$ = aux_node;}}
      | ExprAux EQ ExprAux                                                      {if(flag_error == 0) {insertBrother($1, $3); aux_node = createNode(type_Eq, NULL, $1, NULL);  $$ = aux_node;}}
      | ExprAux GEQ ExprAux                                                     {if(flag_error == 0) {insertBrother($1, $3); aux_node = createNode(type_Geq, NULL, $1, NULL);  $$ = aux_node;}}
      | ExprAux GT ExprAux                                                      {if(flag_error == 0) {insertBrother($1, $3); aux_node = createNode(type_Gt, NULL, $1, NULL);  $$ = aux_node;}}
      | ExprAux LEQ ExprAux                                                     {if(flag_error == 0) {insertBrother($1, $3); aux_node = createNode(type_Leq, NULL, $1, NULL);  $$ = aux_node;}}
      | ExprAux LT ExprAux                                                      {if(flag_error == 0) {insertBrother($1, $3); aux_node = createNode(type_Lt, NULL, $1, NULL);  $$ = aux_node;}}
      | ExprAux NEQ ExprAux                                                     {if(flag_error == 0) {insertBrother($1, $3); aux_node = createNode(type_Neq, NULL, $1, NULL);  $$ = aux_node;}}
      | ExprAux PLUS ExprAux                                                    {if(flag_error == 0) {insertBrother($1, $3); aux_node = createNode(type_Add, NULL, $1, NULL);  $$ = aux_node;}}
      | ExprAux MINUS ExprAux                                                   {if(flag_error == 0) {insertBrother($1, $3); aux_node = createNode(type_Sub, NULL, $1, NULL);  $$ = aux_node;}}
      | ExprAux STAR ExprAux                                                    {if(flag_error == 0) {insertBrother($1, $3); aux_node = createNode(type_Mul, NULL, $1, NULL);  $$ = aux_node;}}
      | ExprAux DIV ExprAux                                                     {if(flag_error == 0) {insertBrother($1, $3); aux_node = createNode(type_Div, NULL, $1, NULL);  $$ = aux_node;}}
      | ExprAux MOD ExprAux                                                     {if(flag_error == 0) {insertBrother($1, $3); aux_node = createNode(type_Mod, NULL, $1, NULL);  $$ = aux_node;}}
      | PLUS ExprAux %prec PRECEDENCE                                                  {if(flag_error == 0) {aux_node = createNode(type_Plus, NULL, $2, NULL); $$ = aux_node;}}
      | MINUS ExprAux %prec PRECEDENCE                                                 {if(flag_error == 0) {aux_node = createNode(type_Minus, NULL, $2, NULL); $$ = aux_node;}}
      | NOT ExprAux   %prec PRECEDENCE                                                 {if(flag_error == 0) {aux_node = createNode(type_Not, NULL, $2, NULL); $$ = aux_node;}}
      | ID                                                                      {if(flag_error == 0) {aux_node = createNode(type_Id, $1, NULL, NULL);free($1);$$ = aux_node;}}
      | ID DOTLENGTH                                                            {if(flag_error == 0) {aux_node = createNode(type_Id, $1, NULL, NULL);free($1); $$ = createNode(type_Length, NULL, aux_node, NULL);}}
      | OCURV Expr CCURV                                                        {if(flag_error == 0) {$$ = $2;}}
      | BOOLLIT                                                                 {if(flag_error == 0) {aux_node = createNode(type_BoolLit, $1, NULL, NULL); $$ = aux_node;}}
      | DECLIT                                                                  {if(flag_error == 0) {aux_node = createNode(type_DecLit, $1, NULL, NULL); $$ = aux_node;}}
      | REALLIT                                                                 {if(flag_error == 0) {aux_node = createNode(type_RealLit, $1, NULL, NULL); $$ = aux_node;}}
      | OCURV error CCURV                                                       {if(flag_error == 0) {aux_node = createNode(type_Error, NULL, NULL, NULL); $$ = aux_node;}}
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
      if(flag_error == 0){
        printList(root,0);
      }

    free_tree(root);

  }else if(strcmp(argv[1],"-s")==0){
      syntax_flag = 1;
      yyparse();

      check_ast_to_table(root);

      if(flag_error == 0){
        //printList(root,0);
      }

    free_tree(root);

    } else if(strcmp(argv[1],"-2")==0){
      syntax_flag = 1;
      yyparse();
      free_tree(root);
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
      free_tree(root);
	}
	return 0;
}
