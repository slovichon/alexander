# $Id$

SUBDIRS = libalex client server

all-recurse:
	@for i in $(SUBDIRS); do 		\
		echo "Making clean in $$i";	\
		(cd $$i && make $@);		\
	done

all: all-recurse

test-recurse:
	@for i in $(SUBDIRS); do 		\
		echo "Making test in $$i";	\
		(cd $$i && make $@);		\
	done

test: all test-recurse

clean-recurse:
	@for i in $(SUBDIRS); do 		\
		echo "Making clean in $$i";	\
		(cd $$i && make $@);		\
	done

clean: clean-recurse
