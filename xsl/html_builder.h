#ifndef __HTML_BUILDER_H_

#define __HTML_BUILDER_H_

#include "../data_structures/element.h"
#include "../data_structures/xsl_element.h"
#include "string"
#include "../AnalyseurXML/commun.h"

using namespace std;

typedef map<string, XSLElement*> templateIndex;

class HTMLBuilder {
protected:
	XSLElement* xsl_root;
	Element* xml_root;
	templateIndex index;
	string build_html(Node* curr);
	void createIndex();
public:
    HTMLBuilder(XSLElement* xsl_root, Element* xml_root);
    string html();
};

#endif