# $Id$

TARGET = server
OBJECTS = main.o ../libalex.o server.o
CFLAGS = -I.. -I. -Wall
LIBS =

.c.o:
	(cd `dirname $<` && $(CC) $(CFLAGS) -c `basename $<`)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(LIBS) -o $(TARGET) $(OBJECTS)

clean:
	rm -f $(TARGET) $(OBJECTS)
