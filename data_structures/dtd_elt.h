#ifndef __DTD_ELT_H_

#define __DTD_ELT_H_

#include <map>
#include <list>

using namespace std;

typedef DtdAttrMap map<string, DtdAttr>;
enum EltContentType {ANY, EMPTY, LIST}

class EltContent {
	ChildElt* content;
	EltContentType contentType;
	Card card;

public:
	EltContent(EltContentType type):
		contentType(type), content(NULL) {};
	EltContent(ChildElt * contentList, EltContentType type = LIST):
		contentType(type), content(contentElt) {};
	~EltContent() {if(content != NULL) delete content};
};

class DtdElt {
	DtdAttrMap * attributes;
	EltContent* content;
	string name;

public:
	DtdElt(DtdAttrMap* theAttributes, EltContent theContent):
		attributes(theAttributes), content(theContent) {};
	~DtdElt() {delete attributes; delete content;};
};

#endif

