#include "html_builder.h"
#include <sstream>
#include "../data_structures/text_node.h"
#include "stdlib.h"
#include "string.h"

#define DBG

#ifdef DBG
#include "iostream"
#endif

// Constant for toXML() comparison
const XSLElement* APPLY_TEMPLATES = (const XSLElement*) Element::createElement(
	new ElementName(string("xsl"), string("apply-templates")), 
	NULL, 
	NULL);
const char* APPLY_TEMPLATES_STR = (const char*) APPLY_TEMPLATES->toXML().c_str();
const int APPLY_TEMPLATES_STR_LEN = strlen(APPLY_TEMPLATES_STR);

HTMLBuilder::HTMLBuilder(XSLElement* xsl_root, Element* xml_root) {
	this->xsl_root = xsl_root;
	this->xml_root = xml_root;
	createIndex();
}

/** Builds the matched_element -> XSLElement index
 */
void HTMLBuilder::createIndex() {
	// Note : All the template are supposed to be children of the XSL stylesheet root element
	if(NULL == xsl_root) {
		return;
	}
	nodeList* children = xsl_root->getChildren();
	if(NULL == children) {
		return;
	}
	for(nodeList::iterator it = children->begin(); it != children->end(); ++it) {
		if((*it)->getName() == "template") {
			XSLElement* xslel = (XSLElement*)(*it);
			index[xslel->getAttributeValue("match")] = xslel;
		}
	}
}

string HTMLBuilder::html() {
	stringstream str;
	// Its children...
	
	if (NULL != this->xml_root)
	{
		str << this->do_build_html_on_children(this->xml_root);
	}
	return str.str();
}

string HTMLBuilder::do_build_html_on_children(Node* node) {
	stringstream str;
	nodeList* children = xml_root->getChildren();
	for(nodeList::iterator it = children->begin(); it != children->end(); ++it) {
		Node* curr = (*it);
		if (TextNode::NODE_NAME != curr->getName()) // Not a text node, so, is an element node (or some children class of Element)
		{
			str << build_html(curr);
		} else {
			str << curr->toXML();
		}
	}
	return str.str();
}


string HTMLBuilder::build_html(Node* curr) {
	// Is there any template for this node ?
	throw NotYetImplementedException();
	stringstream str;

	templateIndex::iterator it = index.find(curr->getName());

	if (it != index.end())
	{
		XSLElement* xslel = it->second;
		const char* tmp = xslel->toXML().c_str();
		const char* pch = strstr(tmp, APPLY_TEMPLATES_STR);
		const char* end = tmp;
		while(*end++);// find the end of the string
		end--; // not the \0 to be taken into account (if we did ++end instead of end++ then the empty string would cause a array overread)
		char* before = (char*)malloc(sizeof(char) * (pch - tmp) + 1);
		char* after = (char*)malloc(sizeof(char) * (end - pch) + 1);
		strncpy (before, tmp, APPLY_TEMPLATES_STR_LEN);// copy the beginning of the string to "before"
		strcpy (after, pch + APPLY_TEMPLATES_STR_LEN); // copy the end of the string to "end"
#ifdef DBG
		std::cout << "Before=" << before << std::endl;
		std::cout << "After=" << before << std::endl;
#endif
		str << before << do_build_html_on_children(xslel) << after;
		free(before);
		free(after);
	}
	return str.str();
}