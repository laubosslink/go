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
 * @file couleur.h
 * 
 * @brief La couleur d'un pion
 */

#ifndef COULEUR_H_INCLUDED
#define COULEUR_H_INCLUDED

/** 
 * Permet de représenter la couleur des pionts
 */
typedef enum eCouleur {
	/** représente aucun pion */
	VIDE=0,
	
	/** Permet de représenter les pions blancs */
	BLANC=1,

	/** Permet de représenter les pions noirs*/
	NOIR=2
} Couleur;

#endif
