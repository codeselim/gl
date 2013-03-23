#ifndef __DTD_ELT_H_

#define __DTD_ELT_H_

#include <map>
#include <list>
#include <sstream>

#include "enums.h"
#include "dtd_attr.h"
#include "child_elt.h"

using namespace std;

class DtdElt {
	Child* content;
	EltType type;
	string name;
	list<DtdAttr*> * attributes;
	string typeToString();

public:
	DtdElt(Child* theContent): name(""), content(theContent), attributes(NULL), type(TOKEN) {}

	DtdElt(EltType theType): name(""), content(NULL), type(theType), attributes(NULL) {}

	DtdElt(string theName, list<DtdAttr*> * theAttributes):
		name(theName), content(NULL), attributes(theAttributes), type(TOKEN) {}

	~DtdElt();
	void copy(DtdElt* toCopy); /* Attention, fait un delete sur l'élément toCopy! */
	void setName(string theName) {name = string(theName); }
	void setAttributes(list<DtdAttr*> * la) { attributes = la; }
	list<DtdAttr*> * getAttributes() { return attributes; }
	Child * getChildren() { return content; }
	EltType getType() { return type; }
	string getName() { return name; }
	string toString();
};

#endif

