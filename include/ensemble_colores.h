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
 * @version 1.2 
 * @date 03-02-2013
 */
 
/** 
 * @file ensemble_colores.h
 * 
 * @brief structures Ensemble_colores permettant la manipulation d'un ensemble de position et d'une couleur
 */

#ifndef ENSEMBLE_COLORES_H_INCLUDED
#define ENSEMBLE_COLORES_H_INCLUDED 

#include <couleur.h>
#include <positions.h>


typedef struct Ensemble_Colores Ensemble_Colores;

/**
 * @brief Structure d'un ensemble coloré contient une couleur, et un ensemble de positions
 */
struct Ensemble_Colores {
	Couleur c; 
	Positions* p;
};

#include <ensemble.h>
#include <position.h>

/**
 * Permet de creer un ensemble
 * @return un pointeur vers un ensemble
 */
Ensemble_Colores* creer_ensemble_colores();

/**
 * Permet d'initialiser un ensemble coloré
 * @param E l'ensenble coloré
 */
void ensemble_colores_init(Ensemble_Colores* E);

/**
 * Permet de vérifier si un ensemble est vide
 * @param E l'ensemble
 * @return 1 si il l'est
 */
int ensemble_colores_vide(Ensemble_Colores* E);

/**
 * Permet de vérifier qu'un élément appartiennent à un ensemble
 * @param element l'élément
 * @return 1 si il appartient, 0 sinon
 */
int ensemble_colores_appartient(Ensemble_Colores* E, Position* element);

/**
 * Permet d'ajouter un élément dans un ensemble
 * @param element l'élément à ajouter
 */	
void ensemble_colores_ajouter(Ensemble_Colores* E, Position* element);

/**
 * Permet de supprimer un élément dans l'ensemble
 * @param element l'élement à supprimer
 * @return E pointeur vers le nouvel ensemble privé de l'élément supprimé
 */
Ensemble_Colores* ensemble_colores_enlever(Ensemble_Colores* E, Position* element);

/**
 * Permet de positionner le pointeur tête sur le debut de mon ensemble
 * @return le pointeur de la tete de l'ensemble
 */
Cell* ensemble_colores_tete(Ensemble_Colores* E);
 
 /**
  * Permet de positionner le pointeur sur un des éléments de l'ensemble 
  * @return le pointeur sur l'élément courant
  */
Cell* ensemble_colores_courant(Ensemble_Colores* E);

/**
 * Permet de dire s'il y a un élément suivant ou non 
 * @return 1 ou 0
 */
int ensemble_colores_suivant(Ensemble_Colores* E);

#endif
