#include <stdio.h>
#include <stdlib.h>
#include <libertes.h>
#include <positions.h>
#include <plateau.h>
#include <chaine.h>
#include <ensemble.h>

Libertes determineLiberte(Plateau plateau,Chaine chaine){
	Libertes L = creer_ensemblePositions();
	Cell* tete = tete(&L);
	Cell* courantChaine;
	
	tete = NULL; 
	courantChaine = tete(&chaine);
	do {
		chaine.	
	
