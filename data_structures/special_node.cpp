#include <iostream>
#include <sstream>
#include "special_node.h"


string SpecialNode::cardToString() {
	switch (this->type) {
		case SNT_DOCTYPE: return "!DOCTYPE";
		case SNT_XML_VER: return "?xml";
		case SNT_SPECIAL: return "?";
	}
}

string SpecialNode::getName() {
	switch (this->type) {
		case SNT_DOCTYPE: return "doctype";
		case SNT_XML_VER: return "xmlver";
		case SNT_SPECIAL: return "special";
	}
}

string SpecialNode::toXML() {
	stringstream str;

	str << "<" << cardToString();
	str << " " <<  (*attributes)["rootName"];
	str << " " << (*attributes)["ref"];
	str << " \"" << (*attributes)["fileUrl"] << "\"";
	str << ">";

	return str.str();
}
