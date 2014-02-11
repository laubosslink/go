#include <stdio.h>

#include <matrice.h>
#include <partie.h>
#include <plateau.h>

int main(){
	int choix;
	int x, y, numero_tour;
	
	FILE* fichier_plateau = fopen("extra/plateau_initiale_9_9.txt", "r");
	
	Plateau plateau_courant = plateau_chargement(fichier_plateau);
	
	fclose(fichier_plateau);
	
	Couleur couleur = BLANC;
	
	printf("Bienvenue !\n");
	
	printf("Que voulez-vous faire ?\n");
	printf("0. quitter\n");
	printf("1. Jouer\n");
	scanf("%d", &choix);
	
	if(choix == 1){
		numero_tour = 0;
		
		do {
			numero_tour++;
			
			plateau_afficher(plateau_courant);
			
			if(couleur == BLANC){
				printf("Au tour du joueur 1 (tour n°%d)\n", numero_tour);
			} else if(couleur == NOIR)
			{
				printf("Au tour du joueur 2 (tour n°%d)\n", numero_tour);
			}
			
			printf("Vous désirez poser votre pion en quels positions ? \n");
			
			do {
			printf("x: ");
			scanf("%d", &x);
			
			printf("y: ");
			scanf("%d", &y);
			
			printf("\n");
			
			x--;
			y--;
			
			} while(!position_appartient_matrice(plateau_courant, x, y));
			
			plateau_set(plateau_courant, x, y, couleur);
			
			echange_joueur(&couleur);
		} while(1);
	}
	
	return 0;
}
