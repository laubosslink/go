#include <position.h>

Position* position_creer(int x, int y){
		Position* p = (Position *) malloc(sizeof(Position));
		
		p->x = x;
		p->y = y;
		
		return p;
}

Position haut(Position p){
	p.y--;
	
	return p;
}

Position bas(Position p){
	p.y++;
	
	return p;
}

Position gauche(Position p){
	p.x--;
	
	return p;
}

Position droite(Position p){
	p.x++;
	
	return p;
}
