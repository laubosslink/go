#include <partie.h>
#include <plateau.h>
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
	
	/* sauvegarde des noms et couleur du joueur */
	est_sauve = (fwrite(&(partie.joueur1), sizeof(char) * 20, 1, fichier) == 1);
	est_sauve = (fwrite(&(partie.joueur2), sizeof(char) * 20, 1, fichier) == 1 && est_sauve == 1);
	est_sauve = (fwrite(&(partie.joueur), sizeof(Couleur), 1, fichier) == 1 && est_sauve == 1);
	
	/* sauvegarde des informations du plateau (taille, donnees) */
	est_sauve = (fwrite(&(partie.plateau.nbligne), sizeof(int), 1, fichier) == 1 && est_sauve == 1);
	
	//est_sauve = (fwrite(partie.plateau.donnees, sizeof(int), partie.plateau.nbligne * partie.plateau.nbcolonne, fichier) == 1 && est_sauve == 1);
	
	for(i=0; i<partie.plateau.nbligne; i++)
	{
		for(j=0; j<partie.plateau.nbcolonne; j++)
		{
			est_sauve = (fwrite(&(partie.plateau.donnees[i][j]), sizeof(int), 1, fichier) == 1 && est_sauve == 1);
		}
	}
	//est_sauve = (fwrite(&(partie.plateau), sizeof(int), 1, fichier) == 1 && est_sauve == 1);
	
	return est_sauve;
}

Partie partie_charge(FILE* fichier){
	Partie partie;
	int i, j;
	
	fread(&(partie.joueur1), sizeof(char) * 20, 1, fichier);
	fread(&(partie.joueur2), sizeof(char) * 20, 1, fichier);
	fread(&(partie.joueur), sizeof(Couleur), 1, fichier);
	
	fread(&(partie.plateau.nbligne), sizeof(int), 1, fichier);
	partie.plateau.nbcolonne = partie.plateau.nbligne;
	
	partie.plateau = creer_plateau(partie.plateau.nbcolonne);

	//fread(&(partie.plateau.donnees), sizeof(int) * partie.plateau.nbligne * partie.plateau.nbcolonne, 1, fichier);
	
	for(i=0; i<partie.plateau.nbligne; i++)
	{
		for(j=0; j<partie.plateau.nbcolonne; j++)
		{
			fread(&(partie.plateau.donnees[i][j]), sizeof(int), 1, fichier);
		}
	}
	
	return partie;
}
