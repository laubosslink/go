#include <stdio.h>

#include <plateau.h>
#include <pion.h>
#include <position.h>

int main(){
	FILE *f = fopen("extra/plateau_test_capture_chaines.txt", "r+");
	
	Plateau plateau = plateau_chargement(f);
	
	Pion pion;
	
	Position position;
	
	int valide;
	
	position.x = 5;
	position.y = 5;
	
	pion.p = position;
	pion.c = BLANC;
	
	plateau_afficher(plateau);
	
	Chaines capture = captureChaines(plateau, pion, &valide);
}
