/* $Id$ */
#include <stdlib.h>
#include <stdio.h>
#include <err.h>
#include "libalex.h"

void *xcalloc(size_t nmemb, size_t size)
{
	void *ptr;
	if ((ptr = calloc(nmemb, size)) == NULL)
		err(EXIT_SYS, "Unable to calloc()");
	return ptr;
}

void *xmalloc(size_t size)
{
	void *ptr;
	if ((ptr = malloc(size)) == NULL)
		err(EXIT_SYS, "Unable to malloc()");
	return ptr;
}

/*
 * We could additionally add code and variables to keep
 * track of all data allocated with xmalloc() and not
 * permit xfree() to free data unless it has been
 * allocated from xmalloc().
 */
void xfree(void *ptr)
{
	if (ptr)
		free(ptr);
}

void *xrealloc(void *ptr, size_t size)
{
	if ((ptr = realloc(ptr, size)) == NULL)
		err(EXIT_SYS, "Unable to realloc()");
	return ptr;
}

#if 0
void *xrecalloc(void *ptr, size_t nmemb, size_t size)
{
	void *new;
	void *olditer, *newiter;
	if ((new = calloc(nmemb, size)) == NULL)
		err(EXIT_SYS, "Unable to calloc()");
	for (olditer = ptr, newiter = new; olditer - ptr < omemb; olditer++, newiter++)
		memcpy(newiter, olditer, size);
	free(ptr);
	return new;
}
#endif
