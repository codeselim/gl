#include "html_builder.h"
#include <sstream>
#include "../data_structures/text_node.h"

HTMLBuilder::HTMLBuilder(XSLElement* xsl_root, Element* xml_root) {
	this->xsl_root = xsl_root;
	this->xml_root = xml_root;
	createIndex();
}

/** Builds the matched_element -> XSLElement index
 */
void HTMLBuilder::createIndex() {
	// Note : All the template are supposed to be children of the XSL stylesheet root element
	nodeList* children = xsl_root->getChildren();
	for(nodeList::iterator it = children->begin(); it != children->end(); ++it) {
		XSLElement* xslel = (XSLElement*)(*it);
		index[xslel->getAttributeValue("match")] = xslel;
	}
}

string HTMLBuilder::html() {
	stringstream str;
	// Its children...
	
	if (NULL != this->xml_root)
	{
		nodeList* children = xml_root->getChildren();
		for(nodeList::iterator it = children->begin(); it != children->end(); ++it) {
			Node* curr = (*it);
			if (TextNode::NODE_NAME != curr->getName()) // Not a text node
			{
				str << build_html(curr);
			}
		}
	}
	return str.str();
}

string HTMLBuilder::build_html(Node* curr) {
	// Is there any template for this node ?
	throw NotYetImplementedException();
	return string("");
	// templateIndex::iterator it = index.find(curr->getName());

	// if (it->second != index.end())
	// {
		
	// }
}