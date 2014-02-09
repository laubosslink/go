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
 * 
 * @todo revoir la doc 
 */
 
/** 
 * @file ensemble_colores.h
 * 
 * structures Ensemble_colores permettant la manipulation d'un ensemble de position et d'une couleur
 */

#include <couleur.h>
#include <position.h>

typedef struct Ensemble_Colores Ensemble_Colores;

struct Ensemble_Colores{
	Couleur c;
	Cell* courant;
	Cell* suivant;
};

typedef struct Cell Cell;

struct Cell{
	Position* contenu;
	Cell* suivant;
};


/**
 * Permet de creer un ensemble
 * @return un pointeur vers un ensemble
 */
Ensemble_Colores* creer_ensembleColores();

/**
 * Permet de vérifier si un ensemble est vide
 * @param E l'ensemble
 * @return 1 si il l'est
 */
int vide(Ensemble_Colores* E);

/**
 * Permet de vérifier qu'un élément appartiennent à un ensemble
 * @param element l'élément
 * @return 1 si il appartient, 0 sinon
 */
int appartient(Ensemble_Colores* E, Position* element);

/**
 * Permet d'ajouter un élément dans un ensemble
 * @param element l'élément à ajouter
 */	
void ajouterElement(Ensemble_Colores* E, Position* element);

/**
 * Permet de supprimer un élément dans l'ensemble
 * @param element l'élement à supprimer
 * @return E pointeur vers le nouvel ensemble privé de l'élément supprimé
 */
Ensemble_Colores* detruire(Ensemble_Colores* E, Position* element);

/**
 * Permet de positionner le pointeur tête sur le debut de mon ensemble
 * @return le pointeur de la tete de l'ensemble
 */
Cell* tete(Ensemble_Colores* E);
 
 /**
  * Permet de positionner le pointeur sur un des éléments de l'ensemble 
  * @return le pointeur sur l'élément courant
  */
Cell* courant(Ensemble_Colores* E);

/**
 * Permet de dire s'il y a un élément suivant ou non 
 * @return 1 ou 0
 */
 int suivant(Ensemble_Colores* E);
