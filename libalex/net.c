/* $Id$ */
#include <netdb.h>
#include <arpa/inet.h>

#include "libalex.h"

/*
 * atoaddr - converts hostname to ip address
 *
 * Arguments:
 * 	address - char array containing hostname or IP
 */
struct in_addr * atoaddr(char *address)
{
	struct hostent *host;
	static struct in_addr saddr;
	
	saddr.s_addr = inet_addr(address);
	if (saddr.s_addr != -1)   
		return &saddr;   /*returns if hostname conversion is not needed*/

	host = gethostbyname(address);
	if (host != NULL)
		return (struct in_addr *)*host->h_addr_list;

	return NULL;
}
