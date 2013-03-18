using namespace std;
#include <cstdio>
#include <cstring>
#include <stdlib.h>

int main (int argc, char **argv) {

FILE* fichierXML = NULL;

if (argc < 2){
	printf("Nombre d'arguments insuffisants");
	return 1;
}

char temp1[200] = "AnalyseurXML/analyseXML < AnalyseurXML/";
char* cmd = strcat(temp1, argv[1]);
system(cmd);

char temp2[200] = "AnalyseurXML/";
char * chemin = strcat(temp2, argv[1]);
fichierXML = fopen(chemin, "r");

 if (fichierXML != NULL)
    {
	char resultat[100];
	fscanf(fichierXML, "<!DOCTYPE %s SYSTEM \"%s",resultat,resultat);
	resultat[strlen(resultat)-2] = '\0';
	fclose(fichierXML);

	char temp3[200] = "AnalyseurDTD/analyseDTD < AnalyseurDTD/";
	char* cmd = strcat(temp3, resultat);
	system(cmd);

    }
    else
    {
        printf("Impossible d'ouvrir le fichier");
    }

return 0;
}
