/* $Id$ */
#include "libalex.h"
#include "server.h"



/* Inspects the pool service availability */
void pool_inspect()
{
	HANDLER **busy, **idle;
	/* Redelegate clients */
	/* Allocate more handlers */
	/* Free handlers */
}

void pool_resize(size_t siz)
{
	HANDLER **new, **olditer, **newiter;
	new = calloc(siz, sizeof(HANDLER));
	for (newiter = new, olditer = handlers; *olditer != NULL; newiter++, olditer++)
		memmove(newiter, olditer, sizeof(HANDLER *));
	free(handlers);
	handlers = new;
}
