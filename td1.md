TD 1
====

<style></style>

Exercice 1
------

### 1. Structuration du document ###
- document
    - titre
    - auteur
    - sections
        - titre
        - contenu
            - paragraphes
                - contenu

### 2. Balises ###
```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE doc SYSTEM "doc.dtd">
<doc>
    <meta titre="Réaliser un compilateur" auteur="Nino Silverio" />
    <section titre="Introduction: concepts de base">
        <paragraphe>
            Tout programme ...
        </paragraphe>
        <paragraphe>
            Comme l'écriture...
        </paragraphe>
    </section>
</doc>
```

### 3. DTD ###
```dtd
<!DOCTYPE doc
[
<!ELEMENT doc (meta, section*)>
<!ELEMENT meta>
<!ATTLIST meta>
<!ELEMENT section (paragraphe*)>
<!ELEMENT paragraphe (#PCDATA)>
]>
```

Exercice 2
--------

Bison:
```bison
%union{
    char * s;
    list<string> * l;
    Element* e;
    pair<string,string> * strp;
    map<string,string> * strm;
    list<Node*> * nl;
}
/** XML **/
%type <e> element
%type <s> DONNEES
%type <nl> contenu_opt
%type <strp> attributs_opt
%type <strm> attribut

/** DTD **/
%token <s> NOM
%type <l> liste_opt

%%

/** XML *********************/
/* ptr Element */
element
    : OBALISE attributs_opt SUP contenu_opt FBALISE SUP     {$$ = new Element($1->second, $2, $4);}
    | OBALISE attributs_opt SLASH SUP                       {$$ = new Element($1->second, $2);}
    ;

/* ptr liste Node */
contenu_opt /* suffixe opt pour signaler qu'il peut y avoir une espilon production (vide)*/
    : contenu_opt DONNEES   {$$ = $1; $$->push_back(new TextNode($2));} 
    | contenu_opt element   {$$ = $1; $$->push_back($2);} 
    | /* vide */            {$$ = new list<Node>;} 
    ;

/* map<string, string>
attributs_opt /* représente 'attribut*' */
    : attributs_opt attribut    {$$ = $1; $$->insert(*$2); delete $2} 
    :                           {$$ = new map<string, string>;} 
    ;

/* ptr pair<string, string> */
attribut
    : NOM EGAL VALEUR      {$$ = new pair(string($1), string($3))}
    ;

/** DTD *********************/

children
    : choice card_opt
    | seq card_opt;

card_opt
    : PTINT
    | PLUS
    | AST
    | /* vide */;

name_or_choice_or_seq:
    : NOM
    | choice
    | seq;

cp
    : name_or_choice_or_seq card_opt;

choice
    : OUVREPAR cp contenu_choice FERMEPAR;

contenu_choice
    : contenu_choice BARRE cp
    | BARRE cp;

seq
    : OUVREPAR cp contenu_seq_opt FERMEPAR;

contenu_seq_opt
    : contenu_choice VIRGULE cp
    | /* vide */;

liste_opt
    : liste_opt NOM     {$$ = $1; $$->push_back(string($2));} /* rajoute un élément à la liste*/
    | /* vide */        {$$ = new list<string>;} /* règle réduite en premier, initialise la liste*/
    ;

liste
    : liste NOM         {$$ = $1; $$->push_back(string($2));}
    | NOM               {$$ = new list<string>; $$->push_back(string($1));}
    ;

```

Exercice 4
---

### 1. Structures de données ###
```c++
/* XML */
enum NodeType {#text, a, b, p}

class Node {
    NodeType type;
}

class TextNode : Node {
    string content;
}

class Element : Node {
    list<Node*> * children;
    map<string, string> * attributes;
    string namespace;
    string name;

    public:
        Element(ElementName* en, map<string, string>* attrs, list<Node*> * children = new list<Node>());
}

/* DTD */
enum Card {qmark, plus, star}

class Dtd {
    map<string, DtdElt> * elements;
}

class DtdElt {
   map<string, DtdAttr> * attributes;
   list<ChildElt> * children;
}


class ChildElt {
    string eltName
    Card card
}

class DtdAttr {
    string name;
    string type;
    bool required;
}

```