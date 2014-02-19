#include <chaine.h>
#include <chaines.h>
#include <position.h>
#include <ensemble.h>

int main(){
	int tests = 0;
	
	Chaines chaines = creer_ensemble_positions();
	
	Chaine chaine1 = creer_ensemble_colores();
	Chaine chaine2 = creer_ensemble_colores();
	Chaine chaine3 = creer_ensemble_colores();
	Chaine chaine4 = creer_ensemble_colores();
	
	Position pos;
	
	pos.x = 5;
	pos.y = 5;
	
	ensemble_colores_set_couleur(chaine1, 1);
	ensemble_colores_ajouter(chaine1, creer_position(pos.x, pos.y));
	ensemble_colores_ajouter(chaine1, creer_position(pos.x++, pos.y++));
	
	
	ensemble_colores_set_couleur(chaine2, 1);
	ensemble_colores_ajouter(chaine2, creer_position(pos.x, pos.y));
	ensemble_colores_ajouter(chaine2, creer_position(pos.x+1, pos.y+1));
	
	ensemble_colores_set_couleur(chaine3, 1);
	ensemble_colores_ajouter(chaine3, creer_position(pos.x--, pos.y--));

	ensemble_colores_ajouter(chaine4, creer_position(pos.x+20, pos.y));
	
	ensemble_ajouter(chaines, chaine1);
	ensemble_ajouter(chaines, chaine2);
	
	if(chaines_appartient_chaine(chaines, chaine3))
		tests = 1;
	
	if(!chaines_appartient_chaine(chaines, chaine4) && tests == 1)
		tests = 1;
	
	if(tests == 1)
		printf("Tests chaines_appartient_chaine(...): OK\n");
	else
		printf("Tests chaines_appartient_chaine(...): Problèmes durant les tests...\n");
		
	return 0;
}
