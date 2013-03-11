#ifndef __TEXT_NODE_H_

#define __TEXT_NODE_H_


#include <string>
#include "node.h"

using namespace std;

class TextNode : Node {
	string content;
	string toXML();
};


#endif

