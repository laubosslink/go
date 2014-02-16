#include <ensemble.h>
#include <position.h>
#include <ensemble_positions.h>
#include <ensemble_colores.h>

int chaines_appartient_chaine(Chaines chaines, Chaine chaine){
	Chaine *cc; /* chaine courante */
	
	if(ensemble_vide(&chaines))
		return 0;
	
	if(ensemble_colores_vide(&chaine))
		return 0;
	
	ensemble_reset_courant(chaine.p);
	ensemble_reset_courant(&chaines);
	
	while(ensemble_suivant(&chaines)){
		cc = ensemble_get_courant_contenu(chaines);
		
		ensemble_reset_courant(chaine.p);
		
		while(ensemble_suivant(chaine.p)){
			if(ensemble_positions_appartient(&cc, position_get_courant(chaine.p))
				return 1;
			
			ensemble_set_courant(chaine.p, ensemble_get_suivant(chaine.p));
		}		
	
		if(ensemble_positions_appartient(&cc, position_get_courant(chaine.p))
			return 1;
		
		ensemble_set_courant(&chaines, ensemble_get_suivant(&chaines));
	}
	
	cc = ensemble_get_courant_contenu(chaines);
	
	ensemble_reset_courant(chaine.p);
	
	while(ensemble_suivant(chaine.p)){
		if(ensemble_positions_appartient(&cc, position_get_courant(chaine.p))
			return 1;
		
		ensemble_set_courant(chaine.p, ensemble_get_suivant(chaine.p));
	}		

	if(ensemble_positions_appartient(&cc, position_get_courant(chaine.p))
		return 1;
	
	return 0;
}
