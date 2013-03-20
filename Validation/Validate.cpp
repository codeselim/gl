#include "Validate.h"

Validate::Validate(Document *xmlFile, Dtd * dtdFile) {
	xml = xmlFile;
	dtd = dtdFile;
}

bool Validate::isElementValid(Element *elt) {
	String eltName = elt->getName();
	AttributesMap attrXml = elt->getAttributes();
	DtdEltMap* elements = dtd->getElements();
	list<DtdAttr*> * attrDtd = elements->getAttributes(eltName);
	bool foundAttr = false;

// Check attributes
	for(AttributesMap::iterator itXml = attrXml.begin(); itXml != attrXml.end(); itXml++) {
  String attrNameXml = itXml->first();
  foundAttr = false;
  for (*(attrDtd)::iterator itDtd = attrDtd->begin(); itDtd != attrDtd->end(); itDtd++) {
  	String attrNameDtd = (*itDtd)->toString();
  	if(attrNameXml == attrNameDtd ) {
  		foundAttr = true;
  	}
  }
  if(!foundAttr) {
  	return false;
  }

}

// Check children
String childrenString = elt->getChildren();
DtdElement * dtdElt = elements.get(eltName);
String dtdEltRegex = dtdElt->getChildren()->toString();
EltType eltContentType = dtdElt->getChildren()->getType();
T_PCDATA, TOKEN
if( eltType == T_EMPTY) {
	if(childrenString.length() > 0) {
		return false;
	}
}
else if (eltType == LIST || eltType == TOKEN) {
	//Match regex
	String regex = createRegex(dtdElt);
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

