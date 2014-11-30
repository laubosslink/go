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
 * @file test_ensemble_colores.c
 * 
 * @brief code source qui permet de réaliser les tests de l'ensemble colores
 */
 
#include <stdio.h>
#include <stdlib.h>

#include <position.h>

#include <ensemble_colores.h>

int main () {
	int tests = 0;
	
	Ensemble_Colores Ec = creer_ensemble_colores();
	
	ensemble_colores_set_couleur(Ec, NOIR);
	
	if(ensemble_colores_get_couleur(Ec) == NOIR)
		tests = 1;
	
	ensemble_colores_ajouter(Ec, creer_position(5, 3));
	ensemble_colores_ajouter(Ec, creer_position(1, 0));
	ensemble_colores_ajouter(Ec, creer_position(7, 10));

	tests = (ensemble_colores_nbr_element(Ec) == 3 && tests == 1) ? 1 : 0;

#if DEBUG_AFFICHE == 1	
	ensemble_colores_affiche(Ec);
#endif

	if(tests == 1)
		printf("Tests ensemble_colores.c: OK\n");
	else
		printf("Tests ensemble_colores.c: Problèmes durant les tests...\n");
	
	return 0;
}
