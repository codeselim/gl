#ifndef __DTD_H_
#define __DTD_H_

#include <map>
#include <iostream>

#include "child_elt.h"
#include "dtd_attr.h"

using namespace std;

class DtdEltMap {
	map<string, DtdElement*>* elt_map;
	map<string, list<DtdAttr*> * > * attr_map;
public:
	DtdEltMap(): elt_map(new map<string, DtdElement*>()), attr_map(new map<string, list<DtdAttr*> *>()) {};
	void add_elt(DtdElement* element) { elt_map->insert(pair<string, DtdElement*>(element->getName(), element)); };
	void add_attrs(string element, list<DtdAttr*> * attList) ;
	list<DtdAttr*> * getAttributes(string eltName) { return (*attr_map)[eltName]; };
	~DtdEltMap();
};

class Dtd {
	DtdEltMap* elements;
public:
	Dtd(DtdEltMap* lst_elements): elements(lst_elements) {};
	string toString();
};

#endif
