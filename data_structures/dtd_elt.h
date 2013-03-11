#include <map>
#include <list>

using namespace std;

class DtdElt {
   map<string, DtdAttr> * attributes;
   list<ChildElt> * children;
};
