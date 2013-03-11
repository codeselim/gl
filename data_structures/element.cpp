#include <stringstream>

Element::Element(ElementName* en, attributesMap* attrs) {
	nodeList* l = new nodeList();
	this(en, attrs, l);
}

Element::Element(ElementName* en, attributesMap* attrs, nodeList* children) {
	this->children = children;
	this->attrs = attrs;
}

Element& Element::setParent(Element* e) {
	this->parent = e;
}

Element& Element::getParent() {
	return this->parent;
}

string Element::toXML() {
	stringstream str;
	str << this->name << endl;
	for(nodeList::iterator it = this->children->begin(); it != this->children->end(); ++it) {
		str << it->toXML();
	}
	return str.str();
}