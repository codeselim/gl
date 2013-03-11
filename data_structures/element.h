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

class Element : Node {
private:
    nodeList * children;
    attributesMap * attributes;
    Element* parent;
    string ns; // namespace
    string name;

public:
	Element& setParent(Element* e);
	Element* getParent();
        Element(ElementName* en, attributesMap* attrs,  nodeList* children = NULL);
	virtual string toXML();
};

#endif
