#include <string>
using namespace std;

enum NodeType {_text, a, b, p};

class Node {
	NodeType type;
public:
	virtual string toXML() = 0;
};
