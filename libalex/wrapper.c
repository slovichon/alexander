/* $Id$ */
#include <sys/types.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>

#include "libalex.h"

/*
 * IPC wrapper functions
 *
 * Go with the W. Stevens method of capitalizing the
 * first character of the wrapper functions names.
 */
key_t Ftok(const char *pathname, int id)
{
	key_t i;
	if ((i = ftok(pathname, id)) == -1)
		err(2, "ftok");
	return i;
}

int Pipe(int fd[2])
{
	int i;
	if ((i = pipe(fd)) == -1)
		err(2, "pipe");
	return i;
}

int Mkfifo(const char *pathname, mode_t mode)
{
	int i;
	if ((i = mkfifo(pathname, mode)) == -1)
		err(2, "mkfifo");
	return i;
}

int Msgget(key_t key, int oflag)
{
	int i;
	if ((i = msgget(key, oflag)) == -1)
		err(2, "msgget");
	return i;
}

int Msgsnd(int msqid, const void *ptr, size_t length, int flag)
{
	int i;
	if ((i = msgsnd(msqid, ptr, length, flag)) == -1)
		err(2, "msgsnd");
	return i;
}

ssize_t Msgrcv(int msqid, void *ptr, size_t length, long type, int flag)
{
	ssize_t i;
	if ((i = msgrcv(msqid, ptr, length, type, flag)) == -1)
		err(2, "msgrcv");
	return i;
}

/* Socket wrapper functions */
int Socket(int family, int type, int protocol)
{
	int i;
	if ((i = socket(family, type, protocol)) == -1)
		err(2, "socket");
	return i;
}

int Connect(int sockfd, const struct sockaddr *servaddr, socklen_t addrlen)
{
	int i;
	if ((i = connect(sockfd, servaddr, addrlen)) == -1)
		err(2, "connect");
	return i;
}

int Bind(int sockfd, const struct sockaddr *myaddr, socklen_t addrlen)
{
	int i;
	if ((i = bind(sockfd, myaddr, addrlen)) == -1)
		err(2, "bind");
	return i;
}

int Listen(int sockfd, int backlog)
{
	int i;
	if ((i = listen(sockfd, backlog)) == -1)
		err(2, "listen");
	return i;
}

int Accept(int sockfd, struct sockaddr *cliaddr, socklen_t *addrlen)
{
	int i;
	if ((i = accept(sockfd, cliaddr, addrlen)) == -1)
		err(2, "accept");
	return i;
}

/* Misc. wrapper functions */
pid_t Fork(void)
{
	pid_t i;
	if ((i = fork()) == -1)
		err(2, "fork");
	return i;
}

int Close(int fd)
{
	int i;
	if ((i = close(fd)) == -1)
		err(2, "close");
	return i;
}

ssize_t Read(int fd, void *buf, size_t nbytes)
{
	ssize_t i;
	if ((i = read(fd, buf, nbytes)) == -1)
		err(2, "read");
	return i;
}

ssize_t Write(int fd, void *buf, size_t nbytes)
{
	ssize_t i;
	if ((i = write(fd, buf, nbytes)) == -1)
		err(2, "write");
	return i;
}

pid_t Waitpid(pid_t wpid, int *status, int options)
{
	pid_t i;
	if ((i = waitpid(wpid, status, options)) == -1)
		err(2, "waitpid");
	return i;
}

int Unlink(const char *pathname)
{
	int i;
	if ((i = unlink(pathname)) == -1)
		err(2, "unlink");
	return i;
}

int Open(const char *pathname, int flags, mode_t mode)
{
	int i;
	if ((i = open(pathname, flags, mode)) == -1)
		err(2, "open");
	return i;
}
