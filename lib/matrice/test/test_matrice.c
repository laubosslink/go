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
 * @todo revoir la doc / remplacer Ensemble_Positions par Ensemble_Position
 */
 
/** 
 * @file test_matrice.c
 * 
 * @brief code source qui permettant de tester la librairie matrice
 */
 
#include <matrice.h>
#include <couleur.h>
#include <stdio.h>

int main(){
	Matrice m;
	
	m = matrice_init("extra/plateau_test.txt");
	
	matrice_affiche(m);
	
	m.donnees[1][1] = BLANC;
	
	printf("\n");
	
	matrice_affiche(m);
	
	return 0;
}
