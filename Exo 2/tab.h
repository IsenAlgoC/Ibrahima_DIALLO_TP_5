#define TAILLEINITIALE 100
#include <stdlib.h>
#include <stdio.h>



typedef struct Tableau {
	int* elt;                       // le tableau d’entiers
	int size;                     // la taille de ce tableau d’entiers
	int eltsCount;                 // le nombre d’éléments dans le tableau
}TABLEAU;

/*========= création d'un nouveau TABLEAU en allouant une taille initiale pour les données =========*/

TABLEAU newArray() {                                // Fonction qui initialise notre tableau
	int i;                                         //initialisation de l'indice i
	TABLEAU Tab;                                  // création de la structure Tab
	Tab.elt = (int*)malloc(TAILLEINITIALE * sizeof(int));                                        // allocation de la mémoire a notre tableau
	if (Tab.elt == NULL) {                                                                    // Condition pour verifier si le tableau pointe sur une valeur nulle 
		return Tab;
	}
	for (i = 0; i < TAILLEINITIALE; i++) {                                          // Mise à zero de tous les elements du tableau grace a une boucle 
		*(Tab.elt + i) = 0;                     
	}
	Tab.eltsCount = 0;                                          // initialisation du nombre d'element a zero 
	Tab.size = TAILLEINITIALE;                                 // initialisation de la taille du tableau a TAILLEINITIALE = 100
	
	return Tab;                                                   // on retourne le tableau 
}

/*========= modification de la taille du tableau =========*/

int incrementArraySize(TABLEAU* tab, int incrementValue) {                           // Fonction qui va augmenter la taille du tableau d'une valeur entiere "incrementValue" et qui reçoit une structure
	int* tmp;                                                                   // creation d'un pointeur tmp qui pointe sur une adresse
	tmp = (int*)realloc(tab->elt, (incrementValue + tab->size) * sizeof(int)); // ce pointeur va empecher l'envoi d'une erreur a propos d'une fuite de memoire engendre par l'utilisation du realloc
	if (tmp == 0) {
		return -1;
	}
	tab->elt = tmp;                   // puis on affecte tmp a tab->elt
	tab->size = incrementValue + TAILLEINITIALE;  // on modifie la taille du tabeau
	return tab->size;         // on renvoie la taille du tableau
} 

/*========= ecriture d'élément à une position donnée sans insertion =========*/

int setElement(TABLEAU* tab, int pos, int element) {     //fonction qui introduit un "element" entier a la "pos" indique dans une structure 
	int i;                         // initialisation de l'indice i
	if (pos <= 0) {                // verification d'une erreur possible
		return 0;
	}
	if (tab->size > pos) {        // ajout de l'element si tab->size > pos
		*(tab->elt + pos - 1) = element;
		return tab->elt + (pos-1);  // on retourne la position de l'element
	}
		
	if (tab->size <= pos) { // ajout de l'element si tab->size <= pos
		incrementArraySize(tab, pos - tab->size);  //on augmente la taille du tableau 
		for (i = tab->size; i < pos - tab->size; i++) {  //on met a zero les elements du tableau entre le nombre insere et la derniere case du tableau initiale
			*(tab->elt + i) = 0;
		}
		*(tab->elt + pos - 1) = element;
		return tab->elt + (pos - 1);
	}
}

/*========= affichage une portion du tableau de l’indice début à l’indice fin =========*/

void swap(int* x, int* y) { //fonction qui va faire un passage par reference en echangeant les valeurs des adresses
	int tmp; // creation d'une variable qui va stocker une valeur de x
	tmp = *x;
	*x = *y;
	*y = tmp;
}


int displayElements(TABLEAU* tab, int startPos, int endPos) { //fonction qui affiche un tableau a partir d'un indice de debut startPos et un indice de fin endPos
	int i;
	if (startPos >= tab->size || endPos >= tab->size) { // verification des erreurs possible
		return -1;
	}
	
	if (startPos >= endPos) {  // On gére une condition. grace a la fonction swap, on va echanger les valeurs et commme ça fixer un probleme
		swap(&startPos, &endPos);
		for (i = 0; i < tab->size; i++) {
			if (i >= startPos && i <= endPos) { // on affiche les elements dan sl'intervalle souhaite
				printf("%d\n", *(tab->elt + i));
			}
		}
		return 0;
	}

	for (i = startPos; i <= endPos; i++) {                  // on affiche les elements dan sl'intervalle souhaite 
		if (i >= startPos && i <= endPos) {
			printf("%d\n", *(tab->elt + i));
		}
	}
	return 0;
}

/*========= suppression des éléments avec compactage du tableau =========*/

int deleteElements(TABLEAU* tab, int startPos, int endPos) { //fonction qui va supprimer  des intervalles souhiates d'un tableau
	int i = 0; 
	int k;
	int* tab1 = (int*)malloc((tab->size - (endPos - startPos) - 1) * sizeof(int));    // creation d'un nouveau tableau qui va contenir le nouveau tableau
	if (tab1 == NULL) { //verification d'une erreur
		return(0);
	}
	for (k = 0; k <= tab->size - 1; k++) { 
		if ((k < startPos) || (k > endPos)) {
			*(tab1 + i) = *(tab->elt + i);                    //on copie l'intervalle a suprimer du tableau passe en arguemnt dans le nouveau tableau lorsque les indices sont les memes
			i++;                                              //incrementation de l'indice du tableau pour passer a la valeur suivante
		}
	}
	tab->size -= (endPos - startPos) + 1;             //mise a jour de la taille du tableau
	tab->eltsCount -= (endPos - startPos) + 1;        // mise a jour du nombre d'elt
	tab->elt = tab;
	return(tab->size);
	
}