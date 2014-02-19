#include <stdio.h>

#include <plateau.h>
#include <pion.h>
#include <position.h>

void affiche_positions(Ensemble_Colores E){
	if(ensemble_colores_vide(E)){
		printf("Rien à afficher, la liste est vide\n");
		return;
	}
	
	ensemble_colores_reset(E);
	
	while(ensemble_colores_suivant(E)){
		printf("{x=%d, ",  ((Position *) ensemble_colores_get_courant(E))->x+1);
		printf("y=%d}\n",  ((Position *) ensemble_colores_get_courant(E))->y+1);
		
		ensemble_colores_set_courant(E, ensemble_colores_get_suivant(E));
	}
	
	printf("{x=%d, ",  ((Position *) ensemble_colores_get_courant(E))->x+1);
	printf("y=%d}\n",  ((Position *) ensemble_colores_get_courant(E))->y+1);
	printf("\n");
}

void affiche_captures(Chaines chaines){
	Chaine cc; /* chaine courante */
	
	if(ensemble_vide(chaines)){
		printf("Aucune capture !\n");
		return;
	}
	
	ensemble_reset_courant(chaines);
	
	while(ensemble_suivant(chaines)){
		cc = ensemble_get_courant_contenu(chaines);
		
		printf("\n\nChaine capturée: \n");
		affiche_positions(cc);
		
		ensemble_set_courant(chaines, ensemble_get_suivant(chaines));
	}
	
	cc = ensemble_get_courant_contenu(chaines);
	
	printf("Chaine capturée: \n");
	affiche_positions(cc);
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
	
	affiche_positions(chaine);
	
	Chaines chaines_captures = captureChaines(plateau, pion, &valide);
	
	affiche_captures(chaines_captures);
}
