/* 
 * File:   html_builder.cpp
 * Author: tdubourg
 *
 * Created on 11 mars 2013, 11:32:33
 */

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "../data_structures/xsl_element.h"
#include "../xsl/html_builder.h"
#include "./test_utils.h"

/*
 * Simple C++ Test Suite
 */

bool htmlb_instanciation() {
	XSLElement* a = (XSLElement*) Element::createElement(new ElementName("xsl", "stylesheet"), NULL, NULL);
	Element* b = Element::createElement(new ElementName("blorg", "stylesheet"), NULL, NULL);
	HTMLBuilder* c = new HTMLBuilder(a, b);

	if (NULL == c)
	{
		fail("htmlb_instanciation", "Returned pointer is null.");
	}
	delete c;
	return true;
}

typedef bool(*test_func)(void);

int main(int argc, char** argv) {
	int fail_counter = 0;
	// insert your new tests function pointers:
	test_func tests[] = {
		htmlb_instanciation
	};
	// insert here your new test names :
	const char* tests_names[] = {
		"htmlb_instanciation"
	};
	// increment this number each time you add a new test
	int test_count = 5;

	std::cout << "%SUITE_STARTING% html_builder" << std::endl;
	std::cout << "%SUITE_STARTED%" << std::endl;

	for (int i = 0; i < test_count; ++i)
	{
		const char* name = tests_names[i];
		std::cout << "%TEST_STARTED% " << name << " (html_builder)" << std::endl;
		try {
			if(!tests[i]()) {
				fail_counter++;
			}
		} catch(exception e) { //Let's assume we will not test exception throwing for "passing" tests but only for "failing" them
			std::cout << "%TEST_FAILED% time=0 testname=" << name << " (html_builder) message="  << "Exception raised" << e.what() << std::endl;
			fail_counter++;
		}
		std::cout << "%TEST_FINISHED% time=0 " << name << " (html_builder)" << std::endl;
	}

	std::cout << "%SUITE_FINISHED% time=0" << std::endl;

	std::cout << test_count << " tests run. " << fail_counter << " failed." << std::endl;

	return (EXIT_SUCCESS);
}

