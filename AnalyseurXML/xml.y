%{

using namespace std;
#include <cstring>
#include <cstdio>
#include <iostream>
#include <cstdlib>

#include "commun.h"
#include <element.h>
#include <text_node.h>
#include <dtd.h>
#include <document.h>
#include <special_node.h>

// ces trois fonctions devront changer de nom dans le cas où l'otion -p est utilisée
int yywrap(void);
void yyerror(const char *msg);
int yylex(void);

Document* rootExpr;
%}

%union {
   char * s;
   ElementName * en;  /* le nom d'un element avec son namespace, cf commun.h */
   nodeList * nl;
   Element * elt;
   Attribut * attr;
   attributesMap * am;
   Document * d;
   SpecialNode * sn;
}

%token EGAL SLASH SUP SUPSPECIAL INFSPECIAL DOCTYPE
%token <s> ENCODING VALEUR DONNEES COMMENT NOM ENNOM
%token <en> OBALISEEN OBALISE OBALISESPECIALE FBALISE FBALISEEN

%type <en> ouvre
%type <elt> element
%type <nl> contenu_opt vide_ou_contenu ferme_contenu_et_fin declarations_opt
%type <attr> attribut
%type <am> attributs_opt
%type <d> document
%type <sn> declaration

%%

document
 : declarations_opt element misc_seq_opt  {$$ = new Document($1, $2); rootExpr = $$;}
 ;


misc_seq_opt
 : misc_seq_opt misc
 | /*vide*/
 ;

misc
 : COMMENT
 ;


declarations_opt
 : declarations_opt declaration { $$ = $1; $$->push_back($2);}
 | /*vide*/ { $$ = new list<Node*>();}
 ;

declaration
 : DOCTYPE NOM NOM VALEUR SUP { 
 				attributesMap* map = new attributesMap();
 				map->insert(pair<string,string>(string("fileUrl"), $4));
 				map->insert(pair<string,string>(string("ref"), $3));
 				map->insert(pair<string,string>(string("rootName"), $2));
 				$$ = new SpecialNode(SNT_DOCTYPE, new ElementName("", "DOCTYPE"), map);  
 				}
 /*				
 | INFSPECIAL attribut attribut SUPSPECIAL {
 				attributesMap* map2 = new attributesMap();
 				map2->insert(*$2);
 				map2->insert(*$3);
 				$$ = new SpecialNode(SNT_XML_VER, new ElementName("", "xml"), map2);
 				}
	*/
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

int yywrap(void)
{
  return 1;
}

void yyerror(const char *msg) {
  cout << msg;
}

