/* $Id$ */
#include <stdio.h>
#include <unistd.h>
#include "libalex.h"

int debuglevel;

void usage(int status);

int main(int argc, char *argv[])
{
	char ch;

	/* Initialize defaults */
	debuglevel = 0;

	/* Parse arguments */
	while ((ch = getopt(argc, argv, "hv")) != -1)
	{
		switch (ch)
		{
			case 'h':
				usage(0);
			case 'v':
				debuglevel++;
				break;
			default:
				usage(1);
		}
	}
	
	/* Set up */
	
	/* Main loop */
	
	/* Clean up */
	
	return 0;
}

void usage(int status)
{
	extern char *__progname;
	fprintf(stderr, "usage: %s <options>\n"
		"Consult manual page for more information.\n", __progname);
	exit(status);
}
