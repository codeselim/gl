CPP_SRC = dtd.cpp dtd_elt.cpp child_elt.cpp dtd_attr.cpp element.cpp node.cpp text_node.cpp document.cpp xsl_element.cpp
CPP_FILES = $(addprefix data_structures/, $(CPP_SRC))
OBJ_FILES = $(CPP_FILES:.cpp=.o)
DSDIR = data_structures
DTDDIR = AnalyseurDTD
XMLDIR = AnalyseurXML
INCLUDES = -I$(CURDIR)/$(DSDIR) -I$(CURDIR)/$(DTDDIR) -I$(CURDIR)/$(XMLDIR)
EXENAME = gl


all: gl

gl: analyseDTD analyseXML $(OBJ_FILES)
	g++ -g -DYYDEBUG=1 -o $(EXENAME) lex.dtd.c dtd.tab.c lex.xml.c xml.tab.c main.cpp $(OBJ_FILES) $(INCLUDES)

analyseDTD: $(DTDDIR)/*.l $(DTDDIR)/*.y makefile
	flex -Pdtd $(DTDDIR)/dtd.l
	bison -p dtd --debug --verbose --defines=$(DTDDIR)/dtd.tab.h $(DTDDIR)/dtd.y

analyseXML: $(XMLDIR)/*.l $(XMLDIR)/*.y makefile
	flex -Pxml $(XMLDIR)/xml.l
	bison -p xml --debug --verbose --defines=$(XMLDIR)/xml.tab.h $(XMLDIR)/xml.y

clean:
	-rm -rf *.tab.c lex.*.c *.tab.h *.output $(EXENAME) $(OBJ_FILES)

$(DSDIR)/%.o: $(DSDIR)/%.cpp
	g++ -c -o $@ $<
