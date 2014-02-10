#include <stdio.h>
#include <stdlib.h>
#include <ensemble.h>
#include <ensemble_colores.h>

Ensemble_Colores* creer_ensemble_colores(){
	return (Ensemble_Colores*)creer_ensemble();
}

int vide_ensemble_colores(Ensemble_Colores* E){
	return vide(E);
}

Cell* tete_ensemble_colores(Ensemble_Colores* E){
	return (Position*)tete(E);
}

Cell* courant_ensemble_colores(Ensemble_Colores* E){
	return (Position*)courant(E);
}

int suivant_ensemble_colores(Ensemble_Colores* E){
	return (Position*)courant(E);
}


int appartient_ensemble_colores(Ensemble_Colores* E, Position* element){
	return appartient(E,(Position*)element);
}

Ensemble_Colores* detruire_ensemble_colores(Ensemble_Colores* E, Position* element){
	return detruire(E,(Position*)element);
} 
	
void ajouter_position_coloree(Ensemble_Colores* E, Position* element){
	return ajouterElement(E,(Position*)element);
}
