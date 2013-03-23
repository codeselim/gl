#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <dtd.h>
#include <document.h>

#include <dtd.tab.h>
#include <xml.tab.h>
#include <xsl.tab.h>

#include <Validate.h>
#include <html_builder.h>

using namespace std;

#define EXIT(success) \
	if (xmlDocument != NULL) delete xmlDocument;\
	if (dtd != NULL) 	delete dtd;\
	if (xsl != NULL) 	delete xsl;\
	return success ? EXIT_SUCCESS : EXIT_FAILURE;\



int main(int argc, char** argv) {
	extern FILE *dtdin, *xmlin, *xslin;
	extern int dtdparse(Dtd**);
	extern int xmlparse(Document**);
	extern int xslparse(Document**);

	int err;
	string xmlfile, dtdfile, xslfile;
	Document* xmlDocument = NULL;
	Document* xsl = NULL;
	Dtd* dtd = NULL;

	/** Lecture paramètres ligne de commande ***********************************/
	xmlfile = string(argv[1]);
	if(argc > 2 && strcmp("_", argv[2]) != 0) {
		dtdfile = string(argv[2]);
	}
	if(argc > 3) {
		xslfile = string(argv[3]);
	}
	//dtddebug = 1; // pour désactiver l'affichage de l'exécution du parser LALR, commenter cette ligne

	/** Lecture XML ************************************************************/
	cerr << "Fichier XML: " << xmlfile << endl;
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


	/** Lecture DTD ***********************************************************/
	if ( dtdfile.empty() && !xmlDocument->getDtdFileName().empty()) {
		string sep = "/";
		string tmp = string(xmlfile);

		// Reconstitution du chemin du fichier DTD à partir de celui du XML et de la valeur indiquée
		// dans la balise <!DOCTYPE> du XML. Ne supporte que les chemins relatifs.
		unsigned found = tmp.rfind(sep); // position de la dernière occurence de sep
  	if ( found != std::string::npos) {
    	tmp.replace(found+1, tmp.substr(found+1).length(), xmlDocument->getDtdFileName());
  	}

		dtdfile = string(tmp.c_str());
	}

	cerr << "Fichier DTD: " << dtdfile << endl;

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

	/** Analyse XML par rapport à la DTD ***************************************/

		if (!dtd->isValid()) {
			cerr << "La DTD n'est pas cohérente. (Des éléments non déclarés peut être?)" << endl;
			EXIT(false);
		}

		//Validating xml with dtd
		Validate validator(xmlDocument, dtd);

		if (validator.isValid()) {
			cerr << "Le document XML est conforme à la DTD." << endl;
		} else {
			cerr << "Le document XML n'est pas conforme à la DTD." << endl;
			EXIT(false);
		}
	}

	/** Transformation XSL *****************************************************/
	cerr << "Fichier XSL: " << xslfile << endl;
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

		// cerr << "------------------------------------" << endl;
		// cerr << xsl->getRoot()->toXML() << endl;
		// cerr << "------------------------------------" << endl;
		// cerr << xmlDocument->getRoot()->toXML() << endl;
		// cerr << "------------------------------------" << endl;

		HTMLBuilder htmlb((XSLElement*)xsl->getRoot(), xmlDocument->getRoot());

		cout << htmlb.html() << endl;
	}

	/****************************************************************/

	EXIT(true);
}
