Projet Grammaire et Langage: Développement d'un processeur XML
==============================================================

(github.com/ndossougbe/gl)


Prérequis
---------
- boost-regex
- python >= 2.4


Compilation
-----------
Il suffit d'exécuter la commande `make`.


Exécution
---------
Le programme se lance avec la commande `./cli`

- Lancer le programme sans paramètre afficher l'aide.
- Le paramètre obligatoire est le chemin du fichier XML
- Les paramètres optionnels sont:
    * Le chemin du fichier DTD (précédé de `-d `). Si il est présent la déclaration de DTD dans le fichier XML sera ignorée
    * Le chemin du fichier XSL (précédé de `-x `).


Affichage
---------
Le html généré est affiché sur `stdout`. Les autres informations sont affichées sur `stderr`. Rediriger la sortie standard sur un fichier permet donc d'obtenir le fichier HTML.


Tests
-----
La suite de tests se lance avec la commande `./test`
