#
# Makefile
#
# Autor: H.Drachenfels
# Erstellt am: 30.8.2021
#

CXX = g++ -g #-fno-elide-constructors
CXXFLAGS = -Wall -Wextra -Werror -Weffc++ -Wold-style-cast -std=$(STD) -pedantic
CPPCHECK = cppcheck --enable=warning,style --std=$(STD)
STD = c++11

TARGET = grusstest
OBJECTS = \
    gruss.o \

.PHONY: all clean cppcheck

all: $(TARGET)

clean:
	rm -f $(TARGET) $(TARGET).o $(OBJECTS)

$(TARGET): $(TARGET).o $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $^

cppcheck: $(TARGET).cpp $(OBJECTS:.o=.cpp)
	$(CPPCHECK) $^

gruss.o: gruss.cpp gruss.h

