#include <stdio.h>
#include <stdlib.h>
#include <position.h>
#include <positions.h>
#include <ensemble.h>
#include <ensemble_colores.h>


Ensemble_Colores* creer_ensemble_colores(){
	Ensemble_Colores* e = (Ensemble_Colores *) malloc(sizeof(Ensemble_Colores));
	
	e->p = (Positions *) creer_ensemble();
	
	return e;
}

int ensemble_colores_vide(Ensemble_Colores* E){
	return ensemble_vide(E->p);
}

Cell* ensemble_colores_tete(Ensemble_Colores* E){
	return ensemble_tete(E->p);
}

Cell* ensemble_colores_courant(Ensemble_Colores* E){
	return ensemble_courant(E->p);
}

int ensemble_colores_suivant(Ensemble_Colores* E){
	return ensemble_suivant(E->p);
}

int ensemble_colores_appartient(Ensemble_Colores* E, Position* element){
	Positions* p = E->p;
	
	p->courant = ensemble_tete(p);

	while(ensemble_suivant(p)){
		if(element->x == ((Position *)ensemble_courant(p)->contenu)->x && element->y == ((Position *)ensemble_courant(p)->contenu)->y)
			return 1;
	
		p->courant = ensemble_courant(p)->suivant;
	}
	
	if(element->x == ((Position *)ensemble_courant(p)->contenu)->x && element->y == ((Position *)ensemble_courant(p)->contenu)->y)
		return 1;
	
	return 0;
}

Ensemble_Colores* ensemble_colores_enlever(Ensemble_Colores* E, Position* element){
	ensemble_enlever(E->p, element);
	return E;
} 
	
void ensemble_colores_ajouter(Ensemble_Colores* E, Position* element){
	return ensemble_ajouter(E->p, (Position*) element);
}

Position* ensemble_colores_contenu(Cell* c){
	return (Position *) c->contenu;
}
