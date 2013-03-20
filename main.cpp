#include <iostream>
#include <cstdio>

#include <dtd.h>
#include <document.h>

#include <dtd.tab.h>
#include <xml.tab.h>

using namespace std;
#define DBG

int dtdparse(Dtd**);
int xmlparse(Document**);


int main(int argc, char** argv) {
	// Note : We do not handle errors of values not being here arrays of things like that as the CLI interface
	// is manage by the "cli" file and we are thus garantueed there will always be a first argument
	// (excluded the binary's name) that is the XML file name and the
	// second and third arguments are going to be DTD and XSL
	char* xmlfile = argv[1];
#ifdef DBG
		cout << "XML file: " << xmlfile << endl;
#endif
		return 0;
}
