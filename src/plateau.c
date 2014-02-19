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
 * @file plateau.c
 * 
 * @brief Le code source permettant de gérer le plateau
 */
 
#include <matrice.h>
#include <ensemble.h>
#include <ensemble_colores.h>
#include <ensemble_positions.h>
#include <chaine.h>
#include <plateau.h>
#include <libertes.h>
#include <position.h>
#include <couleur.h>
#include <stdio.h>
#include <stdlib.h>

int est_un_pion(Couleur c){
	return (c == BLANC || c == NOIR);
}

int est_un_pion_plateau(Plateau plateau, Position pos){
	/* on vérifie premièrement que la position ne sort pas des bords */
	if(!plateau_position_appartient(plateau, pos))
		return 0;
	
	return est_un_pion(plateau_get_pos(plateau, pos));
}

Plateau creer_plateau(int taille){
	return (Plateau) creer_matrice(taille, taille);
}

Plateau plateau_chargement(FILE* fichier){
	return (Plateau) matrice_chargement(fichier);
}

Couleur plateau_get(Plateau p, int x, int y){
	return (Couleur) matrice_get_donnees(p, x, y);
}

Couleur plateau_get_pos(Plateau p, Position pos){
	return plateau_get(p, position_get_x(pos), position_get_y(pos));
}

int plateau_get_taille(Plateau plateau){
	return matrice_get_nombre_colonne(plateau);
}

void plateau_set(Plateau p, int i, int j, Couleur c){
	matrice_set_donnees(p, i, j, c);
}

void plateau_determiner_chaine_rec(Plateau plateau, Position pos, Chaine chaine){
	/* Si la position reçu sort du plateau, ou qu'elle ne correspond pas à la couleur rechercher, on s'arrête */
	if(!plateau_position_appartient(plateau, pos) || plateau_get_pos(plateau, pos) != ensemble_colores_get_couleur(chaine))
		return;
	
	if(ensemble_colores_appartient(chaine, pos))
		return;
	
	ensemble_colores_ajouter(chaine, position_copy(pos));
	
	plateau_determiner_chaine_rec(plateau, haut(pos), chaine);
	bas(pos);
	
	plateau_determiner_chaine_rec(plateau, bas(pos), chaine);
	haut(pos);
	
	plateau_determiner_chaine_rec(plateau, gauche(pos), chaine);
	droite(pos);
	
	plateau_determiner_chaine_rec(plateau, droite(pos), chaine);
	gauche(pos);
}

Chaine plateau_determiner_chaine(Plateau plateau, Position pos){
	Chaine chaine;
	
	if(!plateau_position_appartient(plateau, pos) || !est_un_pion_plateau(plateau, pos))
		return NULL;
	
	chaine = creer_ensemble_colores();
	
	ensemble_colores_set_couleur(chaine, plateau_get_pos(plateau, pos));
	
	/* ajoute de la position actuel dans la chaine */
	ensemble_colores_ajouter(chaine, position_copy(pos));

	/* lancement récursif à droite, gauche, haut, bas pour rechercher des pions de même couleur */
	plateau_determiner_chaine_rec(plateau, droite(pos), chaine);
	gauche(pos);
	
	plateau_determiner_chaine_rec(plateau, gauche(pos), chaine);
	droite(pos);
	
	plateau_determiner_chaine_rec(plateau, haut(pos), chaine);
	bas(pos);
	
	plateau_determiner_chaine_rec(plateau, bas(pos), chaine);
	haut(pos);
	
	return chaine;
}

void plateau_realiser_capture(Plateau plateau, Chaine chaine){
	if(ensemble_colores_vide(chaine))
		return;
	
	ensemble_colores_reset(chaine); 
	
	while(ensemble_colores_suivant(chaine)){
		plateau_set(plateau, position_get_x((Position) ensemble_colores_get_courant(chaine)), position_get_y((Position) ensemble_colores_get_courant(chaine)), VIDE);
		ensemble_colores_set_courant(chaine, ensemble_colores_get_suivant(chaine));
	}
	
	plateau_set(plateau, position_get_x((Position)ensemble_colores_get_courant(chaine)), position_get_y((Position)ensemble_colores_get_courant(chaine)), VIDE);
	
	/* @todo free de chaine */
}

/*** ARRET DEPUIS DERNIER COMMIT ***/

int plateau_est_identique(Plateau plateau, Plateau ancienPlateau){
	int i, j;
	
	if(plateau_get_taille(plateau) != plateau_get_taille(ancienPlateau))
		return 0;
	
	for(i=0; i<plateau_get_taille(plateau); i++){
		for(j=0; j<plateau_get_taille(plateau); j++){
			if(plateau_get(plateau, i, j) != plateau_get(ancienPlateau, i, j))
				return 0;
		}
	}
	
	return 1;
}

int plateau_position_appartient(Plateau plateau, Position position){
	return matrice_position_appartient(plateau, position_get_x(position), position_get_y(position));
}

int plateau_copie(Plateau from, Plateau to){
	int i, j;
	
	if(plateau_get_taille(from) != plateau_get_taille(to)){
		fprintf(stderr, "taille différence pour la copie d'un tableau 'from' vers 'to'");
		return 0;
	}
	
	for(i=0; i<plateau_get_taille(from); i++){
		for(j=0; j<plateau_get_taille(from); j++){
			plateau_set(to, i, j, plateau_get(from, i, j));
		}
	}
	
	return plateau_est_identique(from, to);
}

int plateau_sauvegarde(Plateau plateau, FILE* fichier){
	return matrice_sauvegarde(plateau, fichier);
}

void plateau_afficher(Plateau p){
	char c;
	int i, j;
	
	/* En tete pour connaitre les colonnes */
	printf("   ");
	for(i=0; i<plateau_get_taille(p); i++){
		printf("- ", i);
	}
	printf("\n");
	
	printf("  |");
	for(i=0; i<plateau_get_taille(p); i++){
		if(i<plateau_get_taille(p)-1)
			printf("%d ", i+1);
		else
			printf("%d", i+1);
	}
	printf("|\n");	
	
	printf("   ");
	for(i=0; i<plateau_get_taille(p); i++){
		printf("- ", i);
	}
	printf("\n");
	
	/* Contenu */
	for(j=0; j<plateau_get_taille(p); j++){
		for(i=0; i<plateau_get_taille(p); i++){
			
			if(i == 0)
				printf("%d |", j+1);
			
			switch(plateau_get(p, i, j)){
				case 1:
					c = 'o';
					break;
				case 2:
					c = 'x';
					break;
				default:
					c = '.';
			}
			
			if(i<plateau_get_taille(p)-1)
				printf("%c ", c);
			else
				printf("%c", c);
			
			if(i == plateau_get_taille(p)-1)
				printf("|");
		}
		printf("\n");
	}

	/* bas d'affichage */
	printf("  ");
	for(i=0; i<plateau_get_taille(p); i++){
		printf("- ", i);
	}
	printf("-\n");
	
}

Chaines captureChaines(Plateau plateau, Pion pion, int* valide){
	Chaines chaines, chainesCapturees;
	
	Chaine chaine, chaine_determine;
	
	Libertes libertes;
	
	Position pos, pos_haut, pos_bas, pos_gauche, pos_droite;
	
	/** initialisation des chaines */
	chaines = creer_ensemble();
	chainesCapturees = creer_ensemble();
	
	/** on determine la chaine a laquelle appartient le pion */
	chaine = plateau_determiner_chaine(plateau, pion_get_position(pion));
	libertes = determineLiberte(plateau, chaine);
	if(ensemble_vide(libertes)){
		ensemble_ajouter(chainesCapturees, chaine);
		*valide = 0;
	}
	
	/* @bug valide vaudra toujours 1 !? d'où valide=0 au dessus inutile !? il n'y a aucun return... donc on arrivera forcément ici ! */
	*valide = 1;
	
	if(ensemble_colores_vide(chaine))
		return chainesCapturees;
	
	ensemble_colores_reset(chaine);
	
	/** on se deplace sur cette chaine */
	while(ensemble_colores_suivant(chaine)){
		/** on regarde haut, bas, gauche, droite de chaque position de cette chaine */
		pos = ensemble_colores_get_courant(chaine);
		
		pos_haut = haut(pos);
		pos_bas = bas(pos);
		pos_gauche = gauche(pos);
		pos_droite = droite(pos);
		
		chaine_determine = plateau_determiner_chaine(plateau, pos_haut);
		if(chaine_determine != NULL && !chaines_appartient_chaine(chaines, chaine_determine) && plateau_get_pos(plateau, pos_haut) != ensemble_colores_get_couleur(chaine)){
			/** on determine la chaine de chaque haut/bas/gauche/droite, et on l'ajoute dans une Chaines "tmp"  */
			ensemble_ajouter(chaines, chaine_determine);
			
			/** on vérifie les libertés de chaque chaine, et si ensemble_vide(libertes) == 1 pour une chaine, on capture cette chaine */
			libertes = determineLiberte(plateau, chaine_determine);
			if(ensemble_vide(libertes))
				ensemble_ajouter(chainesCapturees, chaine_determine);
		}
		
		chaine_determine = plateau_determiner_chaine(plateau, pos_bas);
		if(chaine_determine != NULL && !chaines_appartient_chaine(chaines, chaine_determine) && plateau_get_pos(plateau, pos_bas) != ensemble_colores_get_couleur(chaine)){			
			ensemble_ajouter(chaines, chaine_determine);
			
			libertes = determineLiberte(plateau, chaine_determine);
			if(ensemble_vide(libertes))
				ensemble_ajouter(chainesCapturees, chaine_determine);
		}
		
		chaine_determine = plateau_determiner_chaine(plateau, pos_gauche);
		if(chaine_determine != NULL && !chaines_appartient_chaine(chaines, chaine_determine) && plateau_get_pos(plateau, pos_gauche) != ensemble_colores_get_couleur(chaine)){
			ensemble_ajouter(chaines, chaine_determine);
			
			libertes = determineLiberte(plateau, chaine_determine);
			if(ensemble_vide(libertes))
				ensemble_ajouter(chainesCapturees, chaine_determine);
		}
		
		chaine_determine = plateau_determiner_chaine(plateau, pos_droite);
		if(chaine_determine != NULL && !chaines_appartient_chaine(chaines, chaine_determine) && plateau_get_pos(plateau, pos_droite) != ensemble_colores_get_couleur(chaine)){
			ensemble_ajouter(chaines, chaine_determine);
			
			libertes = determineLiberte(plateau, chaine_determine);
			if(ensemble_vide(libertes))
				ensemble_ajouter(chainesCapturees, chaine_determine);
		}		
		
		ensemble_colores_set_courant(chaine, ensemble_colores_get_suivant(chaine));
	}

	pos = ensemble_colores_get_courant(chaine);
	
	pos_haut = haut(pos);
	pos_bas = bas(pos);
	pos_gauche = gauche(pos);
	pos_droite = droite(pos);
	
	chaine_determine = plateau_determiner_chaine(plateau, pos_haut);
	if(chaine_determine != NULL && !chaines_appartient_chaine(chaines, chaine_determine) && plateau_get_pos(plateau, pos_haut)){
		ensemble_ajouter(chaines, chaine_determine);
		
		libertes = determineLiberte(plateau, chaine_determine);
		if(ensemble_vide(libertes))
			ensemble_ajouter(chainesCapturees, chaine_determine);
	}
	
	chaine_determine = plateau_determiner_chaine(plateau, pos_bas);
	if(chaine_determine != NULL && !chaines_appartient_chaine(chaines, chaine_determine) && plateau_get_pos(plateau, pos_bas) != ensemble_colores_get_couleur(chaine)){
		ensemble_ajouter(chaines, chaine_determine);
		
		libertes = determineLiberte(plateau, chaine_determine);
		if(ensemble_vide(libertes))
			ensemble_ajouter(chainesCapturees, chaine_determine);
	}
	
	chaine_determine = plateau_determiner_chaine(plateau, pos_gauche);
	if(chaine_determine != NULL && !chaines_appartient_chaine(chaines, chaine_determine) && plateau_get_pos(plateau, pos_gauche) != ensemble_colores_get_couleur(chaine)){
		ensemble_ajouter(chaines, chaine_determine);
		
		libertes = determineLiberte(plateau, chaine_determine);
		if(ensemble_vide(libertes))
			ensemble_ajouter(chainesCapturees, chaine_determine);
	}
	
	chaine_determine = plateau_determiner_chaine(plateau, pos_droite);
	if(chaine_determine != NULL && !chaines_appartient_chaine(chaines, chaine_determine) && plateau_get_pos(plateau, pos_droite) != ensemble_colores_get_couleur(chaine)){
		ensemble_ajouter(chaines, chaine_determine);
		
		libertes = determineLiberte(plateau, chaine_determine);
		if(ensemble_vide(libertes))
			ensemble_ajouter(chainesCapturees, chaine_determine);
	}

	/* on retourne Chaines "sortie" (les chaines captures) */
	return chainesCapturees;
}
