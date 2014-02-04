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

Cell* tete(Ensemble* E){
	return E->tete;
}

Cell* courant(Ensemble* E){
	return E->courant;
}

int suivant(Ensemble* E){
	return courant(E)->suivant != NULL;
}


int appartient(Ensemble* E, void* element){
	if(vide(E))
		return 0;
		
	E->courant=E->tete;
	
	while(suivant(E) && E->courant->contenu != element ){
		E->courant = E->courant->suivant;
	}
	
	if( !suivant(E) && E->courant->contenu != element)
		return 0;
	
	return 1;
}

Ensemble* detruire(Ensemble* E, void* element){
	Cell* cellule;
	
	if(!appartient(E,element))
		return E;
	
	cellule = (Cell*) malloc(sizeof(Cell));
	E->courant=E->tete;
	
	while( suivant(E) && E->courant->suivant->contenu != element){
		E->courant = E->courant->suivant;
	}
	
	if(!suivant(E) && E->courant->contenu != element)
		return E;
	
	cellule = E->courant->suivant;
	E->courant->suivant = cellule->suivant;
	
	free(cellule);
	
	return E;
	
} 
	
void ajouterElement(Ensemble* E, void* element){
	Cell* cellule;
	
	cellule=(Cell*)malloc(sizeof(Cell));

	cellule->contenu=element;
	
	if(vide(E)){
		E->tete=cellule;
	} else {
		E->courant=E->tete;
		
		while(suivant(E) ) {	
			E->courant=E->courant->suivant;
			}
		
		E->courant->suivant=cellule;
		cellule->suivant=NULL;
	}
}
