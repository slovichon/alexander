/* $Id$ */
#include <string.h>
#include <stdlib.h>

#include "server.h"

/* Initialize client list */
Client **gClients = NULL;
bool gAdminAllow = TRUE;

/* Client-handling functions */
int client_add(in_addr_t *ip, char *nick)
{
	Client *client;
	int error;

	/* Check existance */
	if (client_exists(nick))
		return E_NICK_EXIST;

	/* Permittance */
	if (gAdminAllow == FALSE)
		return E_CONN_ADMIN;

#if 0
	/* Nickname permittance */
	if (connecting IP is valid for nick)
		return E_NICK_OWN;
#endif

	/* Allocate client memory */
	client = (Client *)malloc(sizeof(Client));
	if (client == NULL)
		return E_NO_MEM;

	/* Initialize */
	client->ip = NULL;
	client->modes = 0;
	client->nick = NULL;
	client->hostname = NULL;

#if 0
	/* Lookup hostname */
	client->ip = inet_ntoa(ip);
	client->hostname = inet_aton(ip);
#endif

	/* Fill out nickname */
	client->nick = strdup(nick);
	if (client->nick == NULL) {
		client_remove(client);
		return E_NO_MEM;
	}

	/* Add global reference */
	if ((error = clients_add(client)) != E_NONE) {
		client_remove(client);
		return error;
	}

	return TRUE;
}

void client_remove(Client *client)
{
	/* Remove member memory */
	if (client->ip != NULL)
		free(client->ip);
	if (client->hostname != NULL)
		free(client->hostname);
	if (client->nick != NULL)
		free(client->nick);

	/* Remove client memory */
	free(client);

#if 0
NOTE - USE clients_remove()

	Client **last, **iter, **target;

	/* Remove client reference in global clients memory */
	last = NULL;
	target = NULL;
	for (iter = gClients; (iter != NULL) && (*iter != NULL); last = iter++)
		if (*iter == client)
			target = iter;
	if (target != NULL)
		if (last == NULL) {
			/* Remove last client */
			*target = NULL;
		} else {
			/* Swap target with last */
			*target = *last;
			*last = NULL;
		}
#endif
}

bool client_exists(char *nick)
{
	Client **iter;
	for (iter = gClients; (iter != NULL) && (*iter != NULL); iter++)
		if (strcasecmp((*iter)->nick, nick) == 0)
			return TRUE;
	return FALSE;
}

/* Group client-handling functions */
int clients_resize(size_t target_size)
{
	Client **new, **old_iter, **new_iter;
	size_t current_size = clients_num();

	/* Check for difference */
	if (target_size == current_size)
		return E_NONE;

	/* Allocate new mem */
	if ((new = calloc(target_size, sizeof(Client *))) != NULL)
		return E_NO_MEM;

	/* Copy memory */
	new_iter = new;
	for (old_iter = gClients;
	     (old_iter != NULL) && (*old_iter != NULL);
	     old_iter++, new_iter++)
		memmove(*new_iter, *old_iter, sizeof *old_iter);
	if (gClients != NULL)
		free(gClients);
	gClients = new;

	return E_NONE;
}

size_t clients_num(void)
{
	Client **iter;
	size_t clients = 0;
	for (iter = gClients; (iter != NULL) && (*iter != NULL); iter++)
		clients++;
	return clients;
}

bool client_capacity(size_t size)
{
	return TRUE;
}

int clients_add(Client *client)
{
	return TRUE;
}

void clients_remove(Client *client)
{
}

/* Room-handling functions */
int room_add_client(Room *room, Client *client)
{
	return TRUE;
}

int room_remove_client(Room *room, Client *client)
{
	return TRUE;
}
