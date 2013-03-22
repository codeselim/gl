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
 #include "../data_structures/text_node.h"

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

bool html_building(){

        //<xml>
        //Blorg
        //</xml>
        nodeList l;
        Node* b = new TextNode(string("Blorg"));
        l.push_back(b);
        ElementName en = ElementName(string("blorg"), string("xml"));
        Element* a = Element::createElement(&en, NULL, &l);

        //<xsl:stylesheet> 
        //<xsl:template match="xml">
        //<html>
        //<body>
        //<xsl:apply-templates/>
        //</body>
        //</html>
        //</xsl:template>
        //</xsl:stylesheet>
        nodeList n;
        nodeList n1;
        nodeList n2;
        nodeList n3;
        nodeList n4;
        ElementName dt = ElementName(string("xsl"), string("stylesheet"));
        ElementName dt1 = ElementName(string("xsl"), string("template"));
        ElementName dt2 = ElementName(string("blorg"), string("html"));
        ElementName dt3 = ElementName(string("blorg"), string("body"));
        ElementName dt4 = ElementName(string("xsl"), string("apply-templates"));
        attributesMap am;
        am["match"] = "xml";
        Node* f = Element::createElement(&dt4, NULL, &n4);
        n3.push_back(f);
        Node* e = Element::createElement(&dt3, NULL, &n3);
        n2.push_back(e);
        Node* d = Element::createElement(&dt2, NULL, &n2);
        n1.push_back(d);
        XSLElement* c1 = (XSLElement*) Element::createElement(&dt1, &am, &n1);
        n.push_back(c1);
        XSLElement* root = (XSLElement*) Element::createElement(&dt, NULL, &n);

        HTMLBuilder htmlb(root, a);
        string result = htmlb.html();

        string expected = "<html>\n<body>\nBlorg\n</body>\n</html>";
        if (expected != result)
        {
        	fail("html_building", "Result did not match expected.\nExpected: \n-----------------\n" << expected << "\n-----------------\nResult: \n-----------------\n" << result << "\n-----------------" << std::endl)
        }
        return true;
}


bool html_building2(){

        //<xml>
        //<a><b><c></c></b></a>
        //</xml>
        nodeList lroot, la, lb;
        Node* b = new TextNode(string("Blorg"));
        lroot.push_back(b);
        ElementName enroot = ElementName(string("blorg"), string("xml"));
        Element* xmlroot = Element::createElement(&enroot, NULL, &lroot);

        ElementName ena = ElementName(string("blorg"), string("a"));
        Element* _a = Element::createElement(&ena, NULL, &la);

        lroot.push_back(_a);

        ElementName enb = ElementName(string("blorg"), string("b"));
        Element* _b = Element::createElement(&enb, NULL, &lb);

        la.push_back(_b);

        ElementName enc = ElementName(string("blorg"), string("c"));
        Element* _c = Element::createElement(&enc, NULL, NULL);

        lb.push_back(_c);

        //<xsl:stylesheet> 
        //<xsl:template match="xml">
        //<html>
        //<body>
        //<xsl:apply-templates/>
        //</body>
        //</html>
        //</xsl:template>
        //</xsl:stylesheet>
        nodeList n;
        nodeList n1;
        nodeList n2;
        nodeList n3;
        nodeList n4;
        ElementName dt = ElementName(string("xsl"), string("stylesheet"));
        ElementName dt1 = ElementName(string("xsl"), string("template"));
        ElementName dt2 = ElementName(string("blorg"), string("html"));
        ElementName dt3 = ElementName(string("blorg"), string("body"));
        ElementName dt4 = ElementName(string("xsl"), string("apply-templates"));
        attributesMap am;
        am["match"] = "xml";
        Node* f = Element::createElement(&dt4, NULL, &n4);
        n3.push_back(f);
        Node* e = Element::createElement(&dt3, NULL, &n3);
        n2.push_back(e);
        Node* d = Element::createElement(&dt2, NULL, &n2);
        n1.push_back(d);
        XSLElement* c1 = (XSLElement*) Element::createElement(&dt1, &am, &n1);
        n.push_back(c1);
        XSLElement* root = (XSLElement*) Element::createElement(&dt, NULL, &n);

        HTMLBuilder htmlb(root, xmlroot);
        string result = htmlb.html();

        string expected = "<html>\n<body>\nBlorg<a>\n<b>\n<c>\n</c>\n</b>\n</a>\n</body>\n</html>";
        if (expected != result)
        {
                fail("html_building", "Result did not match expected.\nExpected: \n-----------------\n" << expected << "\n-----------------\nResult: \n-----------------\n" << result << "\n-----------------" << std::endl)
        }
        return true;
}



bool html_building_without_a_apply_templates() {

        //<xml>
        //Blorg
        //</xml>
        nodeList l;
        Node* b = new TextNode(string("Blorg"));
        l.push_back(b);
        ElementName en = ElementName(string("blorg"), string("xml"));
        Element* a = Element::createElement(&en, NULL, &l);

        //<xsl:stylesheet> 
        //<xsl:template match="xml">
        //<html>
        //<body>
        //BlArg
        //</body>
        //</html>
        //</xsl:template>
        //</xsl:stylesheet>
        nodeList n;
        nodeList n1;
        nodeList n2;
        nodeList n3;
        nodeList n4;
        ElementName dt = ElementName(string("xsl"), string("stylesheet"));
        ElementName dt1 = ElementName(string("xsl"), string("template"));
        ElementName dt2 = ElementName(string("blorg"), string("html"));
        ElementName dt3 = ElementName(string("blorg"), string("body"));
        attributesMap am;
        am["match"] = "xml";
        Node* f = new TextNode(string("BlArg"));
        n3.push_back(f);
        Node* e = Element::createElement(&dt3, NULL, &n3);
        n2.push_back(e);
        Node* d = Element::createElement(&dt2, NULL, &n2);
        n1.push_back(d);
        XSLElement* c1 = (XSLElement*) Element::createElement(&dt1, &am, &n1);
        n.push_back(c1);
        XSLElement* root = (XSLElement*) Element::createElement(&dt, NULL, &n);

        HTMLBuilder htmlb(root, a);
        string result = htmlb.html();

        string expected = "<html>\n<body>\nBlArg\n</body>\n</html>";
        delete f, e, d, c1, root;
        if (expected != result)
        {
                fail("html_building", "Result did not match expected.\nExpected: \n-----------------\n" << expected << "\n-----------------\nResult: \n-----------------\n" << result << "\n-----------------" << std::endl)
        }
        return true;
}
typedef bool(*test_func)(void);

int main(int argc, char** argv) {
	int fail_counter = 0;
	// insert your new tests function pointers:
	test_func tests[] = {
		htmlb_instanciation,
                html_building,
                html_building2,
                html_building_without_a_apply_templates
	};
	// insert here your new test names :
	const char* tests_names[] = {
		"htmlb_instanciation",
                "html_building",
                "html_building2",
                "html_building_without_a_apply_templates"
	};
	// increment this number each time you add a new test
	int test_count = 3;

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

