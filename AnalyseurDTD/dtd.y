%{

using namespace std;
#include <list>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "struct_donnees_dtd.h"

void yyerror(char *msg);
int yywrap(void);
int yylex(void);

%}

%union { 
   char *s; 
   list<string> *l;
}

%token ELEMENT ATTLIST SUP OUVREPAR FERMEPAR VIRGULE BARRE FIXED EMPTY ANY PCDATA AST PTINT PLUS CDATA
%token <s> NOM TOKENTYPE DECLARATION VALEUR
/*%type <l> liste_opt liste*/

%%

main: dtd_list_opt
;

dtd_list_opt
: dtd_list_opt ATTLIST NOM att_definition_opt SUP
| dtd_list_opt element_declaration
| /* vide */
;

att_definition_opt
: att_definition_opt attribut
| /* vide */
;

attribut
: NOM att_type defaut_declaration
;

att_type
: CDATA
| TOKENTYPE
| type_enumere
;

type_enumere
: OUVREPAR liste_enum_plus FERMEPAR
;

liste_enum_plus
: liste_enum BARRE NOM
;

liste_enum
: NOM
| liste_enum BARRE NOM
;

defaut_declaration
: DECLARATION
| VALEUR
| FIXED VALEUR
;

element_declaration
: ELEMENT NOM content_spec SUP
;

content_spec
: EMPTY 
| ANY 
| mixed 
| children
;

children
: choice card_opt
| seq card_opt
;

card_opt
: PTINT
| PLUS
| AST
| /* vide */
;

name_or_choice_or_seq
: NOM
| choice
| seq
;

cp
: name_or_choice_or_seq card_opt
;

choice
: OUVREPAR cp contenu_choice FERMEPAR
;

contenu_choice
: contenu_choice BARRE cp
| BARRE cp
;

seq
: OUVREPAR cp contenu_seq_opt FERMEPAR
;

contenu_seq_opt
: contenu_seq_opt VIRGULE cp
| /* vide */
;

/*liste_opt
: liste_opt NOM     {$$ = $1; $$->push_back(string($2));} // rajoute un élément à la liste
| // vide           {$$ = new list<string>;} // règle réduite en premier, initialise la liste
;

liste
: liste NOM         {$$ = $1; $$->push_back(string($2));}
| NOM               {$$ = new list<string>; $$->push_back(string($1));}
;*/

mixed
: OUVREPAR PCDATA contenu_mixed 
| OUVREPAR PCDATA FERMEPAR
;

contenu_mixed
: contenu_mixed BARRE NOM
| FERMEPAR AST
;

%%

int main(int argc, char **argv)
{
  int err;

  yydebug = 1; // pour désactiver l'affichage de l'exécution du parser LALR, commenter cette ligne

  err = yyparse();
  if (err != 0) printf("Parse ended with %d error(s)\n", err);
        else  printf("Parse ended with success\n", err);
  return 0;
}
int yywrap(void)
{
  return 1;
}

void yyerror(char *msg)
{
  fprintf(stderr, "%s\n", msg);
}
