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

/**
 * @brief Structure d'un ensemble coloré contient une couleur, et un ensemble de positions
 */
struct Ensemble_Colores {
	Couleur c; 
	Positions p;
};

Ensemble_Colores creer_ensemble_colores(){
	Ensemble_Colores e = (Ensemble_Colores) malloc(sizeof(struct Ensemble_Colores));
	
	e->p = creer_ensemble();
	
	return e;
}

void ensemble_colores_init(Ensemble_Colores E){
	E->p = creer_ensemble();
}

int ensemble_colores_vide(Ensemble_Colores E){
	if(E == NULL)
		return 1;
	
	return ensemble_vide(E->p);
}

Cell ensemble_colores_tete(Ensemble_Colores E){
	return ensemble_tete(E->p);
}

Cell ensemble_colores_courant(Ensemble_Colores E){
	return ensemble_courant(E->p);
}

int ensemble_colores_suivant(Ensemble_Colores E){
	return ensemble_suivant(E->p);
}

Position ensemble_colores_get_courant(Ensemble_Colores E){
	return (Position) ensemble_get_courant_contenu(E->p);
}

int ensemble_colores_appartient(Ensemble_Colores E, Position element){
	int x, y;
	
	if(ensemble_colores_vide(E))
		return 0;
	
	ensemble_colores_reset(E);
	
	while(ensemble_colores_suivant(E)){
		x = position_get_x(ensemble_colores_get_courant(E));
		y = position_get_y(ensemble_colores_get_courant(E));
		
		if(x == position_get_x(element) && y == position_get_y(element))
			return 1;
			
		ensemble_colores_set_courant(E, ensemble_colores_get_suivant(E));
	}
		
	x = position_get_x(ensemble_colores_get_courant(E));
	y = position_get_y(ensemble_colores_get_courant(E));
		
	if(x == position_get_x(element) && y == position_get_y(element))
		return 1;
	
	return 0;
}

Ensemble_Colores ensemble_colores_enlever(Ensemble_Colores E, Position element){
	ensemble_enlever(E->p, element);
	return E;
} 
	
void ensemble_colores_ajouter(Ensemble_Colores E, Position element){
	/* permet de ne pas ajouter des doublons ! */
	if(ensemble_colores_appartient(E, element))
		return;
		
	return ensemble_ajouter(E->p, (Position) element);
}

void ensemble_colores_set_couleur(Ensemble_Colores E, Couleur c){
	E->c = c;
}

Couleur ensemble_colores_get_couleur(Ensemble_Colores E){
	return E->c;
}

void ensemble_colores_reset(Ensemble_Colores E){
	ensemble_reset_courant(E->p);
}

void ensemble_colores_set_courant(Ensemble_Colores E, Cell c){
	ensemble_set_courant(E->p, c);
}

Cell ensemble_colores_get_suivant(Ensemble_Colores E){
	return ensemble_get_suivant(E->p);
}

void ensemble_colores_affiche(Ensemble_Colores E){
	if(ensemble_colores_vide(E)){
		fprintf(stderr, "Rien à afficher, la liste est vide\n");
		return;
	}
	
	printf("[");
	ensemble_colores_reset(E);
	
	while(ensemble_colores_suivant(E)){
		printf("{%d, %d}, ",  position_get_x(((Position)ensemble_colores_get_courant(E))), position_get_y(((Position)ensemble_colores_get_courant(E))));
		ensemble_colores_set_courant(E, ensemble_colores_get_suivant(E));
	}
	
	printf("{%d, %d}]\n",  position_get_x(((Position)ensemble_colores_get_courant(E))), position_get_y(((Position)ensemble_colores_get_courant(E))));
}

int ensemble_colores_nbr_element(Ensemble_Colores E){
	return ensemble_nbr_element(E->p);
}
