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
 * @file matrice.h
 * 
 * Le fichier d'en tête qui contient la matrice
 */
 
#include <couleur.h>
 
/** @todo description de la structure */
typedef struct Matrice {
	Couleur **donnees; /** Les tableau des données */
	int nbligne; /** Le nombre de lignes */
	int nbcolonne; /** Le nombre de colonnes */
} Matrice;

/**
 * Permet d'allouer une matrice
 * @param nblig le nombre de lignes à allouer
 * @param nbcol le nombre de colonnes à allouer
 * @return une matrice nblig*nbcol
 */
Matrice creer_matrice(int nblig, int nbcol);

/**
 * Permet d'initialiser une matrice à partir d'un fichier
 * @param fichier le nom du fichier
 * @return une matrice initialisé à partir d'un fichier
 */
Matrice initMatrice(char *fichier);

/**
 * Permet d'afficher une matrice
 * @param matrice la matrice en à afficher
 */
void afficheMatrice(Matrice m);

/**
 * Permet de sauvegarder une matrice dans un fichier
 * @param m la matrice à sauvegarder
 * @param fichier le nom du fichier dans lequel on sauvegarde la matrice
 */
void SauvegardeMatrice(Matrice m, char *fichier);
