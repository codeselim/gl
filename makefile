CPP_SRC = dtd.cpp dtd_elt.cpp child_elt.cpp dtd_attr.cpp element.cpp node.cpp text_node.cpp document.cpp special_node.cpp xsl_element.cpp
CPP_FILES = $(addprefix data_structures/, $(CPP_SRC))
OBJ_FILES = $(CPP_FILES:.cpp=.o)
DSDIR = data_structures
DTDDIR = AnalyseurDTD
XMLDIR = AnalyseurXML
VDIR = Validation
HDIR = xsl
INCLUDES = -I$(CURDIR)/$(DSDIR) -I$(CURDIR)/$(DTDDIR) -I$(CURDIR)/$(XMLDIR) -I$(CURDIR)/$(VDIR) -I$(CURDIR)/$(HDIR)
EXENAME = gl
VO_FILES = $(VDIR)/Validate.o $(HDIR)/html_builder.o
LIBRARIES = -lboost_regex


all: gl

gl: analyseDTD analyseXML analyseXSL $(OBJ_FILES) $(VO_FILES)
	g++ -g -DYYDEBUG=1 -o $(EXENAME) -D PREFIXE=xsl lex.dtd.c dtd.tab.c lex.xml.c xml.tab.c lex.xsl.c xsl.tab.c main.cpp $(VO_FILES) $(OBJ_FILES) $(INCLUDES) $(LIBRARIES)

analyseDTD: $(DTDDIR)/*.l $(DTDDIR)/*.y makefile
	flex -Pdtd $(DTDDIR)/dtd.l
	bison -p dtd --debug --verbose --defines=$(DTDDIR)/dtd.tab.h $(DTDDIR)/dtd.y

analyseXML: $(XMLDIR)/*.l $(XMLDIR)/*.y makefile
	flex -Pxml $(XMLDIR)/xml.l
	bison -p xml --debug --verbose --defines=$(XMLDIR)/xml.tab.h $(XMLDIR)/xml.y

analyseXSL: $(XMLDIR)/*.l $(XMLDIR)/*.y makefile
	sed 's/xml/xsl/g' AnalyseurXML/xml.y > AnalyseurXML/xsl.y
	sed -e 's/xml.tab.h/xsl.tab.h/g'\
	    -e 's/xmltext/xsltext/g'\
	    -e 's/xmllval/xsllval/g'\
	    AnalyseurXML/xml.l > AnalyseurXML/xsl.l
	flex -Pxsl $(XMLDIR)/xsl.l
	bison -p xsl --debug --verbose --defines=$(XMLDIR)/xsl.tab.h $(XMLDIR)/xsl.y

clean:
	-rm -rf *.tab.c lex.*.c *.tab.h *.output $(EXENAME) $(OBJ_FILES) xsl.y xsl.l
	-rm -f *.pyc pyutils/*.pyc

$(DSDIR)/%.o: $(DSDIR)/%.cpp
	g++ -c -o $@ $<

$(VDIR)/%.o: $(VDIR)/%.cpp
	g++ -c -o $@ $<

$(HDIR)/%.o: $(HDIR)/%.cpp
	g++ -c -o $@ $<

