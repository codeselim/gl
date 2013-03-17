%{

using namespace std;
#include <list>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>

void yyerror(char *msg);
int yywrap(void);
int yylex(void);

Dtd* rootExpr = NULL;
%}

%union {
   char *s;
   list<string> *l;
}

%token ELEMENT ATTLIST SUP OUVREPAR FERMEPAR VIRGULE BARRE FIXED EMPTY ANY PCDATA AST PTINT PLUS CDATA
%token <s> NOM TOKENTYPE DECLARATION VALEUR
/*%type <l> liste_opt liste*/

%%

main
: dtd_list_opt  {$$ = new Dtd($1); rootExpr = $$}
;

dtd_list_opt
: dtd_list_opt ATTLIST NOM att_definition_opt SUP {$$ = $1; $$->add_attrs($3, $4);}
| dtd_list_opt element_declaration  {$$ = $1; $$->add_elt($2);}
| /* vide */  {$$ = new DtdEltMap();}
;

att_definition_opt
: att_definition_opt attribut {$$ = $1; $$->push_back($2);}
| /* vide */  {$$ = new list<DtdAttr*>();}
;

attribut
: NOM att_type defaut_declaration   {$$ = new DtdAttr($1, $2, $3);}
;

att_type
: CDATA   {$$ = new AttrType($1);}
| TOKENTYPE   {$$ = new AttrType($1);}
| type_enumere  {$$ = new AttrType($1);}
;

type_enumere
: OUVREPAR liste_enum_plus FERMEPAR   {$$ = $1;}
;

liste_enum_plus
: liste_enum BARRE NOM  {$$ = $1; $$->push_back($3);}
;

liste_enum
: NOM   {$$ = new list<string>(); $$->push_back($1);}
| liste_enum BARRE NOM  {$$ = $1; $$->push_back($3);}
;

defaut_declaration
: DECLARATION   {$$ = new DefaultDeclaration($1);}
| VALEUR  {$$ = new DefaultDeclaration($1);}
| FIXED VALEUR  {$$ = new DefaultDeclaration($2, true);}
;

element_declaration
: ELEMENT NOM content_spec SUP  {$$ = new DtdElt($2, $3);}
;

content_spec
: EMPTY   {$$ = new EltContent(EMPTY);}
| ANY   {$$ = new EltContent(ANY);}
| mixed   {$$ = new EltContent($1);}
| children  {$$ = new EltContent($1);}
;

/* ptr Element */
children
: choice card_opt {$$ = new ChildListElt($1, CHOICE, $2);}
| seq card_opt {$$ = new ChildListElt($1, SEQ, $2);}
;

card_opt
: PTINT {$$ = QMARK;}
| PLUS {$$ = PLUS;}
| AST {$$ = STAR;}
| /* vide */ {$$ = NONE;}
;

/* ptr Element */
name_or_choice_or_seq
: NOM   {$$ = new ChildElt($1);}
| choice  {$$ = $1}
| seq  {$$ = $1}
;

/* ptr Element */
cp
: name_or_choice_or_seq card_opt {$$ = $1; $$->setCard($2);}
;

/* ptr Element */
choice
: OUVREPAR cp contenu_choice FERMEPAR   {$$ = new ChildListElt(CHOICE); $$->add($1); $$->add($2)}
;

contenu_choice
: contenu_choice BARRE cp { $$ = $1; $$->add($3);}
| BARRE cp { $$ = new ChildListElt(CHOICE); $$->add($2);}
;

seq
: OUVREPAR cp contenu_seq_opt FERMEPAR { $$ = new ChildListElt(SEQ); $$->add($1); $$->add($2)}
;

contenu_seq_opt
: contenu_seq_opt VIRGULE cp {$$ = $1; $$->add(cp);}
| /* vide */ {$$ = new ChildListElt(SEQ);}
;

mixed
: OUVREPAR PCDATA contenu_mixed {$$ = $3; $$->add(new Element(PCDATA)); }
;

contenu_mixed
: contenu_mixed BARRE NOM {$$ = $1; $$-> add(new ChildElt($3)); }
| FERMEPAR AST {$$ = new ChildListElt(CHOICE); $$->setCard(STAR); }
| FERMEPAR {$$ = new ChildListElt(CHOICE); }
;

%%

int main(int argc, char **argv)
{
  int err;
  //yydebug = 1; // pour désactiver l'affichage de l'exécution du parser LALR, commenter cette ligne

  err = yyparse();
  if (err != 0) {
    printf("Parse ended with %d error(s)\n", err);
    return 1;
  } else {
    printf("Parse ended with success\n", err);
    cout << rootExpr->toString() << endl;
  }
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
