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
	FILE *f = fopen("extra/plateau_test.txt", "r+");
	FILE *f2 = fopen("extra/plateau_test_output.txt", "w+");
	
	Plateau p = plateau_chargement(f);

	Chaine c;

	Libertes libertes;
		
	Position pos;
	
	Pion pion;
	
	Chaines chainesCapturees;
	
	int* valide;
	
	valide = (int*)malloc(sizeof(int));
	
	pos.x = 2;
	pos.y = 3;
	
	pion.p = pos;
	
	fclose(f);
	
	plateau_afficher(p);
	
	/* Test de la détermination d'une chaine */
	c = plateau_determiner_chaine(p, pos);
	
	/* couleur de la chaine ?*/
	printf("\nCouleur: %d\n", c.c);
	
	/* Les différentes positions de la chaine même couleur*/
	afficherPositions(c.p);
	
	/* réalisation d'une capture de la chaine */
	plateau_realiser_capture(p, c);
	
	plateau_afficher(p);
	
	/* on détermine les libertés de la chaine */
	libertes = determineLiberte(p, c);
	
	afficherPositions(&libertes);
	
	printf("largeur: %d\n", p.nbcolonne);
	printf("hauteur: %d\n", p.nbligne);
	
	/* test de la sauvegarde du plateau */
	printf("save ? %d\n", plateau_sauvegarde((Matrice) p, f2));
	
	fclose(f2);
	
	f2 = fopen("extra/plateau_test_output.txt", "r");
	
	/* test de l'ouverture puis de l'affichage du plateau sauvegardé */
	p = plateau_chargement(f2);
	
	plateau_afficher(p);
	
	(*valide) == 0;
	captureChaines(plateau,
	
	return 0;
}
