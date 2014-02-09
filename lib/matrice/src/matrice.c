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
 * @version 1.0 
 * @date 03-12-2013
 *
 * @todo avancer sur matrice et verifier adaptation couleur pour jeu de go
 */
 
/** 
 * @file matrice.c
 * 
 * Le code source permettant de gérer des matrices
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <matrice.h>

Matrice creer_matrice(int nblig, int nbcol){
	int i;
	
	Matrice m;
	
	m.nbligne = nblig;
	m.nbcolonne = nbcol;
	
	m.donnees = (Couleur **) malloc(nblig * sizeof(Couleur *));
	
	for(i=0; i<nblig; i++){
		m.donnees[i] = (Couleur *) malloc(nbcol * sizeof(Couleur));
	}
	
	return m;
}

Matrice matrice_chargement(FILE *fichier){
	char c;
	
	Matrice m;
	int nbligne, nbcolonne, i, j;
	
	if(fichier == NULL){ 
		fprintf(stdout, "Le pointeur d'ouverture de fichier est NULL pour matrice_chargement \n");
	}
	
	/* récupération du nombre de ligne */
	c = fgetc(fichier);
	nbligne = atoi(&c);
	
	/* on passe l'espace */
	fgetc(fichier);
	
	/* récupération du nombre de colonnes*/
	c = fgetc(fichier);
	nbcolonne = atoi(&c);
	
	/* on passe le retour chariot */
	fgetc(fichier);
	
	/* initialisation de la matrice (allocation mémoire) */
	m = creer_matrice(nbligne, nbcolonne);
	m.nbcolonne = nbcolonne;
	m.nbligne = nbligne;
	
	/* récupération des données */
	for(j=0, i=0; j<nbligne && m.donnees[j][i] != EOF; i++, i %= nbcolonne){
		c = (char) fgetc(fichier);
		
		if(c == 'o')
			m.donnees[j][i] = BLANC;
		else if(c == 'x')
			m.donnees[j][i] = NOIR;
		else
			m.donnees[j][i] = VIDE;
			
		if((char) fgetc(fichier) == '\n'){
			j++;
		}
	}
	
	return m;
}

Matrice init_matrice(char *fichier){
	FILE* f;
	Matrice m;
	
	/* ouverture du fichier en lecture/ecriture */
	f = fopen(fichier, "r+");
	
	if(f == NULL){
		fprintf(stdout, "fichier '%s' inexistant \n", fichier);
	}
	
	m = matrice_chargement(f);
	
	fclose(f);
	
	return m;
}

int position_appartient_matrice(Matrice m, int x, int y){
	return !(x >= m.nbcolonne || x < 0 || y >= m.nbligne || y < 0);
}

void affiche_matrice(Matrice m){
	int i, j;
	
	for(j=0; j<m.nbligne; j++){
		for(i=0; i<m.nbcolonne; i++){
			printf("%d ", m.donnees[j][i]);
		}
		printf("\n");
	}
}

void sauvegarde_matrice(struct Matrice m, char *fichier){
	FILE* f;
	int i, j;
	
	f = fopen(fichier, "w+");

	if(f != NULL){
		/* "en-tête" du fichier contenant le nombre de ligne et de colonnes de la matrice */
		fputc(m.nbligne, f);
		fputc(' ', f);
		fputc(m.nbcolonne, f);
		fputc('\n', f);
		
		for(j=0; j<m.nbligne; j++){
			for(i=0; i<m.nbcolonne; i++){
				fputc(m.donnees[j][i], f);
				
				if(i<m.nbcolonne-1)
					fputc(' ', f);
			}
			fputc('\n', f);
		}
		
		/* @TODO facultatif ? */
		fputc('\0', f);
	} else {
		fprintf(stderr, "Erreur : fichier innexistant pour la sauvegarde de la matrice");
	}
	
	fclose(f);
}



