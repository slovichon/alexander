SUBDIRS = libalex client server

all: all-recurse

all-recurse:
	@for i in $(SUBDIRS); do 		\
		(cd $$i && make all)		\
	done

clean: clean-recurse

clean-recurse:
	@for i in $(SUBDIRS); do 		\
		(cd $$i && make clean)		\
	done
