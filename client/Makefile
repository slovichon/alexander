# $Id$

TARGET = client
OBJS = main.o
CFLAGS = -Wall -pedantic -O2 -I../libalex
LIBS = -L../libalex -lalex

all-recurse: all

all: libalex $(TARGET)

libalex:
	(cd ../libalex && make all-recurse)

$(TARGET): $(OBJS)
	$(CC) $(LIBS) -o $(TARGET) $(OBJS)

clean-recurse: clean

clean:
	rm -f $(TARGET) $(OBJS)
