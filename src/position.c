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
 * @file position.c
 * 
 * @brief code source qui permet de gérer les positions
 */
 
#include <stdlib.h>
#include <stdio.h>

#include <position.h>
#include <ensemble.h>

struct Position {
	/** Position x */
	int x;

	/** Position y */
	int y;
};

int position_get_x(Position p){
	return p->x;
}

int position_get_y(Position p){
	return p->y;
}

Position creer_position(int x, int y){
	Position p = (Position) malloc(sizeof(struct Position));
	
	p->x = x;
	p->y = y;
	
	return p;
}

Position position_copy(Position pos){
	return creer_position(pos->x, pos->y);
}

void detruire_position(Position p){
	free(p);
}

Position position_get_courant(Ensemble E){
	return (Position) ensemble_get_courant_contenu(E);
}

Position haut(Position p){
	return creer_position(p->x, p->y-1);
}

Position bas(Position p){
	return creer_position(p->x, p->y+1);
}

Position gauche(Position p){
	return creer_position(p->x-1, p->y);
}

Position droite(Position p){
	return creer_position(p->x+1, p->y);
}

Position deplacer_haut(Position p){
	p->y--;
	return p;
}

Position deplacer_bas(Position p){
	p->y++;
	return p;
}

Position deplacer_gauche(Position p){
	p->x--;
	return p;
}

Position deplacer_droite(Position p){
	p->x++;
	return p;
}

