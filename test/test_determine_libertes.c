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
 * @file test_determine_libertes.c
 * 
 * @brief code source qui permet de tester la determination des libertes
 */
#include <plateau.h>
#include <libertes.h>
#include <position.h>

int main(){
	int tests = 0;
	
	FILE *f = fopen("extra/plateau_test.txt", "r+");
	
	Plateau p = plateau_chargement(f);

	fclose(f);

	Chaine c;

	Libertes libertes;
		
	Position pos = creer_position(2, 3);
	
#if DEBUG_AFFICHE == 1
	printf("\n");
	plateau_afficher(p);
	printf("\n");
#endif

	c = plateau_determiner_chaine(p, pos);
	
	/* on détermine les libertés de la chaine */
	libertes = determineLiberte(p, c);
	
#if DEBUG_AFFICHE == 1
	printf("Libertes :\n");
	ensemble_positions_affiche(libertes);
	printf("\n");
#endif

	if(ensemble_nbr_element(libertes) == 7)
		tests = 1;

	if(tests == 1)
		printf("Tests determineLiberte(...): OK\n");
	else
		printf("Tests determineLiberte(...): Problèmes durant les tests...\n");
		

	return 0;
}
