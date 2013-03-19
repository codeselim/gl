#include "dtd.h"
#include <sstream>

void DtdEltMap::add_attrs(string element, list<DtdAttr*> * attList) {
	map<string, DtdElt*>::iterator it = elt_map->find(element);

	if (it == elt_map->end()) {
		elt_map->insert(pair<string, DtdElt*>(element, new DtdElt(element, attList)));
	} else {
		list<DtdAttr*> * l = it->second->getAttributes();
		if (l == NULL) {
			it->second->setAttributes(attList);
		} else {
			l->splice(l->end(), *attList); /* déplacer les éléments de attList vers l */
			delete attList;
		}
	}

}

void DtdEltMap::add_elt(DtdElt* element) {
	map<string, DtdElt*>::iterator it = elt_map->find(element->getName());

	if (it == elt_map->end()) {
		elt_map->insert(pair<string, DtdElt*>(element->getName(), element));
	} else {
		it->second->copy(element);
	}
}

DtdEltMap::~DtdEltMap() {
	for (map<string, list<DtdAttr*> *>::iterator i = attr_map->begin(); i != attr_map->end(); ++i) {
		for (list<DtdAttr*>::iterator it = i->second->begin(); it != i->second->end(); ++it) {
			delete (*it);
		}
		delete i->second;
	}
	delete attr_map;
	for (map<string, DtdElt*>::iterator i = elt_map->begin(); i != elt_map->end(); ++i) {
		delete i->second;
	}
	delete elt_map;
}

string DtdEltMap::toString() {
	stringstream str;

	for (map<string, DtdElt*>::iterator i = elt_map->begin(); i != elt_map->end(); ++i) {
		str << i->second->toString() << endl;
	}
	return str.str();
};

string Dtd::toString() {return elements->toString(); };
