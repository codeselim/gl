#include "html_builder.h"
#include <sstream>
#include "../data_structures/text_node.h"
#include "stdlib.h"
#include "string.h"

// #define DBG

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
			string matchAgainst = xslel->getAttributeValue("match");
            index[matchAgainst] = xslel;
		}
	}
}

string HTMLBuilder::html() {
	stringstream str;
	
	if (NULL != this->xml_root)
	{
		str << this->build_html(this->xml_root);
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
			str << endl << curr->toXML();
		}
	}
	return str.str();
}


string HTMLBuilder::build_html(Node* curr) {
	stringstream str;

	string currName = curr->getName();
    templateIndex::iterator it = index.find(currName);

	if (it != index.end())
	{
		XSLElement* xslel = it->second;
		int newLineLen = strlen("\n");
		string tmpstring = xslel->toXML();
		const char* tmp = tmpstring.c_str();
		const char* end = tmp;
		while(*(end++));// find the end of the string
		end--; // not the \0 to be taken into account (if we did ++end instead of end++ then the empty string would cause a array overread)
		int openingTagLen = xslel->xmlOpeningTag().length();
		int closingTagLen = xslel->xmlClosingTag().length();
		const char* openingTagPtr = tmp+openingTagLen + newLineLen;//necessarily begins at 0... ! //strstr(tmp, openingTag);
		const char* closingTagPtr = end-closingTagLen - newLineLen; //necessarily ends at end-closingTagLen strstr(tmp, xslel->xmlClosingTag().c_str());
		const char* pch = strstr(tmp, APPLY_TEMPLATES_STR);
		int beforeSize = (pch - openingTagPtr);
		int afterSize = (closingTagPtr - (pch + APPLY_TEMPLATES_STR_LEN));
		char* before = (char*)malloc(sizeof(char) * beforeSize + 1);
		char* after = (char*)malloc(sizeof(char) * afterSize + 1);
		strncpy (before, openingTagPtr, beforeSize);// copy the beginning of the string to "before"
		strncpy (after, pch + APPLY_TEMPLATES_STR_LEN + 1, afterSize); // copy the end of the string to "end"
#ifdef DBG
		std::cout << "tmp: ||" << tmp << "||" << std::endl;
		std::cout << "Opening tag: ||" << openingTagPtr << "||" << std::endl;
		std::cout << "Beforesize=" << beforeSize << std::endl;
		std::cout << "Aftersize=" << afterSize << std::endl;
		std::cout << "Before=" << before << std::endl;
		std::cout << "After=" << after << std::endl;
#endif
		str << before << do_build_html_on_children(xslel) << after;
		free(before);
		free(after);
	}
	return str.str();
}