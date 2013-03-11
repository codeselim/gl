# CPPS:=../data_structures/element.o ../data_structures/text_node.o ../data_structures/child_elt.o ../data_structures/node.o

CPP_FILES := $(wildcard ../data_structures/*.cpp)
OBJ_FILES := $(CPP_FILES:.cpp=.o))

all: analyseXML
analyseXML: *.l *.y makefile
	# cd ../data_structures
	# g++ *.cpp
	# cd -
	flex  xml.l
	bison --debug --verbose --defines=yy.tab.h xml.y
	g++ -g -DYYDEBUG=1 -o analyseXML  lex.yy.c  xml.tab.c $(OBJ_FILES)
clean:
	-rm -rf *.tab.c lex.*.c *.tab.h *.output analyseXML

%.o: %.cpp
	g++ $(CC_FLAGS) -c -o $@ $<
