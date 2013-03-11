CPP_SRC = element.cpp node.cpp text_node.cpp
CPP_FILES = $(addprefix ../data_structures/, $(CPP_SRC))
OBJ_FILES = $(CPP_FILES:.cpp=.o)
DSDIR = ../data_structures
INCLUDES = -I$(CURDIR)/../data_structures -I$(CURDIR)

all: analyseXML

analyseXML: *.l *.y makefile $(OBJ_FILES)
	flex xml.l
	bison --debug --verbose --defines=yy.tab.h xml.y
	g++ -g -DYYDEBUG=1 -o analyseXML  lex.yy.c xml.tab.c $(OBJ_FILES) $(INCLUDES)

clean:
	-rm -rf *.tab.c lex.*.c *.tab.h *.output analyseXML $(OBJ_FILES)

$(DSDIR)/%.o: $(DSDIR)/%.cpp
	g++ -c -o $@ $<
