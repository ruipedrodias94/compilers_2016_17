%{
	int line=1, col=1, auxLine=0, auxCol=0, erro=0;

%}

NUMBER				[0-9]
CHARACTER     [a-zA-Z]

ID             {CHARACTER}({CHARACTER}|{NUMBER}|"$"|"_")*
DECLIT         {NUMBER}+
BOOL           boolean
BOOLIT         true|false
CLASS          class
DO             do
DOTLENGTH      .length
DOUBLE         double
ELSE           else
IF             if
INT            int
PARSEINT       Integer.parseInt
PRINT          System.out.println
PUBLIC         public
RETURN         return
STATIC         static
STRING         string
VOID           void
WHILE          while
OCURV          "("
CCURV          ")"
OBRACE         "{"
CBRACE         "}"
OSQUARE        "["
CSQUARE        "]"
AND            "&&"
OR             "||"
LT             "<"
GT             ">"
EQ             "=="
NEQ            "!="
LEQ            "<="
GEQ            ">="
PLUS           "+"
MINUS          "-"
STAR           "*"
DIV            "/"
MOD            "%"
NOT            "!"
ASSIGN         "="
SEMI           ";"
COMMA          ","
RESERVED       null|"++"|"--"

%%

{IF}		{if(erro == 1){printf("IF\n");}			col+=yyleng;}
{AND}		{if(erro == 1){printf("AND\n");}					col+=yyleng;}
{ASSIGN}		{if(erro == 1){printf("ASSIGN\n");}					col+=yyleng;}
{BOOL}		{if(erro == 1){printf("BOOL\n");} 			col+=yyleng;}
{CLASS}		{if(erro == 1){printf("CLASS\n");}			col+=yyleng;}
{CCURV}		{if(erro == 1){printf("CCURV\n");}					col+=yyleng;}
{CBRACE}		{if(erro == 1){printf("CBRACE\n");}					col+=yyleng;}
{COMMA}		{if(erro == 1){printf("COMMA\n");}					col+=yyleng;}
{CSQUARE}		{if(erro == 1){printf("CSQUARE\n");}					col+=yyleng;}
{DECLIT}		{if(erro == 1){printf("DECLIT\n");}			col+=yyleng;}
{DIV}		{if(erro == 1){printf("DIV\n");}					col+=yyleng;}
{DO}		{if(erro == 1){printf("DO\n");}			col+=yyleng;}
{DOTLENGTH}		{if(erro == 1){printf("DOTLENGTH\n");}			col+=yyleng;}
{DOUBLE}		{if(erro == 1){printf("DOUBLE\n");}			col+=yyleng;}
{ELSE}		{if(erro == 1){printf("ELSE\n");}			col+=yyleng;}
{EQ}		{if(erro == 1){printf("EQ\n");}					col+=yyleng;}
{GEQ}		{if(erro == 1){printf("GEQ\n");}					col+=yyleng;}
{GT}		{if(erro == 1){printf("GT\n");}					col+=yyleng;}
{INT}		{if(erro == 1){printf("INT\n");}			col+=yyleng;}
{LT}		{if(erro == 1){printf("LT\n");}					col+=yyleng;}
{LEQ}		{if(erro == 1){printf("LEQ\n");}					col+=yyleng;}
{MINUS}		{if(erro == 1){printf("MINUS\n");}					col+=yyleng;}
{MOD}		{if(erro == 1){printf("MOD\n");}					col+=yyleng;}
{NEQ}		{if(erro == 1){printf("NEQ\n");}					col+=yyleng;}
{NOT}		{if(erro == 1){printf("NOT\n");}					col+=yyleng;}
{OBRACE}		{if(erro == 1){printf("OBRACE\n");}					col+=yyleng;}
{OCURV}		{if(erro == 1){printf("OCURV\n");}					col+=yyleng;}
{OR}		{if(erro == 1){printf("OR\n");}					col+=yyleng;}
{OSQUARE}		{if(erro == 1){printf("OSQUARE\n");}					col+=yyleng;}
{PARSEINT}		{if(erro == 1){printf("PARSEINT\n");}			col+=yyleng;}
{PLUS}		{if(erro == 1){printf("PLUS\n");}					col+=yyleng;}
{PRINT}		{if(erro == 1){printf("PRINT\n");}			col+=yyleng;}
{PUBLIC}		{if(erro == 1){printf("PUBLIC\n");}			col+=yyleng;}
{RESERVED}		{if(erro == 1){printf("RESERVED\n");}					col+=yyleng;}
{RETURN}		{if(erro == 1){printf("RETURN\n");}			col+=yyleng;}
{SEMI}		{if(erro == 1){printf("SEMI\n");}					col+=yyleng;}
{STAR}		{if(erro == 1){printf("STAR\n");}					col+=yyleng;}
{STATIC}		{if(erro == 1){printf("STATIC\n");}			col+=yyleng;}
{STRING}		{if(erro == 1){printf("STRING\n");}			col+=yyleng;}
{VOID}		{if(erro == 1){printf("VOID\n");}			col+=yyleng;}

{ID}		{if(erro == 1){printf("ID(%s)\n", yytext);}			col+=yyleng;}
\n			{line++; col=1;}
.               {;}

%%
int main(int argc, char** argv){
	if(argc>1){
		if(strcmp(argv[1],"-l")==0 || strcmp(argv[1],"-1")==0){
			erro = 1;
			yylex();
		}
	}
	else{
		yylex();
	}
	return 0;
}

int yywrap()
{
return 1;
}
