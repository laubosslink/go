#include <stdio.h>

#include <plateau.h>
#include <pion.h>
#include <position.h>

void affiche_positions(Ensemble_Positions *E){
	if(ensemble_vide(E)){
		printf("Rien à afficher, la liste est vide\n");
		return;
	}
	
	ensemble_reset_courant(E);
	
	while(ensemble_suivant(E)){
		printf("{x=%d, ",  position_get_courant(E)->x+1);
		printf("y=%d}\n",  position_get_courant(E)->y+1);
		
		ensemble_set_courant(E, ensemble_get_suivant(E));
	}
	
	printf("{x=%d, ",  position_get_courant(E)->x+1);
	printf("y=%d}\n",  position_get_courant(E)->y+1);
	printf("\n");
}

void affiche_captures(Chaines chaines){
	Chaine* cc; /* chaine courante */
	
	if(ensemble_vide(&chaines)){
		printf("Aucune capture !\n");
		return;
	}
	
	ensemble_reset_courant(&chaines);
	
	while(ensemble_suivant(&chaines)){
		cc = ensemble_get_courant_contenu(&chaines);
		
		printf("\n\nChaine capturée: \n");
		affiche_positions(cc->p);
		
		ensemble_set_courant(&chaines, ensemble_get_suivant(&chaines));
	}
	
	cc = ensemble_get_courant_contenu(&chaines);
	
	printf("Chaine capturée: \n");
	affiche_positions(cc->p);
}

int main(){
	FILE *f = fopen("extra/plateau_test_capture_chaines.txt", "r+");
	
	Chaine chaine;
	
	Plateau plateau = plateau_chargement(f);
	
	Pion pion;
	
	Position position;
	
	int valide;
	
	position.x = 4;
	position.y = 4;
	
	pion.p = position;
	pion.c = BLANC;
	
	plateau_afficher(plateau);
	
	chaine = plateau_determiner_chaine(plateau, position);
	
	affiche_positions(chaine.p);
	
	Chaines chaines_captures = captureChaines(plateau, pion, &valide);
	
	affiche_captures(chaines_captures);
}
