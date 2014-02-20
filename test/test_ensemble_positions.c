#include <stdio.h>
#include <stdlib.h>
#include <position.h>
#include <positions.h>
#include <ensemble_positions.h>

void afficherEnsemblePositions(Ensemble_Positions E){
	if(ensemble_positions_vide(E)){
		printf("Rien à afficher, la liste est vide\n");
		return;
	}
	
	printf("{");
	
	ensemble_reset_courant(E);
	
	while(ensemble_positions_suivant(E)){
		printf("{%d;%d} \t",  position_get_x((Position)ensemble_get_courant_contenu(E)), position_get_y((Position)ensemble_get_courant_contenu(E)) );
		ensemble_set_courant(E, ensemble_get_suivant(E));
	}
	
	printf("{%d;%d} \t",  position_get_x((Position)ensemble_get_courant_contenu(E)), position_get_y((Position)ensemble_get_courant_contenu(E)) );
	printf("}\n\n");
}


int main (){
	Ensemble_Positions Ep;
	Position element, p, pp, app;
	int tests = 0;
	
	Ep = creer_ensemble_positions();
	
	element = creer_position(5,10);
	p = creer_position(4,9);
	pp = creer_position(1,2);
	app = creer_position(8,1);
	
	ensemble_positions_ajouter(Ep,creer_position(5,10));
	ensemble_positions_ajouter(Ep,creer_position(4,9));
	ensemble_positions_ajouter(Ep,creer_position(8,1));

	if(ensemble_positions_appartient(Ep, app))
		tests = 1;
		
	tests = (ensemble_nbr_element(Ep) == 3 && tests == 1) ? 1 : 0;

#if DEBUG_AFFICHE == 1		
	afficherEnsemblePositions(Ep);
#endif
	
	if(tests == 1)
		printf("Tests ensemble_positions.c: OK\n");
	else
		printf("Tests ensemble_positions.c: Problèmes durant les tests...\n");
	
	detruire_ensemble(Ep);
		
	return 0;
	
}
