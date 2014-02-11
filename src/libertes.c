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
	Positions* p = chaine.p; /* l'ensemble des positions de la chaine */
	Position pc; /* la position courante */
	Position* pa; /* la position a ajouter */
	
	if(ensemble_vide(p))
		return;
	
	ensemble_init(&l);
	
	p->courant = ensemble_tete(p);
	
	while(ensemble_suivant(p)){
		pc.x = ((Position *) p->courant->contenu)->x;
		pc.y = ((Position *) p->courant->contenu)->y;
		
		pc.x++; /* @todo utiliser haut,bas,gauche,droite */
		if(position_appartient_matrice(plateau, pc.x, pc.y) && plateau_get(plateau, pc.x, pc.y) == VIDE){
			pa = position_creer(pc.x, pc.y);
			ensemble_ajouter(&l, pa);
		}
		
		pc.x -= 2;
		if(position_appartient_matrice(plateau, pc.x, pc.y) && plateau_get(plateau, pc.x, pc.y) == VIDE){
			pa = position_creer(pc.x, pc.y);
			ensemble_ajouter(&l, pa);
		}
		pc.x++;
		
		pc.y++;
		if(position_appartient_matrice(plateau, pc.x, pc.y) && plateau_get(plateau, pc.x, pc.y) == VIDE){
			pa = position_creer(pc.x, pc.y);
			ensemble_ajouter(&l, pa);
		}
		
		pc.y -= 2;
		if(position_appartient_matrice(plateau, pc.x, pc.y) && plateau_get(plateau, pc.x, pc.y) == VIDE){
			pa = position_creer(pc.x, pc.y);
			ensemble_ajouter(&l, pa);
		}
		pc.y++;
		
		p->courant = ensemble_courant(p)->suivant;
	}
	
	pc.x = ((Position *) p->courant->contenu)->x;
	pc.y = ((Position *) p->courant->contenu)->y;

	pc.x++;
	if(position_appartient_matrice(plateau, pc.x, pc.y) && plateau_get(plateau, pc.x, pc.y) == VIDE){
		pa = position_creer(pc.x, pc.y);
		ensemble_ajouter(&l, pa);
	}
	
	pc.x -= 2;
	if(position_appartient_matrice(plateau, pc.x, pc.y) && plateau_get(plateau, pc.x, pc.y) == VIDE){
		pa = position_creer(pc.x, pc.y);
		ensemble_ajouter(&l, pa);
	}
	pc.x++;
	
	pc.y++;
	if(position_appartient_matrice(plateau, pc.x, pc.y) && plateau_get(plateau, pc.x, pc.y) == VIDE){
		pa = position_creer(pc.x, pc.y);
		ensemble_ajouter(&l, pa);
	}
	
	pc.y -= 2;
	if(position_appartient_matrice(plateau, pc.x, pc.y) && plateau_get(plateau, pc.x, pc.y) == VIDE){
		pa = position_creer(pc.x, pc.y);
		ensemble_ajouter(&l, pa);
	}
	pc.y++;

	return l;
}
