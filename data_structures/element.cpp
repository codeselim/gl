#include "element.h"
#include <sstream>
#include "xsl_element.h"
#include <exception>

Element* Element::createElement(ElementName* en, attributesMap* attrs,  nodeList* children /*= NULL*/) {
	if ("xsl" == en->first) // namespace comparison
	{
		// Instanciate a XSL element
		return new XSLElement(en, attrs, children);
	} else {
		return new Element(en, attrs, children);
	}
}

Element::Element(ElementName* en, attributesMap* attrs, nodeList* children/* = NULL */) {
	if(NULL == children) {
		children = new nodeList();
	}
	this->children = children;
	this->attributes = attrs;
	this->name = en->second;
}

Element& Element::setParent(Element* e) {
	this->parent = e;
}

Element* Element::getParent() {
	return this->parent;
}

string Element::getAttributeValue(string attr) {
	attributesMap::iterator it = this->attributes->find(attr);
	if (this->attributes->end() != it)
	{
		return it->second;
	} else {
		return string("");
	}
}

string Element::toXML() const {
	stringstream str;
	// The element tag...
	str << "<" << this->name;

	// Its attributes...
	if (NULL != this->attributes)
	{
		for(attributesMap::iterator it1 = this->attributes->begin(); it1 != this->attributes->end(); ++it1) {
			str << " " << (it1->first) << "=" << "\"" << (it1->second) << "\"";
		}
	}

	str << ">";// close the XML tag
	// Its children...
	if (NULL != this->children)
	{
		for(nodeList::iterator it = this->children->begin(); it != this->children->end(); ++it) {
			str << endl << (*it)->toXML();
		}
	}
	str << endl << "</" << this->name << ">";// close the XML tag
	return str.str();
}

nodeList* Element::getChildren() {
	return this->children;
}

string Element::getSpaceSeparatedChildrenList() {
	stringstream result;
	string space = "";
	if (NULL != this->children)
	{
		for(nodeList::iterator it = this->children->begin(); it != this->children->end(); ++it) {
			result << space << (*it)->getName();
			space = " ";
		}
	}
	return result.str();
}

string Element::getName() {
	return this->name;
}