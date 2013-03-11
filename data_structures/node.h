
using namespace std;

enum NodeType {_text, a, b, p};

abstract class Node {
	NodeType type;
	string toXML() = 0;
};