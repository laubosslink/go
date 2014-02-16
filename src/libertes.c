#include <stdio.h>
#include <stdlib.h>

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
 * @file libertes.c
 * 
 * @brief code source qui permet de gérer les libertés
 */
 
#include <matrice.h>
#include <ensemble.h>
#include <ensemble_colores.h>

#include <libertes.h>
#include <position.h>
#include <positions.h>

#include <plateau.h>
#include <chaine.h>

Libertes determineLiberte(Plateau plateau, Chaine chaine){ /** @todo réfléchir sur le struct dans le .c, et conséquence sur chaine */
	Libertes l;
	Positions* p = chaine.p; /* l'ensemble des positions de la chaine */
	Position pc; /* la position courante */
	//Position pd; /* la position de déplacement */ 
	Position* pa; /* la position a ajouter */
	
	if(ensemble_vide(p))
		return;
	
	ensemble_init(&l);
	
	ensemble_reset_courant(p);
	
	while(ensemble_suivant(p)){
		pc.x = position_get_courant(p)->x;
		pc.y = position_get_courant(p)->y;
		
		pc.x++; /** @todo utiliser haut,bas,gauche,droite */
		if(plateau_position_appartient(plateau, pc) && plateau_get(plateau, pc.x, pc.y) == VIDE){
			ensemble_positions_ajouter(&l, creer_position(pc.x, pc.y));
		}
		
		pc.x -= 2;
		if(plateau_position_appartient(plateau, pc) && plateau_get(plateau, pc.x, pc.y) == VIDE){
			ensemble_positions_ajouter(&l, creer_position(pc.x, pc.y));
		}
		pc.x++;
		
		pc.y++;
		if(plateau_position_appartient(plateau, pc) && plateau_get(plateau, pc.x, pc.y) == VIDE){
			ensemble_positions_ajouter(&l, creer_position(pc.x, pc.y));
		}
		
		pc.y -= 2;
		if(plateau_position_appartient(plateau, pc) && plateau_get(plateau, pc.x, pc.y) == VIDE){
			ensemble_positions_ajouter(&l, creer_position(pc.x, pc.y));
		}
		pc.y++;
		
		ensemble_set_courant(p, ensemble_get_suivant(p));
	}
	
	pc.x = position_get_courant(p)->x;
	pc.y = position_get_courant(p)->y;

	pc.x++;
	if(plateau_position_appartient(plateau, pc) && plateau_get(plateau, pc.x, pc.y) == VIDE){
		pa = creer_position(pc.x, pc.y);
		ensemble_positions_ajouter(&l, pa);
	}
	
	pc.x -= 2;
	if(plateau_position_appartient(plateau, pc) && plateau_get(plateau, pc.x, pc.y) == VIDE){
		ensemble_positions_ajouter(&l, creer_position(pc.x, pc.y));
	}
	pc.x++;
	
	pc.y++;
	if(plateau_position_appartient(plateau, pc) && plateau_get(plateau, pc.x, pc.y) == VIDE){
		ensemble_positions_ajouter(&l, creer_position(pc.x, pc.y));
	}
	
	pc.y -= 2;
	if(plateau_position_appartient(plateau, pc) && plateau_get(plateau, pc.x, pc.y) == VIDE){
		ensemble_positions_ajouter(&l, creer_position(pc.x, pc.y));
	}
	pc.y++;

	return l;
}
