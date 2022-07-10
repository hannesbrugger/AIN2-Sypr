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

TARGET = wuerfeltest
OBJECTS = \
    wuerfel.o \
    quadrat.o \

.PHONY: all clean cppcheck

all: $(TARGET)

clean:
	rm -f $(TARGET) $(TARGET).o $(OBJECTS)

$(TARGET): $(TARGET).o $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

cppcheck: $(TARGET).c $(OBJECTS:.o=.c)
	$(CPPCHECK) $^

wuerfel.o: wuerfel.c wuerfel.h quadrat.h
quadrat.o: quadrat.c quadrat.h
wuerfeltest.o: wuerfeltest.c wuerfel.h

