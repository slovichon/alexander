/* $Id$ */
#include <stdio.h>
#include <stdarg.h>
#include "libalex.h"

char *_prefix;

void bark(char *fmt, ...)
{
	va_list ap;

	fprintf(stderr, "[DEBUG] %s", _prefix);

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);

	fprintf(stderr, "\n");
	fflush(stderr);
}
