# $Id$

TARGET = libalex.so.1.0
OBJS = misc.o net.o vlist.o wrapper.o xalloc.o
CFLAGS = -Wall -pedantic -O2
TEST = test
LIBS = -L. -lalex

all-recurse: all

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -shared -fPIC -o $(TARGET) $(OBJS)

clean-recurse: clean

clean:
	rm -f $(TARGET) $(OBJS) $(TEST)
