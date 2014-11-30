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
 * @version 1.0 
 * @date 03-02-2013
 */
 
/** 
 * @file chaines.h
 * 
 * @brief Ensemble des chaines
 */

#ifndef CHAINES_H_INCLUDED
#define CHAINES_H_INCLUDED

#include <ensemble.h>

/** 
 * @brief Chaines est une ensemble de chaine (alias d'un ensemble)
 * @see Ensemble
 */
typedef Ensemble Chaines;

#include <chaine.h>


/**
 * Permet de savoir si une chaine appartient a un ensemble de chaines
 * Remarque : une chaine appartient a chaines si une seul des position de la chaine se trouve dans chaines
 * @param chaines l'ensemble de chaines
 * @param chaine la chaine a verifie
 * @return 1 si chaine appartient a chaines, 0 sinon
 */
int chaines_appartient_chaine(Chaines chaines, Chaine chaine);

#endif
