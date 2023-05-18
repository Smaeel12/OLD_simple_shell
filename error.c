#include "shell.h"
#define MAX_LENGHT 100
/**
 *
 */
char *program(void)
{
	char procpath[100];
	/*char pid[10];*/
	int fp;
	char progname[1024];

	/*
	pid_t ppid = getpid();
	strcat(procpath, "/proc/");
	_itoa (ppid, pid);
	printf("%i\n", ppid); 
	strcat(procpath, pid);
	strcat(procpath, "/cmdline");
	printf("\n%s\n", procpath);
	*/
	
	snprintf(procpath, 100, "/proc/%d/cmdline", getpid());
	fp = open(procpath, O_RDONLY);
	if (fp != -1)
	{
		int nb = read(fp, progname, sizeof(progname));
		if (nb != -1)
		{
			char *ptrname = progname;
			return (ptrname);
		}
	}
	return (NULL);
}
void error(char *s)
{
	char *progname = program();
	int len = _strlen(progname);

	if (progname == NULL)
	{
		printf("FUCCCK\n");
	}
	write(STDOUT_FILENO, progname, len);
	write(STDOUT_FILENO, ": ", 2);
	perror(s);
}
