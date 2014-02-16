/**
 * ENSICAEN
 * 6 Boulevard Marechal Juin
 * F-14050 Caen Cedex
 * 
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written premission of the authors
 */
 
/**
 * @author ELHIMDI Yasmine <elhimdi@ecole.ensicaen.fr>
 * @author PARMENTIER Laurent <parmentier@ecole.ensicaen.fr, laubosslink@society-lbl.com>
 * @version 1.1 
 * @date 03-02-2013
 * 
 * @todo revoir la doc / remplacer Ensemble_Positions par Ensemble_Position
 */
 
/** 
 * @file ensemble_colores.c
 * 
 * @brief code source qui permet de gérer les ensembles colores
 */
 
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

void ensemble_colores_init(Ensemble_Colores* E){
	E->p = creer_ensemble();
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
	
	ensemble_reset_courant(p);

	while(ensemble_suivant(p)){
		if(element->x == position_get_courant(p)->x && element->y == position_get_courant(p)->y)
			return 1;
			
		ensemble_set_courant(p, ensemble_get_suivant(p));
	}
	
	if(element->x == position_get_courant(p)->x && element->y == position_get_courant(p)->y)
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

