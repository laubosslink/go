#include <stdio.h>
#include <stdlib.h>

#include <position.h>

#include <ensemble_colores.h>

int main () {
	Ensemble_Colores Ec = creer_ensemble_colores();
	
	ensemble_colores_set_couleur(Ec, NOIR);
	
	ensemble_colores_ajouter(Ec, creer_position(5, 3));
	ensemble_colores_ajouter(Ec, creer_position(1, 0));
	ensemble_colores_ajouter(Ec, creer_position(7, 10));

	ensemble_colores_affiche(Ec);

	return 0;
}
