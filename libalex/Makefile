# $Id$

TARGET = libalex.so
OBJECTS = misc.o net.o vlist.o wrapper.o xalloc.o

CFLAGS = -Wall

all: $(TARGET) test

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -shared -o $@ $(OBJECTS)

.c.o:
	$(CC) $(CFLAGS) -c $<

test: $(OBJECTS) test.o
	$(CC) $(CFLAGS) -o test $(OBJECTS) test.o

clean:
	rm -f $(OBJECTS) test test.o
