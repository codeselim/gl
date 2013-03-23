%{

using namespace std;
#include <list>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#include <dtd.h>

void dtderror(Dtd** dtd, char *msg);
int dtdwrap(void);
int dtdlex(void);

%}

%parse-param { Dtd ** dtd }

%union {
  char *s;
  list<string> *l;
  Dtd* dtd;
  DtdEltMap* dem;
  DtdElt* de;
  list<DtdAttr*> * dal;
  DtdAttr* da;
  AttrType* at;
  DefaultDeclaration* dd;
  /* EltContent* ec; */
  Child* c;
  ChildListElt* cle;
Card card;
}

%token ELEMENT ATTLIST SUP OUVREPAR FERMEPAR VIRGULE BARRE FIXED EMPTY ANY PCDATA AST PTINT PLUS CDATA
%token <s> NOM TOKENTYPE DECLARATION VALEUR

%type <dtd> main
%type <dem> dtd_list_opt
%type <de> element_declaration content_spec
%type <dal> att_definition_opt
%type <da> attribut
%type <at> att_type
%type <l> type_enumere liste_enum_plus liste_enum
%type <dd> defaut_declaration
/*%type <ec> content_spec*/
%type <c> name_or_choice_or_seq cp
%type <cle> children choice contenu_choice seq contenu_seq_opt mixed contenu_mixed
%type <card> card_opt

%%

main
: dtd_list_opt  {$$ = new Dtd($1); *dtd = $$;}
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
: CDATA   {$$ = new AttrType(string("CDATA"));}
| TOKENTYPE   {$$ = new AttrType($1);}
| type_enumere  {$$ = new AttrType($1);}
;

type_enumere
: OUVREPAR liste_enum_plus FERMEPAR   {$$ = $2;}
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
: ELEMENT NOM content_spec SUP  {$$ = $3; $$->setName(string($2));}
;

content_spec
: EMPTY   {$$ = new DtdElt(T_EMPTY);}
| ANY   {$$ = new DtdElt(T_ANY);}
| mixed   {$$ = new DtdElt($1);}
| children  {$$ = new DtdElt($1);}
;

children
: choice card_opt {$$ = $1; $$->setCard($2);}
| seq card_opt {$$ = $1; $$->setCard($2);}
;

card_opt
: PTINT {$$ = QMARK;}
| PLUS {$$ = C_PLUS;}
| AST {$$ = STAR;}
| /* vide */ {$$ = NONE;}
;

name_or_choice_or_seq
: NOM   {$$ = new ChildElt($1);}
| choice  {$$ = $1;}
| seq  {$$ = $1;}
;

cp
: name_or_choice_or_seq card_opt {$$ = $1; $$->setCard($2);}
;

choice
: OUVREPAR cp contenu_choice FERMEPAR   {$$ = new ChildListElt(CHOICE); $$->add($2); $$->add($3);}
;

contenu_choice
: contenu_choice BARRE cp { $$ = $1; $$->add($3);}
// | BARRE cp { $$ = new ChildListElt(CHOICE); $$->add($2);}
| BARRE cp { $$ = (ChildListElt*)$2;}
;

seq
: OUVREPAR cp contenu_seq_opt FERMEPAR { $$ = $3; $$->addFront($2); /*cout << $3->toString() << endl;*/}
;

contenu_seq_opt
: contenu_seq_opt VIRGULE cp {$$ = $1; $$->add($3);}
| /* vide */ {$$ = new ChildListElt(SEQ);}
;

mixed
: OUVREPAR PCDATA contenu_mixed {$$ = $3; $$->add(new ChildElt()); }
;

contenu_mixed
: contenu_mixed BARRE NOM {$$ = $1; $$-> add(new ChildElt($3)); }
| FERMEPAR AST {$$ = new ChildListElt(CHOICE); $$->setCard(STAR); }
| FERMEPAR {$$ = new ChildListElt(CHOICE); }
;

%%

int dtdwrap(void)
{
  return 1;
}

void dtderror(Dtd** dtd, char *msg)
{
  fprintf(stderr, "Erreur de parsing: %s\n", msg);
}
