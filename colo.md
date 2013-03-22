\\\python

string html()

courant = racine xml

Retourne build_html(courant)

string build_html(courant)

si courant a un template

    templateXML = XML(template)

    si template contient “apply-templates”

        debut = sous-string de templateXML, entre début et “apply-templates”

        fin = sous-string de templateXML, entre “apply-templates” et fin

milieu = “”

pour (enfant dans courant)

    si enfant est un élément

    milieu = milieu + build_html(enfant)

    sinon si enfant est un noeud texte

        milieu = milieu + contenu_texte(enfant)

sinon
    resultat = XML(courant)

\\\
