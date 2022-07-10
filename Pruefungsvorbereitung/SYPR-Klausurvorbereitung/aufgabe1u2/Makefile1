RM = rm -f
TAR = tar czf

TARGET = aufgabe1.tar.gz

SOURCES = \
	gruss.c \
	grusstest.c \

HEADERS = gruss.h

.PHONY: all clean

all: $(TARGET)

clean:
	$(RM) $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(TAR) $@ $^
