/* $Id$ */

#ifndef _VLIST_H
#define _VLIST_H

#define DEFLISTS 5

struct vlist
{
	void **base;	/* start address */
	size_t avail;	/* # of allocatable list slots */
	size_t siz;	/* size of each list element */
};

void vlist_init(void ***base, size_t nmemb, size_t siz);
void vlist_free(void ***base);
void vlist_ensure(void ***base, size_t members);
struct vlist *vlist_find(void **base);
void vlist_add(void ***base, void *item);
size_t vlist_size(void **base);
void *vlist_remove(void ***base);
void vlist_detach(void ***base, void *item);

#endif /* _VLIST_H */
