# $Id$

ROOT = `pwd`
LIBALEX_ROOT = $(ROOT)/libalex
RM = rm -f

# Color escape sequences
SEQ_GREY   = \033[1;30m
SEQ_RM     = \033[1;31m
SEQ_CC     = \033[1;32m
SEQ_DIR    = \033[1;33m
SEQ_ARG    = \033[1;34m
SEQ_VIOLET = \033[1;35m
SEQ_OUT    = \033[1;36m
SEQ_ESC    = \033[1;0;0m

TARGETS_INC = "$(.CURDIR)/targets.mk"
