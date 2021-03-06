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
 */
 
/** 
 * @file test_matrice.c
 * 
 * @brief code source qui permettant de tester la librairie matrice
 */
 
#include <matrice.h>
#include <stdio.h>

int main(){
	int tests = 0;
	
	Matrice m;
	
	m = matrice_init("extra/plateau_test.txt");
	
#if DEBUG_AFFICHE == 1	
	matrice_affiche(m);
#endif

	matrice_set_donnees(m, 1, 1, 1);

#if DEBUG_AFFICHE == 1	
	printf("\n");	
	matrice_affiche(m);
#endif
		
	if(matrice_get_donnees(m, 1, 1) == 1)
		tests = 1;
		
	detruire_matrice(m);
	
	if(tests == 1)
		printf("Tests libmatrice: OK\n");
	else
		printf("Tests libmatrice: Problèmes durant les tests...\n");
	
	return 0;
}
