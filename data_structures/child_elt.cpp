#include <sstream>

#include "child_elt.h"

string Child::cardToString() {
	switch (card) {
		case NONE: return "";
		case QMARK: return "?";
		case C_PLUS: return "+";
		case STAR: return "*";
	}
}

string Child::typeToString() {
	switch (type) {
		case T_ANY: return "(ANY)";
		case T_EMPTY: return "(EMPTY)";
		case LIST: return "(LIST)";
		case T_PCDATA: return "(PCDATA)";
		case TOKEN: return "(TOKEN)";
	}
}

string ChildElt::toString() {
	// return eltName + cardToString() + " " + typeToString();
	return eltName + cardToString();
}

string ChildListElt::toString() {
	string separator;
	stringstream str;

	if (listType == CHOICE) {
		separator = "| ";
	} else {
		separator = ", ";
	}

	str << "(";
	for (list<Child*>::iterator i = eltList->begin(); i != eltList->end(); ++i) {
		if (i != eltList->begin()) {
			str << separator;
		}
		str << (*i)->toString();
	}
	str << ")";
	// return str.str() + cardToString() + " " + typeToString();
	return str.str() + cardToString();
}
