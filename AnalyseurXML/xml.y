%{

using namespace std;
#include <cstring>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include "commun.h"
#include "yy.tab.h"
#include <document.h>

// ces trois fonctions devront changer de nom dans le cas où l'otion -p est utilisée
int yywrap(void);
void yyerror(const char *msg);
int yylex(void);

Document* rootExpr;
%}

%code requires {
#ifndef __TYPES_XML_INCLUDED__
#define __TYPES_XML_INCLUDED__
#include <element.h>
#include <text_node.h>
#include <document.h>

#endif
}

%union {
   char * s;
   ElementName * en;  /* le nom d'un element avec son namespace, cf commun.h */
   nodeList * nl;
   Element * elt;
   Attribut * attr;
   attributesMap * am;
   Document * d;
}

%token EGAL SLASH SUP SUPSPECIAL DOCTYPE
%token <s> ENCODING VALEUR DONNEES COMMENT NOM ENNOM
%token <en> OBALISEEN OBALISE OBALISESPECIALE FBALISE FBALISEEN
%type <en> ouvre
%type <elt> element
%type <nl> contenu_opt vide_ou_contenu ferme_contenu_et_fin
%type <attr> attribut
%type <am> attributs_opt
%type <d> document

%%

document
 : declarations_opt element misc_seq_opt  {$$ = new Document(NULL, $2); rootExpr = $$;}
 ;


misc_seq_opt
 : misc_seq_opt misc
 | /*vide*/
 ;

misc
 : COMMENT
 ;


declarations_opt
 : declarations_opt declaration
 | /*vide*/
 ;

declaration
 : DOCTYPE NOM NOM VALEUR SUP
 ;


element
 : ouvre attributs_opt vide_ou_contenu  {$$ = new Element($1, $2, $3);}
 ;

attributs_opt
 : attributs_opt attribut   {$$ = $1; $$->insert(*$2); delete $2;}
 | /*vide*/ {$$ = new attributesMap();}
 ;

attribut
 : NOM EGAL VALEUR  {$$ = new pair<string, string>(string($1), string($3));}
 ;

ouvre
 : OBALISE  {$$ = $1;}
 | OBALISEEN {$$ = $1;}
 ;

vide_ou_contenu
 : SLASH SUP  {$$ = new nodeList();}
 | ferme_contenu_et_fin SUP {$$ = $1;}
 ;

ferme_contenu_et_fin
 : SUP contenu_opt FBALISE  {$$ = $2;}
 ;

contenu_opt
 : contenu_opt DONNEES  {$$ = $1; $$->push_back(new TextNode($2));}
 | contenu_opt misc   {$$ = $1;}
 | contenu_opt element  {$$ = $1; $$->push_back($2);}
 | /*vide*/   {$$ = new nodeList();}
 ;

%%

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

int yywrap(void)
{
  return 1;
}

void yyerror(const char *msg) {
  cout << msg;
}

