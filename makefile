LD_LIBRARY_PATH=$(shell pwd)

INCDIR=./include
BINDIR=./bin
LIBDIR=./lib
OBJDIR=./object
SRCDIR=./src

CC=gcc
RM=rm

LDFLAGS=-L $(LIBDIR)/ensemble/bin -Wl,-rpath,$(LD_LIBRARY_PATH)/lib/ensemble/bin
CFLAGS=-I $(INCDIR)

.PHONY: all clean

all:


# La librairie ensemble
libensembletest: $(LIBDIR)/ensemble/bin/test_ensemble

$(LIBDIR)/ensemble/bin/test_ensemble: $(OBJDIR)/test_ensemble.o $(LIBDIR)/ensemble/bin/libensemble.so
	$(CC) $(LDFLAGS) $< -o $@ -lensemble

$(OBJDIR)/test_ensemble.o: $(LIBDIR)/ensemble/src/test_ensemble.c
	$(CC) $(CFLAGS) -c $< -o $@

libensemble: $(LIBDIR)/ensemble/bin/libensemble.so

$(LIBDIR)/ensemble/bin/libensemble.so: $(OBJDIR)/libensemble.o
	$(CC) -shared $^ -o $@

$(OBJDIR)/libensemble.o: $(LIBDIR)/ensemble/src/ensemble.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJDIR)/*.o
