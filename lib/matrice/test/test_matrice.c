#include <matrice.h>
#include <couleur.h>
#include <stdio.h>

int main(){
	Matrice m;
	
	m = init_matrice("extra/plateau_initiale.txt");
	
	affiche_matrice(m);
	
	m.donnees[1][1] = BLANC;
	
	printf("\n");
	
	affiche_matrice(m);
	
	return 0;
}
