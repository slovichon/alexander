/* $Id$ */
#ifndef __LIBALEX_H
#define __LIBALEX_H

#include <sys/types.h>
#include <sys/socket.h>

void substr(int first, int last, char *text, char *subtext);
struct in_addr * atoaddr(char *address);

/* Wrappers */
pid_t Fork(void);
pid_t Waitpid(pid_t wpid, int *status, int options);

int Mkfifo(const char *pathname, mode_t mode);
int Unlink(const char *pathname);

int Pipe(int fd[2]);
int Open(const char *pathname, int flags, mode_t mode);
int Close(int fd);
ssize_t Read(int fd, void *buf, size_t nbytes);
ssize_t Write(int fd, void *buf, size_t nbytes);

int Socket(int family, int type, int protocol);
int Connect(int sockfd, const struct sockaddr *servaddr, socklen_t addrlen);
int Bind(int sockfd, const struct sockaddr *myaddr, socklen_t addrlen);
int Listen(int sockfd, int backlog);
int Accept(int sockfd, struct sockaddr *cliaddr, socklen_t *addrlen);

key_t Ftok(const char *pathname, int id);
ssize_t Msgrcv(int msqid, void *ptr, size_t length, long type, int flag);
int Msgget(key_t key, int oflag);
int Msgsnd(int msqid, const void *ptr, size_t length, int flag);

extern char *_prefix;

void bark(char *fmt, ...);

/* default permission */
#define DEFAULT_FILE_MODE \
	(S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

/* maximum length for read/write buffer */
#define MAXLINE 1024

typedef enum
{
	FALSE = 0,
	TRUE  = 1,
} bool_t;

#endif /* _LIBALEX_H */
