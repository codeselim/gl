#include <iostream>
#include <sstream>
#include "document.h"


Document::Document(list<SpecialNode*> * declarations, Element* rootNode) {
	this->rootNode = rootNode;
	this->declarations = declarations;
}

Document::~Document() {
	cout << "TODO destructors" << endl;
}

string Document::toXML() {
	stringstream str;
	for (list<SpecialNode*>::iterator i = declarations->begin(); i != declarations->end(); ++i) {
		str << (*i)->toXML() << "\n";
	}
	str << this->rootNode->toXML();
	return str.str();
}

string Document::getDtdFileName() {
	string dtdurl;
	for (list<SpecialNode*>::iterator i = declarations->begin(); i != declarations->end(); ++i) {
		if ( (*i)->getType() == SNT_DOCTYPE ) {
			dtdurl = (*i)->getAttributes()->find("fileUrl")->second;
			break;
		}
	}
	return dtdurl;
}
