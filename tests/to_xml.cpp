/* 
 * File:   to_xml.cpp
 * Author: tdubourg
 *
 * Created on 11 mars 2013, 11:32:33
 */

#include <stdlib.h>
#include <iostream>
#include <fstream>
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
	Node* a = Element::createElement(&en, &attrMap, &l);
	
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
	Node* a = Element::createElement(&en, NULL, &l);
	
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
	Node* c = Element::createElement(&enc, NULL, &lc);
	la.push_back(c);
	la.push_back(e);
	Node* a = Element::createElement(&ena, NULL, &la);
	
	
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
	Node* c = Element::createElement(&enc, &attrMapc, &lc);
	la.push_back(c);
	la.push_back(e);
	Node* a = Element::createElement(&ena, &attrMapa, &la);
	
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

bool testDocumentToXML() {
    
        Node* p_text = new TextNode(string("Comme l'écriture d'un compilateur est une tâche fort complexe, le programmateur a tout intérêt à travailler."));
        Node* titre_text = new TextNode(string("Réalisation d'un compilateur"));
        Node* resume_text = new TextNode(string("Ceci est extrait du livre \"Réaliser un compilateur : les outils Lex et Yacc\" de Nino Silverio."));
        
        nodeList p_children = nodeList();
        nodeList titre_children = nodeList();
        nodeList resume_children = nodeList();
        nodeList section_children = nodeList();
        nodeList chapitre_children = nodeList();
        nodeList rapport_children = nodeList();
        
        ElementName titre = ElementName(string("titre"), string(""));
        ElementName p = ElementName(string("p"), string(""));
        ElementName section = ElementName(string("section"), string(""));
        ElementName chapitre = ElementName(string("chapitre"), string(""));
        ElementName resume = ElementName(string("resume"), string(""));
        ElementName rapport = ElementName(string("rapport"), string(""));
        
         
        p_children.push_back(p_text);
	Node* p_elem = Element::createElement(&p, NULL, &p_children);
        
        titre_children.push_back(titre_text);
        Node* titre_elem = Element::createElement(&titre, NULL, &titre_children);
        
        section_children.push_back(titre_elem);
        section_children.push_back(p_elem);
        Node* section_elem = Element::createElement(&section, NULL, &section_children);
        
        chapitre_children.push_back(section_elem);
        Node* chapitre_elem = Element::createElement(&chapitre, NULL, &chapitre_children);
        
        resume_children.push_back(resume_text);
        Node* resume_elem = Element::createElement(&resume, NULL, &resume_children);
        
        rapport_children.push_back(resume_elem);
        rapport_children.push_back(chapitre_elem);
        Node* rapport_elem = Element::createElement(&rapport, NULL, &rapport_children);
        
        
        string line;
        string text = "";
        ifstream xmlfile;
        const char * filename = "../../tests/testfile1.xml";
        xmlfile.open(filename, ios::in);
        if(xmlfile.is_open()) { 
                while (getline (xmlfile,line)){
                        //getline (xmlfile,myline,'\t');
                    text+=line;
                }
        }
        else {
            fail("testDocumentToXML", "Failed to open xml file in ifstream");
        }     
                
       //having problems with encoding, i will write outputs to a file
       ofstream outfile;
       outfile.open("../../tests/output.txt", ios::trunc);
       if (outfile.is_open()){ 
           outfile<<rapport_elem->toXML();
       }
       else {
           fail("testDocumentToXML", "Failed to write output file");
       }
       
//	
//	if (result != expected) {
//		fail("simpleToXMLWithAttributes (to_xml)", "toXML did not answer expected result." << std::endl
//		 << "Expected : " << std::endl << expected << std::endl
//		 << "Got: " << std::endl << result << std::endl)
//	}
//        	
//	delete b;
//	delete a;
       xmlfile.close();
       outfile.close();
	return true;
}

typedef bool(*test_func)(void);

int main(int argc, char** argv) {
	int fail_counter = 0;
	// insert your new tests function pointers:
	test_func tests[] = {
		simpleToXMLWithAttributes, 
		simpleToXMLWithoutAttributes, 
		ComplexXMLWithMixedElementsAndNodesWithoutAttributes,
		ComplexXMLWithMixedElementsAndNodesWithAttributes,
                testDocumentToXML
	};
	// insert here your new test names :
	const char* tests_names[] = {
		"simpleToXMLWithAttributes", 
		"simpleToXMLWithoutAttributes", 
		"ComplexXMLWithMixedElementsAndNodesWithoutAttributes", 
		"ComplexXMLWithMixedElementsAndNodesWithAttributes",
                "testDocumentToXML"
	};
	// increment this number each time you add a new test
	int test_count = 5;

	std::cout << "%SUITE_STARTING% to_xml" << std::endl;
	std::cout << "%SUITE_STARTED%" << std::endl;

	for (int i = 0; i < test_count; ++i)
	{
		const char* name = tests_names[i];
		std::cout << "%TEST_STARTED% " << name << " (to_xml)" << std::endl;
		try {
			if(!tests[i]()) {
				fail_counter++;
			}
		} catch(exception e) { //Let's assume we will not test exception throwing for "passing" tests but only for "failing" them
			std::cout << "%TEST_FAILED% time=0 testname=" << name << " (to_xml) message="  << "Exception raised" << e.what() << std::endl;
			fail_counter++;
		}
		std::cout << "%TEST_FINISHED% time=0 " << name << " (to_xml)" << std::endl;
	}

	std::cout << "%SUITE_FINISHED% time=0" << std::endl;

	std::cout << test_count << " tests run. " << fail_counter << " failed." << std::endl;

	return (EXIT_SUCCESS);
}

