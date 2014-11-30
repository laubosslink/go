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

#include <ensemble.h>

/**
 * @brief structure d'une position qui permet de définir une position 2D. Cette structure comporte l'absice et l'ordonné de la position.
 */
typedef struct Position* Position;


/**
 * Permet de creer une position
 * @param x l'abscisse
 * @param y l'ordonnee
 * @return un pointeur vers la position alloue
 */
Position creer_position(int x, int y);

/**
 * Permet de copier une position actuelle dans une nouvelle
 * @param pos la position actuelle
 * @return une nouvelle position
 */
Position position_copy(Position pos);

/**
 * Permet de détruire une position
 * @param p la position
 */
void detruire_position(Position p);

/**
 * Permet de récupérer l'abcisse de la position p
 * @param p le pointeur sur la position
 * @return x l'abcisse
 */
int position_get_x(Position p);

/**
 * Permet de récupérer l'ordonnée de la position p
 * @param p le pointeur sur la position
 * @return x l'ordonnée
 */
int position_get_y(Position p); 

/**
 * Permet de récupérer la position actuelle d'un ensemble
 * @param E l'ensemble
 * @return Un pointeur vers une position
 */
Position position_get_courant(Ensemble E);

/**
 * Permet de modifier une position
 * @param p la position
 * @param x nouvelle abscisse
 * @param y nouvelle ordonnée
 */
void position_set(Position p, int x, int y);

/**
 * Permet d'avoir une nouvelle position déplacé vers le haut
 * @param p la position a deplacer
 * @return une nouvelle position déplacé
 */
Position haut(Position p);

/**
 * Permet d'avoir une nouvelle position déplacé vers le bas
 * @param p la position a deplacer
 * @return une nouvelle position déplacé
 */
Position bas(Position p);

/**
 * Permet d'avoir une nouvelle position déplacé vers la gauche
 * @param p la position a deplacer
 * @return une nouvelle position déplacé
 */
Position gauche(Position p);

/**
 * Permet d'avoir une nouvelle position déplacé vers la droite
 * @param p la position a deplacer
 * @return une nouvelle position déplacé
 */
Position droite(Position p);

/**
 * Permet de se deplacer vers le haut
 * @param p la position a deplacer
 * @return la position deplacer
 */
Position deplacer_haut(Position p);

/**
 * Permet de se deplacer vers le bas
 * @param p la position a deplacer
 * @return la position deplacer
 */
Position deplacer_bas(Position p);

/**
 * Permet de se deplacer vers la gauche
 * @param p la position a deplacer
 * @return la position deplacer
 */
Position deplacer_gauche(Position p);

/**
 * Permet de se deplacer vers la droite
 * @param p la position a deplacer
 * @return la position deplacer
 */
Position deplacer_droite(Position p);

#endif
