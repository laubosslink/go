#include <matrice.h>

int main(){
	Matrice m;
	
	m = initMatrice("extra/plateau_initiale.txt");
	
	afficheMatrice(m);
	
	m.donnees[1][1] = BLANC;
	
	printf("\n");
	
	afficheMatrice(m);
	
	return 0;
}
