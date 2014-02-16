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
 * @file ensemble.h
 * 
 * @brief structures cell et Ensemble permettant la manipulation d'ensembles
 */

#ifndef ENSEMBLE_H_INCLUDED
#define ENSEMBLE_H_INCLUDED

typedef struct Cell Cell;
typedef struct Ensemble Ensemble;

/** 
 *@brief structure Cell qui contient le contenu de la cellule et le pointeur vers la cellule suivante. 
 */
struct Cell{
	void* contenu;
	Cell* suivant;
};

/** 
 *@brief structure Ensemble contient le pointeur vers la cellule courante et le pointeur vers la tete de l'ensemble. 
 */
struct Ensemble{
	Cell* courant;
	Cell* tete;
};

/**
 * Permet d'initialiser un ensemble
 * @param E l'ensemble
 */
void ensemble_init(Ensemble *E);

/**
 * Permet de creer un ensemble
 * @return un pointeur vers un ensemble
 */
Ensemble* creer_ensemble();

/**
 * Permet de vérifier si un ensemble est vide
 * @param E l'ensemble
 * @return 1 si il l'estsinon
 */
int ensemble_vide(Ensemble* E);

/**
 * Permet de vérifier qu'un élément appartiennent à un ensemble
 * @param element l'élément
 * @return 1 si il appartient, 0 sinon
 */
int ensemble_appartient(Ensemble* E, void* element);

/**
 * Permet d'ajouter un élément dans un ensemble
 * @param element l'élément à ajouter
 */	
void ensemble_ajouter(Ensemble* E, void* element);

/**
 * Permet de supprimer un élément dans l'ensemble
 * @param element l'élement à supprimer
 * @return E pointeur vers le nouvel ensemble privé de l'élément supprimé
 */
Ensemble* ensemble_enlever(Ensemble* E, void* element);

/**
 * Permet de positionner le pointeur tête sur le debut de mon ensemble
 * @return le pointeur de la tete de l'ensemble
 */
Cell* ensemble_tete(Ensemble* E);
 
 /**
  * Permet de positionner le pointeur sur un des éléments de l'ensemble 
  * @return le pointeur sur l'élément courant
  */
Cell* ensemble_courant(Ensemble* E);

/**
 * Permet de récupérer la cellule suivante d'un ensemble
 * @param E l'ensemble
 * @return la cellule suivante (par rapport à courant)
 */
Cell* ensemble_get_suivant(Ensemble* E);

/**
 * Permet de récupérer le contenu de la cellule courante
 * @param E l'ensemble
 * @return void* le contenu
 */
void* ensemble_get_courant_contenu(Ensemble *E);

/**
 * Permet de modifier le pointeur de la cellule courante sur une autre
 * @param E l'ensemble
 * @param c la nouvelle celulle vers laquelle pointe courant
 */
void ensemble_set_courant(Ensemble* E, Cell *c);

/**
 * Permet de dire s'il y a un élément suivant ou non 
 * @return 1 ou 0
 */
int ensemble_suivant(Ensemble* E);

/**
 * Permet de concatener deux ensembles
 * @param e1 l'ensemble e1 ajouter en "tête"
 * @param e2 l'ensemble e2 ajouter en bout de e1
 * @return un nouvel ensemble
 */
Ensemble* ensemble_concatene(Ensemble* e1, Ensemble* e2);

/**
 * Permet de remettre le pointeur courant sur la tête de l'ensemble
 * @param E l'ensemble
 */
void ensemble_reset_courant(Ensemble* E);

#endif
