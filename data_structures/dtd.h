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
	void add_attrs(string element, list<DtdAttr*> * attList) ;

	list<DtdAttr*> * getAttributes(string eltName) { return (*attr_map)[eltName]; };
	string toString();
	~DtdEltMap();
};

class Dtd {
	DtdEltMap* elements;
public:
	Dtd(DtdEltMap* lst_elements): elements(lst_elements) {};
	string toString();
};

#endif
