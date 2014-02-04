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
 * @todo remplacer cell par Cell (avec majuscule)
 */
 
/** 
 * @file ensemble.h
 * 
 * structures cell et Ensemble permettant la manipulation d'ensembles
 */
 
typedef struct cell cell;
typedef struct Ensemble Ensemble;

struct cell{
	void* contenu;
	cell* suivant;
};

struct Ensemble{
	cell* courant;
	cell* tete;
};

/**
 * Permet de creer un ensemble
 * @return un pointeur vers un ensemble
 */
Ensemble* creer_ensemble();

/**
 * Permet de vérifier si un ensemble est vide
 * @param E l'ensemble
 * @return 1 si il l'est
 */
int vide(Ensemble* E);

/**
 * Permet de vérifier qu'un élément appartiennent à un ensemble
 * @param element l'élément
 * @return 1 si il appartient, 0 sinon
 */
int appartient(Ensemble* E, void* element);

/**
 * Permet d'ajouter un élément dans un ensemble
 * @param element l'élément à ajouter
 */	
void ajouterElement(Ensemble* E, void* element);
