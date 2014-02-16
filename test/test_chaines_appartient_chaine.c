#include <chaine.h>
#include <chaines.h>
#include <position.h>
#include <ensemble.h>

int main(){
	Chaines chaines;
	
	Chaine chaine1;
	Chaine chaine2;
	Chaine chaine3;
	
	Position pos;
	
	pos.x = 5;
	pos.y = 5;
	
	ensemble_colores_init(&chaine1);
	ensemble_colores_init(&chaine2);
	ensemble_colores_init(&chaine3);
	
	chaine1.c = 1;
	ensemble_colores_ajouter(&chaine1, creer_position(pos.x, pos.y));
	ensemble_colores_ajouter(&chaine1, creer_position(pos.x++, pos.y++));
	
	chaine2.c = 1;
	ensemble_colores_ajouter(&chaine2, creer_position(pos.x, pos.y));
	ensemble_colores_ajouter(&chaine2, creer_position(pos.x+1, pos.y+1));
	
	chaine3.c = 1;
	ensemble_colores_ajouter(&chaine3, creer_position(pos.x--, pos.y--));
	
	ensemble_init(&chaines);
	
	ensemble_ajouter(&chaines, &chaine1);
	ensemble_ajouter(&chaines, &chaine2);
	
	if(chaines_appartient_chaine(chaines, chaine3))
		printf("chaine3 est dans chaines\n");
	else
		printf("chaine3 n'est PAS dans chaines\n");
		
	return 0;
}
