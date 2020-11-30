#include <stdio.h>
#include <stdlib.h>
#include "tab.h"



/*========= TEST DES FONCTIONS CREES DANS LE FICHIER tab.h =========*/

	
	
int main() {
	int nbCase;                             // nombre de cases à ajouter
	int pos;                                // position de l'élément à inserer
	int element;                            // element à insérer 
	int startpos, endpos;                   // intervalle à sélectionner pour l'affichage    
	int startpos2, endpos2;                 // intervalle selectionner pour la compression

	TABLEAU Tab = newArray();                    // création d'un nouveau TABLEAU en allouant une taille initiale pour les données
	printf("combien de cases voulez vous ajouter : ");
	scanf_s("%d", &nbCase);
	incrementArraySize(&Tab, nbCase);                     //incrementation du tableau d'une valeur nbCase
	
	printf("entrer la position pos et l'element a inserer :\n");
	scanf_s("%i %i", &pos, &element);
	setElement(&Tab, pos, element);                   // insèrtion de l'element "element" à la position "pos"
	
	printf("choisissez l'intervalle a afficher : ");
	scanf_s("%d %d", &startpos, &endpos); 
	displayElements(&Tab, startpos, endpos);             //affichage du tableau a partir de l'indice startPos jusqu'a l'indice endPos
	
	printf("l'ancienne taille du tableau est %d ", Tab.size);
	printf("donner l'intervalle à supprimer :  ");
	scanf_s("%d %d", &startpos2, &endpos2);
	printf("la nouvelle taille du tableau est %d", deleteElements(&Tab, startpos2, endpos2)); //on supprime une partie du tableau et on affiche la nouvelle taille
	free(Tab.elt); // on detruit notre tableau pour liberer de la memoire
	return 0;
}


