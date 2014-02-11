#include <plateau.h>
#include <libertes.h>
#include <position.h>

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
	FILE *f = fopen("extra/plateau_initiale.txt", "r+");
	FILE *f2 = fopen("extra/plateau_2.txt", "w+");
	
	Plateau p = plateau_chargement(f);

	Chaine c;

	Libertes libertes;
		
	Position pos;
	
	pos.x = 2;
	pos.y = 3;
	
	fclose(f);
	
	affiche_matrice(p);
	
	c = plateau_determiner_chaine(p, pos);
	
	printf("\nCouleur: %d\n", c.c);
	
	afficherPositions(c.p);
	
	//plateau_realiser_capture(p, c);
	
	affiche_matrice(p);
	
	libertes = determineLiberte(p, c);
	
	afficherPositions(&libertes);
	
	printf("save ? %d\n", plateau_sauvegarde(p, f2));
	
	return 0;
}
