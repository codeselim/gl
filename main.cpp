#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <dtd.h>
#include <document.h>

#include <dtd.tab.h>
#include <xml.tab.h>

#include <Validate.h>
#include <html_builder.h>

using namespace std;

#define EXIT(success) \
	if (xmlDocument != NULL) delete xmlDocument;\
	if (dtd != NULL) 	delete dtd;\
	return success ? EXIT_SUCCESS : EXIT_FAILURE;\



int main(int argc, char** argv) {
	extern FILE *dtdin, *xmlin, *xslin;
	extern int dtdparse(Dtd**);
	extern int xmlparse(Document**);
	extern int xslparse(Document**);



	// Note : We do not handle errors of values not being here arrays of things like that as the CLI interface
	// is manage by the "cli" file and we are thus garantueed there will always be a first argument
	// (excluded the binary's name) that is the XML file name and the
	// second and third arguments are going to be DTD and XSL

	int err;
	string xmlfile = string(argv[1]);
	Document* xmlDocument = NULL;
	Document* xsl = NULL;
	Dtd* dtd = NULL;

	/** Lecture paramètres ligne de commande ***********************************/
	string dtdfile, xslfile;
	if(argc > 2 && strcmp("_", argv[2]) != 0) {
		dtdfile = string(argv[2]);
	}
	if(argc > 3) {
		xslfile = string(argv[3]);
	}
	//dtddebug = 1; // pour désactiver l'affichage de l'exécution du parser LALR, commenter cette ligne

	/** Lecture XML ************************************************************/
	cerr << "XML: " << xmlfile << endl;
	xmlin = fopen(xmlfile.c_str(), "r");
	if (!xmlin) {
		cerr << "Impossible d'ouvrir le fichier nommé '" << xmlfile << "'" << endl;
		EXIT(false);
	}

	err = xmlparse(&xmlDocument);
	fclose(xmlin);

	if (err != 0) {
		cerr << "Analyse du XML terminée avec " << err << " erreurs" << endl;
		EXIT(false);
	}

	cout << "------------------------------------" << endl;
	cout << xmlDocument->toXML() << endl;
	cout << "------------------------------------" << endl;


	/** Lecture DTD ***********************************************************/
	if ( dtdfile.empty() && !xmlDocument->getDtdFileName().empty()) {
		string sep = "/";
		string tmp = string(xmlfile);

		unsigned found = tmp.rfind(sep); // position de la dernière occurence de sep
  	if ( found != std::string::npos) {
    	tmp.replace(found+1, tmp.substr(found+1).length(), xmlDocument->getDtdFileName());
  	}

		dtdfile = string(tmp.c_str());
	}

	cerr << "DTD: " << dtdfile << endl;

	if (dtdfile.empty()) {
		cerr << "Pas de fichier DTD." << endl;
	} else {
		dtdin = fopen(dtdfile.c_str(), "r");
		if (!dtdin) {
			cerr << "Impossible d'ouvrir le fichier nommé '" << dtdfile << "'" << endl;
			EXIT(false);
		}

		err = dtdparse(&dtd);
		fclose(dtdin);

		if (err != 0) {
			cerr << "Analyse du DTD terminée avec " << err << " erreurs" << endl;
			EXIT(false);
		}

		cout << dtd->toString() << endl;
		cout << "------------------------------------" << endl;

	/** Analyse XML par rapport à la DTD ***************************************/

		if (!dtd->isValid()) {
			cerr << "La DTD n'est pas cohérente. (Des éléments non déclarés peut être?)" << endl;
			EXIT(false);
		}

		//Validating xml with dtd
		Validate validator(xmlDocument, dtd);

		if (validator.isValid()) {
			cout << "Le document XML est conforme à la DTD." << endl;
		} else {
			cout << "Le document XML n'est pas conforme à la DTD." << endl;
			EXIT(false);
		}
	}

	/** Transformation XSL *****************************************************/
	if (xslfile.empty()) {
		cerr << "Pas de fichier XSL. " << endl;
	} else {
		xslin = fopen(xslfile.c_str(), "r");
		if (!xslin) {
			cerr << "Impossible d'ouvrir le fichier nommé '" << xslfile << "'" << endl;
			EXIT(false);
		}

		err = xslparse(&xsl);
		fclose(xslin);

		if (err != 0) {
			cerr << "Analyse du XSL terminée avec " << err << " erreurs" << endl;
			EXIT(false);
		}

		cout << xsl->toXML() << endl;
		cout << "------------------------------------" << endl;

		HTMLBuilder htmlb((XSLElement*)xsl->getRoot(), xmlDocument->getRoot());

		cout << htmlb.html() << endl;
		cout << "------------------------------------" << endl;
	}



	/****************************************************************/

	EXIT(true);
}
