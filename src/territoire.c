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
 * @author PARMENTIER Laurent <parmentier@ecole.ensicaen.fr, laubosslink@society-lbl.com>
 * @author EL HIMDI Yasmine <yasmine.elhimdi@ecole.enciscaen.fr>
 * @version 1.0 
 * @date 03-12-2013
 *
 */
 
/** 
 * @file territoire.c
 * 
 * @brief Le code source permettant de gérer un territoire
 */

#include <ensemble_colores.h>
#include <territoire.h>
#include <plateau.h>
#include <position.h>

void determineTerritoireRec(Plateau plateau, Position pos, Territoire* t){
	Position p;
	
	if(!plateau_position_appartient(plateau, pos))
		return;
		
	if(est_un_pion_plateau(plateau, pos))
		return;
	
	/* ajout de la position actuelle */
	ensemble_colores_ajouter(t, pos);
	
	p = pos;
	
	p = haut(pos);
	determineTerritoireRec(plateau, p, t);
	
	p = bas(pos);
	determineTerritoireRec(plateau, p, t);
	
	p = gauche(pos);
	determineTerritoireRec(plateau, p, t);
	
	p = droite(pos);
	determineTerritoireRec(plateau, p, t);
	
}

Territoire determineTerritoire(Plateau plateau, Position pos){
	Territoire t;
	Position p;
	
	/** @bug risque de bug sans utiliser init_ensemble ou creer_ensemble sur territoire ! */
	
	/* si la position n'appartient pas au plateau on s'arrete */
	if(!plateau_position_appartient(plateau, pos))
		return;
	
	/* si ce n'est pas une case vide, on est deja pas sur un territoire */
	if(plateau_get_pos(pos) != VIDE)
		return;
	
	t.c = plateau_get_pos(pos);
	
	p = pos;
	
	p = haut(pos);
	determineTerritoireRec(plateau, p, &t);
	
	p = bas(pos);
	determineTerritoireRec(plateau, p, &t);
	
	p = gauche(pos);
	determineTerritoireRec(plateau, p, &t);
	
	p = droite(pos);
	determineTerritoireRec(plateau, p, &t);
	
	return t;
}
