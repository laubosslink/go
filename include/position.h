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
 * @file position.h
 * 
 * @brief Une position
 */
 
#ifndef POSITION_H_INCLUDED
#define POSITION_H_INCLUDED 

/**
 * Permet de définir une position 2D
 */
typedef struct Position {
	/* Position x */
	int x;

	/* Position y */
	int y;
} Position;

/**
 * Permet de creer une position
 * @param x l'abscisse
 * @param y l'ordonnee
 * @return un pointeur vers la position alloue
 */
Position* position_creer(int x, int y);

/**
 * Permet de se deplacer vers le haut
 * @param p la position a deplacer
 * @return nouvelle position
 */
Position haut(Position p);

/**
 * Permet de se deplacer vers le bas
 * @param p la position a deplacer
 * @return nouvelle position
 */
Position bas(Position p);

/**
 * Permet de se deplacer vers la gauche
 * @param p la position a deplacer
 * @return nouvelle position
 */
Position gauche(Position p);

/**
 * Permet de se deplacer vers la droite
 * @param p la position a deplacer
 * @return nouvelle position
 */
Position droite(Position p);

#endif
