#
# Makefile
#
# Autor: Leo Tschritter
# Erstellt am: 12.06.2022
#

CC = gcc -g
CFLAGS = -Wall -Wextra -Wvla -std=$(STD) -pedantic
CPPCHECK = cppcheck --enable=warning,style --std=$(STD)
STD = c11

TARGET = \
    filecopy \
    filesize \


.PHONY: all clean cppcheck

all: $(TARGET)

clean:
	$(RM) $(TARGET)

cppcheck: $(TARGET:=.c)
	$(CPPCHECK) $^
