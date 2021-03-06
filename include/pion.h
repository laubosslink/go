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
 * @brief Les informations sur un pion : sa position et sa couleur
 */

#ifndef PION_H_INCLUDED
#define PION_H_INCLUDED

#include <position.h>
#include <couleur.h>

/**
 * @brief Structure d'un pion qui contient la position du pion et sa couleur.
 */
typedef struct Pion* Pion;

/**
 * Permet de créer un pion
 * @return un nouveau pion
 */
Pion creer_pion(Couleur c, Position p);

/**
 * Permet de récupérer la position du pion 
 * @param pion 
 * @return la position du pion
 */
Position pion_get_position(Pion pion);

/**
 * Permet de récupérer la couleur du pion
 * @param pion
 * @return la couleur du pion
 */
Couleur pion_get_color(Pion pion);

#endif
