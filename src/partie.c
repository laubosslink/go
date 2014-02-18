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
 * @file partie.c
 * 
 * @brief Le code source permettant de gérer une partie
 */
 
#include <partie.h>
#include <plateau.h>
#include <matrice.h>
#include <couleur.h>

void partie_demande_questions(int numero_question, Partie *partie){
	int taille;
	
	switch(numero_question){
		case 0:
			printf("Nom du joueur numero 1: ");
			scanf("%s", partie->joueur1);
			printf("Nom du joueur numero 2: ");
			scanf("%s", partie->joueur2);
			break;
		case 1:
			printf("Veuillez entrer la taille du plateau (9, 13, 19) ?");
			scanf("%d", &taille);
			partie->plateau = creer_plateau(taille);
			break;
	}
}

Partie partie_initialisation(FonctionQuestions fonctionQuestions){
	Partie partie;
	
	/* demande des noms de joueurs */
	fonctionQuestions(0, &partie);
	
	/* demande de la taille du plateau */
	fonctionQuestions(1, &partie);
	
	/* le premier joueur a le pion blanc */
	partie.joueur = BLANC;
	
	return partie;
}

void echange_joueur(Couleur* c){
	if(*c == BLANC)
		*c = NOIR;
	else if(*c == NOIR)
		*c = BLANC;
}

/* @todo sauvegarder la partie, le plateau dans un fichier */
int partie_sauvegarde(Partie partie, FILE* fichier){
	int est_sauve = 0, i, j;
	
	int taille = plateau_get_taille(partie.plateau);
	
	/* sauvegarde des noms et couleur du joueur */
	est_sauve = (fwrite(&(partie.joueur1), sizeof(char) * 20, 1, fichier) == 1);
	est_sauve = (fwrite(&(partie.joueur2), sizeof(char) * 20, 1, fichier) == 1 && est_sauve == 1);
	est_sauve = (fwrite(&(partie.joueur), sizeof(Couleur), 1, fichier) == 1 && est_sauve == 1);
	
	/* sauvegarde des informations du plateau (taille, donnees) */
	est_sauve = (fwrite(&taille, sizeof(int), 1, fichier) == 1 && est_sauve == 1);
		
	for(i=0; i<taille; i++)
	{
		est_sauve = (fwrite(matrice_get_donnees_ligne((Matrice) partie.plateau, i), sizeof(int), taille, fichier) == taille && est_sauve == 1);
	}

	return est_sauve;
}

Partie partie_charge(FILE* fichier){
	Partie partie;
	int i, j;
	
	int taille;
	
	fread(&(partie.joueur1), sizeof(char) * 20, 1, fichier);
	fread(&(partie.joueur2), sizeof(char) * 20, 1, fichier);
	fread(&(partie.joueur), sizeof(Couleur), 1, fichier);
	
	fread(&taille, sizeof(int), 1, fichier);
	
	partie.plateau = creer_plateau(taille);

	for(i=0; i<taille; i++)
	{
		fread(matrice_get_donnees_ligne((Matrice) partie.plateau, i), sizeof(int), taille, fichier);
	}
	
	return partie;
}
