/* $Id$ */

#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <string.h>
#include "vlist.h"
#include "libalex.h"

/* Default number of lists that is expected */
#define DEFLISTS 5

/*
 * We have to keep a few pieces of information
 * about every list we are asked to maintain.
 */
static struct vlist **vlists;

void vlist_init(void ***base, size_t nmemb, size_t siz)
{
	static bool_t initialized = FALSE;
	struct vlist *list;

	if (!initialized) {
bark("Uninitialized", vlists, DEFLISTS);
		/*
		 * Initialize internal vlist list (our list
		 * to manage information about our lists).
		 */
		initialized = TRUE;
_prefix = "[INIT] ";
		vlist_init((void ***)&vlists, DEFLISTS, sizeof(struct vlist *));
_prefix = "";
bark("@@@ INITIALIZED");
	}

#if 0
	/* Check if the list has already been initialized? */
bark("Checking for pre-existance");
	struct vlist **iter;
	for (iter = vlists; (*iter)->base != NULL; iter++)
		if ((*iter)->base == *base) {
			return FALSE;
bark("found, quitting");
		}
bark("not found, continuing");
#endif

	/* Our structure to maintain info on the list */
	if ((list = (struct vlist *)malloc(sizeof(struct vlist))) == NULL)
		err(2, "unable to malloc()");
bark("vlist_entry = malloc() = %p", list);

	/* The list of elements */
	if ((*base = (void **)calloc(nmemb, siz)) == NULL)
		err(2, "unable to calloc()");
bark("base = malloc() = %p", *base);

	/*
	 * List ends are denoted by a NULL element or when
	 * the running size reaches the available number of
	 * elements.
	 */
	**base = NULL;

	list->base = *base;
	list->avail = nmemb;
	list->siz = siz;

_prefix = "[INIT] ";
	vlist_add((void ***)&vlists, list);
_prefix = "";
}

void vlist_free(void ***base)
{
	struct vlist *list;

	/* Remove reference from our list of lists' information */
	list = vlist_find(*base);
	vlist_detach((void ***)&vlists, list);
	free(list);

	/* Free list items */
	free(*base);

	*base = NULL;
}

void vlist_ensure(void ***base, size_t newsiz)
{
	void **new, **olditer, **newiter;
	struct vlist *list;
	size_t i, total;

	list = vlist_find(*base);
	/*
	 * During initialization, the vlist_find() will return
	 * NULL, so we must compensate.
	 */
	if (list != NULL) {
		if (list->avail < newsiz) {
			/* Too small, resize */
			newsiz = (newsiz * 3) / 2;
bark("vlist too small! resizing to %d from %d", newsiz, list->avail);
			if ((new = calloc(newsiz, list->siz)) == NULL)
				err(2, "unable to calloc()");
			/*
			 * Copy pointers from the old list that was too
			 * small to the new list that has more space.
			 */
			olditer = list->base;
			newiter = new;
			total = vlist_size(list->base);
			for (i = 0; (*olditer != NULL) && (i < total);
			     newiter++, olditer++, i++)
				memmove(newiter, olditer, list->siz);
			/* Fill an empty gaps with NULL */
			if (i < total)
				*newiter = NULL;
			/*
			 * If the list that was resized was our list
			 * of information about other lists, then
			 * adjust the pointer to the new memory.
			 */
			if (vlists == (struct vlist **)list->base)
				vlists = (struct vlist **)new;
			free(list->base);
			list->base = *base = new;
			list->avail = newsiz;
bark("new vlists is %p=%p=%p", new, list->base, vlists);
		}
	}
}

/*
 * vlist_find - find the struct vlist containing information
 * about a list in our vlists list of list information.
 *
 * Note: this should probably be static, as it deals with
 * our list of information about other lists, which no one
 * should ever need.
 */
struct vlist *vlist_find(void **base)
{
	struct vlist **iter, *list;
	
	list = *vlists;
bark("searching vlists from %p for %p", vlists, base);
	for (iter = vlists;
	     (*iter != NULL) && (iter - vlists < list->avail); iter++) {
bark("comparing %p to %p", (*iter)->base, base);
		if ((*iter)->base == base) {
			return *iter;
		}
	}
bark("couldn't find list %p!", base);
	return NULL;
}

/* Add an item to a list */
void vlist_add(void ***base, void *item)
{
	size_t siz = vlist_size(*base);

bark("ADD - size for %p is %d", *base, siz);
	vlist_ensure(base, siz + 1);
	/* list = vlist_find(*base); */
	(*base)[siz] = item;
}

/*
 * vlist_size - Obtain the number of items
 * concurrently referenced in a list.
 */
size_t vlist_size(void **base)
{
	struct vlist *list;
	void **p;
	size_t nmemb = 0;

	list = vlist_find(base);
	if (list == NULL) {
bark("list not found!");
		nmemb = 0;
	} else {
		for (p = list->base; (*p != NULL) && nmemb < list->avail; p++)
			nmemb++;
bark("size for list %p is %d (avail %d)", list->base, nmemb, list->avail);
	}
	return nmemb;
}

/*
 * Obtain an element stored in a list, and remove the
 * reference to the element.
 */
void *vlist_remove(void ***base)
{
	struct vlist *list;
	void *item = NULL;
	int pos;

	list = vlist_find(*base);
	pos = -1 + vlist_size(*base);

	if (pos >= 0) {
bark("trying to remove element in pos %d", pos);
		item = list->base[pos];
		list->base[pos] = NULL;

		/*
		 * See if size reduction meets threshold to
		 * reclaim wasted/extra allocated list memory.
		 */
	}

	return item;
}

/* Remove the reference of an item from a list */
void vlist_detach(void ***base, void *item)
{
	void **iter;
	struct vlist *list;
	int pos;

	list = vlist_find(*base);
	for (iter = list->base;
	     (*iter != NULL) && (iter - list->base < list->avail); iter++)
		if (*iter == item) {
			/*
			 * Found item, move end of list to new space
			 * and our remove reference to it.
			 */
			pos = -1 + vlist_size(list->base);
			*iter = list->base[pos];
			list->base[pos] = NULL;
			break;
		}
}
