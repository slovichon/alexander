/* $Id$ */

#include <stdio.h>

struct _vlist
{
	void **base;	/* start address */
	size_t avail;	/* # of allocatable list slots */
};

/*
 * We have to keep a few pieces of information
 * about every list we maintain.
 */
static struct _vlist **vlists = 
{
	{ NULL, 0 }
};

vlist_init(void **base, size_t nmemb)
{
	/* Check for existance */
	/* Add maintainence record */
	{base, nmemb};
}

vlist_free(void **base)
{
	void **iter;
	/* Free list items */
	for (iter = base; *iter != NULL; iter++)
		free(*iter);
	/* Clear memory */
	free(base);

	/* Clear associated memory */
}

void vlist_ensure(void **base, size_t members)
{
	void **new;
	struct vlist *list;
	list = vlist_find(base);
	if ((list != NULL) && (list->members < members))
	{
		/* Too small, resize */
	}
}

struct vlist *vlist_find(void **base)
{
	struct vlist **iter;
	for (iter = vlists; *iter != NULL; iter++)
		if ((*iter)->base == base)
			return iter;
	return NULL;
}

vlist_add(void **base, void *item)
{
	struct vlist *list;
	vlist = vlist_find(base);
	if (vlist->members)
	{
		vlist_ensure(base, );
	}
}

vlist_remove(void **base, void *item)
{
}


#if 0
	/* Example: */
	MyType **a, *b;

	a = vlist_init();

	vlist_add(a, b);
	vlist_add(a, b);
	vlist_add(a, b);
	vlist_add(a, b);


	vlist_remove(a, b);

	vlist_free(&a);

#endif
