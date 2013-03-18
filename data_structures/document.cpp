#include <iostream>
#include <sstream>
#include "document.h"

Document::Document(list<Node*> * declarations, Element* rootNode) {
	this->rootNode = rootNode;
	this->declarations = declarations;
}

Document::~Document() {
	cout << "TODO destructors" << endl;
}

string Document::toXML() {
	stringstream str;
	str << this->declarations << endl;
	str << this->rootNode->toXML();
	return str.str();
}

string Document::getDtdFileName() {
	cerr << "TODO getDtdFileName" << endl;
	return string("");
	// for (list<Node*>::iterator i = declarations.begin(); i != declarations.end(); ++i) {


	// }
}