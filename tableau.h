#ifndef TABLEAU_H_
#define TABLEAU_H_

	typedef struct{

		int nb_elt;
		int taille_max;
		int *tab;

	} Tableau;

	void trier_tableau(Tableau *t);
	void initialise_tableau(Tableau *t, int taille);
	void free_tableau(Tableau *t);
	int ajouter_element(Tableau *t, int elt);
	int chercherElt(int elt, Tableau tab);
	int getDim(Tableau *t);
	int* getVAlues(Tableau *t);

#endif