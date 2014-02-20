LD_LIBRARY_PATH=$(shell pwd)

DEBUG=0

INCDIR=./include
BINDIR=./bin
LIBDIR=./lib
OBJDIR=./object
SRCDIR=./src
TESTDIR= ./test

CC=gcc
RM=rm

LDFLAGS=-L $(LIBDIR)/ensemble/bin -L $(LIBDIR)/matrice/bin \
		-Wl,-rpath,$(LD_LIBRARY_PATH)/lib/ensemble/bin \
		-Wl,-rpath,$(LD_LIBRARY_PATH)/lib/matrice/bin

CFLAGS=-I $(INCDIR) -DDEBUG_AFFICHE=$(DEBUG)

.PHONY: all go doc tests \
		test_plateau test_libensemble test_libmatrice ensemble_colores_test \
		libensemble libmatrice \
		clean distclean

all: go

go: libensemble libmatrice $(BINDIR)/go

$(BINDIR)/go: $(OBJDIR)/go.o $(OBJDIR)/partie.o $(OBJDIR)/plateau.o \
			  $(OBJDIR)/ensemble_colores.o $(OBJDIR)/position.o \
			  $(OBJDIR)/ensemble_positions.o $(OBJDIR)/libertes.o \
			  $(OBJDIR)/chaines.o $(OBJDIR)/pion.o
			  
	$(CC) $(LDFLAGS) $^ -o $@ -lensemble -lmatrice

doc:
	doxygen doxygen_config

##
#Fichiers SRCDIR/*.c vers OBJDIR/*.o
##

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

##
# TESTS
##

# Permet d'appliquer l'ensemble des tests
tests: test_libmatrice test_libensemble test_ensemble_colores test_chaines_appartient_chaine \
		test_plateau test_determine_chaine test_determine_territoire test_entoure_territoire test_determine_libertes \
		test_capture_chaines
	@$(LIBDIR)/matrice/bin/test_libmatrice
	@$(LIBDIR)/ensemble/bin/test_libensemble
	@$(BINDIR)/test_ensemble_colores
	@$(BINDIR)/test_chaines_appartient_chaine
	@$(BINDIR)/test_plateau
	@$(BINDIR)/test_determine_chaine
	@$(BINDIR)/test_determine_territoire
	@$(BINDIR)/test_entoure_territoire
	@$(BINDIR)/test_determine_libertes
	@$(BINDIR)/test_capture_chaines
	

# entoire_territoire

test_entoure_territoire: libmatrice libensemble $(BINDIR)/test_entoure_territoire

$(BINDIR)/test_entoure_territoire: $(OBJDIR)/test_entoure_territoire.o \
										  $(OBJDIR)/position.o $(OBJDIR)/ensemble_positions.o \
										  $(OBJDIR)/ensemble_colores.o $(OBJDIR)/chaines.o \
										  $(OBJDIR)/pion.o $(OBJDIR)/plateau.o \
										  $(OBJDIR)/libertes.o $(OBJDIR)/territoire.o
										  
	$(CC) $(LDFLAGS) $^ -o $@ -lensemble -lmatrice

$(OBJDIR)/test_entoure_territoire.o: $(TESTDIR)/test_entoure_territoire.c
	$(CC) $(CFLAGS) -c $< -o $@	

# determine_chaine

test_determine_chaine: libmatrice libensemble $(BINDIR)/test_determine_chaine

$(BINDIR)/test_determine_chaine: $(OBJDIR)/test_determine_chaine.o \
										  $(OBJDIR)/position.o $(OBJDIR)/ensemble_positions.o \
										  $(OBJDIR)/ensemble_colores.o $(OBJDIR)/chaines.o \
										  $(OBJDIR)/pion.o $(OBJDIR)/plateau.o \
										  $(OBJDIR)/libertes.o
										  
	$(CC) $(LDFLAGS) $^ -o $@ -lensemble -lmatrice

$(OBJDIR)/test_determine_chaine.o: $(TESTDIR)/test_determine_chaine.c
	$(CC) $(CFLAGS) -c $< -o $@

# determine_libertes

test_determine_libertes: libmatrice libensemble $(BINDIR)/test_determine_libertes

$(BINDIR)/test_determine_libertes: $(OBJDIR)/test_determine_libertes.o \
										  $(OBJDIR)/position.o $(OBJDIR)/ensemble_positions.o \
										  $(OBJDIR)/ensemble_colores.o $(OBJDIR)/chaines.o \
										  $(OBJDIR)/plateau.o $(OBJDIR)/libertes.o $(OBJDIR)/pion.o 
										  
	$(CC) $(LDFLAGS) $^ -o $@ -lensemble -lmatrice

$(OBJDIR)/test_determine_libertes.o: $(TESTDIR)/test_determine_libertes.c
	$(CC) $(CFLAGS) -c $< -o $@

# chaines_appartient_chaine

test_chaines_appartient_chaine: libmatrice libensemble $(BINDIR)/test_chaines_appartient_chaine

$(BINDIR)/test_chaines_appartient_chaine: $(OBJDIR)/test_chaines_appartient_chaine.o \
										  $(OBJDIR)/position.o $(OBJDIR)/ensemble_positions.o \
										  $(OBJDIR)/ensemble_colores.o $(OBJDIR)/chaines.o
										  
	$(CC) $(LDFLAGS) $^ -o $@ -lensemble -lmatrice

$(OBJDIR)/test_chaines_appartient_chaine.o: $(TESTDIR)/test_chaines_appartient_chaine.c
	$(CC) $(CFLAGS) -c $< -o $@


# captureChaines
test_capture_chaines: libmatrice libensemble $(BINDIR)/test_capture_chaines

$(BINDIR)/test_capture_chaines: $(OBJDIR)/test_capture_chaines.o \
										  $(OBJDIR)/position.o $(OBJDIR)/ensemble_positions.o \
										  $(OBJDIR)/ensemble_colores.o $(OBJDIR)/chaines.o \
										  $(OBJDIR)/plateau.o $(OBJDIR)/pion.o \
										  $(OBJDIR)/libertes.o
										  
	$(CC) $(LDFLAGS) $^ -o $@ -lensemble -lmatrice

$(OBJDIR)/test_capture_chaines.o: $(TESTDIR)/test_capture_chaines.c
	$(CC) $(CFLAGS) -c $< -o $@

# Territoire

test_determine_territoire: libmatrice libensemble $(BINDIR)/test_determine_territoire

$(BINDIR)/test_determine_territoire: $(OBJDIR)/test_determine_territoire.o $(OBJDIR)/territoire.o \
						   $(OBJDIR)/position.o $(OBJDIR)/plateau.o $(OBJDIR)/ensemble_colores.o  \
						   $(OBJDIR)/chaines.o $(OBJDIR)/libertes.o  $(OBJDIR)/ensemble_positions.o \
						   $(OBJDIR)/pion.o
						   
	$(CC) $(LDFLAGS) $^ -o $@ -lensemble -lmatrice

$(OBJDIR)/test_determine_territoire.o: $(TESTDIR)/test_determine_territoire.c
	$(CC) $(CFLAGS) -c $< -o $@

# Plateau

test_plateau: libmatrice libensemble $(BINDIR)/test_plateau

$(BINDIR)/test_plateau: $(OBJDIR)/test_plateau.o $(OBJDIR)/plateau.o $(OBJDIR)/ensemble_colores.o \
						$(OBJDIR)/libertes.o $(OBJDIR)/position.o $(OBJDIR)/ensemble_positions.o  \
						$(OBJDIR)/chaines.o $(OBJDIR)/pion.o 
						
	$(CC) $(LDFLAGS) $^ -o $@ -lensemble -lmatrice

$(OBJDIR)/test_plateau.o: $(TESTDIR)/test_plateau.c
	$(CC) $(CFLAGS) -c $< -o $@

# Ensembles Colores 

test_ensemble_colores: $(LIBDIR)/ensemble/bin/libensemble.so $(BINDIR)/test_ensemble_colores 

$(BINDIR)/test_ensemble_colores: $(OBJDIR)/ensemble_colores.o $(OBJDIR)/test_ensemble_colores.o $(OBJDIR)/position.o
	$(CC) $(LDFLAGS) $^ -o $@ -lensemble 
	
$(OBJDIR)/test_ensemble_colores.o : $(TESTDIR)/test_ensemble_colores.c
	$(CC) $(CFLAGS) -c $< -o $@


# Ensembles Positions

test_ensemble_positions: $(LIBDIR)/ensemble/bin/libensemble.so $(BINDIR)/test_ensemble_positions

$(BINDIR)/test_ensemble_positions: $(OBJDIR)/ensemble_positions.o $(OBJDIR)/test_ensemble_positions.o
	$(CC) $(LDFLAGS) $^ -o $@ -lensemble
	
$(OBJDIR)/test_ensemble_positions.o : $(TESTDIR)/test_ensemble_positions.c
	$(CC) $(CFLAGS) -c $< -o $@


##
# LIBRARIES
##

# Ensembles

libensemble: $(LIBDIR)/ensemble/bin/libensemble.so

$(LIBDIR)/ensemble/bin/libensemble.so: $(OBJDIR)/libensemble.o
	$(CC) -shared $^ -o $@

$(OBJDIR)/libensemble.o: $(LIBDIR)/ensemble/src/ensemble.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

test_libensemble: $(LIBDIR)/ensemble/bin/test_libensemble

$(LIBDIR)/ensemble/bin/test_libensemble: $(OBJDIR)/test_libensemble.o $(LIBDIR)/ensemble/bin/libensemble.so
	$(CC) $(LDFLAGS) $< -o $@ -lensemble

$(OBJDIR)/test_libensemble.o: $(LIBDIR)/ensemble/test/test_ensemble.c
	$(CC) $(CFLAGS) -c $< -o $@

# Matrice

libmatrice: $(LIBDIR)/matrice/bin/libmatrice.so

$(LIBDIR)/matrice/bin/libmatrice.so: $(OBJDIR)/libmatrice.o
	$(CC) -shared $^ -o $@

$(OBJDIR)/libmatrice.o: $(LIBDIR)/matrice/src/matrice.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

test_libmatrice: $(LIBDIR)/matrice/bin/test_libmatrice

$(LIBDIR)/matrice/bin/test_libmatrice: $(OBJDIR)/test_libmatrice.o $(LIBDIR)/matrice/bin/libmatrice.so
	$(CC) $(LDFLAGS) $< -o $@ -lmatrice

$(OBJDIR)/test_libmatrice.o: $(LIBDIR)/matrice/test/test_matrice.c
	$(CC) $(CFLAGS) -c $< -o $@
	
##
# Autres
##
clean:
	rm -f $(OBJDIR)/*.[o-so]

distclean: clean
	rm -f bin/*
	rm -f lib/*/bin/*
