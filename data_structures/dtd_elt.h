#ifndef __DTD_ELT_H_

#define __DTD_ELT_H_

#include <map>
#include <list>
#include <sstream>

#include "enums.h"
#include "dtd_attr.h"
#include "child_elt.h"

using namespace std;

// typedef map<string, DtdAttr*> DtdAttrMap;

// class EltContent {
// 	DtdElement* content;
// 	EltContentType contentType;
// 	Card card;

// public:
// 	EltContent(EltContentType type):
// 		contentType(type), content(NULL) {};
// 	EltContent(DtdElement * contentList, EltContentType type = LIST):
// 		contentType(type), content(contentList) {};
// 	~EltContent() {if(content != NULL) delete content; };
// };

class DtdElt {
	// DtdAttrMap * attributes;
	Child* content;
	EltType type;
	string name;

public:
	string getName() { return name; };
	DtdElt(Child* theContent):name(""), content(theContent) {};
	DtdElt(EltType theType):name(""), content(NULL), type(theType) {};
	void setName(string theName) {name = theName;};
	// DtdElt(DtdAttrMap* theAttributes, EltContent* theContent):
		// attributes(theAttributes), content(theContent) {};
	~DtdElt() {/*delete attributes;*/ delete content; };
	string toString() {
		stringstream str;
		str << name << endl << content->toString() << endl;
		return str.str();
	}
};

#endif

