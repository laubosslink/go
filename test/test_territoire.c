#include <stdio.h>

#include <territoire.h>
#include <plateau.h>
#include <position.h>
#include <ensemble_colores.h>

void afficherPositions(Ensemble_Positions *E){
	if(ensemble_vide(E)){
		printf("Rien à afficher, la liste est vide\n");
		return;
	}
	
	E->courant = E->tete;
	
	while(E->courant->suivant != NULL){
		printf("{x=%d, ",  ((Position *) E->courant->contenu)->x);
		printf("y=%d}\n",  ((Position *) E->courant->contenu)->y);
		E->courant=E->courant->suivant;
	}
	
	printf("{x=%d, ",  ((Position *) E->courant->contenu)->x);
	printf("y=%d}\n",  ((Position *) E->courant->contenu)->y);
	printf("\n\n");
}

int main(){
	FILE *f = fopen("extra/plateau_test_territoire.txt", "r+");
	
	Plateau p = plateau_chargement(f);

	Territoire t;
		
	Position pos;
	
	pos.x = 3;
	pos.y = 4;
	
	fclose(f);
	
	plateau_afficher(p);
	
	/* Test de la détermination d'une chaine */
	t = determineTerritoire(p, pos);
	
	afficherPositions(t.p);
	
	printf("appartient a : %d\n", t.c);
	
	//plateau_afficher(p);
	
	return 0;
}
