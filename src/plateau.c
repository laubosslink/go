#include <matrice.h>
#include <ensemble_colores.h>
#include <chaine.h>
#include <plateau.h>
#include <couleur.h>
#include <stdio.h>
#include <stdlib.h>

int est_un_pion(Couleur c){
	return (c == BLANC || c == NOIR);
}

int est_un_pion_plateau(Plateau plateau, Position pos){
	/* on vérifie premièrement que la position ne sort pas des bords */
	if(!position_appartient_matrice(plateau, pos.x, pos.y))
		return 0;
	
	return est_un_pion(plateau.donnees[pos.y][pos.x]);
}

Plateau creer_plateau(int nbligne, int nbcolonne){
	return (Plateau) creer_matrice(nbligne, nbcolonne);
}

Plateau plateau_chargement(FILE* fichier){
	return (Plateau) matrice_chargement(fichier);
}

Couleur plateau_get(Plateau p, int x, int y){
	return p.donnees[y][x];
}

void plateau_set(Plateau p, int i, int j, Couleur c){
	p.donnees[i][j] = c;
}

void plateau_determiner_chaine_rec(Plateau plateau, Position pos, Chaine* chaine){
	Position* p;
	
	/* Si la position reçu sort du plateau, ou qu'elle ne correspond pas à la couleur rechercher, on s'arrête */
	if(!position_appartient_matrice(plateau, pos.x, pos.y) || plateau_get(plateau, pos.x, pos.y) != chaine->c)
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
	
	if(!position_appartient_matrice(plateau, pos.x, pos.y))
		return;
	
	if(!est_un_pion(plateau.donnees[pos.y][pos.x]))
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
	return sauvegarde_matrice(plateau, fichier);
}

/*
Chaines captureChaines(Plateau plateau,Pion pion, int* valide){
	Chaines CC; // chaines_capturees
	Chaine ChainePion;
	
	if( ensemble_vide(&CC) ) return NULL;
	
	ChainePion = plateau_determiner_chaine(plateau,pion.p);
	if( (*valide) == 0 && ) 
	
*/
	
	
