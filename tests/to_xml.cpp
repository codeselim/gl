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
	std::cout << "to_xml test 2" << std::endl;
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
	std::cout << "to_xml test 2" << std::endl;
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
	fail("ComplexXMLWithMixedElementsAndNodesWithoutAttributes", "Not Yet Implemented");
	return true;
}

typedef bool(*test_func)(void);

int main(int argc, char** argv) {
	int fail_counter = 0;
	test_func tests[] = {simpleToXMLWithAttributes, simpleToXMLWithoutAttributes, ComplexXMLWithMixedElementsAndNodesWithoutAttributes};
	const char* tests_names[] = {"simpleToXMLWithAttributes", "simpleToXMLWithoutAttributes", "ComplexXMLWithMixedElementsAndNodesWithoutAttributes"};
	int test_count = 3;

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

