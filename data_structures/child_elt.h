#ifndef __CHILD_ELT_H_

#define __CHILD_ELT_H_

#include <string>

#include "enums.h"

using namespace std;

class Element {
protected:
	Card card;
	Element(Card theCard = NONE): card(theCard) {};
public:
	void setCard(Card theCard) { card = theCard; };
};

class ChildListElt: public Element {
	list<Element*> * eltList;
	ListType type;
public:
	void add(Element* elt) { eltList->push_back(elt); };
	ChildListElt(Element* elt, ListType theType, Card theCard):
		Element(theCard), eltList(new list<Element*>()), type(theType) {eltList->push_back(elt); };
	ChildListElt(ListType theType): type(theType), eltList(new list<Element*>()) {};
	~ChildListElt() {delete eltList; };
};

class ChildElt: public Element {
	string eltName;
	EltType eltType;
public:
	ChildElt(string name, Card theCard = NONE, EltType type = TOKEN):
		Element(theCard), eltName(name), eltType(type) {};
	ChildElt(): eltName("PCDATA"), eltType(T_PCDATA) {};

};

#endif
