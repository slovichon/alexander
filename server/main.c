/* $Id$ */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libalex.h"
#include "proc.h"

int debuglevel;
Proc **servers;	/* Servers handling clients */
Proc *listener;	/* Listen()-ing server */
Proc **mgt;	/* Management servers */
int servertheshold;
int mgtthreshold;

static void usage(int status);

int main(int argc, char *argv[])
{
	char ch;
	extern char *optarg;
	enum proc_model model;

	/* Initialize defaults */
	debuglevel = 0;
	serverthreshold = DEF_SERVERS;
	mgtthreshold = DEF_MGT;
	model = DEF_MODEL;

	/* Parse arguments */
	while ((ch = getopt(argc, argv, "hvs:m:t:")) != -1)
	{
		switch (ch)
		{
			case 's': /* # of client servers */
				serverthreshold = atoi(optarg);
				if ((serverthreshold < 1) ||
				    (serverthreshold > MAX_SERVERS))
					err(EXIT_USER, "Invalid number of client servers");
				break;
			case 'm': /* # of mgt servers */
				mgtthreshold = atoi(optarg);
				if ((mgtthreshold < 1) ||
				    (mgtthreshold > MAX_SERVERS))
					err(EXIT_USER, "Invalid number of management servers");
				break;
			case 'f': /* fork model */
				model = FORK_MODEL;
				break;
			case 't': /* thread model */
				model = THREAD_MODEL;
				break;
			case 'b': /* thread/fork model */
				model = BOTH_MODEL;
				break;
			case 'M':
				model = MPI_MODEL;
				break;
			case 'h':
				usage(EXIT_OK);
			case 'v':
				debuglevel++;
				break;
			default:
				usage(EXIT_USER);
		}
	}
	
	/* Set up */
	/* Map memory according to process model */
	/* Allocate server processes */
	
	/* Main loop */
	
	/* Clean up */
	/* Release global memory */
	/* Free server processes */
	
	return 0;
}

static void usage(int status)
{
	extern char *__progname;
	fprintf(stderr, "usage: %s <options>\n"
		"Consult manual page for more information.\n", __progname);
	exit(status);
}
