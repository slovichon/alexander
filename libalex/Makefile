# $Id$

.include "../mk/defs.mk"

TARGET = libalex.so
OBJS = misc.o net.o vlist.o wrapper.o xalloc.o
CFLAGS = -Wall
TEST = test

.include $(TARGETS_INC)

$(TARGET): $(OBJS)
	@echo -e "$(SEQ_CC)$(CC)$(SEQ_ESC) $(CFLAGS) -shared -fPIC $(SEQ_OUT)-o $(TARGET)$(SEQ_ESC) $(SEQ_ARG)$(OBJS)$(SEQ_ESC)"
	@$(CC) $(CFLAGS) -shared -fPIC -o $(TARGET) $(OBJS)
