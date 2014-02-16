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
 * 
 */
 
/** 
 * @file matrice.h
 * 
 * @brief Le fichier d'en tête qui contient la matrice
 */

#ifndef MATRICE_H_INCLUDED
#define MATRICE_H_INCLUDED

#include <stdio.h>
 
/** @todo description de la structure */
typedef struct Matrice {
	int **donnees; /** Les tableau des données */
	int nbligne; /** Le nombre de lignes */
	int nbcolonne; /** Le nombre de colonnes */
} Matrice;

/**
 * Permet d'allouer une matrice vide
 * @param nblig le nombre de lignes à allouer
 * @param nbcol le nombre de colonnes à allouer
 * @return une matrice nblig*nbcol
 */
Matrice matrice_creer(int nblig, int nbcol);

/**
 * Permet d'initialiser une matrice à partir d'un fichier
 * @param fichier le nom du fichier
 * @return une matrice initialisé à partir d'un fichier
 */
Matrice matrice_init(char *fichier);

/**
 * Permet d'initialiser une matrice à partir d'un fichier
 * @param fichier le pointeur de fichier
 * @return une matrice initialisé à partir d'un fichier
 */
Matrice matrice_chargement(FILE *fichier);

/**
 * Permet de savoir si un point est dans la matrice, ou si il en sort
 * @param m la matrice
 * @param x l'asbcisse
 * @param y l'ordonnée
 * @return 1 si le point est situé dans la matrice, 0 sinon
 */
int matrice_position_appartient(Matrice m, int x, int y);

/**
 * Permet d'afficher une matrice
 * @param matrice la matrice en à afficher
 */
void matrice_affiche(Matrice m);

/**
 * Permet de sauvegarder une matrice dans un fichier
 * @param m la matrice à sauvegarder
 * @param fichier le nom du fichier dans lequel on sauvegarde la matrice
 */
int matrice_sauvegarde(Matrice m, FILE *fichier);

#endif
