#include <plateau.h>

Couleur plateau_get(Plateau p, int i, int j){
	return p.donnees[i][j];
}

void plateau_set(Plateau p, int i, int j, Couleur c){
	p.donnees[i][j] = c;
}
