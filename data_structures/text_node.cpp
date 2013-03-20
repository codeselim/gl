#include "text_node.h"

string TextNode::NODE_NAME = "#PCDATA";

TextNode::TextNode(string content) {
	this->content = content;
}

string TextNode::toXML() const {
	return this->content;
}

string TextNode::getName() {
	return TextNode::NODE_NAME;
}