# $Id$

TARGET = server
OBJECTS = main.o ../libalex/net.o ../libalex/wrapper.o server.o
CFLAGS = -I../libalex -Ilibalex -Wall
LIBS =

.c.o:
	(cd `dirname $<` && $(CC) $(CFLAGS) -c `basename $<`)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(LIBS) -o $(TARGET) $(OBJECTS)

clean:
	rm -f $(TARGET) $(OBJECTS)
