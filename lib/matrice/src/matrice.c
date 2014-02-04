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
 */
 
/** 
 * @file matrice.c
 * 
 * Le code source permettant de gérer des matrices
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <matrice.h>
#include <couleur.h>

struct Matrice creer_matrice(int nblig, int nbcol){
	int i;
	
	struct Matrice m;
	
	m.nbligne = nblig;
	m.nbcolonne = nbcol;
	
	m.donnees = (char **) malloc(nblig * sizeof(char *));
	
	for(i=0; i<nblig; i++){
		m.donnees[i] = (Couleur *) malloc(nbcol * sizeof(Couleur));
	}
	
	return m;
}

struct Matrice initMatrice(char *fichier){
	FILE* f;
	char c;
	
	struct Matrice m;
	int nbligne, nbcolonne, i, j;
	
	/* ouverture du fichier en lecture/ecriture */
	f = fopen(fichier, "r+");
	
	if(f == NULL) fprintf(stdout, "fichier '%s' inexistant \n", fichier);
	
	/* récupération du nombre de ligne */
	c = fgetc(f);
	nbligne = atoi(&c);
	
	/* on passe l'espace */
	fgetc(f);
	
	/* récupération du nombre de colonnes*/
	c = fgetc(f);
	nbcolonne = atoi(&c);
	
	/* on passe le retour chariot */
	fgetc(f);
	
	/* initialisation de la matrice (allocation mémoire) */
	m = creer_matrice(nbligne, nbcolonne);
	m.nbcolonne = nbcolonne;
	m.nbligne = nbligne;
	
	/* récupération des données */
	if(f != NULL){
		for(j=0, i=0; j<nbligne && m.donnees[j][i] != EOF; i++, i %= nbcolonne){
			c = (char) fgetc(f);
			
			if(c == '.')
				m.donnees[j][i] = VIDE;
			else if(c == 'o')
				m.donnees[j][i] = BLANC;
			else if(c == 'x')
				m.donnees[j][i] = NOIR;
			
			if((char) fgetc(f) == '\n'){
				j++;
			}
		}
	} else {
			fprintf(stderr, "Erreur : fichier innexistant pour l'initialisation de la matrice");
	}
	
	fclose(f);
	
	return m;
}

void afficheMatrice(struct Matrice m){
	int i, j;
	
	for(j=0; j<m.nbligne; j++){
		for(i=0; i<m.nbcolonne; i++){
			printf("%c ", m.donnees[j][i]);
		}
		printf("\n");
	}
}

/**
 * @todo hehe
 */
void SauvegardeMatrice(struct Matrice m, char *fichier){
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



