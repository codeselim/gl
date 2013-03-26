#ifndef __DOCUMENT_H_

#define __DOCUMENT_H_

#include <string>
#include "node.h"
#include "element.h"
#include "special_node.h"
#include "../AnalyseurXML/commun.h"

using namespace std;


class Document {
private:
	Element* rootNode;
	list<SpecialNode*> * declarations;

public:
	/** Constructs a new document
	 * @param declarations : List of document declaration (like doctypes)
	 * @param rootNode : The Node element that is the root of that document's xml tree
	 */
	Document(list<SpecialNode*> * declarations, Element* rootNode);
	~Document();
	
/** Serializes the document to an XML string
	*/
	virtual string toXML() const;
	/** Gets the name of the XML node that is the root of the document's XML tree */
	string getRootName(){return rootNode->getName();};
	/** Gets the XML node that is the root of the document's XML tree */
	Element* getRoot () {return rootNode;}
	/** Gets the name of the dtd file associated with this document, if any */
	string getDtdFileName();
};

#endif
