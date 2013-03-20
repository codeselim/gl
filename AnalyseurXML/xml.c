using namespace std;
#include <cstring>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include "commun.h"
#include <special_node.h>
#include <document.h>
#include "yy.tab.h"



extern Document* rootExpr;
int yyparse();

int main(int argc, char **argv) {
  int err;

  //yydebug = 1; // pour enlever l'affichage de l'exécution du parser, commenter cette ligne

  // Document* document = NULL;
  err = yyparse();
  
  if (err != 0) {
    printf("Parse ended with %d error(s)\n", err);
  } else {
    printf("Parse ended with success\n", err);
    cout << rootExpr->toXML() << endl;
  } 
  return 0;
}
