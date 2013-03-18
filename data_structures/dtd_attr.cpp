#include <cstring>

#include "dtd_attr.h"


Type AttrType::stringToType(string strType) {
	if (strcmp("CDATA", strType.c_str())) { return T_CDATA; }
	if (strcmp("ID", strType.c_str())) { return ID; }
	if (strcmp("IDREF", strType.c_str())) { return IDREF; }
	if (strcmp("IDREFS", strType.c_str())) { return IDREFS; }
	if (strcmp("NMTOKEN", strType.c_str())) { return NMTOKEN; }
	if (strcmp("NMTOKENS", strType.c_str())) { return NMTOKENS; }
	if (strcmp("ENTITY", strType.c_str())) { return ENTITY; }
	if (strcmp("ENTITIES", strType.c_str())) { return ENTITIES; }
	if (strcmp("NOTATION", strType.c_str())) { return NOTATION; }
}

AttrType::AttrType(string cdata_or_token):
	enumValues(NULL), type(stringToType(cdata_or_token)) {};

AttrType::AttrType(list<string>* enums):
	enumValues(enums), type(_ENUM) {};

AttrType::~AttrType() {
	if (enumValues != NULL) {
		delete enumValues;
	}
}

DtdAttr::~DtdAttr() {
	delete type;
	delete defaultDecl;
}