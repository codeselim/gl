bool Validate->isElementValid(Element * elt)

if c’est un Node
#on vérifie si les attributs sont autorisés
	for (un attribut in attributsmap)
		if un attribut is not in DtdElement->attributs
			return False
		


#on vérifie si les élements fils sont autorisés
if in la dtd l’element a des fils
	if le type de contenu == EMPTY
		if l’element correspondant in le xml a des fils
			return False

elif (le type de contenu == MIXED) || (type de contenu == CHILDREN)
	Créer string représentant les noeuds fils (“nomFils1 nomFils2 nomFils3 …”)
	Créer la regex du noeud courant
	Comparer la regex du noeud courant (parent) à la chaine précédente (match)
	if match == False 
		return False
	

for (Element in la liste des children)
	
	if l’element n’est pas un PCDATA
		if Element isValid() == False
				return False

return True
