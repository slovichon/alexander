# $Id$

.c.o:
	@echo -e "$(SEQ_CC)$(CC)$(SEQ_ESC) $(CFLAGS) -c $(SEQ_ARG)`basename $<`$(SEQ_ESC)"
	@(cd `dirname $<` && $(CC) $(CFLAGS) -c `basename $<`)

all:
	if [ "$(TARGET)" ]; then					\
		@echo -e "Making $@ in $(SEQ_DIR)$(.CURDIR)$(SEQ_ESC)";	\
		@make all-recurse $(TARGET);				\
	fi

$(TARGET): $(OBJS)
	@echo -e "$(SEQ_CC)$(CC)$(SEQ_ESC) $(LIBS) $(SEQ_OUT)-o $(TARGET)$(SEQ_ESC) $(SEQ_ARG)$(OBJS)$(SEQ_ESC)"
	@$(CC) $(LIBS) -o $(TARGET) $(OBJS)

clean:
	@echo -e "Making $@ in $(SEQ_DIR)$(.CURDIR)$(SEQ_ESC)"
	@make clean-recurse
	@if [ "$(TARGET)$(OBJECTS)" ]; then \
		echo -e '$(SEQ_RM)$(RM)$(SEQ_ESC) $(SEQ_OUT)$(TARGET)$(SEQ_ESC) $(SEQ_ARG)$(OBJS)$(SEQ_ESC)'; \
		$(RM) $(TARGET) $(OBJS); \
	fi

test: $(TARGET) $(TEST)
	@echo -e "$(SEQ_CC)$(CC)$(SEQ_ESC) $(CFLAGS) -o $(SEQ_OUT)$(TEST)$(SEQ_ESC)"
	@$(CC) $(CFLAGS) -o $(TEST)

test-clean:
	@echo -e "$(SEQ_RM)$(RM)$(SEQ_ESC) $(SEQ_OUT)$(TEST)$(SEQ_ESC)"
	@$(RM) $(TEST)

all-recurse:
	@for i in $(SUBDIRS); do 			\
		(cd $$i && env MAKEHIER="$$i" make $@);	\
	done

clean-recurse:
	@for i in $(SUBDIRS); do 			\
		(cd $$i && env MAKEHIER="$$i" make $@);	\
	done
