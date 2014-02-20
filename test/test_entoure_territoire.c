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
	
	Chaines chaines_entoure_territoire;
	
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

	chaines_entoure_territoire = plateau_entoure_un_territoire(t, p);
	
	tests = (ensemble_nbr_element(chaines_entoure_territoire) == 5) ? 1 : 0;

	if(tests == 1)
		printf("Tests plateau_entoure_un_territoire(...): OK\n");
	else
		printf("Tests plateau_entoure_un_territoire(...): Problèmes durant les tests...\n");
		

	
	return 0;
}
