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

string Element::xmlOpeningTag() const {
	stringstream str;

	str << "<" << this->name;

	// Its attributes...
	if (NULL != this->attributes)
	{
		for(attributesMap::iterator it1 = this->attributes->begin(); it1 != this->attributes->end(); ++it1) {
			str << " " << (it1->first) << "=" << "\"" << (it1->second) << "\"";
		}
	}

	str << ">";// close the XML tag
	return str.str();
}

string Element::xmlClosingTag() const {
	stringstream str;
	str << endl << "</" << this->name << ">";// close the XML tag
	return str.str();
}

string Element::toXML() const {
	stringstream str;
	// The element tag...
	str << this->xmlOpeningTag();
	str << this->getInnerXML();
	str << this->xmlClosingTag();
	return str.str();
}

string Element::getInnerXML() const {
	stringstream str;
	// Its children...
	if (NULL != this->children)
	{
		for(nodeList::iterator it = this->children->begin(); it != this->children->end(); ++it) {
			str << endl << (*it)->toXML();
		}
	}
	return str.str();
}

nodeList* Element::getChildren() {
	return this->children;
}

string Element::getSpaceSeparatedChildrenList() {
	stringstream result;
	string space = "";
	string dernier = "";
	if (NULL != this->children)
	{
		for(nodeList::iterator it = this->children->begin(); it != this->children->end(); ++it) {
			if ((*it)->getName() == dernier) space= "";
			result << space << (*it)->getName();
			space = " ";
			dernier = (*it)->getName();
		}
	}
	return result.str();
}

string Element::getName() {
	return this->name;
}

string Element::getFullName() {
	if (ns.empty()) {
		return name;
	} else {
		return ns + ":" + name;
	}
}
