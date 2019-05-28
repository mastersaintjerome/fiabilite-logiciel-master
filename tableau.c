#include "tableau.h"

/*
 * Trie le tableau tab de maniere croissante.
 */
void trier_tableau(Tableau *t){

    int i, j, temp = 0;
   
    for(i = 0; i < t->nb_elt; i++){

        for(j = i; j < t->nb_elt; j++){

            if(t->tab[j] < t->tab[i]) {
            
                temp = t->tab[i];
                t->tab[i] = t->tab[j];
                t->tab[j] = temp;
            
            }
        }
    }
}

/*
 * Initialise le tableau avec des valeurs et une taille donnée.
 */
void initialise_tableau(Tableau *t, int taille){
	t->tab = malloc(taille * sizeof(int));
	t->taille_max = taille;
	t->nb_elt = 0;
}


/*
 * Désalloue la mémoire prise du tableau.
 */
void free_tableau(Tableau *t){
	for(int i = 0; i < t->taille_max; i++)
		free(t->tab[i]);
	free(t);
}

/*
 * Renvoie 1 et ajoute un élément dans le tableau t si la taille du tableau est suffisante, 0 sinon.
 */
int ajouter_element(Tableau *t, int elt){
	int ok = 0;

	if(t->taille_max > t->nb_elt ){
		t->tab[ t->nb_elt ] = elt;
		t->nb_elt += 1;
		trier_tableau(t);
		ok = 1;
	}	

	return ok;
}

/*
 * Recherche un element dans le tableau tab et renvoie 1 si il est présent, -1 sinon.
 */
int chercherElt(int elt, Tableau tab){

	int ok = 1;

	for(int i = 0; i < tab.nb_elt && ok; i++){
		if(t.tab[i] == elt){
			ok = 0;
		}
	}
	
	if(ok){
		return i-1;
	} else {
		return -1;
	}
}

/*
 * Return : Renvoie le nombre d'éléments du tableau t.
 */
int getDim(Tableau *t){
	return t->nb_elt;
}

/*
 * Return : Renvoie les éléments du tableau d'entiers de t.
 */
int* getVAlues(Tableau *t){
	return &(t->tab);
}

int main(){

	Tableau t;
	initialise_tableau(&t, 100);


	
	
	return 0;
}