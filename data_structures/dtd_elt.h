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

public:
	string getName() { return name; }
	DtdElt(Child* theContent):name(""), content(theContent) {}
	DtdElt(EltType theType):name(""), content(NULL), type(theType) {}
	void setName(string theName) {name = theName;}
	~DtdElt() { delete content; }
	string toString() { return name + " " + content->toString(); }
};

#endif

