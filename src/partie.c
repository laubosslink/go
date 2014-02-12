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
			partie->plateau = creer_plateau(taille, taille);
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

int partie_sauvegarde(Partie partie, FILE* fichier){
	int est_sauve = 0;
	
	est_sauve = (fwrite(&partie, sizeof(Partie), 1, fichier) == sizeof(Partie));
	
	fwrite(&(partie.plateau), sizeof(Plateau), 1, fichier);
	
	return est_sauve;
}
