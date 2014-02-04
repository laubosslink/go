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
 * Contient la position de l'ensemble des pions sur la grille
 */
 
#include <matrice.h>
#include <chaine.h>
#include <position.h>
#include <territoire.h>

typedef struct Matrice Plateau;

/**
 * Permet de recuperer un pion sur une position
 * @param m la matrice
 * @param i l'abscisse
 * @param j l'ordonnee
 * @return La couleur du pion
 */
Couleur plateau_get(Plateau m, int i, int j);

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
 * @param plateau lle plateau
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

int plateau_copie(Plateau from, Plateau to);

Chaines plateau_entoure_un_territoire(Territoire leTerritoire, Plateau plateau);

int plateau_sauvegarde(Plateau plateau, FILE* fichier);

Plateau plateau_chargement(FILE* fichier);

Chaines captureChaines(Plateau plateau, Pion pion, int *valide);
