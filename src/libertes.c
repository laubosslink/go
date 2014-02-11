#include <stdio.h>
#include <stdlib.h>
#include <matrice.h>
#include <libertes.h>
#include <position.h>
#include <positions.h>
#include <plateau.h>
#include <chaine.h>
#include <ensemble.h>

Libertes determineLiberte(Plateau plateau, Chaine chaine){
	Libertes l;
	Positions* p = chaine.p;
	Position* pos_courante;
	
	if(ensemble_vide(p))
		return;
	
	p->courant = ensemble_tete(p);
	
	while(ensemble_suivant(p)){
		pos_courante = (Position*) p->courant->contenu;
		
		pos_courante->x++;
		if(position_appartient_matrice(plateau, pos_courante->x, pos_courante->y) && plateau_get(plateau, pos_courante->x, pos_courante->y == VIDE)){
			ensemble_ajouter(&l, pos_courante);
		}
		
		pos_courante->x -= 2;
		if(position_appartient_matrice(plateau, pos_courante->x, pos_courante->y) && plateau_get(plateau, pos_courante->x, pos_courante->y == VIDE)){
			ensemble_ajouter(&l, pos_courante);
		}
		pos_courante->x++;
		
		pos_courante->y++;
		if(position_appartient_matrice(plateau, pos_courante->x, pos_courante->y) && plateau_get(plateau, pos_courante->x, pos_courante->y == VIDE)){
			ensemble_ajouter(&l, pos_courante);
		}
		
		pos_courante->y -= 2;
		if(position_appartient_matrice(plateau, pos_courante->x, pos_courante->y) && plateau_get(plateau, pos_courante->x, pos_courante->y == VIDE)){
			ensemble_ajouter(&l, pos_courante);
		}
		pos_courante->y++;
		
		p->courant = ensemble_courant(p)->suivant;
	}

	pos_courante = (Position*) p->courant->contenu;
	
	pos_courante->x++;
	if(position_appartient_matrice(plateau, pos_courante->x, pos_courante->y) && plateau_get(plateau, pos_courante->x, pos_courante->y == VIDE)){
		ensemble_ajouter(&l, pos_courante);
	}
	
	pos_courante->x -= 2;
	if(position_appartient_matrice(plateau, pos_courante->x, pos_courante->y) && plateau_get(plateau, pos_courante->x, pos_courante->y == VIDE)){
		ensemble_ajouter(&l, pos_courante);
	}
	pos_courante->x++;
	
	pos_courante->y++;
	if(position_appartient_matrice(plateau, pos_courante->x, pos_courante->y) && plateau_get(plateau, pos_courante->x, pos_courante->y == VIDE)){
		ensemble_ajouter(&l, pos_courante);
	}
	
	pos_courante->y -= 2;
	if(position_appartient_matrice(plateau, pos_courante->x, pos_courante->y) && plateau_get(plateau, pos_courante->x, pos_courante->y == VIDE)){
		ensemble_ajouter(&l, pos_courante);
	}
	pos_courante->y++;
	

	return l;
}
