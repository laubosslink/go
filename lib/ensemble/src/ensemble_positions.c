#include <stdio.h>
#include <stdlib.h>
#include <ensemble_positions.h>
#include <position.h>

Ensemble_Positions* creer_ensemble_positions(){
	return (Ensemble_Positions*) creer_ensemble();
}

int vide_ensemble_positions(Ensemble_Positions* E){
	return E->tete == NULL;
}

Cell* tete(Ensemble_Positions* E){
	return E->tete;
}

Cell* courant(Ensemble_Positions* E){
	return E->courant;
}

int suivant(Ensemble_Positions* E){
	return courant(E)->suivant != NULL;
}


int appartient(Ensemble_Positions* E, Position* element){
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

Ensemble_Positions* detruire(Ensemble_Positions* E, Position* element){
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
	
void ajouterElement(Ensemble_Positions* E, Position* element){
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
