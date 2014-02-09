#include <stdio.h>
#include <stdlib.h>
#include <ensemble_colores.h>

Ensemble_Colores* creer_ensembleColores(){
	Ensemble_Colores* E;
	
	E = (Ensemble_Colores*) malloc(sizeof(Ensemble_Colores));
	E->tete = NULL;
	E->courant = NULL;
	
	return E;
}

int vide(Ensemble_Colores* E){
	return E->tete == NULL;
}

Cell* tete(Ensemble_Colores* E){
	return E->tete;
}

Cell* courant(Ensemble_Colores* E){
	return E->courant;
}

int suivant(Ensemble_Colores* E){
	return courant(E)->suivant != NULL;
}


int appartient(Ensemble_Colores* E, Position* element){
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

Ensemble_Colores* detruire(Ensemble_Colores* E, Position* element){
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
	
void ajouterElement(Ensemble_Colores* E, Position* element){
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
