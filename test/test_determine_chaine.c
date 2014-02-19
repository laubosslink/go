#include <plateau.h>
#include <libertes.h>
#include <position.h>

int main(){
	int tests = 0;
	
	FILE *f = fopen("extra/plateau_test.txt", "r+");
	
	Plateau p = plateau_chargement(f);

	fclose(f);

	Chaine c;
		
	Position pos = creer_position(2, 3);
	
#if DEBUG_AFFICHE == 1
	printf("\n");
	plateau_afficher(p);
	printf("\n");
#endif

	c = plateau_determiner_chaine(p, pos);

#if DEBUG_AFFICHE == 1
	printf("Chaine: \n");
	ensemble_colores_affiche(c);
	printf("Nombre d'éléments: %d\n", ensemble_colores_nbr_element(c));
	printf("\n");
#endif

	if(ensemble_colores_nbr_element(c) == 5)
		tests = 1;

	if(tests == 1)
		printf("Tests plateau_determine_chaine(...): OK\n");
	else
		printf("Tests plateau_determine_chaine(...): Problèmes durant les tests...\n");
		

	return 0;
}
