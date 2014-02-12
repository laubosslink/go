#include <stdio.h>
#include <string.h>

#include <matrice.h>
#include <partie.h>
#include <plateau.h>



int main(){
	char choix;
	
	char *nom_fichier, string_choix_tour[80];
	
	int x, y, numero_tour, choix_tour;
	
	Partie partie;
	
	Position pos;
	
	FILE* fichier_plateau;

	printf("Bienvenue au jeu de Go!\n\n");
	
	printf("Que voulez-vous faire ?\n");
	printf("j. Jouer\n");
	printf("c. Charger\n");
	printf("q. Quitter\n");
	
	choix = getchar();
	
	if(choix =='j'){
		numero_tour = 0;
		
		partie = partie_initialisation(partie_demande_questions);
		
		do {
			numero_tour++;
			
			plateau_afficher(partie.plateau);
			
			if(partie.joueur == BLANC){
				printf("Au tour de %s (pion o - tour n°%d)\n", partie.joueur1, numero_tour);
			} else if(partie.joueur == NOIR)
			{
				printf("Au tour de %s (pion x - tour n°%d)\n", partie.joueur2, numero_tour);
			}
			
			choix = getchar();
			
			do {
				printf("Que voulez-vous faire ?\n");
				printf("c. continuer\n");
				printf("r. revenir sur un tour\n");
				printf("s. sauvegarde la partie\n");
				printf("q. quitter\n");
				
				choix = getchar();
			} while(choix != 'c' && choix != 'q' && choix != 'r' && choix != 's');
			
			if(choix == 'c'){
				printf("Vous désirez poser votre pion en quelle position ? \n");
			
				do {
					printf("x: ");
					scanf("%d", &x);
					
					printf("y: ");
					scanf("%d", &y);
					
					printf("\n");
					
					x--;
					y--;
					
					pos.x = x;
					pos.y = y;				
					
				/* on demande la position jusqu'a avoir des coordonnees dans la plateau, et sur une case vide */
				} while(!matrice_position_appartient(partie.plateau, x, y) || est_un_pion_plateau(partie.plateau, pos));
				
				/* on pose le pion */
				plateau_set(partie.plateau, x, y, partie.joueur);
				
				/* changement du joueur */
				echange_joueur(&partie.joueur);
				
				nom_fichier = malloc(sizeof(char) * 50);
				strcat(nom_fichier, "extra/sauvegardes/");
				
				sprintf(string_choix_tour, "%d", numero_tour);
				strcat(nom_fichier, string_choix_tour);
				
				fichier_plateau = fopen(nom_fichier, "w+");
	
				plateau_sauvegarde(partie.plateau, fichier_plateau);
				
				fclose(fichier_plateau);

			} else if(choix == 'r')
			{
				do {
					printf("Vous souhaitez revenir a quel tour ?\n");
					printf("tour numero: ");
					scanf("%d", &choix_tour);
					
					/* on controle le choix du tour */
					if(choix_tour <= 0 || choix_tour >= numero_tour)
						printf("Veuillez entrer un tour > 0 et < au tour actuel ! ");
						
				} while(choix_tour <= 0 || choix_tour >= numero_tour);
				
				nom_fichier = malloc(sizeof(char) * 50);
				strcat(nom_fichier, "extra/sauvegardes/");
				
				sprintf(string_choix_tour, "%d", choix_tour);
				strcat(nom_fichier, string_choix_tour);
				
				fichier_plateau = fopen(nom_fichier, "r");
	
				partie.plateau = plateau_chargement(fichier_plateau);
				
				numero_tour = choix_tour-1;
				
				fclose(fichier_plateau);
				
			} else if(choix == 's')
			{
				fichier_plateau = fopen("extra/sauvegardes/sauvegarde_partie", "w+");
	
				if(partie_sauvegarde(partie, fichier_plateau)){
					printf("\nLa partie a ete correctement sauvegarde\n");
				} else {
					printf("\n /!\\ La partie na pas pu etre sauvegarde /!\\ \n");
				}
				
				getchar();
				
				fclose(fichier_plateau);
			} else if(choix == 'q')
			{
				break;
			}
			
			printf("--------------------------------\n\n");
			
		} while(1);
	}
	
	return 0;
}
