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
protected:
    nodeList * children;
    attributesMap * attributes;
    Element* parent;
    string ns; // namespace
    string name;
    Element(ElementName* en, attributesMap* attrs,  nodeList* children = NULL);

public:
	/** @function createELement
	 * Factory method that creates a XML Element
	 * @return the created element
	 */
	static Element* createElement(ElementName* en, attributesMap* attrs,  nodeList* children = NULL);
	Element& setParent(Element* e);
	virtual string getName();
	Element* getParent();
	nodeList* getChildren();
	string getAttributeValue(string attr);
	string getSpaceSeparatedChildrenList();
	/*
		@function toXML Serializes the current element (and its children) to a XML string
		/!\ The attributes are ALWAYS output in alphabetical order /!\
		@return string valid XML for this element
	*/
	virtual string toXML() const;
	virtual string getInnerXML() const;
	virtual string xmlOpeningTag() const;
	virtual string xmlClosingTag() const;
};

#endif
