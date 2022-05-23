#
# Makefile
#
# Autor: H.Drachenfels
# Erstellt am: 11.2.2021
#

#----------------------------------- Kommando-Variablen
CC = gcc
CPPFLAGS = -I.
CFLAGS = -Wall -Wextra -Werror -std=c11 -pedantic
RM = rm -f

#--------------------------------------- Hilfsvariablen
TARGET = hallo
OBJECTS = gruss.o
SOURCES = $(TARGET).c $(OBJECTS:.o=.c)
HEADERS = $(OBJECTS:.o=.h)

#----------------------------------------- Musterregeln
%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

#---------------------------------------- Standardziele
.PHONY: all clean

all: $(TARGET)

clean:
	$(RM) $(TARGET) $(TARGET).o $(OBJECTS) depend

depend: $(SOURCES) $(HEADERS)
	$(CC) $(CPPFLAGS) -MM $(SOURCES) > $@

#------------------------- Ziele zur Programmerstellung
$(TARGET): $(TARGET).o $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

#-------------------------------------- Abhaengigkeiten
include depend

