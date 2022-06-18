#
# Makefile
#
# Autor: Leo Tschritter
# Erstellt am: 09.06.2022
#

SHELL = /bin/sh
CXX = g++ -g #-fno-elide-constructors
CXXFLAGS = -fPIC -Wall -Wextra -Werror -Weffc++ -Wold-style-cast -std=$(STD) -pedantic
STATIC = ar rcs
DYNAMIC = g++ -shared

STD = c++11


TARGET = lib$(LIBNAME).$(LIBTYPE)
LIBTYPE = a
LIBNAME = aufgabe6

SOURCES = \
	fachnoten_liste.cpp \
	fachnote.cpp \
	benotung.cpp \

HEADERS = $(SOURCES:.cpp=.h)
OBJECTS = $(SOURCES:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

lib$(LIBNAME).a: $(OBJECTS)
	$(STATIC) $@ $^

lib$(LIBNAME).so: $(OBJECTS)
	$(DYNAMIC) $(CXXFLAGS) $^ -o $@

clean:
	rm -f lib$(LIBNAME).a lib$(LIBNAME).so $(OBJECTS) depend

# Könnte man weglassen, wenn man auf die make-Option -R verzichten würde
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

depend: $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) -MM $(SOURCES) > $@

include depend
