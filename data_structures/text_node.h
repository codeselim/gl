#ifndef __TEXT_NODE_H_

#define __TEXT_NODE_H_


#include <string>
#include "node.h"

using namespace std;

class TextNode : public Node {
	string content;
public:
	TextNode(string content);
	virtual string toXML() const;
	virtual string getName();
	static string NODE_NAME;
};


#endif

