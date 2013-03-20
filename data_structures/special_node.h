#include "enums.h"
#include "element.h"
#include "../AnalyseurXML/commun.h"

using namespace std;

class SpecialNode: public Element {
	SpecialNodeType type;

	public:
		SpecialNode(SpecialNodeType atype, ElementName* en, attributesMap* attrs) : Element(en,  attrs, NULL), type (atype){}
		virtual string toXML();
		SpecialNodeType getType() { return type; }
};