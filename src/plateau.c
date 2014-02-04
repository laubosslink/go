#include <matrice.h>
#include <plateau.h>

Couleur plateau_get(Plateau p, int i, int j){
	return p.donnees[i][j];
}

void plateau_set(Plateau p, int i, int j, Couleur c){
	p.donnees[i][j] = c;
}

Chaine plateau_determiner_chaine(Plateau plateau, Position pos){
	
}

Plateau plateau_chargement(FILE* fichier){
	
}
