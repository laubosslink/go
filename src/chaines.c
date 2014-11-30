/**
 * ENSICAEN
 * 6 Boulevard Marechal Juin
 * F-14050 Caen Cedex
 * 
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written premission of the authors
 */
 
/**
 * @author ELHIMDI Yasmine <elhimdi@ecole.ensicaen.fr>
 * @author PARMENTIER Laurent <parmentier@ecole.ensicaen.fr, laubosslink@society-lbl.com>
 * @version 1.1 
 * @date 03-02-2013
 */
 
/** 
 * @file chaines.c
 * 
 * @brief code source qui permet de gérer les chaines
 */
 
#include <position.h>

#include <ensemble.h>
#include <ensemble_positions.h>
#include <ensemble_colores.h>

#include <chaine.h>
#include <chaines.h>

int chaines_appartient_chaine(Chaines chaines, Chaine chaine){
	Chaine cc; /* chaine courante */
	
	if(ensemble_vide(chaines))
		return 0;
	
	if(ensemble_colores_vide(chaine))
		return 0;
	
	ensemble_colores_reset(chaine);
	ensemble_reset_courant(chaines);
	
	while(ensemble_suivant(chaines)){
		cc = ensemble_get_courant_contenu(chaines);
		
		ensemble_colores_reset(chaine);
		
		while(ensemble_colores_suivant(chaine)){
			if(ensemble_colores_appartient(cc, ensemble_colores_get_courant(chaine)))
				return 1;
			
			ensemble_colores_set_courant(chaine, ensemble_colores_get_suivant(chaine));
		}		
	
		if(ensemble_colores_appartient(cc, ensemble_colores_get_courant(chaine)))
			return 1;
		
		ensemble_set_courant(chaines, ensemble_get_suivant(chaines));
	}
	
	cc = ensemble_get_courant_contenu(chaines);
	
	ensemble_colores_reset(chaine);
	
	while(ensemble_colores_suivant(chaine)){
		if(ensemble_colores_appartient(cc, ensemble_colores_get_courant(chaine)))
			return 1;
		
		ensemble_colores_set_courant(chaine, ensemble_colores_get_suivant(chaine));
	}		

	if(ensemble_colores_appartient(cc, ensemble_colores_get_courant(chaine)))
		return 1;
	
	return 0;
}
