
Chaines captureChaines(Plateau plateau,Pion pion, int* valide){
	Chaines CC;
	Chaines chaines;
	Pion pionChaine;
	Position* voisinHaut;
	Position* voisinBas;
	Position* voisinGauche;
	Position* voisinDroite;
	Cell* tete;
	Cell* tete_chaines;
	Chaine chaine;
	Chaine chaineAdverse;
	Libertes libertes_chaine;
	Libertes libertes_chaineAdverse;
	
	chaine = plateau_determiner_chaine(plateau, pion.p);
	
	pionChaine.c = chaine.c;
	
	
	if((*valide) != 0 && (*valide) != 1 && ensemble_vide(&CC)){
		printf("Aucune chaine n'a été capturé\n");
		return;
	}
	
	if(chaine.p == NULL){
		printf("Aucune chaine n'a été capturé\n");
		return;
	}
	
	tete = (Cell*) malloc(sizeof(Cell));
	tete = ensemble_colores_tete(&chaine);
	
	tete_chaine = (Cell*) malloc(sizeof(Cell));

	pionChaine.p = (*((Position*)tete->contenu));
		
	voisinHaut = (Position*) malloc(sizeof(Position));
	voisinBas = (Position*) malloc(sizeof(Position));
	voisinGauche = (Position*) malloc(sizeof(Position));
	voisinDroite = (Position*) malloc(sizeof(Position));
	
	/* on parcours la chaine à laquelle appartient le pion pour determiner la chaine des pions adverses */
	while(ensemble_colores_suivant(&chaine)){

		(*voisinHaut) = haut(pionChaine.p);
		(*voisinBas) = bas(pionChaine.p);
		(*voisinGauche) = gauche(pionChaine.p);
		(*voisinDroite) = droite(pionChaine.p);

		
		if(plateau_position_appartient(plateau,haut(pionChaine.p)) && ensemble_appartient(&chaines,(Chaine*)&plateau_determiner_chaine(plateau,haut(pionChaine.p))) && plateau_get(plateau,haut(pionChaine.p).x,haut(pionChaine.p).y) != pionChaine.c)
			ensemble_ajouter(&chaines,(Chaine*)&plateau_determiner_chaine(plateau,(*voisinHaut)));
		
		if(plateau_position_appartient(plateau,bas(pionChaine.p)) && ensemble_appartient(&chaines,(Chaine*)&plateau_determiner_chaine(plateau,bas(pionChaine.p))) && plateau_get(plateau,bas(pionChaine.p).x,bas(pionChaine.p).y) != pionChaine.c)
			ensemble_ajouter(&chaines,(Chaine*)&plateau_determiner_chaine(plateau,(*voisinBas)));
		
		if(plateau_position_appartient(plateau,droite(pionChaine.p)) && ensemble_appartient(&chaines,(Chaine*)&plateau_determiner_chaine(plateau,droite(pionChaine.p))) && plateau_get(plateau,droite(pionChaine.p).x,droite(pionChaine.p).y) != pionChaine.c)
			ensemble_ajouter(&chaines,(Chaine*)&plateau_determiner_chaine(plateau,(*voisinDroite)));
		
		if(plateau_position_appartient(plateau,gauche(pionChaine.p)) && ensemble_appartient(&chaines,(Chaine*)&plateau_determiner_chaine(plateau,gauche(pionChaine.p))) && plateau_get(plateau,gauche(pionChaine.p).x,gauche(pionChaine.p).y) != pionChaine.c)
			ensemble_ajouter(&chaines,(Chaine*)&plateau_determiner_chaine(plateau,(*voisinGauche)));
			
		pionChaine.p = (*(Position*)(ensemble_colores_tete(&chaine)->suivant));
	}
	
	/* On determine les libertes de chacune des chaines */
	libertes_chaine = determineLiberte(plateau,chaine);
	
	tete_chaines = ensemble_tete(&chaines);
	courant_chaines = tete_chaines;
	
	while(ensemble_suivant(&chaines)){
		liberte_chaineAdverse = determineLiberte(plateau,(*chaines.courant->contenu));
		
		
		
		
	libertes_chaineAdverse = determineLiberte(plateau,chaines);
	
	/* si la chaine ne possède aucune liberté elle est capturée */
	if(ensemble_positions_vide(&libertes_chaine)){
		plateau_realiser_capture(plateau,chaine);
		ensemble_ajouter(&CC,&chaine);
		(*valide) = 0;
		return CC;
	}
	else{
		if(ensemble_positions_vide(&libertes_chaineAdverse)){
			plateau_realiser_capture(plateau,chaineAdverse);
			ensemble_ajouter(&CC,&chaineAdverse);
			(*valide) = 1;
			return CC;
		}
	}
	

	
}
