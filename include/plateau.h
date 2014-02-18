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
 * @file plateau.h
 * 
 * @brief Contient la position de l'ensemble des pions sur la grille
 */
 
#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED

#include <stdio.h>

/**
 * @brief Structure d'un plateau de jeu. Plateau est un alias du type Matrice.
 */
typedef struct Matrice* Plateau;

#include <matrice.h>
#include <chaine.h>
#include <position.h>
#include <pion.h>
#include <chaines.h>
#include <territoire.h>

/**
 * Permet d'afficher un plateau dans la console
 * @param p le plateau
 */
void plateau_afficher(Plateau p);

/**
 * Permet de creer un plateau [taille x taille]
 * @param taille 
 * @return un plateau
 */
Plateau creer_plateau(int taille);

/**
 * Permet de savoir si la couleur est un pion
 * @param c la couleur
 * @return 1 si c'est un pion, 0 sinon 
 */
int est_un_pion(Couleur c);

/**
 * Permet de savoir si c'est un pion du plateau
 * @param plateau Le plateau 
 * @param pos La position d'un plateau
 * @return 1 si le pion est dans le plateau, 0 sinon
 */
int est_un_pion_plateau(Plateau plateau, Position pos);

/**
 * Permet de recuperer un pion sur une position
 * @param m la matrice
 * @param x l'abscisse
 * @param y l'ordonnee
 * @return La couleur du pion
 */
Couleur plateau_get(Plateau m, int x, int y);

/**
 * Permet de recuperer un pion sur une position
 * @param p le plateau
 * @param pos la position
 * @return La couleur du pion
 */
Couleur plateau_get_pos(Plateau p, Position pos);

/**
 * Permet de mettre un pion sur le plateau
 * @param m la matrice
 * @param i l'abscisse
 * @param j l'ordonnee
 * @param c la couleur du pion
 */
void plateau_set(Plateau m, int i, int j, Couleur c);

/**
 * Produit la chaine a laquelle appartient le pion, a la position
 * pos sur le plateau. Si il n'y a pas de pion, sur cette case alors le
 * resultat est NULL
 * @param plateau le plateau
 * @param pos la position du pion
 * @return NULL si il n'y a pas de pion, une chaine sinon
 */
Chaine plateau_determiner_chaine(Plateau plateau, Position pos);

/**
 * Realise la capture des pions correspondant a la chaine en les enlevant du plateau
 * @param plateau le plateau
 * @param chaine une chaine
 */
void plateau_realiser_capture(Plateau plateau, Chaine chaine);

/**
 * indique sur l'organisation du plateau est identique a une precedente organisation
 * de plateau. 
 * @param plateau le plateau actuel
 * @param ancienPlateau l'ancien plateau
 * @return 1 si identique, 0 sinon
 */
int plateau_est_identique(Plateau plateau, Plateau ancienPlateau);

/**
 * Copie un plateau, les deux tableaux sont supposes deja alloues
 * @param from le plateau source
 * @param to le plateau destination
 * @return 1 si la copie a fonctionnee, 0 sinon
 */
int plateau_copie(Plateau from, Plateau to);

/**
 * Determine la ou les chaines entourant un territoire
 * @param leTerritoire le territoire
 * @param plateau le plateau
 * @return une ou plusieurs chaines
 */
Chaines plateau_entoure_un_territoire(Territoire leTerritoire, Plateau plateau);

/**
 * Permet de sauvegarde un plateau dans un fichier
 * @param plateau le plateau
 * @param fichier le fichier dans lequel on sauvegarde le plateau
 * @return 1 si tout s'est bien passé, 0 sinon
 */
int plateau_sauvegarde(Plateau plateau, FILE* fichier);

/**
 * Permet de savoir si une position est sur plateau
 * @param plateau le plateau
 * @param position la position à vérifier
 * @return 1 si elle appartient au plateau, 0 sinon
 */
int plateau_position_appartient(Plateau plateau, Position position);

/**
 * Permet de charger un plateau a partir d'un fichier
 * @param fichier le fichier qui contient le plateau
 * @return un plateau
 */
Plateau plateau_chargement(FILE* fichier);

/**
 * En fonction de la position du pion et de sa couleur, retourne les chaines captures. Si aucune
 * chaine n'est capturé par la pose du pion, alors la valeur NULL est retournée. L'entier (référencé par) valide
 * est égal à zéro si le fait de placer le pion en cette position conduit à construire une chaine
 * sans liberté de la couleur du pion (sauf si ce coup produit la capture d'au moins une chaine adverse).
 * Dans le cas contraire l'entier référencé par valide est égale à 1
 * 
 * @param plateau Le plateau
 * @param pion le pion
 * @param valide
 * @return un ensemble de chaine
 */
Chaines captureChaines(Plateau plateau, Pion pion, int *valide);


/**
 * Permet de récupérer la taille du plateau (largeur) sachant que hauteur est la même
 * @param plateau le plateau
 * @return le taille du plateau (largeur) 
 */
int plateau_get_taille(Plateau plateau);

#endif
