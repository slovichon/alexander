#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include "libalex.h"
#include "vlist.h"

int main(int argc, char *argv[])
{
	int **a, *b, i;

	extern char *_prefix;
	_prefix = "";

	vlist_init(&a, 4, sizeof(int *));

	for (i = 0; i < 6; i++) {
		if ((b = (int *)malloc(sizeof(int))) == NULL)
			err(2, "unable to malloc()");
		*b = i;
bark("[test] adding %d", *b);
		vlist_add(&a, b);
	}

	while ((b = vlist_remove(&a)) != NULL)
		printf("Retrieved %d\n", *b);

	vlist_free(&a);

	printf("done!\n");

	return 0;
}
