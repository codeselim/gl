#include "text_node.h"

TextNode::TextNode(string content) {
	this->content = content;
}

string TextNode::toXML() {
	return this->content;
}

