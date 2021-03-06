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
 */
 
/** 
 * @file ensemble_positions.h
 * 
 * @brief structures cell et Ensemble permettant la manipulation d'ensembles
 */

#ifndef ENSEMBLE_POSITIONS_H_INCLUDED
#define ENSEMBLE_POSITIONS_H_INCLUDED 

#include <ensemble.h>

/**
 * @brief Ensemble_Positions est un alias du type Ensemble
 */ 
typedef Ensemble Ensemble_Positions;

#include <position.h>

/**
 * Permet de creer un ensemble
 * @return un pointeur vers un ensemble
 */
Ensemble_Positions creer_ensemble_positions();

/**
 * Permet de détruire un ensemble de positions
 * @param E l'ensemble de positions
 */
void detruire_ensemble_positions(Ensemble_Positions E);

/**
 * Permet de vérifier si un ensemble est vide
 * @param E l'ensemble
 * @return 1 si il l'est
 */
int ensemble_positions_vide(Ensemble_Positions E);

/**
 * Permet de vérifier qu'un élément appartiennent à un ensemble
 * @param element l'élément
 * @return 1 si il appartient, 0 sinon
 */
int ensemble_positions_appartient(Ensemble_Positions E, Position element);

/**
 * Permet d'ajouter un élément dans un ensemble
 * @param element l'élément à ajouter
 */	
void ensemble_positions_ajouter(Ensemble_Positions E, Position element);

/**
 * Permet de supprimer un élément dans l'ensemble
 * @param element l'élement à supprimer
 * @return E pointeur vers le nouvel ensemble privé de l'élément supprimé
 */
Ensemble_Positions ensemble_positions_enlever(Ensemble_Positions E, Position element);

/**
 * Permet de positionner le pointeur tête sur le debut de mon ensemble
 * @return le pointeur de la tete de l'ensemble
 */
Cell ensemble_positions_tete(Ensemble_Positions E);
 
/**
 * Permet de positionner le pointeur sur un des éléments de l'ensemble 
 * @return le pointeur sur l'élément courant
 */
Cell ensemble_positions_courant(Ensemble_Positions E);

/**
 * Permet de dire s'il y a un élément suivant ou non 
 * @return 1 ou 0
 */
int ensemble_positions_suivant(Ensemble_Positions E);

/**
 * Permet de récupérer la position courrante de l'ensemble
 * @param E l'ensemble de positions
 * @return une position
 */
Position ensemble_positions_get_courant(Ensemble_Positions E);

/**
 * Permet d'afficher l'ensemble des positions
 * @param E l'ensemble de positions
 */
void ensemble_positions_affiche(Ensemble_Positions E);

#endif
