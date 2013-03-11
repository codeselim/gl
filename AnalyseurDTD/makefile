CPP_SRC = dtd.cpp dtd_elt.cpp child_elt.cpp dtd_attr.cpp
CPP_FILES = $(addprefix ../data_structures/, $(CPP_SRC))
OBJ_FILES = $(CPP_FILES:.cpp=.o)
DSDIR = ../data_structures
INCLUDES = -I$(CURDIR)/../data_structures -I$(CURDIR)

all: analyseDTD

analyseDTD: *.l *.y makefile $(OBJ_FILES)
	flex dtd.l
	bison --debug --verbose --defines=yy.tab.h dtd.y
	g++ -g -DYYDEBUG=1 -o analyseDTD  lex.yy.c dtd.tab.c $(OBJ_FILES) $(INCLUDES)

clean:
	-rm -rf *.tab.c lex.*.c *.tab.h *.output analyseDTD $(OBJ_FILES)

$(DSDIR)/%.o: $(DSDIR)/%.cpp
	g++ -c -o $@ $<
