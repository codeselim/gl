#ifndef __DOCUMENT_H_

#define __DOCUMENT_H_

#include <string>
#include "node.h"
#include "element.h"
#include "../AnalyseurXML/commun.h"

using namespace std;


class Document {
private:
	Element* rootNode;
	list<Node*> *  declarations;

public:
	Document(list<Node*> * declarations, Element* rootNode);
	~Document();
	string toXML();
};

#endif
