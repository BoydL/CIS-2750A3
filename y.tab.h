#define EQUALS 257
#define SEMICOLON 258
#define LEFTBRACE 259
#define RIGHTBRACE 260
#define COMMA 261
#define QUOTE 262
#define TITLE 263
#define FIELDS 264
#define BUTTONS 265
#define WORD 266
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union
{
   char * strval;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
