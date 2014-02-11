#include <matrice.h>
#include <couleur.h>
#include <stdio.h>

int main(){
	Matrice m;
	
	m = matrice_init("extra/plateau_test_13.txt");
	
	matrice_affiche(m);
	
	m.donnees[1][1] = BLANC;
	
	printf("\n");
	
	matrice_affiche(m);
	
	return 0;
}
