%{
#include "y.tab.h"
extern int line_count;
%}

%%
[\t ]+	{/*White space*/}
#(.*)	{ /*Comments*/ }
\n	{line_count++;}
=	{return EQUALS;}
;	{return SEMICOLON;}
[{]	{return LEFTBRACE;}
[}]	{return RIGHTBRACE;}
\"	{return QUOTE;}
,   	{return COMMA;}
[^=;{},\n\t\" ]+	{
			yylval.strval = strdup(yytext);
			if(strcmp(yytext, "title") == 0){
				return TITLE;
			}
			if(strcmp(yytext, "fields")==0){
				return FIELDS;
			}
			if(strcmp(yytext, "buttons")==0){
				return BUTTONS;
			}
			return WORD;
		}

%%



