/*
 * File:   element_getters.cpp
 * Author: tdubourg
 *
 * Created on 18.03.2013, 09:24:37
 */

#include <iostream>
#include <stdlib.h>
#include "../data_structures/node.h"
#include "../data_structures/element.h"
#include "../data_structures/text_node.h"
#include "./test_utils.h"
/*
 * Simple C Test Suite
 */

bool testGetChildren() {
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

	nodeList *expected, *result;
	expected = &la;
	result = ((Element*)a)->getChildren();
	if (expected != result)
	{
		fail("testGetChildren", "\n-------------------------\nExpected (a) : " << expected << "\n-------------------------\nGot: " << result);
	}
	
	expected = &la;
	result = ((Element*)b)->getChildren();
	if (expected != result)
	{
		fail("testGetChildren", "\n-------------------------\nExpected (b): " << expected << "\n-------------------------\nGot: " << result);
	}

	return true;
}

bool testGetSpaceSeparatedChildrenList() {
	// Children lists for a and b elements
	nodeList la = nodeList();
	nodeList lc = nodeList();
	Node* b = new TextNode(string("Blorg1"));
	Node* d = new TextNode(string("Blorg2"));
	Node* e = new TextNode(string("Blorg3"));
	ElementName ena = ElementName(string("xml"), string("blorg"));
	ElementName enc = ElementName(string("yoyo"), string("blorg"));
	Node* c = new Element(&enc, NULL, &lc);
	// A children
	la.push_back(b);
	la.push_back(c);
	la.push_back(e);
	// C children
	lc.push_back(d);
	Node* a = new Element(&ena, NULL, &la);

	string expected, result;
	expected = "#PCDATA yoyo #PCDATA";
	result = ((Element*)a)->getSpaceSeparatedChildrenList();
	if (expected != result)
	{
		fail("testGetChildren", "\n-------------------------\nExpected (a) : " << expected << "\n-------------------------\nGot: " << result);
	}
	
	expected = "#PCDATA";
	result = ((Element*)b)->getSpaceSeparatedChildrenList();
	if (expected != result)
	{
		fail("testGetChildren", "\n-------------------------\nExpected (b): " << expected << "\n-------------------------\nGot: " << result);
	}

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
		testGetChildren, 
		testGetSpaceSeparatedChildrenList
	};
	// insert here your new test names :
	const char* tests_names[] = {
		"testGetChildren", 
		"testGetSpaceSeparatedChildrenList"
	};
	// increment this number each time you add a new test
	int test_count = 2;

	std::cout << "%SUITE_STARTING% element_getters" << std::endl;
	std::cout << "%SUITE_STARTED%" << std::endl;

	for (int i = 0; i < test_count; ++i)
	{
		const char* name = tests_names[i];
		std::cout << "%TEST_STARTED% " << name << " (element_getters)" << std::endl;
		try {
			if(!tests[i]()) {
				fail_counter++;
			}
		} catch(exception e) { //Let's assume we will not test exception throwing for "passing" tests but only for "failing" them
			std::cout << "%TEST_FAILED% time=0 testname=" << name << " (element_getters) message="  << "Exception raised" << e.what() << std::endl;
			fail_counter++;
		}
		std::cout << "%TEST_FINISHED% time=0 " << name << " (element_getters)" << std::endl;
	}

	std::cout << "%SUITE_FINISHED% time=0" << std::endl;

	std::cout << test_count << " tests run. " << fail_counter << " failed." << std::endl;

	return (EXIT_SUCCESS);
}

