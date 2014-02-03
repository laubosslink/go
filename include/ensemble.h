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
