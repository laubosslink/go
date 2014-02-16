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
	Position *pp;
	
	if(!plateau_position_appartient(plateau, pos))
		return;
	
	/* si la couleur du territoire n'est pas definis et qu'on a trouve un pion, on definis la couleur */
	if(t->c == INDEFINI && est_un_pion_plateau(plateau, pos)){
		t->c = plateau_get_pos(plateau, pos);
	} else if(est_un_pion(t->c) && t->c != plateau_get_pos(plateau, pos) && plateau_get_pos(plateau, pos) != VIDE) /* si en revanche la couleur du territoire est deja definis et on trouve une couleur oppose, le territoire n'appartient a personne */
	{
		t->c = VIDE;
	}
	
	if(plateau_get_pos(plateau, pos) != VIDE)
		return;
	
	if(ensemble_colores_appartient(t, &pos))
		return;
	
	pp = position_creer(pos.x, pos.y);
	
	/* ajout de la position actuelle */
	ensemble_colores_ajouter(t, pp);
	
	determineTerritoireRec(plateau, haut(pos), t);
	determineTerritoireRec(plateau, bas(pos), t);
	determineTerritoireRec(plateau, gauche(pos), t);
	determineTerritoireRec(plateau, droite(pos), t);
	
}

Territoire determineTerritoire(Plateau plateau, Position pos){
	Territoire t;
	Position *pp;
	
	/* si la position n'appartient pas au plateau on s'arrete */
	if(!plateau_position_appartient(plateau, pos))
		return;
	
	/* si ce n'est pas une case vide, on est deja pas sur un territoire */
	if(plateau_get_pos(plateau, pos) != VIDE)
		return;
	
	t.p = creer_ensemble();
	t.c = INDEFINI;
	
	pp = position_creer(pos.x, pos.y);
	ensemble_ajouter(t.p, pp);
	
	determineTerritoireRec(plateau, haut(pos), &t);
	determineTerritoireRec(plateau, bas(pos), &t);
	determineTerritoireRec(plateau, gauche(pos), &t);
	determineTerritoireRec(plateau, droite(pos), &t);
	
	return t;
}
