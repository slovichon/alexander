# $Id$

TARGET = libalex
OBJECTS = net.o wrapper.o vlist.o misc.o

CFLAGS = -Wall

all: $(TARGET)

$(TARGET): $(OBJECTS)

.c.o:
	$(CC) $(CFLAGS) -c $<

test: $(OBJECTS) test.o
	$(CC) $(CFLAGS) -o test $(OBJECTS) test.o

clean:
	rm -f $(OBJECTS) test
