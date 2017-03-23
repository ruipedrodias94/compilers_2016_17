
%{
	#include "y.tab.h"
	 int line=1, col=1, auxLine=0, auxCol=0;
	 extern int erro;

%}
%x COMMENT
%x STRING
%x LINECOMMENT
%x STRINGBAR

NUMBER																			[0-9]
NONZERO																			[1-9]
CHARACTER     															[a-zA-Z]
ZERO																				0
JAVALETTER																	[a-zA-Z]|$|_
JAVALETTERORDIGIT 													{JAVALETTER}|[0-9]
UNDERSCORE																	_
DECIMALNUMERAL	 														0|{NONZERO}{DIGITS}?
DIGITS        															{DIGIT}|{DIGIT}{DIGITSANDUNDERSCORES}?{DIGIT}
DIGIT 																			0|{NONZERO}
DIGITSANDUNDERSCORES 												{DIGITORUNDERSCORE}{DIGITORUNDERSCORE}*
DIGITORUNDERSCORE 													{DIGIT}|_
UNDERSCORES 																_(_)*
EXPONENTPART 																{EXPONENTINDICATOR}{SIGNEDINTEGER}
EXPONENTINDICATOR 													e|E
SIGNEDINTEGER 															{SIGN}?{DIGITS}
SIGN 																				"+"|"-"
ESCAPESEQUENCE 															\\f|\\n|\\r|\\t|\\\\|\\\"
STRINGCHARACTER 														({ESCAPESEQUENCE}|{INPUTCHARACTER})
INPUTCHARACTER 															[^\r\n\\\"]
LINETERMINATOR  														"\n"|"\r"|"\r\n"
LINECOMMENT  																"//"([^\n\r])*


ID             ({JAVALETTER}{JAVALETTERORDIGIT}*)
DECLIT         {ZERO}|{NONZERO}{DIGITS}?|{NONZERO}{UNDERSCORES}{DIGITS}
REALLIT				 {DIGITS}"."{DIGITS}?{EXPONENTPART}?|"."{DIGITS}{EXPONENTPART}?|{DIGITS}{EXPONENTPART}
STRLIT					\"{STRINGCHARACTER}*\"
BOOL           boolean
BOOLIT         true|false
CLASS          class
DO             do
DOTLENGTH      ("."length)
DOUBLE         double
ELSE           else
IF             if
INT            int
PARSEINT       (Integer"."parseInt)
PRINT          (System"."out"."println)
PUBLIC         public
RETURN         return
STATIC         static
STRING        String
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
RESERVED       assert|System|Integer|null|"++"|"--"|abstract|continue|for|new|switch|default|package|synchronized|goto|private|this|break|implements|protected|throw|byte|import|throws|case|enum|instanceof|transient|catch|extends|short|try|char|final|interface|finally|long|strictfp|volatile|const|float|native|super

%%

"/*"		    																{BEGIN COMMENT; auxLine=line; auxCol=col; col+=yyleng;}
<COMMENT>"*/"       												{BEGIN 0;col+=yyleng;}
<COMMENT>{LINETERMINATOR}	    							{line++; col=1;return LINETERMINATOR;}
<COMMENT><<EOF>>    												{printf("Line %d, col %d: unterminated comment\n",auxLine,auxCol); return *yytext;}
<COMMENT>.	    														{col+=yyleng;}


\" 																					{BEGIN STRING; auxLine=line; auxCol=col; col+=yyleng;}
<STRING>\" 																	{BEGIN 0;col+=yyleng;}
<STRING>{ESCAPESEQUENCE}										{col+=yyleng; return ESCAPESEQUENCE;}
<STRING>{LINETERMINATOR}										{col=1; line++; printf("Line %d, col %d: unterminated string literal\n", auxLine, auxCol); BEGIN 0;return LINETERMINATOR;}
<STRING>\\.?			 													{printf("Line %d, col %d: invalid escape sequence (%s)\n",line,col,yytext);col+=yyleng;}
<STRING><<EOF>>    													{printf("Line %d, col %d: unterminated string literal\n",auxLine,auxCol); return *yytext;}
<STRING>. 																	{col+=yyleng;}


{LINECOMMENT} 															{;}
{IF}																				{if(erro == 1){printf("IF\n");}  auxCol=col; auxLine=line; col+=yyleng; return IF;}
{AND}																				{if(erro == 1){printf("AND\n");}	 auxCol=col; auxLine=line;				col+=yyleng; return AND;}
{ASSIGN}																		{if(erro == 1){printf("ASSIGN\n");}		 auxCol=col; auxLine=line;			col+=yyleng; return ASSIGN;}
{BOOL}																			{if(erro == 1){printf("BOOL\n");} 		 auxCol=col; auxLine=line;	col+=yyleng; return BOOL;}
{CLASS}																			{if(erro == 1){printf("CLASS\n");}		 auxCol=col; auxLine=line;	col+=yyleng; return CLASS;}
{CCURV}																			{if(erro == 1){printf("CCURV\n");}		 auxCol=col; auxLine=line;		col+=yyleng; return CCURV;}
{CBRACE}																		{if(erro == 1){printf("CBRACE\n");}			 auxCol=col; auxLine=line;		col+=yyleng;return CBRACE;}
{COMMA}																			{if(erro == 1){printf("COMMA\n");}			 auxCol=col; auxLine=line;		col+=yyleng;return COMMA;}
{CSQUARE}																		{if(erro == 1){printf("CSQUARE\n");}		 auxCol=col; auxLine=line;			col+=yyleng;return CSQUARE;}
{DIV}																				{if(erro == 1){printf("DIV\n");}				 auxCol=col; auxLine=line;	col+=yyleng;return DIV;}
{DO}																				{if(erro == 1){printf("DO\n");}		 auxCol=col; auxLine=line;	col+=yyleng;return DO;}
{DOTLENGTH}																	{if(erro == 1){printf("DOTLENGTH\n");}	 auxCol=col; auxLine=line;		col+=yyleng;return DOTLENGTH;}
{DOUBLE}																		{if(erro == 1){printf("DOUBLE\n");}	 auxCol=col; auxLine=line;		col+=yyleng;return DOUBLE;}
{ELSE}																			{if(erro == 1){printf("ELSE\n");}		 auxCol=col; auxLine=line;	col+=yyleng;return ELSE;}
{EQ}																				{if(erro == 1){printf("EQ\n");}			 auxCol=col; auxLine=line;		col+=yyleng;return EQ;}
{GEQ}																				{if(erro == 1){printf("GEQ\n");}		 auxCol=col; auxLine=line;			col+=yyleng;return GEQ;}
{GT}																				{if(erro == 1){printf("GT\n");}			 auxCol=col; auxLine=line;		col+=yyleng;return GT;}
{INT}																				{if(erro == 1){printf("INT\n");}		 auxCol=col; auxLine=line;	col+=yyleng;return INT;}
{LT}																				{if(erro == 1){printf("LT\n");}			 auxCol=col; auxLine=line;		col+=yyleng;return LT;}
{LEQ}																				{if(erro == 1){printf("LEQ\n");}		  auxCol=col; auxLine=line;			col+=yyleng;return LEQ;}
{MINUS}																			{if(erro == 1){printf("MINUS\n");}		 auxCol=col; auxLine=line;			col+=yyleng;return MINUS;}
{MOD}																				{if(erro == 1){printf("MOD\n");}			 auxCol=col; auxLine=line;		col+=yyleng;return MOD;}
{NEQ}																				{if(erro == 1){printf("NEQ\n");}			 auxCol=col; auxLine=line;		col+=yyleng;return NEQ;}
{NOT}																				{if(erro == 1){printf("NOT\n");}			 auxCol=col; auxLine=line;		col+=yyleng;return NOT;}
{OBRACE}																		{if(erro == 1){printf("OBRACE\n");}		 auxCol=col; auxLine=line;			col+=yyleng;return OBRACE;}
{OCURV}																			{if(erro == 1){printf("OCURV\n");}		 auxCol=col; auxLine=line;			col+=yyleng;return OCURV;}
{OR}																				{if(erro == 1){printf("OR\n");}				 auxCol=col; auxLine=line;	col+=yyleng;return OR;}
{OSQUARE}																		{if(erro == 1){printf("OSQUARE\n");}		 auxCol=col; auxLine=line;			col+=yyleng;return OSQUARE;}
{PARSEINT}																	{if(erro == 1){printf("PARSEINT\n");}		 auxCol=col; auxLine=line;	col+=yyleng;return PARSEINT;}
{PLUS}																			{if(erro == 1){printf("PLUS\n");}				 auxCol=col; auxLine=line;	col+=yyleng;return PLUS;}
{PRINT}																			{if(erro == 1){printf("PRINT\n");}		 auxCol=col; auxLine=line;	col+=yyleng;return PRINT;}
{PUBLIC}																		{if(erro == 1){printf("PUBLIC\n");}			 auxCol=col; auxLine=line; col+=yyleng;return PUBLIC;}
{RESERVED}																	{if(erro == 1){printf("RESERVED(%s)\n", yytext);}		 auxCol=col; auxLine=line;			col+=yyleng;return RESERVED;}
{RETURN}																		{if(erro == 1){printf("RETURN\n");}		 auxCol=col; auxLine=line;	col+=yyleng;return RETURN;}
{SEMI}																			{if(erro == 1){printf("SEMI\n");}			 auxCol=col; auxLine=line;		col+=yyleng;return SEMI;}
{STAR}																			{if(erro == 1){printf("STAR\n");}				 auxCol=col; auxLine=line;	col+=yyleng;return STAR;}
{STATIC}																		{if(erro == 1){printf("STATIC\n");}		 auxCol=col; auxLine=line;	col+=yyleng;return STATIC;}
{STRING}																		{if(erro == 1){printf("STRING\n");}		 auxCol=col; auxLine=line;	col+=yyleng;return STRING;}
{VOID}																			{if(erro == 1){printf("VOID\n");}			 auxCol=col; auxLine=line; col+=yyleng;return VOID;}
{WHILE} 																		{if(erro == 1){printf("WHILE\n");}		 auxCol=col; auxLine=line;	col+=yyleng;return WHILE;}
{BOOLIT}																		{if(erro == 1){printf("BOOLLIT(%s)\n", yytext);}		 auxCol=col; auxLine=line;	col+=yyleng;return BOOLLIT;}
{REALLIT}																		{if(erro == 1){printf("REALLIT(%s)\n", yytext);}		 auxCol=col; auxLine=line;	col+=yyleng;return REALLIT;}
{DECLIT}																		{if(erro == 1){printf("DECLIT(%s)\n", yytext);}		 auxCol=col; auxLine=line;	col+=yyleng;return DECLIT;}
{ID}																				{if(erro == 1){printf("ID(%s)\n", yytext);}		 auxCol=col; auxLine=line;	col+=yyleng;return ID;}
{STRLIT} 																		{if(erro == 1){printf("STRLIT(%s)\n", yytext);}	  auxCol=col; auxLine=line;		col+=yyleng;return STRLIT;}

\t|" "|\f																		{col+=yyleng; auxCol=col; auxLine=line;}
{LINETERMINATOR}														{line++;col=1;return LINETERMINATOR; auxCol=col; auxLine=line;}
.              															{printf("Line %d, col %d: illegal character (%s)\n", line , col , yytext);	col+=yyleng;}

%%



int yywrap()
{
	return 1;
}

 /*Ainda não sei qual o valor a meter na string s*/
void yyerror (const char *s) {
	printf ("Line %d, col %d: %s: %s\n", line, col, s, yytext);
}
