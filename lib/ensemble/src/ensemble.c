#include <stdio.h>
#include <stdlib.h>
#include <ensemble.h>

Ensemble* creer_ensemble(){
	Ensemble* E;
	
	E = (Ensemble*) malloc(sizeof(Ensemble));
	E->tete = NULL;
	E->courant = NULL;
	
	return E;
}

int vide(Ensemble* E){
	return E->tete == NULL;
}


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

Ensemble* detruire(Ensemble* E, void* element){
	Cell* cellule;
	
	if(!appartient(E,element))
		return E;
	
	cellule = (Cell*) malloc(sizeof(Cell));
	
	while(E->courant->suivant != NULL && E->courant->suivant->contenu != element){
		E->courant = E->courant->suivant;
	}
	
	if(E->courant->suivant == NULL && E->courant->contenu != element)
		return E;
	
	printf("On arrive la");
	cellule = E->courant->suivant;
	E->courant->suivant = cellule->suivant;
	
	free(cellule);
	
	return E;
	
}// TODO 
	
void ajouterElement(Ensemble* E, void* element){
	Cell* cellule;
	
	cellule=(Cell*)malloc(sizeof(Cell));

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
