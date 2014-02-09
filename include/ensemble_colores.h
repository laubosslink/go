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
 * @todo remplacer cell par Cell (avec majuscule)
 */
 
/** 
 * @file ensemble_colores.h
 * 
 * structures Ensemble_colores permettant la manipulation d'un ensemble de position et d'une couleur
 */

#ifndef ENSEMBLE_COLORES_H_INCLUDED
#define ENSEMBLE_COLORES_H_INCLUDED

#include <couleur.h>
#include <positions.h>

typedef struct Ensemble_colores Ensemble_colores;
 
typedef struct Ensemble_colores{
	Couleur couleur;
	Positions position;
};

#endif
