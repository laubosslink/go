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
	
	return est_un_pion(plateau.donnees[pos.y][pos.x]);
}

Plateau creer_plateau(int taille){
	return (Plateau) matrice_creer(taille, taille);
}

Plateau plateau_chargement(FILE* fichier){
	return (Plateau) matrice_chargement(fichier);
}

Couleur plateau_get(Plateau p, int x, int y){
	return (Couleur) p.donnees[y][x];
}

Couleur plateau_get_pos(Plateau p, Position pos){
	return (Couleur) p.donnees[pos.y][pos.x];
}

void plateau_set(Plateau p, int i, int j, Couleur c){
	p.donnees[i][j] = c;
}

void plateau_determiner_chaine_rec(Plateau plateau, Position pos, Chaine* chaine){
	Position* p;
	
	/* Si la position reçu sort du plateau, ou qu'elle ne correspond pas à la couleur rechercher, on s'arrête */
	if(!plateau_position_appartient(plateau, pos) || plateau_get(plateau, pos.x, pos.y) != chaine->c)
		return;
	
	if(ensemble_colores_appartient(chaine, &pos))
		return;
	
	ensemble_colores_ajouter(chaine, creer_position(pos.x, pos.y));
	
	plateau_determiner_chaine_rec(plateau, haut(pos), chaine);
	plateau_determiner_chaine_rec(plateau, bas(pos), chaine);
	plateau_determiner_chaine_rec(plateau, gauche(pos), chaine);
	plateau_determiner_chaine_rec(plateau, droite(pos), chaine);
	
}

Chaine plateau_determiner_chaine(Plateau plateau, Position pos){
	Chaine chaine;
	
	ensemble_colores_init(&chaine);
	
	if(!plateau_position_appartient(plateau, pos) || !est_un_pion_plateau(plateau, pos))
		return chaine;
	
	chaine.c = plateau_get_pos(plateau, pos);
	
	/* ajoute de la position actuel dans la chaine */
	ensemble_colores_ajouter(&chaine, creer_position(pos.x, pos.y));

	/* lancement récursif à droite, gauche, haut, bas pour rechercher des pions de même couleur */
	plateau_determiner_chaine_rec(plateau, droite(pos), &chaine);
	plateau_determiner_chaine_rec(plateau, gauche(pos), &chaine);
	plateau_determiner_chaine_rec(plateau, haut(pos), &chaine);
	plateau_determiner_chaine_rec(plateau, bas(pos), &chaine);
	
	return chaine;
}

void plateau_realiser_capture(Plateau plateau, Chaine chaine){
	Positions* p = chaine.p;
	
	if(ensemble_vide(p))
		return;
	
	ensemble_reset_courant(p); 
	
	while(ensemble_suivant(p)){
		plateau.donnees[position_get_courant(p)->y][position_get_courant(p)->x] = VIDE;
		ensemble_set_courant(p, ensemble_get_suivant(p));
	}
	
	plateau.donnees[position_get_courant(p)->y][position_get_courant(p)->x] = VIDE;
	
	/* @todo free de chaine */
}

int plateau_est_identique(Plateau plateau, Plateau ancienPlateau){
	int i, j;
	
	if(plateau.nbcolonne != ancienPlateau.nbcolonne || plateau.nbligne != ancienPlateau.nbligne)
		return 0;
	
	for(i=0; i<plateau.nbcolonne; i++){
		for(j=0; j<plateau.nbligne; j++){
			if(plateau.donnees[j][i] != ancienPlateau.donnees[j][i])
				return 0;
		}
	}
	
	return 1;
}

int plateau_position_appartient(Plateau plateau, Position position){
	return matrice_position_appartient(plateau, position.x, position.y);
}

int plateau_copie(Plateau from, Plateau to){
	int i, j;
	
	if(from.nbcolonne != to.nbcolonne || from.nbligne != to.nbligne){
		fprintf(stderr, "taille différence pour la copie d'un tableau 'from' vers 'to'");
		return 0;
	}
	
	for(i=0; i<from.nbcolonne; i++){
		for(j=0; j<from.nbligne; j++){
			to.donnees[j][i] != from.donnees[j][i];
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
	for(i=0; i<p.nbcolonne; i++){
		printf("- ", i);
	}
	printf("\n");
	
	printf("  |");
	for(i=0; i<p.nbcolonne; i++){
		if(i<p.nbcolonne-1)
			printf("%d ", i+1);
		else
			printf("%d", i+1);
	}
	printf("|\n");	
	
	printf("   ");
	for(i=0; i<p.nbcolonne; i++){
		printf("- ", i);
	}
	printf("\n");
	
	/* Contenu */
	for(j=0; j<p.nbligne; j++){
		for(i=0; i<p.nbcolonne; i++){
			
			if(i == 0)
				printf("%d |", j+1);
			
			switch(p.donnees[j][i]){
				case 1:
					c = 'o';
					break;
				case 2:
					c = 'x';
					break;
				default:
					c = '.';
			}
			
			if(i<p.nbcolonne-1)
				printf("%c ", c);
			else
				printf("%c", c);
			
			if(i == p.nbcolonne-1)
				printf("|");
		}
		printf("\n");
	}

	/* bas d'affichage */
	printf("  ");
	for(i=0; i<p.nbcolonne; i++){
		printf("- ", i);
	}
	printf("-\n");
	
}

Chaines captureChaines(Plateau plateau, Pion pion, int* valide){
	Chaines chaines, chainesCapturees;
	
	Chaine chaine, chaine_determine;
	
	Libertes libertes;
	
	/** initialisation des chaines */
	ensemble_init(&chaines);
	ensemble_init(&chainesCapturees);
	
	/** on determine la chaine a laquelle appartient le pion */
	chaine = plateau_determiner_chaine(plateau, pion.p);
	
	if(ensemble_colores_vide(&chaine))
		return chainesCapturees;
	
	ensemble_reset_courant(chaine.p);
	
	/** on se deplace sur cette chaine */
	while(ensemble_positions_suivant(chaine.p)){
		/** on regarde haut, bas, gauche, droite de chaque position de cette chaine */
		
		/** @bug risque de poser problème, on ajoute une adresse "chainede_determiner qui reste la même (seul le contenu chance à chaque appel
		 * de plateau_determiner_chaine. */
		chaine_determine = plateau_determiner_chaine(plateau, haut(*position_get_courant(chaine.p)));
		if(!chaines_appartient_chaine(chaines, chaine_determine) && plateau_get_pos(plateau, haut(*position_get_courant(chaine.p))) != chaine.c){
			/** on determine la chaine de chaque haut/bas/gauche/droite, et on l'ajoute dans une Chaines "tmp"  */
			ensemble_ajouter(&chaines, &chaine_determine);
			
			/** on vérifie les libertés de chaque chaine, et si ensemble_vide(libertes) == 1 pour une chaine, on capture cette chaine */
			libertes = determineLiberte(plateau, chaine_determine);
			if(ensemble_vide(&libertes))
				ensemble_ajouter(&chainesCapturees, &chaine_determine);
		}
		
		chaine_determine = plateau_determiner_chaine(plateau, bas(*position_get_courant(chaine.p)));
		if(!chaines_appartient_chaine(chaines, chaine_determine) && plateau_get_pos(plateau, bas(*position_get_courant(chaine.p))) != chaine.c){
			ensemble_ajouter(&chaines, &chaine_determine);
			
			libertes = determineLiberte(plateau, chaine_determine);
			if(ensemble_vide(&libertes))
				ensemble_ajouter(&chainesCapturees, &chaine_determine);
		}
		
		
		chaine_determine = plateau_determiner_chaine(plateau, gauche(*position_get_courant(chaine.p)));
		if(!chaines_appartient_chaine(chaines, chaine_determine) && plateau_get_pos(plateau, gauche(*position_get_courant(chaine.p))) != chaine.c){
			ensemble_ajouter(&chaines, &chaine_determine);
			
			libertes = determineLiberte(plateau, chaine_determine);
			if(ensemble_vide(&libertes))
				ensemble_ajouter(&chainesCapturees, &chaine_determine);
		}
		
		chaine_determine = plateau_determiner_chaine(plateau, droite(*position_get_courant(chaine.p)));
		if(!chaines_appartient_chaine(chaines, chaine_determine) && plateau_get_pos(plateau, droite(*position_get_courant(chaine.p))) != chaine.c){
			ensemble_ajouter(&chaines, &chaine_determine);
			
			libertes = determineLiberte(plateau, chaine_determine);
			if(ensemble_vide(&libertes))
				ensemble_ajouter(&chainesCapturees, &chaine_determine);
		}
		
		ensemble_set_courant(chaine.p, ensemble_get_suivant(chaine.p));
	}
	
	chaine_determine = plateau_determiner_chaine(plateau, haut(*position_get_courant(chaine.p)));
	if(!chaines_appartient_chaine(chaines, chaine_determine) && plateau_get_pos(plateau, haut(*position_get_courant(chaine.p))) != chaine.c){
		/** on determine la chaine de chaque haut/bas/gauche/droite, et on l'ajoute dans une Chaines "tmp"  */
		ensemble_ajouter(&chaines, &chaine_determine);
		
		/** on vérifie les libertés de chaque chaine, et si ensemble_vide(libertes) == 1 pour une chaine, on capture cette chaine */
		libertes = determineLiberte(plateau, chaine_determine);
		if(ensemble_vide(&libertes))
			ensemble_ajouter(&chainesCapturees, &chaine_determine);
	}
	
	chaine_determine = plateau_determiner_chaine(plateau, bas(*position_get_courant(chaine.p)));
	if(!chaines_appartient_chaine(chaines, chaine_determine) && plateau_get_pos(plateau, bas(*position_get_courant(chaine.p))) != chaine.c){
		ensemble_ajouter(&chaines, &chaine_determine);
		
		libertes = determineLiberte(plateau, chaine_determine);
		if(ensemble_vide(&libertes))
			ensemble_ajouter(&chainesCapturees, &chaine_determine);
	}
	
	
	chaine_determine = plateau_determiner_chaine(plateau, gauche(*position_get_courant(chaine.p)));
	if(!chaines_appartient_chaine(chaines, chaine_determine) && plateau_get_pos(plateau, gauche(*position_get_courant(chaine.p))) != chaine.c){
		ensemble_ajouter(&chaines, &chaine_determine);
		
		libertes = determineLiberte(plateau, chaine_determine);
		if(ensemble_vide(&libertes))
			ensemble_ajouter(&chainesCapturees, &chaine_determine);
	}
	
	chaine_determine = plateau_determiner_chaine(plateau, droite(*position_get_courant(chaine.p)));
	if(!chaines_appartient_chaine(chaines, chaine_determine) && plateau_get_pos(plateau, droite(*position_get_courant(chaine.p))) != chaine.c){
		ensemble_ajouter(&chaines, &chaine_determine);
		
		libertes = determineLiberte(plateau, chaine_determine);
		if(ensemble_vide(&libertes))
			ensemble_ajouter(&chainesCapturees, &chaine_determine);
	}

	/* on retourne Chaines "sortie" (les chaines captures) */
	return chainesCapturees;
}
