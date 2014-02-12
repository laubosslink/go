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
 * @file matrice.c
 * 
 * Le code source permettant de gérer des matrices
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <matrice.h>

Matrice matrice_creer(int nblig, int nbcol){
	int i;
	
	Matrice m;
	
	m.nbligne = nblig;
	m.nbcolonne = nbcol;
	
	m.donnees = (int **) malloc(nblig * sizeof(int *));
	
	for(i=0; i<nblig; i++){
		m.donnees[i] = (int *) malloc(nbcol * sizeof(int));
	}
	
	return m;
}

Matrice matrice_chargement(FILE *fichier){
	Matrice m;
	int nbligne, nbcolonne, i, j;
	
	if(fichier == NULL){ 
		fprintf(stdout, "Le pointeur d'ouverture de fichier est NULL pour matrice_chargement \n");
	}
	
	/** 
	 * @bug si dans un fichier la taille est > 9, il y a un problème pour récupérer 
	 * le nombre de ligne, et de colonnes. Il faut changer fgetc par autre chose.
	 */
	
	/* récupération du nombre de ligne */
	nbligne = (int) fgetc(fichier) - '0';
	
	/* on passe l'espace */
	fgetc(fichier);
	
	/* récupération du nombre de colonnes*/
	nbcolonne = (int) fgetc(fichier) - '0';
	
	/* on passe le retour chariot */
	fgetc(fichier);
	
	/* initialisation de la matrice (allocation mémoire) */
	m = matrice_creer(nbligne, nbcolonne);
	m.nbcolonne = nbcolonne;
	m.nbligne = nbligne;	
	
	/* récupération des données */
	for(j=0, i=0; j<nbligne && m.donnees[j][i] != EOF; i++, i %= nbcolonne){
		m.donnees[j][i] = (int) fgetc(fichier) - '0';
		
		if((char) fgetc(fichier) == '\n'){
			j++;
		}
	}

	return m;
}

Matrice matrice_init(char *fichier){
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

int matrice_position_appartient(Matrice m, int x, int y){
	return (x < m.nbcolonne && x >= 0 && y < m.nbligne && y >= 0);
}

void matrice_affiche(Matrice m){
	int i, j;
	
	for(j=0; j<m.nbligne; j++){
		for(i=0; i<m.nbcolonne; i++){
			printf("%d ", m.donnees[j][i]);
		}
		printf("\n");
	}
}

int matrice_sauvegarde(Matrice m, FILE *fichier){
	int i, j;
	unsigned char r;

	if(fichier == NULL)
		return 0;

	/* "en-tête" du fichier contenant le nombre de ligne et de colonnes de la matrice */
	r = fputc(m.nbligne + '0', fichier);
	if(r == EOF) return 0;
	
	r = fputc(' ', fichier);
	if(r == EOF) return 0;
	
	r = fputc(m.nbcolonne + '0', fichier);
	if(r == EOF) return 0;
	
	r = fputc('\n', fichier);
	if(r == EOF) return 0;
	
	for(j=0; j<m.nbligne; j++){
		for(i=0; i<m.nbcolonne; i++){
			r = fputc(m.donnees[j][i] + '0', fichier);
			if(r == EOF) return 0;

			if(i<m.nbcolonne-1){
				r = fputc(' ', fichier);
				if(r == EOF) return 0; 
			}
		}
		r = fputc('\n', fichier);
		if(r == EOF) return 0;

	}
	
	return 1;
}



