#include <iostream>
#include <sstream>
#include <exception>
#include "special_node.h"


string SpecialNode::toXML() {
	stringstream str;
	
	// The element tag...
	str << "<docrype dude>>>";
	//if(this->type == )
	// str << "<" << this->name;

	// // Its attributes...
	// if (NULL != this->attributes)
	// {
	// 	for(attributesMap::iterator it1 = this->attributes->begin(); it1 != this->attributes->end(); ++it1) {
	// 		str << " " << (it1->first) << "=" << "\"" << (it1->second) << "\"";
	// 	}
	// }

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