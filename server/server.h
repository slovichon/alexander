/* $Id$ */
#ifndef _CLIENT_H
#define _CLIENT_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "libalex.h"

struct client;
struct room;

typedef struct client Client;
typedef struct room Room;

struct client {
	char *hostname;
	in_addr_t *ip;
	char *nick;
	unsigned int modes;
};

struct room {
	Client **clients;		/* List of channel users */
	char *name;
	char *topic;
	unsigned int modes;
};

extern Client **gClients;		/* All clients connected to this server */
extern char *gMotd;			/* Message of the day */
extern bool gAdminAllow;		/* Administratively allow/deny connections */
extern size_t gNumClients;		/* Number of connected clients */

/* Client-handling functions */
int client_add(in_addr_t *, char *);	/* Add a client */
void client_remove(Client *);		/* Remove a client */
bool client_exists(char *);		/* Checks existance of nickname */

/* Group client-handling functions */
bool client_ensure_capacity(size_t);	/* Ensure capacity in gClients */
int clients_add(Client *);		/* Add client */

/* Room-handling functions */
int room_add_client(Room *, Client *);
int room_remove_client(Room *, Client *);

/* Errors */
#define E_NONE			0 	/* No error */
#define E_NO_MEM 		1 	/* No memory available */
#define E_BAD_ADDR		2 	/* Denied source address */
#define E_NICK_EXIST		3 	/* Already existant nickname */
#define E_NICK_LEN		4 	/* Nickname too long */
#define E_NICK_CHAR		5 	/* Invalid characters in nickname */
#define E_NICK_OWN		6 	/* User does not own nick */
#define E_CONN_ADMIN		7 	/* Temporary administrative deny */

/* Client mode flags */

/* Room mode flags */

#endif /* _CLIENT_H */
