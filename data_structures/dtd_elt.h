#include <map>
#include <list>

using namespace std;

typedef DtdAttrMap map<string, DtdAttr>;

class DtdElt {
	DtdAttrMap * attributes;
	list<ChildElt> * children;
};
