#include <stdio.h>
#include <stdlib.h>
#include "tab.h"



/*========= TEST DES FONCTIONS CREES DANS LE FICHIER tab.h =========*/

	
	
int main() {
	int nbCase;                             // nombre de cases � ajouter
	int pos;                                // position de l'�l�ment � inserer
	int element;                            // element � ins�rer 
	int startpos, endpos;                   // intervalle � s�lectionner pour l'affichage    
	int startpos2, endpos2;                 // intervalle selectionner pour la compression

	TABLEAU Tab = newArray();                    // cr�ation d'un nouveau TABLEAU en allouant une taille initiale pour les donn�es
	printf("combien de cases voulez vous ajouter : ");
	scanf_s("%d", &nbCase);
	incrementArraySize(&Tab, nbCase);                     //incrementation du tableau d'une valeur nbCase
	
	printf("entrer la position pos et l'element a inserer :\n");
	scanf_s("%i %i", &pos, &element);
	setElement(&Tab, pos, element);                   // ins�rtion de l'element "element" � la position "pos"
	
	printf("choisissez l'intervalle a afficher : ");
	scanf_s("%d %d", &startpos, &endpos); 
	displayElements(&Tab, startpos, endpos);             //affichage du tableau a partir de l'indice startPos jusqu'a l'indice endPos
	
	printf("l'ancienne taille du tableau est %d ", Tab.size);
	printf("donner l'intervalle � supprimer :  ");
	scanf_s("%d %d", &startpos2, &endpos2);
	printf("la nouvelle taille du tableau est %d", deleteElements(&Tab, startpos2, endpos2)); //on supprime une partie du tableau et on affiche la nouvelle taille
	free(Tab.elt); // on detruit notre tableau pour liberer de la memoire
	return 0;
}


