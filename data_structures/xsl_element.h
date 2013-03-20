#ifndef __XSL_ELEMENT_H_

#define __XSL_ELEMENT_H_

#include "element.h"
#include "../AnalyseurXML/commun.h"

using namespace std;

class XSLElement : public Element {
protected:

private:
    XSLElement(ElementName* en, attributesMap* attrs,  nodeList* children = NULL);

public:
	bool hasApplyTemplate();
};

#endif
