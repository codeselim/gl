CPP_FILES := element.cpp node.cpp text_node.cpp
OBJ_FILES := $(addprefix ../data_structures/, $(CPP_FILES:.cpp=.o))

all: analyseXML
analyseXML: *.l *.y makefile
	cd ../data_structures ; pwd; g++ -c $(CPP_FILES)
	flex  xml.l
	bison --debug --verbose --defines=yy.tab.h xml.y
	g++ -g -DYYDEBUG=1 -o analyseXML  lex.yy.c  xml.tab.c $(OBJ_FILES)
clean:
	-rm -rf *.tab.c lex.*.c *.tab.h *.output analyseXML $(OBJ_FILES)