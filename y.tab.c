/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parse.y"
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    unsigned int line_count = 1;
    int numButtons = 0;
    int numFields = 0;
    int numTypes = 0;
    int bufferSize = 0;
    int i = 0;
    char * fileName = "null";
    char * title = NULL;
    char * buffer[20] = {NULL};
    char * fields[20]= {NULL};
    char * buttons[20]= {NULL};
    char * type[30][2] = {NULL};
#line 19 "parse.y"
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
#line 49 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

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
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    2,    2,    2,    2,    3,    3,    3,    3,
    1,    1,    4,    4,    4,    5,    5,    5,
};
static const YYINT yylen[] = {                            2,
    2,    1,    1,    1,    1,    1,    3,    3,    3,    3,
    4,    1,    3,    1,    1,    5,    4,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    2,    0,    0,    0,    0,
    1,   12,    0,    7,   15,    0,    3,    4,    5,    6,
   14,    8,    9,   10,    0,   18,    0,    0,    0,    0,
   13,   11,    0,   17,    0,   16,
};
static const YYINT yydgoto[] = {                          5,
   14,   21,    6,   22,   28,
};
static const YYINT yysindex[] = {                      -253,
 -254, -237, -233, -232, -253,    0, -240, -257, -257, -240,
    0,    0, -248,    0,    0, -239,    0,    0,    0,    0,
    0,    0,    0,    0, -236,    0, -248, -231, -230, -229,
    0,    0, -256,    0, -239,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   19,  -13,   25,   22,   -3,
};
#define YYTABLESIZE 33
static const YYINT yytable[] = {                         25,
   15,   16,    7,   34,   35,   17,   18,   19,   20,    1,
    2,    3,    4,   30,   17,   18,   19,   20,   12,    8,
   26,   13,   27,    9,   10,   29,   31,   32,   24,   11,
   23,   36,   33,
};
static const YYINT yycheck[] = {                         13,
  258,  259,  257,  260,  261,  263,  264,  265,  266,  263,
  264,  265,  266,   27,  263,  264,  265,  266,  259,  257,
  260,  262,  262,  257,  257,  262,  258,  258,   10,    5,
    9,   35,  262,
};
#define YYFINAL 5
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 266
#define YYUNDFTOKEN 274
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"EQUALS","SEMICOLON","LEFTBRACE",
"RIGHTBRACE","COMMA","QUOTE","TITLE","FIELDS","BUTTONS","WORD",0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : statement",
"statement : statement assignment",
"statement : assignment",
"string : TITLE",
"string : FIELDS",
"string : BUTTONS",
"string : WORD",
"assignment : TITLE EQUALS expr",
"assignment : FIELDS EQUALS listexpr",
"assignment : BUTTONS EQUALS listexpr",
"assignment : WORD EQUALS expr",
"expr : QUOTE string QUOTE SEMICOLON",
"expr : LEFTBRACE",
"listexpr : LEFTBRACE listitem SEMICOLON",
"listexpr : string",
"listexpr : SEMICOLON",
"listitem : QUOTE string QUOTE COMMA listitem",
"listitem : QUOTE string QUOTE RIGHTBRACE",
"listitem : RIGHTBRACE",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 111 "parse.y"

extern FILE * yyin;
extern char * yytext;

int yyerror(char *s){
	fprintf(stderr, "%s in %s on line %d\n", s, fileName, line_count);
	exit(-1);
	return(-1);
}

int main(int argc, char ** argv){
    int j = 0;
    int k = 0;
    FILE * input;
    FILE * output;
    char * pName;
    char * directory;
    char fn[1024];
    fileName = argv[1];
    pName = argv[2];
    directory = argv[3];
    input = fopen(fileName, "r");
    if(input == NULL){
		fprintf(stderr, "the file %s could not be opened for reading\n", fileName);
		return -1;
    }
    yyin = input;
    while(!feof(yyin)){
        yyparse();
    }
    /*Check if everything has been initialized properly.*/
    if(title == NULL){
	fprintf(stderr, "title is not initialized in %s\n", fileName);
	return -1;
    }
    for(j = 0; j<numButtons; j++){
	if(buttons[j] == NULL){
	    fprintf(stderr, "buttons are not initialized in %s\n %d", fileName, numButtons);
	    return -1;
	}
	for(k = 0; k<numTypes; k++){
            if(strcmp(type[k][0], buttons[j])){
		if(type[k][1] == NULL){
		   fprintf(stderr, "the button %s has not been initialized with an actionlistener\n",buttons[j]);	
		}
	    }
	    if(k == numTypes){
		fprintf(stderr,"The button %s has not been initialized.\n",buttons[j]);
	    }
	} 
    }
    for(j = 0; j<numFields; j++){
	if(fields[j] == NULL){
	    fprintf(stderr, "buttons are not initialized in %s\n", fileName);
	    return -1;
	}
	for(k = 0; k<numTypes; k++){
            if(strcmp(type[k][0], fields[j])){
		if(strcmp(type[k][1], "string")!=0 && strcmp(type[k][1], "integer")!=0  && strcmp(type[k][1], "float")!=0){
		    fprintf(stderr, "%s is not initialized to a valid type. got %s expect(string, integer, float)\n",fields[j],type[k][1]);
		    return(-1);    
		}
		k = numTypes + 1;
	    }
	    if(k == numTypes){
		fprintf(stderr,"The field %s has not been initialized with a type\n",buttons[j]);
		return -1;
	    }
	} 
    }
    sprintf(fn, "%s/IllegalFieldValue.java",directory);
    output = fopen(fn, "wb");
    fprintf(output, "public class IllegalFieldValue extends Exception\n");
    fprintf(output, "{\n");
    fprintf(output, "\tpublic IllegalFieldValue(){\n\t\tsuper();\n\t}\n");
    fprintf(output, "\tpublic IllegalFieldValue(String message){\n\t\tsuper(message);\n\t}\n"); 
    fprintf(output, "}\n");
    fclose(output);
    /*Accessor and Mutator methods interface file.*/
    sprintf(fn, "%s/%sFieldEdit.java",directory, pName);
    output = fopen(fn, "wb");
    fprintf(output, "import java.awt.*;\n");
    fprintf(output, "import javax.swing.*;\n");
    fprintf(output, "import java.awt.event.ActionListener;\n");
    fprintf(output, "import java.awt.event.ActionEvent;\n");
    fprintf(output, "public interface %sFieldEdit{\n", pName);
    for(j = 0; j<numFields; j++){
	fprintf(output, "\tpublic String getDC%s() throws IllegalFieldValue;\n", fields[j]);
	fprintf(output, "\tpublic void setDC%s(String input);\n", fields[j]);
    }
    fprintf(output, "\tpublic void appendToStatusArea(String message);\n");
    fprintf(output, "}");
    fclose(output);

    /*Java file*/
    sprintf(fn,"%s/%s.java",directory, pName); 
    output = fopen(fn, "wb");

    fprintf(output, "import java.awt.*;\n");
    fprintf(output, "import javax.swing.*;\n");
    fprintf(output, "import java.awt.event.ActionListener;\n");
    fprintf(output, "import java.awt.event.ActionEvent;\n");
    fprintf(output, "\n");
    fprintf(output, "public class %s implements %sFieldEdit{\n", pName, pName);
    fprintf(output, "\tJFrame main;\n");
    fprintf(output, "\tJPanel top = new JPanel();\n");
    fprintf(output, "\tJPanel bot = new JPanel();\n");
    fprintf(output, "\tJPanel field = new JPanel();\n");
    fprintf(output, "\tJPanel buttonArea = new JPanel();\n");
    for(j = 0; j<numFields; j++){
    	fprintf(output, "\tJTextField %sText;\n",fields[j]);
    }
    fprintf(output,"\tJTextArea textArea;\n");
    for(j=0; j<numButtons;j++){
    	fprintf(output, "\tJButton %sButton;\n", buttons[j]);
    }
    fprintf(output, "\tJLabel statusLabel;\n");
    fprintf(output, "\tint i;\n");
    fprintf(output, "\tpublic %s(){\n", pName);
    fprintf(output, "\t\tmain = new JFrame(\"%s\");\n", title);
    fprintf(output, "\t\tmain.setSize(400,400);\n");
    fprintf(output, "\t\tmain.setResizable(false);\n");
    fprintf(output, "\t\tmain.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);\n");
    fprintf(output, "\t\ttop.setLayout(new BoxLayout(top, BoxLayout.Y_AXIS));\n");
    fprintf(output, "\t\tbot.setLayout(new BoxLayout(bot, BoxLayout.Y_AXIS));\n");
    fprintf(output, "\t\tbuttonArea.setLayout(new FlowLayout());\n");
    fprintf(output, "\t\tfield.setLayout(new GridLayout(%d, 2, 1, 2));\n", numFields);
    for(j=numFields-1; j>=0; j--){
    	fprintf(output, "\t\tJLabel %sLabel = new JLabel(\"%s\");\n",fields[j],fields[j]);
    	fprintf(output, "\t\t%sText = new JTextField();\n",fields[j]);
    	fprintf(output, "\t\tfield.add(%sLabel);\n",fields[j]);
    	fprintf(output, "\t\tfield.add(%sText);\n",fields[j]);
    }
    fprintf(output, "\t\ttop.add(field);\n");
    for(j=numButtons-1; j>=0; j--){
    	fprintf(output, "\t\t%sButton = new JButton(\"%s\");\n", buttons[j],buttons[j]);
    	fprintf(output, "\t\t%sButton.addActionListener(new ActionListener(){\n", buttons[j]);
    	fprintf(output, "\t\t\t@Override\n");
    	fprintf(output, "\t\t\tpublic void actionPerformed(ActionEvent e){\n");
    	fprintf(output, "\t\t\t\ttextArea.append(e.getActionCommand()+ \"button pushed.\");\n");
   	fprintf(output, "\t\t\t}\n");
    	fprintf(output, "\t\t});\n");
    	fprintf(output, "\t\tbuttonArea.add(%sButton);\n",buttons[j]);
    }
    fprintf(output, "\t\ttop.add(buttonArea);\n");
    fprintf(output, "\t\tstatusLabel = new JLabel(\"status\");\n");
    fprintf(output, "\t\tbot.add(statusLabel);\n");
    fprintf(output, "\t\ttextArea = new JTextArea();\n");
    fprintf(output, "\t\tJScrollPane scroll = new JScrollPane(textArea);\n");
    fprintf(output, "\t\tscroll.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS);\n");
    fprintf(output, "\t\tbot.add(scroll);\n");
    fprintf(output, "\t\tmain.add(top, BorderLayout.NORTH);\n");
    fprintf(output, "\t\tmain.add(bot, BorderLayout.CENTER);\n");
    fprintf(output, "\t\tmain.setVisible(true);\n");
    fprintf(output, "\t}\n");
    for(j=0; j<numFields; j++){
    	fprintf(output, "\tpublic String getDC%s(){\n",fields[j]);
    	fprintf(output, "\t\treturn(%sText.getText());\n",fields[j]);
    	fprintf(output, "\t}\n");
    	fprintf(output, "\tpublic void setDC%s(String input){\n",fields[j]);
    	fprintf(output, "\t\t%sText.setText(input);\n",fields[j]);
    	fprintf(output, "\t}\n");
    }
    fprintf(output, "\tpublic void appendToStatusArea(String message){\n");
    fprintf(output, "\t\ttextArea.append(message);\n");
    fprintf(output, "\t}\n");
    fprintf(output, "\tpublic static void main(String[] args){\n");
    fprintf(output, "\t\t%s window = new %s();\n",pName, pName);
    fprintf(output, "\t}\n");
    fprintf(output, "}\n");
    fclose(output);
    return(0);
}
















#line 406 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 7:
#line 48 "parse.y"
	{
						if(title == NULL){
						    title = yystack.l_mark[0].strval;
						}
						else
						{
				                    return yyerror("double assignment of title.");
						}
					}
break;
case 8:
#line 57 "parse.y"
	{
					        if(fields[0] == NULL){
                                                    for(i = 0; i<bufferSize; i++){
                                                        fields[i] = buffer[i];   
                                                        buffer[i] = NULL;
                                                        numFields++;
                                                    }
                                                    bufferSize = 0;         
                                                }
                                                else{
                                                    return yyerror("double assignment of fields.");
                                                }
					}
break;
case 9:
#line 71 "parse.y"
	{
                                                if(buttons[0] == NULL){
                                                   for(i = 0; i<bufferSize; i++){
                                                       buttons[i] = buffer[i];
                                                       buffer[i] = NULL;
                                                       numButtons++;
                                                   }
                                                   bufferSize = 0;
                                                }
                                                else{
                                                   return yyerror("double assignment of buttons.");
                                                }
                                         }
break;
case 10:
#line 85 "parse.y"
	{
                                             type[numTypes][0] = yystack.l_mark[-2].strval;
                                             type[numTypes][1] = yystack.l_mark[0].strval;
                                             numTypes++;           
                                         }
break;
case 11:
#line 91 "parse.y"
	{yyval.strval = yystack.l_mark[-2].strval;}
break;
case 12:
#line 92 "parse.y"
	{return yyerror("expected string but got list");}
break;
case 14:
#line 95 "parse.y"
	{return yyerror("expected list but got string");}
break;
case 15:
#line 96 "parse.y"
	{return yyerror("expected list but got semicolon");}
break;
case 16:
#line 98 "parse.y"
	{
                                            buffer[bufferSize] = yystack.l_mark[-3].strval;
                                            bufferSize++;   
                                        }
break;
case 17:
#line 102 "parse.y"
	{
                                            buffer[bufferSize] = yystack.l_mark[-2].strval;
                                            bufferSize++;
                                        }
break;
case 18:
#line 107 "parse.y"
	{
                                        }
break;
#line 695 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
