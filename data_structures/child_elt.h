#ifndef __CHILD_ELT_H_

#define __CHILD_ELT_H_

#include <string>
#include "dtd.h"

using namespace std;

class Element {
	Card card;
public:
	setCard(theCard) { card = theCard; };
};

class ChildListElt: public Element {
	list<Element*> * eltList;
	ListType type;
public:
	add(Element* elt) { eltList->push_back(elt); };
	ChildListElt(ListType theType): type(theType), eltList(new list<Element*>()) {};
	~ChildListElt() {delete eltList; };
};

class ChildElt: public Element {
	string eltName;
	EltType eltType;
public:
	ChildElt(string name, Card theCard = NONE, EltType type = TOKEN):
		eltName(name), card(theCard), eltType(type) {};
	ChildElt(): eltName("PCDATA"), card(NONE), eltType(PCDATA) {};

};

#endif
