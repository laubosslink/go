#include <stdio.h>
#include <stdlib.h>
#include <ensemble.h>
#include <ensemble_positions.h>
#include <position.h>

Ensemble_Positions* creer_ensemble_positions(){
	return (Ensemble_Positions*) creer_ensemble();
}

int ensemble_positions_vide(Ensemble_Positions* E){
	return E->tete == NULL;
}

Cell* ensemble_positions_tete(Ensemble_Positions* E){
	return E->tete;
}

Cell* ensemble_positions_courant(Ensemble_Positions* E){
	return E->courant;
}

int ensemble_positions_suivant(Ensemble_Positions* E){
	return ensemble_courant(E)->suivant != NULL;
}


int ensemble_positions_appartient(Ensemble_Positions* E, Position* element){
	return ensemble_appartient(E,(Position*) element);
}

Ensemble_Positions* ensemble_positions_detruire(Ensemble_Positions* E, Position* element){
	return ensemble_detruire(E,(Position*)element);
}
	
void ensemble_positions_ajouter(Ensemble_Positions* E, Position* element){
	ensemble_ajouter(E,(Position*)element);
}
