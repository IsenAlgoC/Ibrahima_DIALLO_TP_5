#include <stdio.h>
#include <stdlib.h>
#define TAB2SIZE 100
#include "tab.h"


int main() {
	int i;
	int myTab1[10] = {0}; //creation d'un tableau de 10 cases avec tous les elements mis a zero
	int *MyTab2 = NULL;
	int Valeurs = 20;
	MyTab2 = (int*)malloc(TAB2SIZE * sizeof(int)); //assignation de memoire au tableau MyTab2
	
	if ( MyTab2 != NULL){           // on verifie la condition
		initTab(MyTab2, TAB2SIZE);  // on met tous les elements de MyTab2 a zero pour un nombre de case TAB2SIZE
	}
	else {
		printf("Memoire insuffisante\n"); //message si on n'a pas asse assigne de l amemoire a MyTab2
		return -1;
	}

	for (i = 0; i < Valeurs; i++) { // on donne des valeurs aux cases du tableau
		*(MyTab2 + i) = i + 1 ;
	}
    
	afficheTab(MyTab2, TAB2SIZE, Valeurs); // on affiche les valeurs du tableau
	free(MyTab2);      // on detruit le tableau pour liberer de la memoire
}