# $Id$

TARGET = server
OBJS = main.o server.o
CFLAGS = -Wall -pedantic -O2 -I../libalex
LIBS = -L../libalex -lalex

all-recurse: all

all: libalex $(TARGET)

libalex:
	(cd ../libalex && make all-recurse)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

clean-recurse: clean

clean:
	rm -f $(TARGET) $(OBJS)
