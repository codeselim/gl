#include "dtd_elt.h"

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
	str << name;
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