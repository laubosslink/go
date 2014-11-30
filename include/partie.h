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
 * @brief Fichier d'en-tête permettant de gérer une partie 
 */

#ifndef PARTIE_H_INCLUDED
#define PARTIE_H_INCLUDED

#include <stdio.h>
#include <couleur.h>
#include <plateau.h>

/**
 * @brief Structure d'une partie qui comporte les noms des joueurs, la couleur que choisit chaque joueur et le plateau du jeu
 */
 
typedef struct Partie* Partie;

typedef void (*FonctionQuestions)(int numeroQuestion, Partie partie); 

/**
 * Permet de créer une partie
 * @return un pointeur vers une partie
 */
Partie creer_partie();

/**
 * Permet d'initialiser une partie !
 * @param fonctionQuestions une fonction qui permet de demander des questions
 * @return une partie initialise
 */
Partie partie_initialisation(FonctionQuestions fonctionQuestions);

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

/**
 * Questions a demande a l'utilisateur
 * @param numero de la question
 * @param partie pointeur vers une partie
 */
void partie_demande_questions(int numero_question, Partie partie);

void partie_echange_joueur(Partie p);

Plateau partie_get_plateau(Partie p);

char* partie_get_joueur1(Partie p);

char* partie_get_joueur2(Partie p);

Couleur partie_get_joueur(Partie p);

void partie_set_plateau(Partie p, Plateau plateau);

#endif
