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
		printf("{x=%d, ",  position_get_x(ensemble_colores_get_courant(E))+1);
		printf("y=%d}\n",  position_get_y(ensemble_colores_get_courant(E))+1);
		
		ensemble_colores_set_courant(E, ensemble_colores_get_suivant(E));
	}
	
	printf("{x=%d, ",  position_get_x(ensemble_colores_get_courant(E))+1);
	printf("y=%d}\n",  position_get_y(ensemble_colores_get_courant(E))+1);
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
		
		printf("\nChaine capturée: \n");
		affiche_positions(cc);
		
		ensemble_set_courant(chaines, ensemble_get_suivant(chaines));
	}
	
	cc = ensemble_get_courant_contenu(chaines);
	
	printf("Chaine capturée: \n");
	affiche_positions(cc);
}

int main(){
	int tests = 0;
	
	FILE *f = fopen("extra/plateau_test_capture_chaines.txt", "r+");
	
	Chaine chaine;
	
	Plateau plateau = plateau_chargement(f);
	
	Position position = creer_position(4, 4);
	
	Pion pion = creer_pion(BLANC, position);
	
	int valide;
	
#if DEBUG_AFFICHE == 1
	plateau_afficher(plateau);
#endif

	chaine = plateau_determiner_chaine(plateau, position);

#if DEBUG_AFFICHE == 1	
	printf("\nChaine du pion posé: \n");
	affiche_positions(chaine);
#endif

	Chaines chaines_captures = captureChaines(plateau, pion, &valide);

#if DEBUG_AFFICHE == 1	
	affiche_captures(chaines_captures);
#endif

	if(ensemble_nbr_element(chaines_captures) == 3)
		tests = 1;
	
	if(tests == 1)
		printf("Tests captureChaines(...): OK\n");
	else
		printf("Tests captureChaines(...): Problèmes durant les tests...\n");
	
	return 0;
}
