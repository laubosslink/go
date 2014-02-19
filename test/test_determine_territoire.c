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
	
	Position pos_sans_territoire;
	
	Position pos = creer_position(8,8);
	
	fclose(f);


#if DEBUG_AFFICHE == 1
	plateau_afficher(p);
#endif

	/* Test de la détermination d'un territoire */
	t = determineTerritoire(p, pos);
	
#if DEBUG_AFFICHE == 1
	ensemble_colores_affiche(t);
#endif

	if(ensemble_colores_get_couleur(t) == BLANC)
		tests = 1;
	
	tests = (ensemble_colores_nbr_element(t) == 18 && tests == 1) ? 1 : 0;
	
	pos_sans_territoire = creer_position(1,1);
	
	t = determineTerritoire(p, pos_sans_territoire);
	
	tests = (ensemble_colores_get_couleur(t) == VIDE && tests == 1) ? 1 : 0;

	if(tests == 1)
		printf("Tests determineTerritoire(...): OK\n");
	else
		printf("Tests determineTerritoire(...): Problèmes durant les tests...\n");
		

	
	return 0;
}
