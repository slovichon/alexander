/* $Id$ */
#include "libAlex.h"
#include <sys/types.h>
#include <sys/wait.h>

/*
 * substr - takes a character array and takes
 * a portion of it and copies it to a pointer
 * that is also passed
 *
 * Arguments:
 *	first - first element of char array
 *	last - ending element of char array
 *	text - character array to be subscripted
 *	subtext - pointer to char array that will be written to
 */
void substr(int first, int last, char *text, char *subtext)
{
	int i, j = 0;

	/* bound check */
	if (i < 1)
		return;

	for(i = first; i <= last; i++)
	{
		subtext[j] = text[i - 1];
		j++;
	}
	subtext[j] = '\0';
}

/*
 * IPC wrapper functions
 *
 * Go with the W. Stevens method of capitalizing the
 * first character of the wrapper functions names.
 */
key_t Ftok(const char *pathname, int id)
{
	key_t i;

	if ((i = ftok(pathname, id)) != -1)
		return i;

	errFunction("ftok");
}

int Pipe(int fd[2])
{
	int i;

	if ((i = pipe(fd)) != -1)
		return i;

	errFunction("pipe");
}

int Mkfifo(const char *pathname, mode_t mode)
{
	int i;

	if ((i = mkfifo(pathname, mode)) != -1)
		return i;

	errFunction("mkfifo");
}

int Msgget(key_t key, int oflag)
{
	int i;

	if ((i = msgget(key, oflag)) != -1)
		return i;

	errFunction("msgget");
}

int Msgsnd(int msqid, const void *ptr, size_t length, int flag)
{
	int i;

	if ((i = msgsnd(msqid, ptr, length, flag)) != -1)
		return i;

	errFunction("msgsnd");
}

ssize_t
Msgrcv(int msqid, void *ptr, size_t length,
	long type, int flag)
{
	ssize_t i;

	if ((i = msgrcv(msqid, ptr, length, type, flag)) != -1)
		return i;

	errFunction("msgrcv");
}

/* Socket wrapper functions */
int Socket(int family, int type, int protocol)
{
	int i;

	if ((i = socket(family, type, protocol)) != -1)
		return i;

	errFunction("socket");
}

int
Connect(int sockfd, const struct sockaddr *servaddr,
	socklen_t addrlen)
{
	int i;

	if ((i = connect(sockfd, servaddr, addrlen)) != -1)
		return i;

	errFunction("connect");
}

int
Bind(int sockfd, const struct sockaddr *myaddr,
	socklen_t addrlen)
{
	int i;

	if ((i = bind(sockfd, myaddr, addrlen)) != -1)
		return i;

	errFunction("bind");
}

int Listen(int sockfd, int backlog)
{
	int i;

	if ((i = listen(sockfd, backlog)) != -1)
		return i;

	errFunction("listen");
}

int
Accept(int sockfd, struct sockaddr *cliaddr,
	socklen_t *addrlen)
{
	int i;

	if ((i = accept(sockfd, cliaddr, addrlen)) != -1)
		return i;

	errFunction("accept");
}

/* Misc. wrapper functions */
pid_t Fork(void)
{
	pid_t i;

	if ((i = fork()) != -1)
		return i;

	errFunction("fork");
}

int Close(int fd)
{
	int i;

	if ((i = close(fd)) != -1)
		return i;

	errFunction("close");
}

ssize_t Read(int fd, void *buf, size_t nbytes)
{
	ssize_t i;

	if ((i = read(fd, buf, nbytes)) != -1)
		return i;

	errFunction("read");
}

ssize_t Write(int fd, void *buf, size_t nbytes)
{
	ssize_t i;

	if ((i = write(fd, buf, nbytes)) != -1)
		return i;

	errFunction("write");
}

pid_t Waitpid(pid_t wpid, int *status, int options)
{
	pid_t i;

	if ((i = waitpid(wpid, status, options)) != -1)
		return i;

	errFunction("waitpid");
}

int Unlink(const char *pathname)
{
	int i;

	if ((i = unlink(pathname)) != -1)
		return i;

	errFunction("unlink");
}

int Open(const char *pathname, int flags, mode_t mode)
{
	int i;

	if ((i = open(pathname, flags, mode)) != -1)
		return i;

	errFunction("open");
}

/* Error functions */
/*
 * errFunction - displays errors associated with
 * calling a function, uses systems 'errno'
 */
void errFunction(char *functionName)
{
	printf("\nerror calling %s(): %s\n\n", functionName,
		strerror(errno));

	exit(1);
}
