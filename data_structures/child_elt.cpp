#include <sstream>

string ChildElt::toString() {
	return eltName;
}

string ChildListElt::toString() {
	stringstream str;
	for (list<DtdElement*>::iterator i = eltList.begin(); i != eltList.end(); ++i) {
		str << "\t" << i->toString() << endl;
	}
}