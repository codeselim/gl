#include <iostream>
#include "document.h"

Document::Document(list<Node*> * declarations, Element* rootNode) {
	this->rootNode = rootNode;
	this->declarations = declarations;
}

string Document::toXML() {
	cout << "Appel à la fonction toXML de document" << endl;
}
