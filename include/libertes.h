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
 * @author PARMENTIER Laurent <parmentier@ecole.ensicaen.fr, laubosslink@society-lbl$
 * @version 1.0 
 * @date 03-02-2013
 */
 
/** 
 * @file libertes.h
 * 
 * L'ensemble de libertes d'un pion (implémentation de Liste)
 */

#ifndef LIBERTES_H_INCLUDED
#define LIBERTES_H_INCLUDED 


#include <ensemble_positions.h>
#include <plateau.h>
#include <chaine.h>

typedef Ensemble_Positions Libertes;

/**
 * Permet de determiner les libertes d'une chaine
 * @param plateau le plateau
 * @param chaine la chaine contenant un ensemble de position
 * @return un ensemble de positions qui represente les libertes
 */
Libertes determineLiberte(Plateau plateau, Chaine chaine);

#endif
