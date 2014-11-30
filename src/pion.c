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
 * @file pion.c
 * 
 * @brief code source qui permet de gérer les pions
 */
 
#include <stdlib.h>
#include <stdio.h>

#include <pion.h>
#include <position.h>
#include <couleur.h>


/**
 * @brief Structure qui représente un pion
 */
struct Pion {
	/** La position du pion */
	Position p;

	/** La couleur du pion */
	Couleur c;
};

Pion creer_pion(Couleur c, Position p){
	Pion pion = (Pion) malloc(sizeof(struct Pion));
	
	pion->c = c;
	pion->p = p;
	
	return pion;
}

Position pion_get_position(Pion pion){
	return pion->p;
}

Couleur pion_get_color(Pion pion){
	return pion->c;
}

