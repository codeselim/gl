#include "xsl_element.h"

using namespace std;

XSLElement::XSLElement(ElementName* en, attributesMap* attrs,  nodeList* children /*= NULL*/): Element(en, attrs, children) {
		
}

bool hasApplyTemplate() {
	return false;
}