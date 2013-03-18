/* 
 * File:   to_xml.cpp
 * Author: tdubourg
 *
 * Created on 11 mars 2013, 11:32:33
 */

#include <stdlib.h>
#include <iostream>
#include "../data_structures/node.h"
#include "../data_structures/element.h"
#include "../data_structures/text_node.h"
#include "./test_utils.h"

/*
 * Simple C++ Test Suite
 */

bool simpleToXMLWithAttributes() {
	nodeList l = nodeList();
	Node* b = new TextNode(string("Blorg"));
	l.push_back(b);
	ElementName en = ElementName(string("xml"), string("blorg"));
	attributesMap attrMap;
	attrMap["blorg1"] = "blurp";
	attrMap["huhu"] = "haha";
	attrMap["numeric"] = "42";
	Node* a = new Element(&en, &attrMap, &l);
	
	string expected = "<xml blorg1=\"blurp\" huhu=\"haha\" numeric=\"42\">\nBlorg\n</xml>";
	string result = a->toXML();
	
	if (result != expected) {
		fail("simpleToXMLWithAttributes (to_xml)", "toXML did not answer expected result." << std::endl
		 << "Expected : " << std::endl << expected << std::endl
		 << "Got: " << std::endl << result << std::endl)
	}
	
	delete b;
	delete a;
	return true;
}

bool simpleToXMLWithoutAttributes() {
	nodeList l = nodeList();
	Node* b = new TextNode(string("Blorg"));
	l.push_back(b);
	ElementName en = ElementName(string("xml"), string("blorg"));
	Node* a = new Element(&en, NULL, &l);
	
	string expected = "<xml>\nBlorg\n</xml>";
	string result = a->toXML();
	
	if (result != expected) {
		fail("simpleToXMLWithoutAttributes (to_xml)", "toXML did not answer expected result." << std::endl
		 << "Expected : " << std::endl << expected << std::endl
		 << "Got: " << std::endl << result << std::endl)
	}
	
	delete b;
	delete a;
	return true;
}

bool ComplexXMLWithMixedElementsAndNodesWithoutAttributes() {
	// Children lists for a and b elements
	nodeList la = nodeList();
	nodeList lc = nodeList();
	Node* b = new TextNode(string("Blorg1"));
	Node* d = new TextNode(string("Blorg2"));
	Node* e = new TextNode(string("Blorg3"));
	la.push_back(b);
	lc.push_back(d);
	ElementName ena = ElementName(string("xml"), string("blorg"));
	ElementName enc = ElementName(string("yoyo"), string("blorg"));
	Node* c = new Element(&enc, NULL, &lc);
	la.push_back(c);
	la.push_back(e);
	Node* a = new Element(&ena, NULL, &la);
	
	
	string expected = "<xml>\nBlorg1\n<yoyo>\nBlorg2\n</yoyo>\nBlorg3\n</xml>";
	string result = a->toXML();
	
	if (result != expected) {
		fail("ComplexXMLWithMixedElementsAndNodesWithoutAttributes (to_xml)", "toXML did not answer expected result." << std::endl
		 << "Expected : " << std::endl << expected << std::endl
		 << "Got: " << std::endl << result << std::endl)
	}
	
	delete a;
	delete b;
	delete c;
	delete d;
	return true;
}


bool ComplexXMLWithMixedElementsAndNodesWithAttributes() {
	// Children lists for a and b elements
	nodeList la = nodeList();
	nodeList lc = nodeList();
	Node* b = new TextNode(string("Blorg1"));
	Node* d = new TextNode(string("Blorg2"));
	Node* e = new TextNode(string("Blorg3"));
	la.push_back(b);
	lc.push_back(d);
	attributesMap attrMapa, attrMapc;
	//* Recall: The attributes will be output in alphabetical order, not in the order of addition to the attributesMap
	attrMapa["blorg1"] = "blurp";
	attrMapa["huhu"] = "haha";
	attrMapc["numeric"] = "42";
	attrMapc["vulgar"] = "Hey, you touch my tralala.";
	attrMapc["type"] = "xml";

	ElementName ena = ElementName(string("xml"), string("blorg"));
	ElementName enc = ElementName(string("yoyo"), string("blorg"));
	Node* c = new Element(&enc, &attrMapc, &lc);
	la.push_back(c);
	la.push_back(e);
	Node* a = new Element(&ena, &attrMapa, &la);
	
	string expected = "<xml blorg1=\"blurp\" huhu=\"haha\">\nBlorg1\n<yoyo numeric=\"42\" type=\"xml\" vulgar=\"Hey, you touch my tralala.\">\nBlorg2\n</yoyo>\nBlorg3\n</xml>";
	string result = a->toXML();
	
	if (result != expected) {
		fail("ComplexXMLWithMixedElementsAndNodesWithoutAttributes (to_xml)", "toXML did not answer expected result." << std::endl
		 << "\n------------------------\nExpected : " << std::endl << expected << std::endl
		 << "------------------------\nGot: " << std::endl << result << std::endl)
	}
	
	delete a;
	delete b;
	delete c;
	delete d;
	return true;
}

bool testTemplateCopyPasteMe() {
	fail("Put My Name here", "Error message here (Not Yet Implemented)");
	return true;
}

int main(int argc, char** argv) {
	int fail_counter = 0;
	// insert your new tests function pointers:
	test_func tests[] = {
		simpleToXMLWithAttributes, 
		simpleToXMLWithoutAttributes, 
		ComplexXMLWithMixedElementsAndNodesWithoutAttributes,
		ComplexXMLWithMixedElementsAndNodesWithAttributes
	};
	// insert here your new test names :
	const char* tests_names[] = {
		"simpleToXMLWithAttributes", 
		"simpleToXMLWithoutAttributes", 
		"ComplexXMLWithMixedElementsAndNodesWithoutAttributes", 
		"ComplexXMLWithMixedElementsAndNodesWithAttributes"
	};
	// increment this number each time you add a new test
	int test_count = 4;

	std::cout << "%SUITE_STARTING% to_xml" << std::endl;
	std::cout << "%SUITE_STARTED%" << std::endl;

	for (int i = 0; i < test_count; ++i)
	{
		const char* name = tests_names[i];
		std::cout << "%TEST_STARTED% " << name << " (to_xml)" << std::endl;
		if(!tests[i]()) {
			fail_counter++;
		}
		std::cout << "%TEST_FINISHED% time=0 " << name << " (to_xml)" << std::endl;
	}

	std::cout << "%SUITE_FINISHED% time=0" << std::endl;

	std::cout << test_count << " tests run. " << fail_counter << " failed." << std::endl;

	return (EXIT_SUCCESS);
}

