#
# Makefile
#
# Erzeugt die Beispiel-Programme zur Systemprogrammierung Teil 3
#
# Autor: H.Drachenfels
# Erstellt am: 28.11.2018
#

CC=gcc
CFLAGS = -g -W -Wall -std=c11 -pedantic

TARGETS =  integer_methods.o

all: $(TARGETS)

clean:
	$(RM) $(TARGETS)

