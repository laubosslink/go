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
	
	/* 
	 * On regarde à droite 
	 * On fait bien attention à vérifie que la position ne se trouve pas déjà dans la chaine, permet un appel récursif infinie
	 */
	pos.x++;
	if(est_un_pion_plateau(plateau, pos) && plateau_get(plateau, pos.x, pos.y) == chaine->c && !ensemble_colores_appartient(chaine, &pos)){
		p = (Position *) malloc(sizeof(Position));
		p->x = pos.x;
		p->y = pos.y;
		
		/* Si on est là, c'est qu'a droite il a une position a ajouter dans notre chaine */
		ensemble_colores_ajouter(chaine, p);
		
		/* On relance un appel récursif sur la position droite */
		plateau_determiner_chaine_rec(plateau, pos, chaine);
	}
	
	/* On regarde à gauche */
	pos.x -= 2;
	if(est_un_pion_plateau(plateau, pos) && plateau_get(plateau, pos.x, pos.y) == chaine->c && !ensemble_colores_appartient(chaine, &pos)){
		p = (Position *) malloc(sizeof(Position));
		p->x = pos.x;
		p->y = pos.y;
		
		ensemble_colores_ajouter(chaine, p);
		
		plateau_determiner_chaine_rec(plateau, pos, chaine);
	}
	
	pos.x++;

	/* On regarde en bas  */
	pos.y++;
	if(est_un_pion_plateau(plateau, pos) && plateau_get(plateau, pos.x, pos.y) == chaine->c && !ensemble_colores_appartient(chaine, &pos)){
		p = (Position *) malloc(sizeof(Position));
		p->x = pos.x;
		p->y = pos.y;
		
		ensemble_colores_ajouter(chaine, p);
		
		plateau_determiner_chaine_rec(plateau, pos, chaine);
	}
	
	/* On regarde en haut */
	pos.y -= 2;
	if(est_un_pion_plateau(plateau, pos) && plateau_get(plateau, pos.x, pos.y) == chaine->c && !ensemble_colores_appartient(chaine, &pos)){
		p = (Position *) malloc(sizeof(Position));
		p->x = pos.x;
		p->y = pos.y;
		
		ensemble_colores_ajouter(chaine, p);
		
		plateau_determiner_chaine_rec(plateau, pos, chaine);
	}
	
	pos.y++;
}

Chaine plateau_determiner_chaine(Plateau plateau, Position pos){
	Chaine chaine;
	Position* p;
	
	if(!est_un_pion_plateau(plateau, pos))
		return;
	
	chaine.c = plateau.donnees[pos.y][pos.x];
	
	p = (Position *) malloc(sizeof(Position));
	p->x = pos.x;
	p->y = pos.y;
	
	chaine.p = creer_ensemble(); /** IMPORTANT */
	
	/* ajoute de la position actuel dans la chaine */
	ensemble_colores_ajouter(&chaine, p);

	/* lancement récursif à droite, gauche, haut, bas pour rechercher des pions de même couleur */
	pos.x++;
	plateau_determiner_chaine_rec(plateau, pos, &chaine);
	pos.x -= 2;
	plateau_determiner_chaine_rec(plateau, pos, &chaine);
	pos.x++;
	
	pos.y++;
	plateau_determiner_chaine_rec(plateau, pos, &chaine);
	pos.y -= 2;
	plateau_determiner_chaine_rec(plateau, pos, &chaine);
	pos.x++;
	
	return chaine;
}

void plateau_realiser_capture(Plateau plateau, Chaine chaine){
	Positions* p = chaine.p;
	
	if(ensemble_vide(p))
		return;
	
	p->courant = ensemble_tete(p);
	
	while(ensemble_suivant(p)){
		plateau.donnees[((Position*)p->courant->contenu)->y][((Position*)p->courant->contenu)->x] = VIDE;
		p->courant = ensemble_courant(p)->suivant;
	}
	
	plateau.donnees[((Position*)p->courant->contenu)->y][((Position*)p->courant->contenu)->x] = VIDE;
	
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

/*
Chaines captureChaines(Plateau plateau,Pion pion, int* valide){
	Chaines CC;
	Pion pionChaine;
	Position* voisinHaut;
	Position* voisinBas;
	Position* voisinGauche;
	Position* voisinDroite;
	Chaine chaine;
	Chaine chaineAdverse;
	Libertes libertes_chaine;
	Libertes libertes_chaineAdverse;
	
	chaine = plateau_determiner_chaine(plateau,pion.p);
	
	pionChaine.c = chaine.c;
	pionChaine.p = (*(Position*)(ensemble_colores_tete(&chaine)->contenu));
	
	voisinHaut = (Position*)malloc(sizeof(Position));
	voisinBas = (Position*)malloc(sizeof(Position));
	voisinGauche = (Position*)malloc(sizeof(Position));
	voisinDroite = (Position*)malloc(sizeof(Position));
	
	/* on parcours la chaine à laquelle appartient le pion pour determiner la chaine des pions adverses */
	while(ensemble_colores_suivant(&chaine)){
		
		(*voisinHaut) = haut(pionChaine.p);
		(*voisinBas) = bas(pionChaine.p);
		(*voisinGauche) = gauche(pionChaine.p);
		(*voisinDroite) = droite(pionChaine.p);

		
		if(plateau_position_appartient(plateau,haut(pionChaine.p)) && plateau_get(plateau,haut(pionChaine.p).x,haut(pionChaine.p).y) != pionChaine.c)
			ensemble_colores_ajouter(&chaineAdverse,voisinHaut);
		
		if(plateau_position_appartient(plateau,bas(pionChaine.p)) && plateau_get(plateau,bas(pionChaine.p).x,bas(pionChaine.p).y) != pionChaine.c)
			ensemble_colores_ajouter(&chaineAdverse,voisinBas);
		
		if(plateau_position_appartient(plateau,droite(pionChaine.p)) && plateau_get(plateau,droite(pionChaine.p).x,droite(pionChaine.p).y) != pionChaine.c)
			ensemble_colores_ajouter(&chaineAdverse,voisinDroite);
		
		if(plateau_position_appartient(plateau,gauche(pionChaine.p)) && plateau_get(plateau,gauche(pionChaine.p).x,gauche(pionChaine.p).y) != pionChaine.c)
			ensemble_colores_ajouter(&chaineAdverse,voisinGauche);
			
		pionChaine.p = (*(Position*)(ensemble_colores_tete(&chaine)->suivant));
	}
	
	/* On determine les libertes de chacune des deux chaines */
	libertes_chaine = determineLiberte(plateau,chaine);
	libertes_chaineAdverse = determineLiberte(plateau,chaineAdverse);
	
	/* si la chaine ne possède aucune liberté elle est capturée */
	if(ensemble_positions_vide(&libertes_chaine)){
		plateau_realiser_capture(plateau,chaine);
		ensemble_ajouter(&CC,&chaine);
		(*valide) = 0;
		return CC;
	}
	else{
		if(ensemble_positions_vide(&libertes_chaineAdverse)){
			plateau_realiser_capture(plateau,chaineAdverse);
			ensemble_ajouter(&CC,&chaineAdverse);
			(*valide) = 1;
			return CC;
		}
	}
	
	if((*valide) != 0 && (*valide) != 1 && ensemble_vide(&CC)){
		printf("Aucune chaine n'a été capturé");
	}
	
}
*/
