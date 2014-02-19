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
	
	Position pos = creer_position(5, 5);
	
	Position pos_check = creer_position(5, 5);
	
	ensemble_colores_set_couleur(chaine1, 1);
	ensemble_colores_ajouter(chaine1, position_copy(pos));
	
	haut(pos); gauche(pos);
	ensemble_colores_ajouter(chaine1, position_copy(pos));
	
	haut(pos); gauche(pos);
	ensemble_colores_set_couleur(chaine2, 1);
	ensemble_colores_ajouter(chaine2, position_copy(pos));
	
	haut(pos); gauche(pos);
	ensemble_colores_ajouter(chaine2, position_copy(pos));
	
	ensemble_colores_set_couleur(chaine3, 1);
	ensemble_colores_ajouter(chaine3, pos_check);

	haut(pos); gauche(pos);
	ensemble_colores_ajouter(chaine4, position_copy(pos));
	
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
