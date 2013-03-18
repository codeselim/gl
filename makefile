
all: analyse

analyse: makefile 
	g++ -g -DYYDEBUG=1 -o analyse  Analyseur.c 

clean:
	-rm -rf analyse

