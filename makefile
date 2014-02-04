LD_LIBRARY_PATH=$(shell pwd)

INCDIR=./include
BINDIR=./bin
LIBDIR=./lib
OBJDIR=./object
SRCDIR=./src

CC=gcc
RM=rm

LDFLAGS=-L $(LIBDIR)/ensemble/bin -L $(LIBDIR)/matrice/bin \
		-Wl,-rpath,$(LD_LIBRARY_PATH)/lib/ensemble/bin \
		-Wl,-rpath,$(LD_LIBRARY_PATH)/lib/matrice/bin

CFLAGS=-I $(INCDIR)

.PHONY: all clean

all:

##
# LIBRARIES
##

##
# Ensembles
##

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

##
# Matrice
##

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
