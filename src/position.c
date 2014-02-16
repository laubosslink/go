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

Position* creer_position(int x, int y){
	Position* p = (Position *) malloc(sizeof(Position));
	
	p->x = x;
	p->y = y;
	
	return p;
}

Position* position_get_courant(Ensemble *E){
	return (Position *) ensemble_get_courant_contenu(E);
}

Position haut(Position p){
	p.y--;
	
	return p;
}

Position bas(Position p){
	p.y++;
	
	return p;
}

Position gauche(Position p){
	p.x--;
	
	return p;
}

Position droite(Position p){
	p.x++;
	
	return p;
}
