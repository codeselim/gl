#include "element.h"
#include <sstream>

Element::Element(ElementName* en, attributesMap* attrs, nodeList* children/* = NULL */) {
	if(NULL == children) {
		children = new nodeList();
	}
	this->children = children;
	this->attributes = attrs;
	this->name = en->first;
}

Element& Element::setParent(Element* e) {
	this->parent = e;
}

Element* Element::getParent() {
	return this->parent;
}

string Element::toXML() {
	stringstream str;
	str << "<" << this->name;

	if (NULL != this->attributes)
	{
		for(attributesMap::iterator it1 = this->attributes->begin(); it1 != this->attributes->end(); ++it1) {
			str << " " << (it1->first) << "=" << "\"" << (it1->second) << "\"";
		}
	}

	str << ">";// open the XML tag
	if (NULL != this->children)
	{
		for(nodeList::iterator it = this->children->begin(); it != this->children->end(); ++it) {
			str << endl << (*it)->toXML() << endl;
		}
	}
	str << "</" << this->name << ">";// close the XML tag
	return str.str();
}
