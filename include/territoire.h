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
 * @file territoire.h
 *
 * @brief Une portion de plateau encadré par une ou plusieurs chaines de pions en tenant compte des bords du plateau
 */

#ifndef TERRITOIRE_H_INCLUDED
#define TERRITOIRE_H_INCLUDED

#include <ensemble_colores.h>

/**
 * @brief le type Territoire est un ensemble de positions colorés. C'est donc un alias du type Ensemble_Colores
 */
typedef Ensemble_Colores Territoire;

#include <plateau.h>
#include <position.h>

/**
 * Retourne un ensemble d'intersection innocupees voisines de proche en proche delimites par des
 * pierres de meme couleur en commencant par l'intersection vide a la position pos.
 * Important: si la case ne fait pas partie d'un territoire de meme couleur, retourne quand meme l'ensemble
 * des intersections voisines mais en specifiant que territoire n'a aucune couleur. Ce cas est exploite pas la fonction
 * estUnSeki
 */
Territoire determineTerritoire(Plateau plateau, Position pos);

#endif
