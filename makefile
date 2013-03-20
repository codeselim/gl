CPP_SRC = dtd.cpp dtd_elt.cpp child_elt.cpp dtd_attr.cpp
CPP_FILES = $(addprefix data_structures/, $(CPP_SRC))
OBJ_FILES = $(CPP_FILES:.cpp=.o)
DSDIR = data_structures
DTDDIR = AnalyseurDTD
INCLUDES = -I$(CURDIR)/$(DSDIR) -I$(CURDIR)/$(DTDDIR)
EXENAME = gl


all: gl

gl: analyseDTD analyseXML
	g++ -g -DYYDEBUG=1 -o $(EXENAME)  $(DTDDIR)/lex.dtd.c $(DTDDIR)/dtd.tab.c $(OBJ_FILES) $(INCLUDES)

analyseDTD: $(DTDDIR)/*.l $(DTDDIR)/*.y makefile $(OBJ_FILES)
	flex -Pdtd $(DTDDIR)/dtd.l
	bison -p dtd --debug --verbose --defines=$(DTDDIR)/dtd.tab.h $(DTDDIR)/dtd.y

analyseXML: $(XMLDIR)/*.l $(XMLDIR)/*.y makefile $(OBJ_FILES)
	flex -Pxml $(XMLDIR)/xml.l
	bison -p xml --debug --verbose --defines=$(XMLDIR)/xml.tab.h $(XMLDIR)/xml.y
	g++ -g -DYYDEBUG=1 -o $(EXENAME)  $(XMLDIR)/lex.xml.c $(XMLDIR)/xml.tab.c $(OBJ_FILES) $(INCLUDES)


clean:
	-rm -rf *.tab.c lex.*.c *.tab.h *.output $(EXENAME) $(OBJ_FILES)

$(DSDIR)/%.o: $(DSDIR)/%.cpp
	g++ -c -o $@ $<
