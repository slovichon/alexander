# $Id$

TARGET = server
OBJECTS = server.o ../libalex.o
CFLAGS = -I..
LIBS =

.c.o:
	(cd `dirname $<` && $(CC) $(CFLAGS) -c `basename $<`)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(LIBS) -o $(TARGET) $(OBJECTS)

clean:
	rm -f $(TARGET) $(OBJECTS)
