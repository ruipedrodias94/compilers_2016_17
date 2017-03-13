
%{
	int line=1, col=1, auxLine=0, auxCol=0, erro=0;
	char* aux;


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
STRINGCHARACTER 														({ESCAPESEQUENCE}|{INPUTCHARACTER})
ESCAPESEQUENCE 															\\f|\\n|\\r|\\t|\\\\|\\\"
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
<COMMENT>{LINETERMINATOR}	    							{line++; col=1;}
<COMMENT><<EOF>>    												{printf("Line %d, col %d: unterminated comment\n",auxLine,auxCol); return *yytext;}
<COMMENT>.	    														{col+=yyleng;}


\" 																					{BEGIN STRING; auxLine=line; auxCol=col; col+=yyleng;}
<STRING>\" 																	{BEGIN 0;col+=yyleng;}
<STRING>{ESCAPESEQUENCE}										{col+=yyleng;}
<STRING>{LINETERMINATOR}										{col=1; line++; printf("Line %d, col %d: unterminated string literal\n", auxLine, auxCol); BEGIN 0;}
<STRING>\\.?			 													{printf("Line %d, col %d: invalid escape sequence (%s)\n",line,col,yytext);col+=yyleng;}
<STRING><<EOF>>    													{printf("Line %d, col %d: unterminated string literal\n",auxLine,auxCol); return *yytext;}
<STRING>. 																	{col+=yyleng;}


{LINECOMMENT} 															{;}
{IF}																				{if(erro == 1){printf("IF\n");}col+=yyleng; return IF;}
{AND}																				{if(erro == 1){printf("AND\n");}					col+=yyleng; return AND;}
{ASSIGN}																		{if(erro == 1){printf("ASSIGN\n");}					col+=yyleng; return ASSIGN;}
{BOOL}																			{if(erro == 1){printf("BOOL\n");} 			col+=yyleng; return BOOL;}
{CLASS}																			{if(erro == 1){printf("CLASS\n");}			col+=yyleng; return CLASS;}
{CCURV}																			{if(erro == 1){printf("CCURV\n");}					col+=yyleng; return CCURV;}
{CBRACE}																		{if(erro == 1){printf("CBRACE\n");}					col+=yyleng;return CBRACE;}
{COMMA}																			{if(erro == 1){printf("COMMA\n");}					col+=yyleng;return COMMA;}
{CSQUARE}																		{if(erro == 1){printf("CSQUARE\n");}					col+=yyleng;return CSQUARE;}
{DIV}																				{if(erro == 1){printf("DIV\n");}					col+=yyleng;return DIV;}
{DO}																				{if(erro == 1){printf("DO\n");}			col+=yyleng;return DO;}
{DOTLENGTH}																	{if(erro == 1){printf("DOTLENGTH\n");}			col+=yyleng;return DOTLENGTH;}
{DOUBLE}																		{if(erro == 1){printf("DOUBLE\n");}			col+=yyleng;return DOUBLE;}
{ELSE}																			{if(erro == 1){printf("ELSE\n");}			col+=yyleng;return ELSE;}
{EQ}																				{if(erro == 1){printf("EQ\n");}					col+=yyleng;return EQ;}
{GEQ}																				{if(erro == 1){printf("GEQ\n");}					col+=yyleng;return GEQ;}
{GT}																				{if(erro == 1){printf("GT\n");}					col+=yyleng;return GT;}
{INT}																				{if(erro == 1){printf("INT\n");}			col+=yyleng;return INT;}
{LT}																				{if(erro == 1){printf("LT\n");}					col+=yyleng;return LT;}
{LEQ}																				{if(erro == 1){printf("LEQ\n");}					col+=yyleng;return LEQ;}
{MINUS}																			{if(erro == 1){printf("MINUS\n");}					col+=yyleng;return MINUS;}
{MOD}																				{if(erro == 1){printf("MOD\n");}					col+=yyleng;return MOD;}
{NEQ}																				{if(erro == 1){printf("NEQ\n");}					col+=yyleng;return NEQ;}
{NOT}																				{if(erro == 1){printf("NOT\n");}					col+=yyleng;return NOT;}
{OBRACE}																		{if(erro == 1){printf("OBRACE\n");}					col+=yyleng;return OBRACE;}
{OCURV}																			{if(erro == 1){printf("OCURV\n");}					col+=yyleng;return OCURV;}
{OR}																				{if(erro == 1){printf("OR\n");}					col+=yyleng;return OR;}
{OSQUARE}																		{if(erro == 1){printf("OSQUARE\n");}					col+=yyleng;return OSQUARE;}
{PARSEINT}																	{if(erro == 1){printf("PARSEINT\n");}			col+=yyleng;return PARSEINT;}
{PLUS}																			{if(erro == 1){printf("PLUS\n");}					col+=yyleng;return PLUS;}
{PRINT}																			{if(erro == 1){printf("PRINT\n");}			col+=yyleng;return PRINT;}
{PUBLIC}																		{if(erro == 1){printf("PUBLIC\n");}			col+=yyleng;return PUBLIC;}
{RESERVED}																	{if(erro == 1){printf("RESERVED(%s)\n", yytext);}					col+=yyleng;return RESERVED;}
{RETURN}																		{if(erro == 1){printf("RETURN\n");}			col+=yyleng;return RETURN;}
{SEMI}																			{if(erro == 1){printf("SEMI\n");}					col+=yyleng;return SEMI;}
{STAR}																			{if(erro == 1){printf("STAR\n");}					col+=yyleng;return STAR;}
{STATIC}																		{if(erro == 1){printf("STATIC\n");}			col+=yyleng;return STATIC;}
{STRING}																		{if(erro == 1){printf("STRING\n");}			col+=yyleng;return STRING;}
{VOID}																			{if(erro == 1){printf("VOID\n");}			col+=yyleng;return VOID;}
{WHILE} 																		{if(erro == 1){printf("WHILE\n");}			col+=yyleng;return WHILE;}
{BOOLIT}																		{if(erro == 1){printf("BOOLLIT(%s)\n", yytext);}			col+=yyleng;return BOOLIT;}
{REALLIT}																		{if(erro == 1){printf("REALLIT(%s)\n", yytext);}			col+=yyleng;return REALLIT;}
{DECLIT}																		{if(erro == 1){printf("DECLIT(%s)\n", yytext);}			col+=yyleng;return DECLIT;}
{ID}																				{if(erro == 1){printf("ID(%s)\n", yytext);}			col+=yyleng;return ID;}
{STRLIT} 																		{if(erro == 1){printf("STRLIT(%s)\n", yytext);}			col+=yyleng;return STRLIT;}

\t|" "|\f																		{col+=yyleng;}
{LINETERMINATOR}														{line++;col=1;return LINETERMINATOR;}
.              															{printf("Line %d, col %d: illegal character (%s)\n", line , col , yytext);	col+=yyleng;}

%%
int main(int argc, char** argv){
	if(argc>1){
		if(strcmp(argv[1],"-l")==0){
			erro = 1;
			yylex();
		}
		else
		{
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
