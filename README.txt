Lucas Boyd             0795339
CIS 2750              Assignment Three

***************
Program summary:
***************
This assignment implements a new config option, "Compile Mode", which allows the user to switch between the default compiler, or the lex/yacc compiler. There is additional functionality added to the program for the data fields to throw exceptions when inproper data is entered.

*************
compiling the program
*************
Go to directory where programfiles are.
type make, to compile, or make run to compile and run.

*************
running the program
*************
make run at apppropriate directory.

Short cuts:

File:
open - ctrl+O
New - ctrl+N
Save - ctrl+S
SaveAs - alt+S
Quit - ctrl+Q

Compile:
Compile - ctrl+B
Compile&Run - ctrl+R

Config:
Java-Compiler - alt+B
Compile Options - alt+C
Java Run-Time - ctrl+J
Run-Time Options - alt+R
Working Directory - ctrl+D
Compiler Mode - ctrl+M

Help:
help - ctrl+H
about - ctrl+A

*********
known limitations
*********
The program does not implement the throws exception class, but does print the exption file. lex and yacc has been implemented. some limitations, such as compiler options are still present in this program.

**********
Example config file.
**********
title = "compiled_exampl";    #name of app.
fields = {
          "Name",
          "Student_ID",
          "A1",
          "A2",
          "A3",
          "A4",
          "Average",
         }; #field names
# button names
buttons = { "Add", "Update", "Delete", "Query");
#!#

Name = "string";
Student_ID = "integer";
A1 = "integer";
A2 = "integer";
A3 = "integer";
A4 = "integer";

# actionListener classes for buttons
Add = "AddListener";
Update = "UpdateListener";
Delete = "DeleteListener";
Query = "QueryListener";

