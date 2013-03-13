#ifndef __DTD_ATTR_H_

#define __DTD_ATTR_H_

#include <string>

using namespace std;

class AttrType {
	bool isEnum;
	AttrType(string cdata_or_token);
	AttrType(list<string>* enums); /* TODO: delete list*/
};

class DefaultDeclaration {
	bool fixed;
	string value
	DefaultDeclaration(string _value, bool isFixed = false):
		value(_value), fixed(isFixed){};
};

class DtdAttr {
  string name;
  AttrType* type;
  DefaultDeclaration* defaultDecl;
  DtdAttr(string _name, AttrType* _type, DefaultDeclaration* _defaultDecl ):
  	name(_name), type(_type), defaultDecl(_defaultDecl){};
};

#endif
