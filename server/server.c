/* $Id$ */
#include <string.h>
#include <stdlib.h>

#include "server.h"

/* Initialize client list */
Client **gClients = NULL;

/*
 * This variable contains the number of concurrently
 * allocatable clients. clients_num() will determine
 * the number of actually connected clients.
 */
size_t gAvailClients = 0;
bool_t gAdminAllow = TRUE;

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
	if (client->nick == NULL)
	{
		client_remove(client);
		return E_NO_MEM;
	}

	/* Add global reference */
	if ((error = clients_add(client)) != E_NONE)
	{
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

	/* Remove all references/mem/etc. to client */
	clients_remove(client);

	/* Remove client memory */
	free(client);
}

bool_t client_exists(char *nick)
{
	int i;
	for (i = 0; i < clients_num(); i++)
		if (strcasecmp(gClients[i]->nick, nick) == 0)
			return TRUE;
	return FALSE;
}

/* Group client-handling functions */
int clients_resize(size_t tsiz)
{
	Client **new, **iter;
	int i;

#if 0
	/* Check for difference */
	if (tsiz <= gAvailClients)
		return E_NONE;
#endif

	/* Allocate new mem */
	if ((new = calloc(tsiz, sizeof(Client *))) != NULL)
#if 0
		err("couldn't malloc()");
#endif
		return E_NO_MEM;

	/* Copy clients' refs to new list */
	for (i = 0, iter = new; i < clients_num(); iter++, i++)
		memmove(*iter, gClients[i], sizeof(Client *));
	/* Append null entry to end of list */
	*iter = NULL;
	free(gClients);
	gClients = new;
	gAvailClients = tsiz;

	return E_NONE;
}

void client_ensure_capacity(size_t size)
{
	if (size < gAvailClients)
		clients_resize(size);
}

size_t clients_num(void)
{
	int i;
	size_t num = 0;
	for (i = 0; i < clients_num(); i++)
		num++;
	return num;
}

int clients_add(Client *client)
{
	return TRUE;
}

void clients_remove(Client *client)
{
	Client **last, **iter, **target;

	/* Remove client reference in global clients memory */
	last = NULL;
	target = NULL;
	for (iter = gClients; (iter != NULL) && (*iter != NULL); last = iter++)
		if (*iter == client)
			target = iter;
	if (target != NULL)
	{
		if (last == NULL)
		{
			/* Remove last client */
			*target = NULL;
		} else {
			/* Swap target with last */
			*target = *last;
			*last = NULL;
		}
	}
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
