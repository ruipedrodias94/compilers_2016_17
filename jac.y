%{
  #include <stdio.h>
  int yylex(void);
  int yyerror(const char *s);

%}

%token IF
%token AND
%token ASSIGN
%token BOOL
%token CLASS
%token CCURV
%token CBRACE
%token COMMA
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
%token STRING
%token VOID
%token WHILE
%token BOOLIT
%token REALLIT
%token DECLIT
%token ID
%token STRLIT
%token LINETERMINATOR

%%
  /*Expressions here*/
  
%%

int main()
  while (yyparse()==0);
      return 0;
