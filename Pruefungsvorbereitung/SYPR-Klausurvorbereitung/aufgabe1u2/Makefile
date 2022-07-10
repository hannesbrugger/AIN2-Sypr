#
# Makefile
#
# Autor: H.Drachenfels
# Erstellt am: 30.8.2021
#

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror -std=$(STD) -pedantic
CPPCHECK = cppcheck --enable=warning,style --std=$(STD)
STD = c11

TARGET = grusstest
OBJECTS = gruss.o

.PHONY: all clean

all: $(TARGET)

clean:
	rm -f $(TARGET) $(TARGET).o $(OBJECTS)

$(TARGET): $(TARGET).o $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

gruss.o: gruss.c gruss.h
grusstest.o: grusstest.c gruss.h
