LD_LIBRARY_PATH=$(shell pwd)

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

CFLAGS=-I $(INCDIR)

.PHONY: all clean plateautest libensemble libmatrice libensembletest libmatricetest ensemble_colores_test

all:

##
# TESTS
##

# PLATEAU

plateautest: $(LIBDIR)/ensemble/bin/libensemble.so $(LIBDIR)/matrice/bin/libmatrice.so $(BINDIR)/plateautest

$(BINDIR)/plateautest: $(OBJDIR)/test_plateau.o $(OBJDIR)/plateau.o $(OBJDIR)/ensemble_colores.o $(OBJDIR)/libertes.o
	$(CC) $(LDFLAGS) $^ -o $@ -lensemble -lmatrice

$(OBJDIR)/test_plateau.o: $(SRCDIR)/test_plateau.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/plateau.o: $(SRCDIR)/plateau.c
	$(CC) $(CFLAGS) -c $< -o $@

# Ensembles Colores 

ensemble_colores_test: $(LIBDIR)/ensemble/bin/libensemble.so $(BINDIR)/ensemble_colores_test

$(BINDIR)/ensemble_colores_test: $(OBJDIR)/ensemble_colores.o $(OBJDIR)/test_ensemble_colores.o
	$(CC) $(LDFLAGS) $^ -o $@ -lensemble 
	
$(OBJDIR)/test_ensemble_colores.o : $(TESTDIR)/test_ensemble_colores.c
	$(CC) $(CFLAGS) -c $< -o $@


# Ensembles Positions

ensemble_positions_test: $(LIBDIR)/ensemble/bin/libensemble.so $(BINDIR)/ensemble_positions_test

$(BINDIR)/ensemble_positions_test: $(OBJDIR)/ensemble_positions.o $(OBJDIR)/test_ensemble_positions.o
	$(CC) $(LDFLAGS) $^ -o $@ -lensemble
	
$(OBJDIR)/test_ensemble_positions.o : $(TESTDIR)/test_ensemble_positions.c
	$(CC) $(CFLAGS) -c $< -o $@


#Fichiers .o

$(OBJDIR)/libertes.o: $(SRCDIR)/libertes.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/ensemble_colores.o: $(SRCDIR)/ensemble_colores.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/ensemble_positions.o : $(SRCDIR)/ensemble_positions.c
	$(CC) $(CFLAGS) -c $< -o $@

##
# LIBRARIES
##

# Ensembles

libensembletest: $(LIBDIR)/ensemble/bin/test_ensemble

$(LIBDIR)/ensemble/bin/test_ensemble: $(OBJDIR)/test_ensemble.o $(LIBDIR)/ensemble/bin/libensemble.so
	$(CC) $(LDFLAGS) $< -o $@ -lensemble

$(OBJDIR)/test_ensemble.o: $(LIBDIR)/ensemble/src/test_ensemble.c
	$(CC) $(CFLAGS) -c $< -o $@

libensemble: $(LIBDIR)/ensemble/bin/libensemble.so

$(LIBDIR)/ensemble/bin/libensemble.so: $(OBJDIR)/libensemble.o
	$(CC) -shared $^ -o $@

$(OBJDIR)/libensemble.o: $(LIBDIR)/ensemble/src/ensemble.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@


# Matrice

libmatricetest: $(LIBDIR)/matrice/bin/test_matrice

$(LIBDIR)/matrice/bin/test_matrice: $(OBJDIR)/test_matrice.o $(LIBDIR)/matrice/bin/libmatrice.so
	$(CC) $(LDFLAGS) $< -o $@ -lmatrice

$(OBJDIR)/test_matrice.o: $(LIBDIR)/matrice/src/test_matrice.c
	$(CC) $(CFLAGS) -c $< -o $@

libmatrice: $(LIBDIR)/matrice/bin/libmatrice.so

$(LIBDIR)/matrice/bin/libmatrice.so: $(OBJDIR)/libmatrice.o
	$(CC) -shared $^ -o $@

$(OBJDIR)/libmatrice.o: $(LIBDIR)/matrice/src/matrice.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

##
# Autres
##
clean:
	rm -f $(OBJDIR)/*.[o-so]
