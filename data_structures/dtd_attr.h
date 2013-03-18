#ifndef __DTD_ATTR_H_

#define __DTD_ATTR_H_

#include <string>
#include <list>

#include "enums.h"

using namespace std;


class AttrType {
	list<string>* enumValues;
	Type type;
	Type stringToType(string strType);

	public:
		AttrType(string cdata_or_token);
		AttrType(list<string>* enums);
		~AttrType();
};

class DefaultDeclaration {
	bool fixed;
	string value;

	public:
		DefaultDeclaration(string _value, bool isFixed = false):
			value(_value), fixed(isFixed){};
};

class DtdAttr {
  string name;
  AttrType* type;
  DefaultDeclaration* defaultDecl;

	public:
	  DtdAttr(string _name, AttrType* _type, DefaultDeclaration* _defaultDecl ):
	  	name(_name), type(_type), defaultDecl(_defaultDecl){};
	  ~DtdAttr();
	  string toString() { return name;};
};

#endif
