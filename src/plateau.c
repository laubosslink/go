#include <matrice.h>
#include <ensemble_colores.h>
#include <chaine.h>
#include <plateau.h>
#include <couleur.h>
#include <stdio.h>

int est_un_pion(Couleur c){
	return (c == BLANC || c == NOIR);
}

int est_un_pion_plateau(Plateau plateau, Position pos){
	/* on vérifie premièrement que la position ne sort pas des bords */
	if(!position_appartient_matrice(plateau, pos.x, pos.y))
		return 0;
	
	return est_un_pion(plateau.donnees[pos.y][pos.x]);
}

Plateau creer_plateau(int nbligne, int nbcolonne){
	return (Plateau) creer_matrice(nbligne, nbcolonne);
}

Plateau plateau_chargement(FILE* fichier){
	return (Plateau) matrice_chargement(fichier);
}

Couleur plateau_get(Plateau p, int i, int j){
	return p.donnees[i][j];
}

void plateau_set(Plateau p, int i, int j, Couleur c){
	p.donnees[i][j] = c;
}

Positions* plateau_determiner_chaine(Plateau plateau, Position pos, Couleur c){
	Positions* c = creer_ensemble_colores();
	Position* p;
	
	if(plateau_get(plateau, pos.y, pos.x) != c)
		return NULL;
		
	ensemble_colores_concatene
	
	pos.x++;
	if(est_un_pion_plateau(plateau, p) && plateau_get(plateau, pos.y, pos.x) == c.couleur){
		p = (Position *) malloc(sizeof(Position));
		p->x = pos.x;
		p->y = pos.y;
		
		ensemble_colores_ajouter(c, p);
	}
	
	pos.x -= 2;
	if(est_un_pion_plateau(plateau, p) && plateau_get(plateau, pos.y, pos.x) == c.couleur){
		p = (Position *) malloc(sizeof(Position));
		p->x = pos.x;
		p->y = pos.y;
		
		ensemble_colores_ajouter(c, p);
	}
	
	if(est_un_pion(plateau.donnees[pos.y+1][pos.x]))
		ajouterElement(&c, plateau.donnees[pos.y+1][pos.x]);
		
	if(est_un_pion(plateau.donnees[pos.y-1][pos]))
		ajouterElement(&c, plateau.donnees[pos.y-1][pos.x]);

}

Chaine plateau_determiner_chaine(Plateau plateau, Position pos){
	Chaine* c;
	Position p = pos;
	
	if(!position_appartient_matrice(plateau, pos.x, pos.y))
		return NULL;
	
	if(!est_un_pion(plateau.donnees[pos.y][pos.x]))
		return NULL;
	
	c = creer_ensemble_colores();
	
	c->couleur = plateau.donnees[pos.y][pos.x];
	
	
	
	
		
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
