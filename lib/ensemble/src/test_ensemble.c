#include <stdio.h>
#include <stdlib.h>
#include <ensemble.h>

void afficherEnsembleAdr(Ensemble *E){
	if(vide(E)){
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
	if(vide(E)){
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
	int t[] = {1, 4, 15, 17};
	
	E = creer_ensemble();
	
	// on ajout 4 éléments
	ajouterElement(E, t);
	ajouterElement(E, t+1);
	ajouterElement(E, t+2);
	ajouterElement(E, t+3);
	
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
	printf("Appartient (%p): %d\n\n", t+2, appartient(E, t+2));
	
	// On check si une adresse appartient à l'ensemble
	printf("Appartient (%p): %d\n\n", t+4, appartient(E, t+4));
	
	return 0;
}

