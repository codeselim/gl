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
	virtual string toXML() const;
	string getRootName(){return rootNode->getName();};
	string getDtdFileName();
};

#endif
