#include <map>
#include <list>
#include <string>
#include "../AnalyseurXML/commun.h"
#include "node.h"

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
