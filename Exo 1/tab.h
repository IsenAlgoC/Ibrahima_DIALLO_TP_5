#define TAILLEAJOUT 50

/*========= fonction qui remplit un tableau d’entiers de taille size avec des zéros =========*/

int initTab(int* tab, int size){ 
	int i;                              //on initiialise un indice i
    if (tab == NULL || size < 0) {      // verificiation des erreurs possibles 
		return -1;
	}
	else {                              //si pas d'erreur on retourne la vtaille du tableau
		return size;
	}
	for (i = 0; i < size; i++) {        // on met tous les elements du tableau a zero 
		*(tab + i) = 0;
	}
}

/*========= fonction qui affiche les nbElts premièrs éléments du tableau tab =========*/

int afficheTab(int *tab, int size, int nbElts) {
	int i;
	if (tab == NULL || size < 0 || size < nbElts) {      //erification des erreurs possibles
		return -1;
	
	}
	for (i = 0; i < nbElts; i++) {                              
		printf("Case indice %d : %d\n",i , *(tab + i));           //affichage des premiers elements du tableau jsuqu'a nbElts
	}
	
	return 0;
}

/*========= fonction qui ajoute un nombre entier à la suite des valeurs déjà entrées =========*/

int * ajoutElementDansTableau(int * tab, int * size, int * nbElts, int element) {
	
	if (*nbElts >= *size) {                                                   // verifivation d'une erreur possible pour ensuite attribuer plus de memoire au tableau
		int* tmp = (int*)realloc(tab, (TAILLEAJOUT + *size) * sizeof(int));   // on cree une variable tmp qui va stocker la nouvelle adresse et gerer l'erreur cause par le malloc
		if (tmp == 0) {
			return NULL;
		}
		tab = tmp;                                                   //on affecte les donnees de tmp au tableau apres avoir gere les erreurs
		*(tab + *nbElts) = element;                                  // ajout de l'element a la positon souhaite
		*nbElts += 1;                                                // on augmente le nbElts
		*size += 1;                                                  // on augmente la taille
	}
	*(tab + *nbElts) = element;
	*nbElts += 1;
	*size += TAILLEAJOUT;                                             
	return tab + *nbElts;                                             //on retourne la position de l'element

}

