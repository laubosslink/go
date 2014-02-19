#include <stdio.h>

#include <territoire.h>
#include <plateau.h>
#include <position.h>
#include <ensemble_colores.h>



int main(){
	FILE *f = fopen("extra/plateau_test_territoire.txt", "r+");
	
	Plateau p = plateau_chargement(f);

	Territoire t;
	
	Position pos = creer_position(8,8);
	
	fclose(f);
	
	plateau_afficher(p);
	
	/* Test de la détermination d'une chaine */
	t = determineTerritoire(p, pos);
	
	ensemble_colores_affiche(t);
	
	if(t != NULL)
		printf("appartient a : %d\n", ensemble_colores_get_couleur(t));
	
	return 0;
}
