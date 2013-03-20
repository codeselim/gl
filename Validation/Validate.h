#ifndef __VALIDATE_H_

#define __VALIDATE_H_

#include <string>
#include "../data_structures/document.h"
#include "../data_structures/dtd.h"
#include "../data_structures/element.h"

class Validate {

protected:
	Document *xml;
	Dtd *dtd;

public:

	Validate(Document *xmlFile, Dtd *dtdFile);
	bool isValid();
	bool isElementValid(Element *elt);

};

#endif