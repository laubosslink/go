#include <stdio.h>
#include <stdlib.h>
#include <ensemble.h>
#include <ensemble_positions.h>
#include <position.h>

Ensemble_Positions* creer_ensemble_positions(){
	return (Ensemble_Positions*) creer_ensemble();
}

int vide_ensemble_positions(Ensemble_Positions* E){
	return E->tete == NULL;
}

Cell* tete_ensemble_positions(Ensemble_Positions* E){
	return E->tete;
}

Cell* courant_ensemble_positions(Ensemble_Positions* E){
	return E->courant;
}

int suivant_ensemble_positions(Ensemble_Positions* E){
	return courant(E)->suivant != NULL;
}


int appartient_ensemble_positions(Ensemble_Positions* E, Position* element){
	return appartient(E,(Position*) element);
}

Ensemble_Positions* detruire_ensemble_positions(Ensemble_Positions* E, Position* element){
	return detruire(E,(Position*)element);
}
	
void ajouterPosition(Ensemble_Positions* E, Position* element){
	ajouterElement(E,(Position*)element);
}
