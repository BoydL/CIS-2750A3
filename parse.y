%{
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
%}

%union
{
   char * strval;
}

%token EQUALS
%token SEMICOLON
%token LEFTBRACE
%token RIGHTBRACE
%token COMMA
%token QUOTE
%token <strval> TITLE
%token <strval> FIELDS
%token <strval> BUTTONS
%token <strval> WORD

%type <strval> expr
%type <strval> string

%%

statement 	: statement assignment
          	| assignment
          	;
string    	: TITLE
          	| FIELDS
	  	| BUTTONS
          	| WORD
          	;
assignment	: TITLE EQUALS expr	{
						if(title == NULL){
						    title = $3;
						}
						else
						{
				                    return yyerror("double assignment of title.");
						}
					}
		|FIELDS EQUALS listexpr {
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

                |BUTTONS EQUALS listexpr {
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

                |WORD EQUALS expr        {
                                             type[numTypes][0] = $1;
                                             type[numTypes][1] = $3;
                                             numTypes++;           
                                         }
                ;
expr            : QUOTE string QUOTE SEMICOLON      {$$ = $2;}
                | LEFTBRACE             {return yyerror("expected string but got list");}
                ;
listexpr        : LEFTBRACE listitem SEMICOLON
                | string                {return yyerror("expected list but got string");}
                | SEMICOLON             {return yyerror("expected list but got semicolon");}
		;
listitem        : QUOTE string QUOTE COMMA listitem {
                                            buffer[bufferSize] = $2;
                                            bufferSize++;   
                                        }
                |QUOTE string QUOTE RIGHTBRACE      {
                                            buffer[bufferSize] = $2;
                                            bufferSize++;
                                        }

                |RIGHTBRACE             {
                                        }
                ;
%%

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
















