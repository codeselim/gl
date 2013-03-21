#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>

#include "html_builder.h"
#include "../data_structures/text_node.h"

#define DBG


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

#ifdef DBG
  cout << "templateIndex: " << endl;
  for (templateIndex::iterator i = index.begin(); i != index.end(); ++i) {
  	cout << "\t" << i->first << i->second->toXML() << endl;
  }
#endif
}

/** Builds the matched_element -> XSLElement index
 */
void HTMLBuilder::createIndex() {
	// Note : All the templates are supposed to be children of the XSL stylesheet root element
	if(NULL == xsl_root) {
		cerr << "La racine XSL vaut NULL" << endl;
		return;
	}
	nodeList* children = xsl_root->getChildren();
	if(NULL == children) {
		cerr << "La racine XSL est vide" << endl;
		return;
	}
	for(nodeList::iterator it = children->begin(); it != children->end(); ++it) {

		if((*it)->getName() == "template") {
			XSLElement* xslel = (XSLElement*)(*it);
			string matchAgainst = xslel->getAttributeValue("match");

			if (xslel->getChildren() == NULL || xslel->getChildren()->empty()) {
				cerr << "Le template n'a pas d'élément fils." << endl;
			} else {
				index[matchAgainst] = xslel;
			}

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

string HTMLBuilder::do_build_html_on_children(Element* node) {
	stringstream str;
	nodeList* children = node->getChildren();
	for(nodeList::iterator it = children->begin(); it != children->end(); ++it) {
		Node* curr = (*it);
		if (TextNode::NODE_NAME != curr->getName()) // Not a text node, so, is an element node (or some children class of Element)
		{
			str << build_html((Element*)curr);
		} else {
			str << curr->toXML();
		}
	}
	return str.str();
}


string HTMLBuilder::build_html(Element* curr) {
	stringstream str;
	string before, after;
  templateIndex::iterator it = index.find(curr->getName());

#ifdef DBG
  cout << "currentNode: " << curr->getFullName() << endl;
#endif

	if (it != index.end()) {
		Element* xslcontent = (Element*)it->second->getChildren()->front();

		string tmpstring = xslcontent->toXML();
		cout << "--" << tmpstring << endl;
		string pch = APPLY_TEMPLATES->toXML();
		before = tmpstring.substr(0, tmpstring.find(pch));
		after = tmpstring.substr(pch.length() + before.length());
	} else {
		cout << "ELSE!" << endl;
		before = curr->xmlOpeningTag();
		after = curr->xmlClosingTag();
	}
	str << before << do_build_html_on_children(curr) << after;
	return str.str();
}
