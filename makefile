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

.PHONY: all go \
		test_plateau test_libensemble test_libmatrice ensemble_colores_test \
		libensemble libmatrice \
		clean distclean

all: go

go: $(BINDIR)/go

$(BINDIR)/go: $(SRCDIR)/go.o $(OBJDIR)/partie.o $(OBJDIR)/plateau.o $(OBJDIR)/ensemble_colores.o
	$(CC) $(LDFLAGS) $^ -o $@ -lensemble -lmatrice

##
#Fichiers SRCDIR/*.c vers OBJDIR/*.o
##

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

##
# TESTS
##

# Plateau

test_plateau: $(LIBDIR)/ensemble/bin/libensemble.so $(LIBDIR)/matrice/bin/libmatrice.so $(BINDIR)/test_plateau

$(BINDIR)/test_plateau: $(OBJDIR)/test_plateau.o $(OBJDIR)/plateau.o $(OBJDIR)/ensemble_colores.o $(OBJDIR)/libertes.o $(OBJDIR)/position.o
	$(CC) $(LDFLAGS) $^ -o $@ -lensemble -lmatrice

$(OBJDIR)/test_plateau.o: $(TESTDIR)/test_plateau.c
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
