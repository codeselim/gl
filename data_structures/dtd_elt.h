#ifndef __DTD_ELT_H_

#define __DTD_ELT_H_

#include <map>
#include <list>

using namespace std;

typedef DtdAttrMap map<string, DtdAttr>;

class DtdElt {
	DtdAttrMap * attributes;
	list<ChildElt> * children;
	string name;
};

#endif

