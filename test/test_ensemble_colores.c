#include <stdio.h>
#include <stdlib.h>
#include <position.h>
#include <positions.h>
#include <ensemble_colores.h>


void afficherEnsembleColores(Ensemble_Colores *E){
	if(ensemble_colores_vide(E)){
		printf("Rien à afficher, la liste est vide\n");
		return;
	}
	
	printf("{");
	
	E->p.courant=E->p.tete;
	
	while(ensemble_colores_suivant(E)){
		//ensemble_colores_courant(E)
		printf("%d \t",  ensemble_colores_contenu(E->p.courant)->x);
		printf("%d \t",  ensemble_colores_contenu(E->p.courant)->y);
		//printf("%d\t", E->p.courant->contenu->y);
		E->p.courant=E->p.courant->suivant;
	}
	
	printf("%d \t",  ensemble_colores_contenu(E->p.courant)->x);
	printf("%d \t",  ensemble_colores_contenu(E->p.courant)->y);
	printf("}\n\n");
}


int main () {
	Ensemble_Colores* Ec;
	Position* pos;
	Position* p;
	Position* m;
	
	pos=(Position*)malloc(sizeof(Position));  //@TODO : faire une fonction d'allocation dynamique 
	p=(Position*)malloc(sizeof(Position));
	m=(Position*)malloc(sizeof(Position));
	
	Ec->c=NOIR; 
	
	pos->x=5;
	pos->y=3;
	
	p->x=1;
	p->y=0;
	
	m->x=7;
	m->y=10;
	
	Ec = creer_ensemble_colores();
	
	ensemble_colores_ajouter(Ec,pos);
	ensemble_colores_ajouter(Ec,p);
	ensemble_colores_ajouter(Ec,m);

	afficherEnsembleColores(Ec);
	
	//printf("%d\n", Ec->c);
	

	return 0;
}
