#include "Validate.h"

Validate::Validate(Document *xmlFile, Dtd * dtdFile) {
	xml = xmlFile;
	dtd = dtdFile;
}

bool Validate::isElementValid(Element *elt) {
	string eltName = elt->getName();
	attributesMap attrXml = elt->getAttributes();
	DtdEltMap* elements = dtd->getElements();
	list<DtdAttr*> * attrDtd = elements->getAttributes(eltName);
	bool foundAttr = false;

// Check attributes
	for(attributesMap::iterator itXml = attrXml.begin(); itXml != attrXml.end(); itXml++) {
		  string attrNameXml = itXml->first();
		  foundAttr = false;
		  for (*(attrDtd)::iterator itDtd = attrDtd->begin(); itDtd != attrDtd->end(); itDtd++) {
		  	string attrNameDtd = (*itDtd)->tostring();
		  	if(attrNameXml == attrNameDtd ) {
		  		foundAttr = true;
		  	}
		  }
		  if(!foundAttr) {
		  	return false;
  }

}

// Check children
string childrenstring = elt->getChildren();
DtdElement * dtdElt = elements.get(eltName);
string dtdEltRegex = dtdElt->getChildren()->tostring();
EltType eltContentType = dtdElt->getChildren()->getType();
T_PCDATA, TOKEN
if( eltType == T_EMPTY) {
	if(childrenstring.length() > 0) {
		return false;
	}
}
else if (eltType == LIST || eltType == TOKEN) {
	//Match regex
	string regex = createRegex(dtdElt);
	//TODO
}

// Get children of the current xml element
NodeList children = elt->getChildren();
// Validate children element nodes
for(NodeList::iterator itNode = children.begin(); itNode != children.end(); itNode++) {
	if((*itNode)->getType() == ELEMENT) {
		isElementValid(*itNode);
	}
}

}

bool Validate::isValid() {
	isElementValid(xml->getRoot());
}

