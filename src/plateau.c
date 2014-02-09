#include <matrice.h>
#include <plateau.h>
#include <couleur.h>

int est_un_pion(Couleur c){
	return (c == BLANC || c == NOIR);
}

int est_un_pion_plateau(Plateau plateau, Position pos){
	/* on vérifie premièrement que la position ne sort pas des bords */
	if(!position_appartient_matrice(plateau, pos.x, pos.y))
		return 0;
	
	return est_un_pion(plateau.donnees[pos.y][pos.x]);
}

Plateau creer_plateau(){
	//Matrice m = initMatrice;
	return NULL;
}

Couleur plateau_get(Plateau p, int i, int j){
	return p.donnees[i][j];
}

void plateau_set(Plateau p, int i, int j, Couleur c){
	p.donnees[i][j] = c;
}

Chaine plateau_determiner_chaine(Plateau plateau, Position pos){
	Chaine c;
	Position p = pos;
	
	if(!position_appartient_matrice(plateau, pos.x, pos.y))
		return NULL;
	
	if(!est_un_pion(plateau.donnees[pos.y][pos.x]))
		return NULL;
	
	c.couleur = plateau.donnees[pos.y][pos.x];
	
	if(est_un_pion(plateau.donnees[pos.y][pos.x+1]))
		ajouterElement(&c, plateau.donnees[pos.y][pos.x+1]);
		
	if(est_un_pion(plateau.donnees[pos.y][pos.x-1]))
		ajouterElement(&c, plateau.donnees[pos.y][pos.x-1]);
		
	if(est_un_pion(plateau.donnees[pos.y+1][pos.x]))
		ajouterElement(&c, plateau.donnees[pos.y+1][pos.x]);
		
	if(est_un_pion(plateau.donnees[pos.y-1][pos]))
		ajouterElement(&c, plateau.donnees[pos.y-1][pos.x]);
		
	p.x++;
	plateau_determiner_chaine(plateau, p);
	p.x -= 2;
	plateau_determiner_chaine(plateau, p);
	p.x++;
	
	p.y++;
	plateau_determiner_chaine(plateau, p);
	p.y -= 2;
	plateau_determiner_chaine(plateau, p);
	p.x++;
	
	return c;
}

Plateau plateau_chargement(FILE* fichier){
	return NULL;
}
