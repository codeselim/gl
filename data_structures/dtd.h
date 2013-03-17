#ifndef __DTD_H_

#define __DTD_H_

/* DTD */
#include <map>

using namespace std;

enum Card {NONE, QMARK, PLUS, STAR};
enum ListType {CHOICE, SEQ};
enum EltType {TOKEN, PCDATA};

class DtdEltMap {
	map<string, DtdElt>* elt_map;
	DtdEltMap();
	add_elt();
	add_attrs(string element, list<DtdAttr*> * attList); /*Attention: delete la liste à la fin!*/
};

class Dtd {
	DtdEltMap* elements;
	Dtd(DtdEltMap* lst_elements);
};

#endif
