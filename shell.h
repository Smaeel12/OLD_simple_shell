#ifndef SHELL_H
#define SHELL_H
/*---MODE---*/
void interactive_mode(char *progname);
void non_interactive_mode(char *progname);

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
int excutcmd(char *line, char **cmd);
void errors(char *s);
char *_strdup(char *s);
int _strlen(const char *s);
int _strncmp(const char *str1, const char *str2, int n);
char *_getenv(const char *name);
void im_error(char *progname, int status, char **s, int running);
void _itoa(int num, char *str);
char *_strcat(char *dest, char *src);
int end(char *line, char **cmd);
char *_strcpy(char *dest, char *src);
int env_print(char *line, char **cmd);
char *_strtok(char *str, char *delim);
int _getline(char **lineptr, size_t *n, FILE *stream);
int line_check(char *line);
void nim_error(char *progname, int status,char *line, char **s, int running);

/*---STRUCTRES---*/
/**
 * struct built - structure for builtins.
 * @name: name of the builtin.
 * @f: function prototype.
 */
typedef struct built
{
	char *name;
	int (*f)(char *, char **);
} built_in;

#endif
