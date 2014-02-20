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
 * @file test_ensemble.c
 * 
 * @brief code source qui permet de tester la librairie ensemble
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <ensemble.h>
	
int main(){
	int tests = 0;
	
	Ensemble E;
	Ensemble A;
	Ensemble e;
	
	int t[] = {1, 4, 15, 17};
	
	E = creer_ensemble();
	
	// on ajout 4 éléments
	ensemble_ajouter(E, t);
	ensemble_ajouter(E, t+1);
	ensemble_ajouter(E, t+2);
	ensemble_ajouter(E, t+3);

	if(ensemble_nbr_element(E) == 4)
		tests = 1;

#if DEBUG_AFFICHE == 1	
	// on regarde les adresses du tableau t
	printf("adr1: %p\n", t); 
	printf("adr2: %p\n", t+1); 
	printf("adr3: %p\n", t+2); 
	printf("adr3: %p\n\n", t+3); 

	// on affiche les adresses des contenus dans la liste pour voir si elles sont exactement pareil que celle du tableau t
	ensemble_afficher_pointeur(E);
	
	// on affiche les entiers contenus
	ensemble_afficher_entier(E);
	
	// On check si une adresse appartient à l'ensemble
	printf("Appartient (%p): %d\n\n", t+2, ensemble_appartient(E, t+2));
	
	// On check si une adresse appartient à l'ensemble
	printf("Appartient (%p): %d\n\n", t+4, ensemble_appartient(E, t+4));
#endif
	
	tests = (ensemble_appartient(E, t+2) && tests == 1) ? 1 : 0;
		
	tests = (!ensemble_appartient(E, t+4) && tests == 1) ? 1 : 0;

	ensemble_enlever(E, t+3);

	tests = (!ensemble_appartient(E, t+3) && tests == 1) ? 1 : 0;

#if DEBUG_AFFICHE == 1	
	printf("Enleve element a la fin: \n");
	ensemble_afficher_entier(E);
	printf("--------------------------\n");
#endif

	ensemble_ajouter(E, t+3);

	ensemble_enlever(E, t+2);

	tests = (!ensemble_appartient(E, t+2) && tests == 1) ? 1 : 0;

#if DEBUG_AFFICHE == 1	
	printf("Enleve element au milieu: \n");
	ensemble_afficher_entier(E);
	printf("--------------------------\n");
#endif

	ensemble_enlever(E, t);

	tests = (!ensemble_appartient(E, t) && tests == 1) ? 1 : 0;

#if DEBUG_AFFICHE == 1	
	printf("Enleve element au debut: \n");
	ensemble_afficher_entier(E);
	printf("--------------------------\n");
#endif

	ensemble_ajouter(E, t);

	A = creer_ensemble();
	
	ensemble_ajouter(A, t+3);
	ensemble_ajouter(A, t+3);
	ensemble_ajouter(A, t+3);

	tests = (ensemble_nbr_element(A) == 1 && tests == 1) ? 1 : 0;

#if DEBUG_AFFICHE == 1	
	ensemble_afficher_entier(A);
#endif

	A = ensemble_concatene(A, E);
	
	tests = (ensemble_nbr_element(A) == 3 && tests == 1) ? 1 : 0;
		
#if DEBUG_AFFICHE == 1
	ensemble_afficher_entier(A);
#endif
	
	e = creer_ensemble();
	
	ensemble_ajouter(e, t+1);
	ensemble_ajouter(e, t+2);
	ensemble_ajouter(e, t+3);
	ensemble_ajouter(e, t+3);

	tests = (ensemble_nbr_element(e) == 3 && tests == 1) ? 1 : 0;
	
	ensemble_enlever(e, t+1);
	ensemble_enlever(e, t+2);
	ensemble_enlever(e, t+3);
	
	tests = (ensemble_nbr_element(e) == 0 && tests == 1) ? 1 : 0;
	
	ensemble_ajouter(e, t+3);
	detruire_ensemble(e);
	
	tests = (ensemble_nbr_element(e) == 0 && ensemble_tete(e) == NULL && tests == 1) ? 1 : 0;
	
#if DEBUG_AFFICHE == 1
	ensemble_afficher_entier(e);
#endif

	if(tests == 1)
		printf("Tests libensemble: OK\n");
	else
		printf("Tests libensemble: Problèmes durant les tests...\n");

	return 0;
}

