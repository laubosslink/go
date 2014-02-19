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
	Position pc; /* la position courante */
	//Position pd; /* la position de déplacement */ 
	Position* pa; /* la position a ajouter */
	
	if(ensemble_colores_vide(chaine))
		return NULL;

	l = creer_ensemble_positions();
	
	ensemble_colores_reset(chaine);
	
	while(ensemble_colores_suivant(chaine)){
		pc.x = ((Position *) ensemble_colores_get_courant(chaine))->x;
		pc.y = ((Position *) ensemble_colores_get_courant(chaine))->y;
		
		pc.x++; /** @todo utiliser haut,bas,gauche,droite */
		if(plateau_position_appartient(plateau, pc) && plateau_get(plateau, pc.x, pc.y) == VIDE){
			ensemble_positions_ajouter(l, creer_position(pc.x, pc.y));
		}
		
		pc.x -= 2;
		if(plateau_position_appartient(plateau, pc) && plateau_get(plateau, pc.x, pc.y) == VIDE){
			ensemble_positions_ajouter(l, creer_position(pc.x, pc.y));
		}
		pc.x++;
		
		pc.y++;
		if(plateau_position_appartient(plateau, pc) && plateau_get(plateau, pc.x, pc.y) == VIDE){
			ensemble_positions_ajouter(l, creer_position(pc.x, pc.y));
		}
		
		pc.y -= 2;
		if(plateau_position_appartient(plateau, pc) && plateau_get(plateau, pc.x, pc.y) == VIDE){
			ensemble_positions_ajouter(l, creer_position(pc.x, pc.y));
		}
		pc.y++;
		
		ensemble_colores_set_courant(chaine, ensemble_colores_get_suivant(chaine));
	}
	
	pc.x = ((Position *) ensemble_colores_get_courant(chaine))->x;
	pc.y = ((Position *) ensemble_colores_get_courant(chaine))->y;

	pc.x++;
	if(plateau_position_appartient(plateau, pc) && plateau_get(plateau, pc.x, pc.y) == VIDE){
		pa = creer_position(pc.x, pc.y);
		ensemble_positions_ajouter(l, pa);
	}
	
	pc.x -= 2;
	if(plateau_position_appartient(plateau, pc) && plateau_get(plateau, pc.x, pc.y) == VIDE){
		ensemble_positions_ajouter(l, creer_position(pc.x, pc.y));
	}
	pc.x++;
	
	pc.y++;
	if(plateau_position_appartient(plateau, pc) && plateau_get(plateau, pc.x, pc.y) == VIDE){
		ensemble_positions_ajouter(l, creer_position(pc.x, pc.y));
	}
	
	pc.y -= 2;
	if(plateau_position_appartient(plateau, pc) && plateau_get(plateau, pc.x, pc.y) == VIDE){
		ensemble_positions_ajouter(l, creer_position(pc.x, pc.y));
	}
	pc.y++;

	return l;
}
