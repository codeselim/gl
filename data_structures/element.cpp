#include "element.h"


Element::Element(ElementName* en, attributesMap* attrs, nodeList* children) {
	if (children == NULL) {
		this->children = new nodeList();
	} else {
		this->children = children;
	}
	this->attributes = attrs;
}
