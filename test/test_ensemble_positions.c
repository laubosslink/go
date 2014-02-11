#include <stdio.h>
#include <stdlib.h>
#include <position.h>
#include <positions.h>
#include <ensemble_positions.h>


void afficherEnsemblePositions(Ensemble_Positions *E){
	if(ensemble_positions_vide(E)){
		printf("Rien à afficher, la liste est vide\n");
		return;
	}
	
	printf("{");
	
	E->courant=E->tete;
	
	while(ensemble_positions_suivant(E)){
		printf("{%d;%d} \t",  ((Position*)E->courant->contenu)->x, ((Position*)E->courant->contenu)->y );
		E->courant=E->courant->suivant;
	}
	
	printf("{%d;%d} \t",  ((Position*)E->courant->contenu)->x, ((Position*)E->courant->contenu)->y );
	printf("}\n\n");
}


int main (){
	Ensemble_Positions* Ep;
	Position* element;
	Position* p;
	Position* pp;
	Position* app;
	int test;
	
	Ep = creer_ensemble_positions();
	
	element = (Position*)malloc(sizeof(Position));
	p = (Position*)malloc(sizeof(Position));
	pp = (Position*)malloc(sizeof(Position));
	app = (Position*)malloc(sizeof(Position));
	
	element->x = 5;
	element->y = 10;
	
	p->x = 4;
	p->y = 9;
	
	pp->x = 1;
	pp->y = 2;
	
	app->x=8;
	app->y=1;
	
	ensemble_positions_ajouter(Ep,element);
	ensemble_positions_ajouter(Ep,p);
	ensemble_positions_ajouter(Ep,pp);
	
	afficherEnsemblePositions(Ep);
	
	test = ensemble_positions_appartient(Ep,app);
	if(test == 1)
		printf("L'element appartient à l'ensemble.\n");
	if(test == 0)
		printf("L'element n'appartient pas à l'ensemble. \n");
		
		
	return 0;
	
}
	
	
