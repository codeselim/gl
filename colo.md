\\\python

string html()

courant = racine xml

Return build_html(courant)

string build_html(courant)

if courant a un template

    templateXML = XML(template)

    if template contient “apply-templates”

        debut = sous-string de templateXML, entre début et “apply-templates”

        fin = sous-string de templateXML, entre “apply-templates” et fin

milieu = “”

for (enfant dans courant)

    if enfant est un élément

    milieu = milieu + build_html(enfant)

    else if enfant est un noeud texte

        milieu = milieu + contenu_texte(enfant)

else
    resultat = XML(courant)

\\\
