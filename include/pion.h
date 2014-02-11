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
 * @author ELHIMDI Yasmine <yasmine.elhimdi@ecole.ensicaen.fr>
 * @author PARMENTIER Laurent <parmentier@ecole.ensicaen.fr, laubosslink@society-lbl.com>
 * @version 1.0 
 * @date 03-02-2013
 */
 
/** 
 * @file pion.h
 * 
 * Les informations sur un pion : sa position et sa couleur
 */

#ifndef PION_H_INCLUDED
#define PION_H_INCLUDED

#include <position.h>
#include <couleur.h>

/**
 * Informations d'un pion
 */
typedef struct Pion {
	/* La position du pion */
	Position p;

	/* La couleur du pion */
	Couleur c;
} Pion;

#endif
