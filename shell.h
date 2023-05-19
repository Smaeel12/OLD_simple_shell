#ifndef SHELL_H
#define SHELL_H
/*---MODE---*/
void interactive_mode(int running);
void non_interactive_mode(void);

/*---MACROS---*/
extern char **environ;
#define MAX_NUM 10
#define MAX_LENGHT 256 
#define BUFFER_SIZE 1024

/*---LIBRARIES---*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/*---PROTOTYPES---*/
char *read_stdin(void);
char *read_stream(void);
char **tokeniz(char *line);
void excutcmd(char **cmd, int running);
void errors(char *s);
char *_strdup(char *s);
int _strlen(const char *s);
int _strncmp(const char *str1, const char *str2, int n);
char *_getenv(const char *name);
void error(char *s, int running);
void _itoa(int num, char *str);
char *_strcat(char *dest, char *src);
void end(char **cmd);

/*---STRUCTRES---*/
typedef struct
{
	char *name;
	void (*f)(char **cmd);
} built_in;

#endif
