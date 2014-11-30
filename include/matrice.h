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
 * @todo pouvoir modifier la taille de la matrice (utilisation de realloc, modification nbligne, nbcolonne)
 */
 
/** 
 * @file matrice.h
 * 
 * @brief Le fichier d'en tête qui contient la matrice
 */

#ifndef MATRICE_H_INCLUDED
#define MATRICE_H_INCLUDED

#include <stdio.h>

typedef struct Matrice* Matrice;

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

/**
 * Permet de récupérer la taille de la matrice en hauteur
 * @param m la matrice
 * @return le nombre de ligne
 */
int matrice_get_nombre_ligne(Matrice m);

/**
 * Permet de récupérer la taille de la matrice en largeur
 * @param m la matrice
 * @return le nombre de colonne
 */
int matrice_get_nombre_colonne(Matrice m);

/**
 * Permet de récupérer une donnée de la matrice
 * @param m la matrice
 * @param j la hauteur (ligne)
 * @param i la largeur (colonne)
 * @return une donnée
 */
int matrice_get_donnees(Matrice m, int i, int j);

/**
 * Permet de récupérer les données d'une ligne
 * @param m la matrice
 * @param j la ligne
 * @return un tableau de données
 */
int* matrice_get_donnees_ligne(Matrice m, int j);

/**
 * Permet de modifier une données de la matrice
 * @param m la matrice
 * @param j la hauteur (ligne)
 * @param i la largeur (colonne)
 * @param data la donnée à insérer
 */
void matrice_set_donnees(Matrice m, int i, int j, int data);

#endif
