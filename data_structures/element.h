#include <map>
#include <list>

using namespace std;

typedef list<Node*> nodeList;
typedef map<string, string> attributesMap;

class Element : Node {
    list<Node*> * children;
    map<string, string> * attributes;
    string ns; // namespace
    string name;

    public:
	Element(ElementName* en, attributesMap* attrs);
        Element(ElementName* en, attributesMap* attrs,  nodeList* children);
};