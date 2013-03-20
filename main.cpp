#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <dtd.h>
#include <document.h>

#include <dtd.tab.h>
#include <xml.tab.h>

#include <Validate.h>

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
  //dtddebug = 1; // pour désactiver l'affichage de l'exécution du parser LALR, commenter cette ligne

	extern FILE *dtdin, *xmlin;
  int err;
  Document* xmlDocument = NULL;
	Dtd* dtd = NULL;

  xmlin = fopen(xmlfile, "r");
  if (!xmlin) {
  	cerr << "Impossible d'ouvrir le fichier nommé '" << xmlfile << "'" << endl;
  	return EXIT_FAILURE;
  }

  err = xmlparse(&xmlDocument);
  fclose(xmlin);

  if (err != 0) {
  	cerr << "Analyse du XML terminée avec " << err << " erreurs" << endl;
    return EXIT_FAILURE;
  }

  cout << "------------------------------------" << endl;
  cout << xmlDocument->toXML() << endl;
  cout << "------------------------------------" << endl;

  if (! xmlDocument->getDtdFileName().empty()) {
  	strcpy(dtdfile, xmlDocument->getDtdFileName().c_str());
  }

  if (dtdfile == NULL) {
  	cerr << "Pas de fichier DTD." << endl;
  	return EXIT_FAILURE;
  }

	dtdin = fopen(dtdfile, "r");
	if (!dtdin) {
  	cerr << "Impossible d'ouvrir le fichier nommé '" << dtdfile << "'" << endl;
  	return EXIT_FAILURE;
  }

  err = dtdparse(&dtd);
  fclose(dtdin);

<<<<<<< HEAD
	if (err != 0) {
  	cerr << "Analyse du DTD terminée avec " << err << " erreurs" << endl;
    return EXIT_FAILURE;
=======
	  	//Validating xml with dtd
	  	Validate validator(xmlDocument, dtd);
	  	cout << validator.isValid() << endl;

  	}
>>>>>>> 8765b712092a6d9ca3e7af6ad2b255f3dda330ff
  }


  cout << dtd->toString() << endl;
  cout << "------------------------------------" << endl;

  /* dtd et xmlDocument sont maintenant correctement initialisés. */


  delete dtd;
  delete xmlDocument;

  return EXIT_SUCCESS;
}
