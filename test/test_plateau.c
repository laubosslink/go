#include <plateau.h>
#include <libertes.h>
#include <position.h>

int main(){
	int tests = 0;
	
	FILE *f = fopen("extra/plateau_test.txt", "r+");
	FILE *f2 = fopen("extra/plateau_test_output.txt", "w+");
	
	Plateau p = plateau_chargement(f);

	Chaine c;

	Libertes libertes;
		
	Position pos = creer_position(2, 3);
	
	Chaines chainesCapturees;
	
	fclose(f);
	
#if DEBUG_AFFICHE == 1
	plateau_afficher(p);
#endif

	/* Test de la détermination d'une chaine */
	c = plateau_determiner_chaine(p, pos);

#if DEBUG_AFFICHE == 1	
	/* couleur de la chaine ?*/
	printf("\nCouleur: %d\n\n", ensemble_colores_get_couleur(c));
	
	/* Les différentes positions de la chaine même couleur*/
	printf("Chaine : ");
	ensemble_colores_affiche(c);
	printf("\n");
	
	/* réalisation d'une capture de la chaine */
	//plateau_realiser_capture(p, c);
	
	plateau_afficher(p);
#endif

	/* on détermine les libertés de la chaine */
	libertes = determineLiberte(p, c);

#if DEBUG_AFFICHE == 1		
	printf("Libertes :\n");
	ensemble_positions_affiche(libertes);
	printf("\n");
#endif

	//printf("largeur: %d\n", p.nbcolonne);
	//printf("hauteur: %d\n", p.nbligne);
	
	/* test de la sauvegarde du plateau */
	if(plateau_sauvegarde((Matrice) p, f2))
		tests = 1;
	
	fclose(f2);
	
	f2 = fopen("extra/plateau_test_output.txt", "r");
	
	/* test de l'ouverture puis de l'affichage du plateau sauvegardé */
	p = plateau_chargement(f2);

#if DEBUG_AFFICHE == 1			
	plateau_afficher(p);
#endif
	
	if(tests == 1)
		printf("Tests test_plateau.c: OK \n");
	else
		printf("Tests test_plateau.c: Problèmes durant les tests...\n");
		

	
	return 0;
}
