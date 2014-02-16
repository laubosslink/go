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

void afficherEnsembleAdr(Ensemble *E){
	if(ensemble_vide(E)){
		printf("Rien à afficher, la liste est vide\n");
		return;
	}
	
	printf("{");
	
	E->courant=E->tete;
	
	while(E->courant->suivant != NULL){
		printf("%p\t",  E->courant->contenu);
		E->courant=E->courant->suivant;
	}
	
	printf("%p", E->courant->contenu);
	printf("}\n\n");
}

void afficherEnsembleInt(Ensemble *E){
	if(ensemble_vide(E)){
		printf("Rien à afficher, la liste est vide\n");
		return;
	}
	
	printf("{");
	
	E->courant=E->tete;
	
	while(E->courant->suivant != NULL){
		printf("%d\t",  *((int *) E->courant->contenu));
		E->courant=E->courant->suivant;
	}
	
	printf("%d", *((int *) E->courant->contenu));
	printf("}\n\n");
}
	
int main(){
	Ensemble* E;
	Ensemble* A;
	Ensemble e;
	
	int t[] = {1, 4, 15, 17};
	
	E = creer_ensemble();
	
	// on ajout 4 éléments
	ensemble_ajouter(E, t);
	ensemble_ajouter(E, t+1);
	ensemble_ajouter(E, t+2);
	ensemble_ajouter(E, t+3);
	
	// on regarde les adresses du tableau t
	printf("adr1: %p\n", t); 
	printf("adr2: %p\n", t+1); 
	printf("adr3: %p\n", t+2); 
	printf("adr3: %p\n\n", t+3); 
	
	// on affiche les adresses des contenus dans la liste pour voir si elles sont exactement pareil que celle du tableau t
	afficherEnsembleAdr(E);
	
	// on affiche les entiers contenus
	afficherEnsembleInt(E);
	
	// On check si une adresse appartient à l'ensemble
	printf("Appartient (%p): %d\n\n", t+2, ensemble_appartient(E, t+2));
	
	// On check si une adresse appartient à l'ensemble
	printf("Appartient (%p): %d\n\n", t+4, ensemble_appartient(E, t+4));
	
	ensemble_enlever(E, t+3);
	
	A = (Ensemble*) malloc(sizeof(Ensemble));
	
	ensemble_ajouter(A, t+3);
	ensemble_ajouter(A, t+3);
	ensemble_ajouter(A, t+3);
	
	afficherEnsembleInt(A);
	
	A = ensemble_concatene(A, E);
	
	afficherEnsembleInt(A);
	
	ensemble_init(&e);
	ensemble_ajouter(&e, t+1);
	ensemble_ajouter(&e, t+2);
	ensemble_ajouter(&e, t+3);
	ensemble_ajouter(&e, t+3);
	afficherEnsembleInt(&e);
	
	return 0;
}

