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
 * @file ensemble_positions.c
 * 
 * @brief code source qui permet de gérer les ensembles de positions
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <ensemble.h>
#include <ensemble_positions.h>
#include <position.h>

Ensemble_Positions creer_ensemble_positions(){
	return (Ensemble_Positions) creer_ensemble();
}

void detruire_ensemble_positions(Ensemble_Positions E){
	detruire_ensemble(E);
}

int ensemble_positions_vide(Ensemble_Positions E){
	return ensemble_tete(E) == NULL;
}

Cell ensemble_positions_tete(Ensemble_Positions E){
	return ensemble_tete(E);
}

Cell ensemble_positions_courant(Ensemble_Positions E){
	return ensemble_courant(E);
}

int ensemble_positions_suivant(Ensemble_Positions E){
	return ensemble_get_suivant(E) != NULL;
}

int ensemble_positions_appartient(Ensemble_Positions E, Position element){
	int x, y;
	
	if(ensemble_vide(E))
		return 0;
	
	ensemble_reset_courant(E);
	
	while(ensemble_positions_suivant(E))
	{	
		x = position_get_x(ensemble_positions_get_courant(E));
		y = position_get_y(ensemble_positions_get_courant(E));
		
		if(x == position_get_x(element) && y == position_get_y(element))
			return 1;
		
		ensemble_set_courant(E, ensemble_get_suivant(E));
	}
	
	x = position_get_x(ensemble_positions_get_courant(E));
	y = position_get_y(ensemble_positions_get_courant(E));
	
	if(x == position_get_x(element) && y == position_get_y(element)) return 1;
	
	return 0;
}

Ensemble_Positions ensemble_positions_enlever(Ensemble_Positions E, Position element){
	return ensemble_enlever(E,(Position)element);
}
	
void ensemble_positions_ajouter(Ensemble_Positions E, Position element){
	/* permet de ne pas ajouter des doublons ! */
	if(ensemble_positions_appartient(E, element))
		return;
		
	ensemble_ajouter(E, (Position) element);
}

Position ensemble_positions_get_courant(Ensemble_Positions E){
	return (Position) ensemble_get_courant_contenu(E);
}

void ensemble_positions_affiche(Ensemble_Positions E){
	if(ensemble_positions_vide(E)){
		printf("Rien à afficher, la liste est vide\n");
		return;
	}
	
	ensemble_reset_courant(E);
	
	while(ensemble_positions_suivant(E)){
		printf("{x=%d, ",  position_get_x(ensemble_positions_get_courant(E))+1);
		printf("y=%d}\n",  position_get_y(ensemble_positions_get_courant(E))+1);
		
		ensemble_set_courant(E, ensemble_get_suivant(E));
	}
	
	printf("{x=%d, ",  position_get_x(ensemble_positions_get_courant(E))+1);
	printf("y=%d}\n",  position_get_y(ensemble_positions_get_courant(E))+1);
	printf("\n");
}
