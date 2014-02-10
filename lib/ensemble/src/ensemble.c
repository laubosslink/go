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

int ensemble_vide(Ensemble* E){
	return E->tete == NULL;
}

Cell* ensemble_tete(Ensemble* E){
	return E->tete;
}

Cell* ensemble_courant(Ensemble* E){
	return E->courant;
}

int ensemble_suivant(Ensemble* E){
	return (ensemble_courant(E))->suivant != NULL;
}


int ensemble_appartient(Ensemble* E, void* element){
	if(ensemble_vide(E))
		return 0;
		
	E->courant=E->tete;
	
	while(ensemble_suivant(E) && E->courant->contenu != element ){
		E->courant = E->courant->suivant;
	}
	
	if(!ensemble_suivant(E) && E->courant->contenu != element)
		return 0;
	
	return 1;
}

Ensemble* ensemble_enlever(Ensemble* E, void* element){
	Cell* cellule;
	
	if(!ensemble_appartient(E, element))
		return E;
	
	cellule = (Cell*) malloc(sizeof(Cell));
	E->courant=E->tete;
	
	while(ensemble_suivant(E) && E->courant->suivant->contenu != element){
		E->courant = E->courant->suivant;
	}
	
	if(!ensemble_suivant(E) && E->courant->contenu != element)
		return E;
	
	cellule = E->courant->suivant;
	E->courant->suivant = cellule->suivant;
	
	free(cellule);
	
	return E;
	
} 
	
void ensemble_ajouter(Ensemble* E, void* element){
	Cell* cellule;
	
	if(element == NULL)
		return;
	
	cellule = (Cell*)malloc(sizeof(Cell));

	cellule->contenu = element;
	
	if(ensemble_vide(E)){
		E->tete=cellule;
	} else {
		E->courant=E->tete;
		
		while(ensemble_suivant(E) ) {	
			E->courant=E->courant->suivant;
		}
		
		E->courant->suivant=cellule;
		cellule->suivant=NULL;
	}
}
