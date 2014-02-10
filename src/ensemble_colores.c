#include <stdio.h>
#include <stdlib.h>
#include <position.h>
#include <ensemble.h>
#include <ensemble_colores.h>

/* @todo revoir le passage parametre des &(E->p) */

Ensemble_Colores* creer_ensemble_colores(){
	return (Ensemble_Colores*)creer_ensemble();
}

int ensemble_colores_vide(Ensemble_Colores* E){
	return ensemble_vide(&(E->p));
}

Cell* ensemble_colores_tete(Ensemble_Colores* E){
	return ensemble_tete(&(E->p));
}

Cell* ensemble_colores_courant(Ensemble_Colores* E){
	return ensemble_courant(&(E->p));
}

int ensemble_colores_suivant(Ensemble_Colores* E){
	return ensemble_suivant(&(E->p));
}

int ensemble_colores_appartient(Ensemble_Colores* E, Position* element){
	return ensemble_appartient(&(E->p),(Position*)element);
}

Ensemble_Colores* ensemble_colores_enlever(Ensemble_Colores* E, Position* element){
	return ensemble_enlever(&(E->p),(Position*)element);
} 
	
void ensemble_colores_ajouter(Ensemble_Colores* E, Position* element){
	return ensemble_ajouter(&(E->p),(Position*)element);
}

Position* ensemble_colores_contenu(Cell* c){
	return (Position *) c->contenu;
}
