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
 * @file test_entoure_territoire.c
 * 
 * @brief code source qui permet de réaliser les tests qui entoure le territoire
 */
 
#include <stdio.h>

#include <territoire.h>
#include <plateau.h>
#include <position.h>
#include <ensemble_colores.h>

int main(){
	int tests = 0;
	
	FILE *f = fopen("extra/plateau_test_territoire.txt", "r+");
	
	Plateau p = plateau_chargement(f);

	Territoire t;
	
	Chaines chaines_entoure_territoire;
	
	Position pos = creer_position(8,8);
	
	fclose(f);


#if DEBUG_AFFICHE == 1
	plateau_afficher(p);
	printf("\n");
#endif

	/* Test de la détermination d'un territoire */
	t = determineTerritoire(p, pos);
	
#if DEBUG_AFFICHE == 1
	printf("Territoire:\n");
	ensemble_colores_affiche(t);
	printf("\n");
#endif

	chaines_entoure_territoire = plateau_entoure_un_territoire(t, p);

#if DEBUG_AFFICHE == 1
	printf("Il y a %d chaines qui entoure le territoires \n", ensemble_nbr_element(chaines_entoure_territoire));
#endif

	/* @todo doit être égale à 5 ? */
	tests = (ensemble_nbr_element(chaines_entoure_territoire) == 1) ? 1 : 0;

	if(tests == 1)
		printf("Tests plateau_entoure_un_territoire(...): OK\n");
	else
		printf("Tests plateau_entoure_un_territoire(...): Problèmes durant les tests...\n");
	
	return 0;
}
