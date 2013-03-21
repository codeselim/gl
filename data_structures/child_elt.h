#ifndef __CHILD_ELT_H_

#define __CHILD_ELT_H_

#include <string>
#include <list>
#include <iostream>

#include "enums.h"

using namespace std;

class Child {
protected:
	Card card;
	EltType type;
	Child(Card theCard = NONE, EltType theType = T_PCDATA):
		card(theCard), type(theType){};
public:
	void setCard(Card theCard) { card = theCard; };
	virtual string toString() = 0;
	EltType getType();
	string cardToString(); /* Retourne ?, + ou * suivant la valeur de card */
	string typeToString();
};

class ChildListElt: public Child {
	list<Child*> * eltList;
	ListType listType;
public:
	void add(Child* elt) { eltList->push_back(elt); };
	void addFront(Child* elt) { eltList->push_front(elt); };
	ChildListElt(Child* elt, ListType theType, Card theCard):
		Child(theCard, LIST), eltList(new list<Child*>()), listType(theType) {eltList->push_back(elt); };
	ChildListElt(ListType theType):
		Child(NONE, LIST), listType(theType), eltList(new list<Child*>()) {};
	~ChildListElt() {delete eltList; };
	virtual string toString();
};

class ChildElt: public Child {
	string eltName;
public:
	ChildElt(string name, Card theCard = NONE, EltType type = TOKEN):
		Child(theCard, type) {eltName = name; };
	ChildElt(): Child(NONE, T_PCDATA), eltName("#PCDATA")  {};
	string getName() { return eltName; };
	string setName(string name) { eltName = name; };
	virtual string toString();
};

#endif
