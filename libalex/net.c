/* $Id$ */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <err.h>

#include "libalex.h"

/*
 * atoaddr - converts hostname to ip address
 *
 * Arguments:
 * 	address - char array containing hostname or IP
 */
struct in_addr *atoaddr(char *address)
{
	struct hostent *host;
	static struct in_addr saddr;

	/*
	 * If the argument was an IP address, return
	 * the IP address as in_addr.
	 */
	if ((saddr.s_addr = inet_addr(address)) != -1)
		return &saddr;

	if ((host = gethostbyname(address)) != NULL)
		return (struct in_addr *)*host->h_addr_list;

	return NULL;
}
