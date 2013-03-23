#include "dtd_elt.h"

string DtdElt::typeToString() {
	switch (type) {
		case T_ANY: return "ANY";
		case T_EMPTY: return "EMPTY";
		case TOKEN: return "";
		default: return "Pas de type valide!";
	}
}


void DtdElt::copy(DtdElt* toCopy) {
	if (attributes == NULL || content != NULL) {
		cerr << "Erreur lors de la copie. Attributes de la destination doit être non NULL et content NULL" << endl;
		return;
	}
	if (attributes != NULL || content == NULL) {
		cerr << "Erreur lors de la copie. Attributes de la cible doit être NULL et content non NULL" << endl;
		return;
	}

	content = toCopy->content;
	type = toCopy->type;
	name = string(toCopy->name);
	toCopy->content = NULL;
	delete toCopy;
}

string DtdElt::toString() {
	stringstream str;
	str << name << " " << typeToString();
	if (content != NULL) {
		str << "\n\tElements fils: " << content->toString();
	}

	if (attributes != NULL) {
		str << "\n\tAttributs: ";

		for (list<DtdAttr*>::iterator i = attributes->begin(); i != attributes->end(); ++i) {
			if (i != attributes->begin()) {
				str << ", ";
			}
			str << (*i)->toString();
		}
	}

	return str.str();
}
