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
 * @file partie.h
 * 
 * Fichier d'en-tête permettant de gérer une partie 
 */

#ifndef PARTIE_H_INCLUDED
#define PARTIE_H_INCLUDED

#include <stdio.h>
#include <couleur.h>
#include <plateau.h>
 
typedef struct Partie {
	Couleur joueur_actuel;
	Plateau plateau;
} Partie;

Partie partie_initialisation();

/**
 * Sauvegarde la partie dans sa position actuelle. Si la sauvegarde se passe
 * sans problème la fonction retourne 1, 0 sinon
 * @param partie La partie actuelle
 * @param fichier Le fichier dans lequel on sauvegarde la partie
 * @return 0 si il n'y a pas de problème, 1 sinon
 */
int partie_sauvegarde(Partie partie, FILE* fichier);

/**
 * Charge une partie précédement sauvegardée. Si le chargement n'est pas possible,
 * retorune un pointeur NULL
 * @param fichier Le fichier à partir du quel on charge la partie
 * @return La partie, ou NULL si le chargement n'est pas possible
 */
Partie partie_charge(FILE* fichier);

/**
 * Calcul la valeur des deux scores des deux joueurs en fin de partie en tenant compte du komi
 * @param p la partie
 * @param scores les scores des joueurs
 * @param valKomi
 */
void partie_score_joueurs(Partie p, int *scores, float valKomi);
#endif
