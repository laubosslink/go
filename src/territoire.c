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

Territoire creer_territoire(){
	return (Territoire) creer_ensemble_colores();
}

void determineTerritoireRec(Plateau plateau, Position pos, Territoire t){
	
	/* si la position n'est pas dans le plateau on s'arrête */
	if(!plateau_position_appartient(plateau, pos))
		return;
	
	/* si la couleur du territoire n'est pas definis et qu'on a trouve un pion, on definis la couleur */
	if(ensemble_colores_get_couleur(t) == INDEFINI && est_un_pion_plateau(plateau, pos)){
		ensemble_colores_set_couleur(t, plateau_get_pos(plateau, pos));
	} else if(est_un_pion(ensemble_colores_get_couleur(t)) && ensemble_colores_get_couleur(t) != plateau_get_pos(plateau, pos) && plateau_get_pos(plateau, pos) != VIDE) /* si en revanche la couleur du territoire est deja definis et on trouve une couleur oppose, le territoire n'appartient a personne */
	{
		ensemble_colores_set_couleur(t, VIDE);
	}
	
	if(plateau_get_pos(plateau, pos) != VIDE)
		return;
	
	/* si la position appartient déjà à l'ensemble on s'arrête la */
	if(ensemble_colores_appartient(t, pos))
		return;
	
	/* ajout de la position actuelle */
	ensemble_colores_ajouter(t, position_copy(pos));
	
	determineTerritoireRec(plateau, haut(pos), t);
	bas(pos);
	
	determineTerritoireRec(plateau, bas(pos), t);
	haut(pos);
	
	determineTerritoireRec(plateau, gauche(pos), t);
	droite(pos);
	
	determineTerritoireRec(plateau, droite(pos), t);
	gauche(pos);
}

Territoire determineTerritoire(Plateau plateau, Position pos){
	Territoire t;
	
	/* si la position n'appartient pas au plateau on s'arrete */
	if(!plateau_position_appartient(plateau, pos))
		return NULL;
	
	/* si ce n'est pas une case vide, on est deja pas sur un territoire */
	if(plateau_get_pos(plateau, pos) != VIDE)
		return NULL;
	
	t = creer_territoire();
	ensemble_colores_set_couleur(t, INDEFINI);

	ensemble_colores_ajouter(t, position_copy(pos));
	
	determineTerritoireRec(plateau, haut(pos), t);
	bas(pos);
	
	determineTerritoireRec(plateau, bas(pos), t);
	haut(pos);
	
	determineTerritoireRec(plateau, gauche(pos), t);
	droite(pos);
	
	determineTerritoireRec(plateau, droite(pos), t);
	gauche(pos);
	
	return t;
}
