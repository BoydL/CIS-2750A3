LEX=lex
YACC=yacc
LDFLAGS=-ll

all: build
	javac Dialogc.java
	javah -jni Dialogc
	gcc -shared -I"/usr/lib/jvm/java-1.6.0-openjdk/include" Dialogc.c -o libJNIpm.so -fPIC
run: all
	java -Djava.library.path=. Dialogc

build: y.tab.o lex.yy.o
	gcc y.tab.o lex.yy.o $(LDFLAGS) -o yadc

y.tab.o: y.tab.c
	gcc -c y.tab.c

lex.yy.o: lex.yy.c y.tab.h
	gcc -c lex.yy.c

y.tab.h: y.tab.c

y.tab.c: parse.y
	$(YACC) -d parse.y

lex.yy.c: parse.l
	$(LEX) parse.l

clean:
	rm -f *.class
	rm -f *.log
	

