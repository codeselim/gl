#ifndef __CHILD_ELT_H_

#define __CHILD_ELT_H_

#include <string>
#include <list>
#include <iostream>

#include "enums.h"

using namespace std;

class DtdElement {
protected:
	Card card;
	EltType type;
	string eltName;
	DtdElement(Card theCard = NONE, EltType theType = T_PCDATA):
		card(theCard), type(theType), eltName("") {};
public:
	void setCard(Card theCard) { card = theCard; };
	string getName() { return eltName; };
	string setName(string name) { eltName = name; };
	virtual string toString() = 0;
};

class ChildListElt: public DtdElement {
	list<DtdElement*> * eltList;
	ListType listType;
public:
	void add(DtdElement* elt) { eltList->push_back(elt); };
	ChildListElt(DtdElement* elt, ListType theType, Card theCard):
		DtdElement(theCard), eltList(new list<DtdElement*>()), listType(theType) {eltList->push_back(elt); };
	ChildListElt(ListType theType): listType(theType), eltList(new list<DtdElement*>()) {};
	~ChildListElt() {delete eltList; };
	virtual string toString();
};

class ChildElt: public DtdElement {
public:
	ChildElt(string name, Card theCard = NONE, EltType type = TOKEN):
		DtdElement(theCard, type) {eltName = name; };
	ChildElt(EltType theType): DtdElement(NONE, theType) {};
	virtual string toString();
};

#endif
