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
 * @author ELHIMDI Yasmine <yasmine.elhimdi@ecole.ensicaen.fr>
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

Libertes determineLiberte(Plateau plateau, Chaine chaine){ 
	Libertes l;
	Position pos, pos_haut, pos_bas, pos_gauche, pos_droite;
	
	if(ensemble_colores_vide(chaine))
		return NULL;

	l = creer_ensemble_positions();
	
	ensemble_colores_reset(chaine);
	
	while(ensemble_colores_suivant(chaine)){
		pos = ensemble_colores_get_courant(chaine);
		
		pos_haut = haut(pos);
		pos_bas = bas(pos);
		pos_gauche = gauche(pos);
		pos_droite = droite(pos);
		
		if(plateau_position_appartient(plateau, pos_haut) && plateau_get_pos(plateau, pos_haut) == VIDE){
			ensemble_positions_ajouter(l, pos_haut);
		}
		
		if(plateau_position_appartient(plateau, pos_bas) && plateau_get_pos(plateau, pos_bas) == VIDE){
			ensemble_positions_ajouter(l, pos_bas);
		}
		
		if(plateau_position_appartient(plateau, pos_gauche) && plateau_get_pos(plateau, pos_gauche) == VIDE){
			ensemble_positions_ajouter(l, pos_gauche);
		}
		
		if(plateau_position_appartient(plateau, pos_droite) && plateau_get_pos(plateau, pos_droite) == VIDE){
			ensemble_positions_ajouter(l, pos_droite);
		}
		
		ensemble_colores_set_courant(chaine, ensemble_colores_get_suivant(chaine));
	}
	
	pos = ensemble_colores_get_courant(chaine);
	
	pos_haut = haut(pos);
	pos_bas = bas(pos);
	pos_gauche = gauche(pos);
	pos_droite = droite(pos);

	if(plateau_position_appartient(plateau, pos_haut) && plateau_get_pos(plateau, pos_haut) == VIDE){
		ensemble_positions_ajouter(l, pos_haut);
	}
	
	if(plateau_position_appartient(plateau, pos_bas) && plateau_get_pos(plateau, pos_bas) == VIDE){
		ensemble_positions_ajouter(l, pos_bas);
	}
	
	if(plateau_position_appartient(plateau, pos_gauche) && plateau_get_pos(plateau, pos_gauche) == VIDE){
		ensemble_positions_ajouter(l, pos_gauche);
	}
	
	if(plateau_position_appartient(plateau, pos_droite) && plateau_get_pos(plateau, pos_droite) == VIDE){
		ensemble_positions_ajouter(l, pos_droite);
	}

	return l;
}
