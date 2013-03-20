#include <iostream>
#include <sstream>
#include <exception>
#include "special_node.h"


string SpecialNode::cardToString() {
	switch (this->type) {
		case SNT_DOCTYPE: return "!DOCTYPE";
		case SNT_XML_VER: return "?xml";
		case SNT_SPECIAL: return "?"; //TODO
	}
}

string SpecialNode::toXML() {
	stringstream str;
	
	str << "<" << cardToString();


	//	for(attributesMap::iterator it1 = attributes->begin(); it1 != attributes->end(); ++it1) {
	//		str << " " << (it1->first) << " " << (it1->second) << " ";
	//	}
		str << " " <<  (*attributes)["rootName"] << " " << (*attributes)["ref"] << " \"" << (*attributes)["fileUrl"] << "\">";

	// str << ">";// close the XML tag
	// // Its children...
	// if (NULL != this->children)
	// {
	// 	for(nodeList::iterator it = this->children->begin(); it != this->children->end(); ++it) {
	// 		str << endl << (*it)->toXML();
	// 	}
	// }
	// str << endl << "</" << this->name << ">";// close the XML tag
	return str.str();
}