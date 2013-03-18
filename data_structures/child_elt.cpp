#include <sstream>

#include "child_elt.h"

string ChildElt::toString() {
	return eltName;
}

string ChildListElt::toString() {
	stringstream str;
	for (list<Child*>::iterator i = eltList->begin(); i != eltList->end(); ++i) {
		str << "\t" << (*i)->toString() << endl;
	}
	return str.str();
}