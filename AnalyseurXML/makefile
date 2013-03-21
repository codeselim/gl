<<<<<<< HEAD
CPP_SRC = element.cpp node.cpp text_node.cpp document.cpp xsl_element.cpp
=======
CPP_SRC = element.cpp node.cpp text_node.cpp document.cpp special_node.cpp
>>>>>>> master
CPP_FILES = $(addprefix ../data_structures/, $(CPP_SRC))
OBJ_FILES = $(CPP_FILES:.cpp=.o)
DSDIR = ../data_structures
INCLUDES = -I$(CURDIR)/../data_structures -I$(CURDIR)

all: analyseXML

analyseXML: *.l *.y makefile $(OBJ_FILES)
	flex -Pxml xml.l
	bison -p xml --debug --verbose --defines=xml.tab.h xml.y
	g++ -g -DYYDEBUG=1 -o analyseXML  lex.xml.c xml.tab.c xml.c $(OBJ_FILES) $(INCLUDES)

clean:
	-rm -rf *.tab.c lex.*.c *.tab.h *.output analyseXML $(OBJ_FILES)

$(DSDIR)/%.o: $(DSDIR)/%.cpp
	g++ -c -o $@ $<
