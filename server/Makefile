# $Id$

TARGET = server
OBJECTS = server.o
CFLAGS = -I..
LIBS =

.c.o:
	$(CC) $(CFLAGS) -c $<

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(LIBS) -o $(TARGET) $(OBJECTS)

clean:
	rm -f $(TARGET) $(OBJECTS)
