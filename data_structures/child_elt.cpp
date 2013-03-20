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

EltType Child::getType() {
	return type;
}

string ChildElt::toString() {
	// return eltName + cardToString() + " " + typeToString();
	return eltName + cardToString();
}

string ChildListElt::toString() {
	string separator;
	stringstream str;
	string startWrapper;
	string endWrapper;

	if (listType == CHOICE && eltList->size() > 1) {
		separator = "| ";
		startWrapper = "[";
		endWrapper = "]";
	} else {
		separator = " ";
		startWrapper = "(";
		endWrapper = ")";
	}

	str << startWrapper;
	for (list<Child*>::iterator i = eltList->begin(); i != eltList->end(); ++i) {
		if (i != eltList->begin()) {
			str << separator;
		}
		str << (*i)->toString();
	}
	str << endWrapper;
	// return str.str() + cardToString() + " " + typeToString();
	return str.str() + cardToString();
}
