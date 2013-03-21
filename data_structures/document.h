#ifndef __DOCUMENT_H_

#define __DOCUMENT_H_

#include <string>
#include "node.h"
#include "element.h"
#include "special_node.h"
#include "../AnalyseurXML/commun.h"

using namespace std;


class Document {
private:
	Element* rootNode;
	list<SpecialNode*> *  declarations;

public:
	Document(list<SpecialNode*> * declarations, Element* rootNode);
	~Document();
	virtual string toXML() const;
	string getRootName(){return rootNode->getName();};
	Element* getRoot () {return rootNode;}
	string getDtdFileName();
};

#endif
