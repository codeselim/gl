#ifndef __ELEMENT_H_

#define __ELEMENT_H_

#include <map>
#include <list>
#include <string>
#include "node.h"
#include "../AnalyseurXML/commun.h"

using namespace std;

typedef list<Node*> nodeList;
typedef map<string, string> attributesMap;

class Element : public Node {
private:
    nodeList * children;
    attributesMap * attributes;
    Element* parent;
    string ns; // namespace
    string name;

public:
	Element& setParent(Element* e);
	Element* getParent();
	nodeList* getChildren();
	string getSpaceSeparatedChildrenList();
    Element(ElementName* en, attributesMap* attrs,  nodeList* children = NULL);
	/*
		@function toXML Serializes the current element (and its children) to a XML string
		/!\ The attributes are ALWAYS output in alphabetical order /!\
		@return string valid XML for this element
	*/
	virtual string toXML();
};

#endif
