#
# Makefile
#
# Autor: H.Drachenfels
# erstellt am: 6.11.2019
#

CXX = g++ # -fno-elide-constructors
CXXFLAGS = -g -W -Wall -std=c++11 -pedantic

TARGET = htwg_string_test
OBJECTS = htwg_string.o

all: $(TARGET)

clean:
	rm -f $(TARGET) $(TARGET).o $(OBJECTS)

$(TARGET): $(TARGET).o $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

htwg_string_test.o: htwg_string_test.cpp htwg_string.h
htwg_string.o: htwg_string.cpp htwg_string.h

