# $Id$

TARGET = libalex
OBJECTS = net.o wrapper.o

$(TARGET): $(OBJECTS)

.c.o:
	$(CC) -c $<

clean:
	rm -f $(OBJECTS)
