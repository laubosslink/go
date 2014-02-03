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
 * @version 1.0 
 * @date 03-02-2013
 */
 
/** 
 * @file ensemble.h
 * 
 * structures cell et Ensemble permettant la manipulation d'ensembles
 */
 
typedef struct cell cell;
typedef struct Ensemble Ensemble;

struct cell{
	void* contenu;
	cell* suivant;
};

struct Ensemble{
	cell* courant;
	cell* tete;
};
