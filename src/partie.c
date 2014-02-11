#include <partie.h>

void echange_joueur(Couleur* c){
	if(*c == BLANC)
		*c = NOIR;
	else if(*c == NOIR)
		*c = BLANC;
}
