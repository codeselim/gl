#ifndef __XSL_ELEMENT_H_

#define __XSL_ELEMENT_H_

#include "element.h"
#include "../AnalyseurXML/commun.h"

using namespace std;

class XSLElement : public Element {
private:
    XSLElement(ElementName* en, attributesMap* attrs,  nodeList* children = NULL);

friend Element* Element::createElement(ElementName*, attributesMap*,  nodeList*);

public:
	bool hasApplyTemplate();
};

#endif
