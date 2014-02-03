#include <stdio.h>
#include <stdlib.h>
#include <ensemble.h>

void afficherEnsemble(Ensemble *E){
	if(vide(E)){
		printf("Rien à afficher, la liste est vide\n");
		return;
	}
	
	printf("{");
	
	E->courant=E->tete;
	
	while(E->courant->suivant != NULL){
		printf("%p\t", E->courant->contenu);
		E->courant=E->courant->suivant;
	}
	
	printf("%p",E->courant->contenu);
	printf("}\n");
}
	
int main(){
	Ensemble* E;
	int nbr;
	
	E = creer_ensemble();
	
	ajouterElement(15,E);
	ajouterElement(1,E);
	ajouterElement(3,E); 
	
	afficherEnsemble(E);
	
	nbr = appartient(E,1); 
	
	printf("Appartient: %d\n", nbr);
	
	return 0;
}

