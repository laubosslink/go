#include <plateau.h>

int main(){
	FILE *f = fopen("extra/plateau_initiale.txt", "r+");
	
	Plateau p = plateau_chargement(f);
	
	fclose(f);
	
	affiche_matrice(p);
	
	// test de plateau_determiner_chaine
	
	return 0;
}
