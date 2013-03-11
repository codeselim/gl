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
/*
 * Simple C++ Test Suite
 */

void test1() {
	std::cout << "to_xml test 1" << std::endl;
}

void test2() {
	std::cout << "to_xml test 2" << std::endl;
	nodeList l = nodeList();
	Node* b = new TextNode(string("Blorg"));
	l.push_back(b);
	ElementName en = ElementName(string("xml"), string("blorg"));
	Node* a = new Element(&en, NULL, &l);
	
	string expected = "<xml>\nBlorg\n</xml>";
	string result = a->toXML();
	
	if (result != expected) {
		std::cout << "%TEST_FAILED% time=0 testname=test2 (to_xml) message=toXML did not answer expected result." << std::endl;
		std::cout << "Expected : " << std::endl << expected << std::endl;
		std::cout << "Got: " << std::endl << result << std::endl;
	}
	
	delete b;
	delete a;
	
}

int main(int argc, char** argv) {
	std::cout << "%SUITE_STARTING% to_xml" << std::endl;
	std::cout << "%SUITE_STARTED%" << std::endl;

	std::cout << "%TEST_STARTED% test1 (to_xml)" << std::endl;
	test1();
	std::cout << "%TEST_FINISHED% time=0 test1 (to_xml)" << std::endl;

	std::cout << "%TEST_STARTED% test2 (to_xml)\n" << std::endl;
	test2();
	std::cout << "%TEST_FINISHED% time=0 test2 (to_xml)" << std::endl;

	std::cout << "%SUITE_FINISHED% time=0" << std::endl;

	return (EXIT_SUCCESS);
}

