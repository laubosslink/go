#include <stdio.h>
#include <stdlib.h>
#include <position.h>
#include <ensemble.h>

Ensemble* creer_ensemble(){
	Ensemble* E;
	
	E = (Ensemble*) malloc(sizeof(Ensemble));
	E->tete = NULL;
	E->courant = NULL;
	
	return E;
}

int ensemble_vide(Ensemble* E){
	return (E == NULL || E->tete == NULL);
}

Cell* ensemble_tete(Ensemble* E){
	return E->tete;
}

Cell* ensemble_courant(Ensemble* E){
	return E->courant;
}

int ensemble_suivant(Ensemble* E){
	return (ensemble_courant(E))->suivant != NULL;
}


int ensemble_appartient(Ensemble* E, void* element){
	if(ensemble_vide(E))
		return 0;
		
	E->courant = E->tete;
	
	while(ensemble_suivant(E) && E->courant->contenu != element ){
		E->courant = E->courant->suivant;
	}
	
	if(!ensemble_suivant(E) && E->courant->contenu != element)
		return 0;
	
	return 1;
}

Ensemble* ensemble_enlever(Ensemble* E, void* element){
	Cell* cellule;
	
	if(!ensemble_appartient(E, element))
		return E;
	
	cellule = (Cell*) malloc(sizeof(Cell));
	E->courant=E->tete;
	
	while(ensemble_suivant(E) && E->courant->suivant->contenu != element){
		E->courant = E->courant->suivant;
	}
	
	if(!ensemble_suivant(E) && E->courant->contenu != element)
		return E;
	
	cellule = E->courant->suivant;
	E->courant->suivant = cellule->suivant;
	
	free(cellule);
	
	return E;
	
} 
	
void ensemble_ajouter(Ensemble* E, void* element){
	Cell* cellule;
	
	/* Si l'élément est NULL ou il appartient déjà à l'ensemble on ne fait rien */
	if(element == NULL || ensemble_appartient(E, element))
		return;
	
	cellule = (Cell*) malloc(sizeof(Cell));

	cellule->contenu = element;
	cellule->suivant = NULL;
	
	if(ensemble_vide(E)){
		E->tete = cellule;
	} else {
		E->courant = E->tete;
		
		while(ensemble_suivant(E) ) {	
			E->courant = E->courant->suivant;
		}
		
		E->courant->suivant = cellule;
		cellule->suivant = NULL;
	}
}

Ensemble* ensemble_concatene(Ensemble* e1, Ensemble* e2){
	Ensemble* e = creer_ensemble();
			
	if(!ensemble_vide(e1)){
		/* ajout des éléments de l'ensemble e1 */
		e1->courant = ensemble_tete(e1);
		
		while(ensemble_suivant(e1)){
			ensemble_ajouter(e, ensemble_courant(e1)->contenu);
			e1->courant = e1->courant->suivant;
		}

		ensemble_ajouter(e, ensemble_courant(e1)->contenu);
	}
	
	if(!ensemble_vide(e2)){
		/* ajout des éléments de l'ensemble e2 */
		e2->courant = ensemble_tete(e2);
		
		while(ensemble_suivant(e2)){
			ensemble_ajouter(e, ensemble_courant(e2)->contenu);
			e2->courant = e2->courant->suivant;
		}
		
		ensemble_ajouter(e, ensemble_courant(e2)->contenu);
	}

	/* retourne les deux ensembles */
	return e;
}
