CXX = g++ -g #-fno-elide-constructors
CXXFLAGS = -fPIC -Wall -Wextra -Werror -Weffc++ -Wold-style-cast -std=$(STD) -pedantic
STD = c++11
STATIC = ar rcs
DYNAMIC = g++ -shared

TARGET = lib$(LIBNAME).$(LIBTYPE)
LIBTYPE = a
LIBNAME = aufgabe6

SOURCES = \
	benotung.cpp \
	fachnote.cpp \
	fachnoten_liste.cpp \

HEADERS = $(SOURCES:.cpp=.h)
OBJECTS = $(SOURCES:.cpp=.o)

.PHONY: all clean

all: lib$(LIBNAME).$(LIBTYPE)

clean:
	rm -f lib$(LIBNAME).a lib$(LIBNAME).so $(OBJECTS) depend

lib$(LIBNAME).a: $(OBJECTS)
	$(STATIC) $@ $^

lib$(LIBNAME).so: $(OBJECTS)
	$(DYNAMIC) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

depend: $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) -MM $(SOURCES) > $@

include depend

