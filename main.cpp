#include <iostream>
#include <cstdio>

#include <dtd.h>
#include <document.h>

#include <dtd.tab.h>
#include <xml.tab.h>

using namespace std;
#define DBG
int dtdparse(Dtd**);
int main(int argc, char** argv) {
	// Note : We do not handle errors of values not being here arrays of things like that as the CLI interface
	// is manage by the "cli" file and we are thus garantueed there will always be a first argument
	// (excluded the binary's name) that is the XML file name and the
	// second and third arguments are going to be DTD and XSL
	char* xmlfile = argv[1];
#ifdef DBG
		cout << "XML file: " << xmlfile << endl;
#endif
	char*dtdfile, *xslfile;
	bool is_dtd = false, is_xsl = false;
	if(argc > 2) {
		is_dtd = true;
		dtdfile = argv[2];
#ifdef DBG
		cout << "DTD: " << dtdfile << endl;
#endif
	}
	if(argc > 3) {
		is_xsl = true;
		xslfile = argv[3];
#ifdef DBG
		cout << "XSL: " << xslfile << endl;
#endif
	}


	extern FILE* dtdin;

  FILE* fid;
  int err;
  fid = fopen("rap1.dtd", "r");
  //dtddebug = 1; // pour désactiver l'affichage de l'exécution du parser LALR, commenter cette ligne

  dtdin = fid;
  Dtd* dtd = NULL;
  err = dtdparse(&dtd);
  if (err != 0) {
    printf("Parse ended with %d error(s)\n", err);
    return 1;
  } else {
    printf("Parse ended with success\n", err);
    cout << dtd->toString() << endl;
  }

  fclose(fid);
  return 0;


	// Put main test logic here

	return 0;
}