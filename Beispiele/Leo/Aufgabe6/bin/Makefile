#
# Makefile
#
# Autor: Leo Tschritter
# Erstellt am: 09.06.2022
#

CXX = g++ -g
CXXFLAGS = -I$(LIBRARY) -Wall -Wextra -Werror -std=$(STD) -pedantic
LDFLAGS = -L$(LIBRARY)
LIBRARY = ../lib/
LDLIBS = -l$(LIBNAME)
LIBNAME = aufgabe6
LIBTYPE = a
STD = c++11

TARGET = notenspiegel
HEADERS = \
	$(LIBRARY)benotung.h \
	$(LIBRARY)fachnote.h \
	$(LIBRARY)fachnoten_liste.h \

SOURCES = $(TARGET).cpp
OBJECTS = $(TARGET).o

all: $(TARGET)

$(TARGET): $(OBJECTS) $(LIBRARY)lib$(LIBNAME).$(LIBTYPE)
	$(CXX) $(LDFLAGS) $(CXXFLAGS) $< $(LDLIBS) -o $@

clean:
	rm -f $(TARGET) $(OBJECTS) depend

# Könnte man weglassen, wenn man auf die make-Option -R verzichten würde
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(LDLIBS) -c $< -o $@

depend: $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) -MM $(SOURCES) > $@

include depend
