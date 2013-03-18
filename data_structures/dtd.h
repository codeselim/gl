#ifndef __DTD_H_
#define __DTD_H_

#include <map>
#include <iostream>

#include "dtd_elt.h"
#include "dtd_attr.h"

using namespace std;

class DtdEltMap {
	map<string, DtdElt*>* elt_map;
	map<string, list<DtdAttr*> * > * attr_map;
public:
	DtdEltMap(): elt_map(new map<string, DtdElt*>()), attr_map(new map<string, list<DtdAttr*> *>()) {};
	void add_elt(DtdElt* element) { elt_map->insert(pair<string, DtdElt*>(element->getName(), element)); };
	void add_attrs(string element, list<DtdAttr*> * attList) {
		if (attList == NULL) {
			cout << "oh shit!" << endl;
		}
		list<DtdAttr*> * l = (*attr_map)[element];
		for (std::list<DtdAttr*>::iterator i = attList->begin(); i != attList->end(); ++i) {
			cout << (*i)->toString() << endl;
			l->push_back(*i); // @TODO segfault
		}
		attList->clear();
		delete attList;
		//l->splice(l->end(), *attList); /* déplacer les éléments de attList vers l */
		// delete attList;
	}
	~DtdEltMap() {delete elt_map; delete attr_map; };
};

class Dtd {
	DtdEltMap* elements;
public:
	Dtd(DtdEltMap* lst_elements): elements(lst_elements) {};
	string toString() {return string("TODO: DTD::toString()"); };
};

#endif
