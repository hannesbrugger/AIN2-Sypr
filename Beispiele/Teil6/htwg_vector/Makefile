#
# Makefile
#
# Autor: H.Drachenfels
# erstellt am: 11.5.2022
#

CXX = g++
CXXFLAGS = -g -Wall -Wextra -Werror -std=c++11 -pedantic

TARGET = htwg_vector_test

all: $(TARGET)

clean:
	rm -f $(TARGET) $(TARGET).o

$(TARGET): $(TARGET).o
	$(CXX) $(CXXFLAGS) -o $@ $<

htwg_vector_test.o: htwg_vector_test.cpp htwg_vector.h

