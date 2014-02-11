#include <partie.h>
#include <couleur.h>

void partie_demande_questions(int numero_question, Partie *partie){
	switch(numero_question){
		case 0:
			partie->joueur1;
			break;
	}
}

Partie partie_initialisation(FonctionQuestions fonctionQuestions){
	Partie partie;
	
	fonctionQuestions(0, &partie);
	
	partie.couleur = BLANC;
	
	//partie.plateau = cre
}

void echange_joueur(Couleur* c){
	if(*c == BLANC)
		*c = NOIR;
	else if(*c == NOIR)
		*c = BLANC;
}
