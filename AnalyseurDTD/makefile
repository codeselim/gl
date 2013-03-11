CPP_FILES := dtd.cpp dtd_elt.cpp child_elt.cpp dtd_attr.cpp
OBJ_FILES := $(addprefix ../data_structures/, $(CPP_FILES:.cpp=.o))

all: analyseDTD
analyseDTD: *.l *.y makefile
	cd ../data_structures ; pwd; g++ -c $(CPP_FILES)
	flex dtd.l
	bison --debug --verbose --defines=yy.tab.h dtd.y
	g++ -g -DYYDEBUG=1 -o analyseDTD  lex.yy.c dtd.tab.c $(OBJ_FILES)
clean:
	-rm -rf *.tab.c lex.*.c *.tab.h *.output analyseDTD $(OBJ_FILES)
