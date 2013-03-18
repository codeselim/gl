#ifndef __DTD_ELT_H_

#define __DTD_ELT_H_

#include <map>
#include <list>

#include "enums.h"
#include "dtd_attr.h"
#include "child_elt.h"

using namespace std;

typedef map<string, DtdAttr*> DtdAttrMap;

class EltContent {
	DtdElement* content;
	EltContentType contentType;
	Card card;

public:
	EltContent(EltContentType type):
		contentType(type), content(NULL) {};
	EltContent(DtdElement * contentList, EltContentType type = LIST):
		contentType(type), content(contentList) {};
	~EltContent() {if(content != NULL) delete content; };
};

class DtdElt {
	// DtdAttrMap * attributes;
	EltContent* content;
	string name;

public:
	string getName() { return name; };
	DtdElt(string theName, EltContent* theContent):
		name(theName), content(theContent) {};
	// DtdElt(DtdAttrMap* theAttributes, EltContent* theContent):
		// attributes(theAttributes), content(theContent) {};
	~DtdElt() {/*delete attributes;*/ delete content; };
};

#endif

