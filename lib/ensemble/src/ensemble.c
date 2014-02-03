#include <stdio.h>
#include <stdlib.h>
#include <ensemble.h>

/**
 * Permet de creer un ensemble
 * @return un pointeur vers un ensemble
 */
Ensemble* creer_ensemble(){
	Ensemble* E;
	
	E = (Ensemble*) malloc(sizeof(Ensemble));
	E->tete = NULL;
	E->courant = NULL;
	
	return E;
}

/**
 * Permet de vérifier si un ensemble est vide
 * @param E l'ensemble
 * @return 1 si il l'est
 */
int vide(Ensemble* E){
	return E->tete == NULL;
}

/**
 * Permet de vérifier qu'un élément appartiennent à un ensemble
 * @param element l'élément
 * @return 1 si il appartient, 0 sinon
 */
int appartient(Ensemble* E, void* element){
	if(vide(E))
		return 0;
		
	E->courant=E->tete;
	
	while(E->courant->suivant != NULL && E->courant->contenu != element ){
		E->courant = E->courant->suivant;
	}
	
	if(E->courant->suivant == NULL && E->courant->contenu != element)
		return 0;
	
	return 1;
}

/*Liste* supprimer(Liste* L) // @TODO */

/**
 * Permet d'ajouter un élément dans un ensemble
 * @param element l'élément à ajouter
 */	
void ajouterElement(Ensemble* E, void* element){
	cell* cellule;
	
	cellule=(cell*)malloc(sizeof(cell));

	cellule->contenu=element;
	
	if(vide(E)){
		E->tete=cellule;
	} else {
		E->courant=E->tete;
		
		while(E->courant->suivant != NULL ) {	
			E->courant=E->courant->suivant;
			}
		
		E->courant->suivant=cellule;
		cellule->suivant=NULL;
	}
}
