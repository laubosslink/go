INCDIR=include/
BINDIR=bin/
LIBDIR=lib/
OBJDIR=object/
SRCDIR=src/

CC=gcc
RM=rm

CFLAGS=-I $(INCDIR)

.PHONY: all clean

all:

clean:
	rm -f $(OBJDIR)/*.o
