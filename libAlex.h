/*******************libAlex.h************/
#ifndef __LIBALEX_H
#define __LIBALEX_H

/*headers*/
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>   //byte manipulation
#include <string.h>
#include <time.h>      //i love rand
#include <sys/ipc.h>
#include <sys/stat.h>  
#include <sys/msg.h>   //system V message queues 
#include <sys/sem.h>   //system V semaphores
#include <sys/shm.h>   //system V shared memory
#include <sys/types.h>
#include <unistd.h>    //pipes
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <netinet/in.h>   //byte order conversion
#include <arpa/inet.h>
#include <sys/socket.h>  //sockets

/*prototypes*/
void substr(int first, int last, char *text, char *subtext);
key_t Ftok(const char *pathname, int id);
int Pipe(int fd[2]);
pid_t Fork(void);
int Close(int fd);
ssize_t Read(int fd, void *buf, size_t nbytes);
ssize_t Write(int fd, void *buf, size_t nbytes);
pid_t Waitpid(pid_t wpid, int *status, int options);
int Mkfifo(const char *pathname, mode_t mode);
int Unlink(const char *pathname);
int Open(const char *pathname, int flags, mode_t mode);
void errFunction(char *functionName);
int Msgget(key_t key, int oflag);
int Msgsnd(int msqid, const void *ptr, size_t length, int flag);
ssize_t Msgrcv(int msqid, void *ptr, size_t length, long type, int flag);
int Socket(int family, int type, int protocol);
int Connect(int sockfd, const struct sockaddr *servaddr, socklen_t addrlen);
int Bind(int sockfd, const struct sockaddr *myaddr, socklen_t addrlen);
int Listen(int sockfd, int backlog);
int Accept(int sockfd, struct sockaddr *cliaddr, socklen_t *addrlen);

/*Defines*/
#define DEFAULT_FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)  //default permission
#define MAXLINE 1024  //maximum length for read/write buffer

#endif
