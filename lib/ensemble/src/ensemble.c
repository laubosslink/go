/**
 * ENSICAEN
 * 6 Boulevard Marechal Juin
 * F-14050 Caen Cedex
 * 
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written premission of the authors
 */
 
/**
 * @author ELHIMDI Yasmine <elhimdi@ecole.ensicaen.fr>
 * @author PARMENTIER Laurent <parmentier@ecole.ensicaen.fr, laubosslink@society-lbl.com>
 * @version 1.1 
 * @date 03-02-2013
 * 
 * @todo revoir la doc / remplacer Ensemble_Positions par Ensemble_Position
 */
 
/** 
 * @file ensemble.c
 * 
 * @brief code source qui permet de gérer les ensembles
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <ensemble.h>

void ensemble_init(Ensemble *E){
	E->tete = NULL;
	E->courant = NULL;
}

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

/** @todo get_ */
Cell* ensemble_tete(Ensemble* E){
	return E->tete;
}

/** @todo get_ */
Cell* ensemble_courant(Ensemble* E){
	return E->courant;
}

void ensemble_reset_courant(Ensemble* E){
	E->courant = E->tete;
}

int ensemble_suivant(Ensemble* E){
	if(ensemble_courant(E) == NULL) 	
		return 0;
	
	return(ensemble_courant(E))->suivant != NULL;
}

void* ensemble_get_courant_contenu(Ensemble *E){
	return E->courant->contenu;
}

Cell* ensemble_get_suivant(Ensemble* E){
	if(E->courant == NULL)
		return NULL;
		
	return E->courant->suivant;
}

void ensemble_set_courant(Ensemble* E, Cell *c){
	E->courant = c;
}

int ensemble_appartient(Ensemble* E, void* element){
	if(ensemble_vide(E))
		return 0;
		
	E->courant = E->tete;
	
	while(ensemble_suivant(E) && E->courant->contenu != element){
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
