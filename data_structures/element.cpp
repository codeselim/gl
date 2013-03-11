

Element::Element(ElementName* en, attributesMap* attrs) {
	nodeList* l = new nodeList();
	this(en, attrs, l);
}

Element::Element(ElementName* en, attributesMap* attrs, nodeList* children) {
	this->children = children;
	this->children = children; 
}