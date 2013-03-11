#include <map>
#include <list>
#include <string>
#include "node.h"
#include "../AnalyseurXML/commun.h"

using namespace std;

typedef list<Node*> nodeList;
typedef map<string, string> attributesMap;

class Element : Node {
	list<Node*> * children;
	map<string, string> * attributes;
    string ns; // namespace
    string name;

  public:
  	Element(ElementName* en, attributesMap* attrs,  nodeList* children=NULL);
  };