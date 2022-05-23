#
# Makefile
#
# Autor: H.Drachenfels
# erstellt am: 26.4.2017
#

CXX = g++
CXXFLAGS = -g -W -Wall -std=c++11

TARGET = htwg_array_test

all: $(TARGET)

clean:
	rm -f $(TARGET) $(TARGET).o

$(TARGET): $(TARGET).o
	$(CXX) $(CXXFLAGS) -o $@ $<

htwg_array_test.o: htwg_array_test.cpp htwg_array.h

