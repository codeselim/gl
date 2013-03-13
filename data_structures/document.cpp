#include <iostream>
#include "document.h"

Document::Document(list<Node*> * declarations, Element* rootNode) {
	this->rootNode = rootNode;
	this->declarations = declarations;
}

Document::~Document() {
	cout << "TODO destructors" << endl;
}

string Document::toXML() {
	return string("Appel à la fonction toXML de document");
}

