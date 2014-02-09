#include <stdio.h>
#include <stdlib.h>
#include <position.h>
#include <ensemble.h>
#include <ensemble_colores.h>

Ensemble_Colores* creer_ensemble_colores(){
	return (Ensemble_Colores*)creer_ensemble();
}

int ensemble_colores_vide(Ensemble_Colores* E){
	return ensemble_vide(E);
}

Cell* ensemble_colores_tete(Ensemble_Colores* E){
	return (Position*) ensemble_tete(E);
}

Cell* ensemble_colores_courant(Ensemble_Colores* E){
	return (Position*) ensemble_courant(E);
}

int ensemble_colores_suivant(Ensemble_Colores* E){
	return (Position*) ensemble_suivant(E);
}

int ensemble_colores_appartient(Ensemble_Colores* E, Position* element){
	return ensemble_appartient(E,(Position*)element);
}

Ensemble_Colores* detruire_ensemble_colores(Ensemble_Colores* E, Position* element){
	return detruire(E,(Position*)element);
} 
	
void ajouter_position_coloree(Ensemble_Colores* E, Position* element){
	return ajouterElement(E,(Position*)element);
}
