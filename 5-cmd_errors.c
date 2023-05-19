#include "shell.h"
/**
 * program - function that look for the program name.
 * Return: the program name in success, and NULL if it fails.
 */
char *program(void)
{
	char *progname = NULL;
	char buffer[BUFFER_SIZE], pid[MAX_NUM], procpath[MAX_LENGHT] = "/proc/";
	int fp;

	_itoa(getpid(), pid);
	_strcat(procpath, pid);
	_strcat(procpath, "/cmdline");

	fp = open(procpath, O_RDONLY);
	if (fp != -1)
	{
		int nb = read(fp, buffer, sizeof(progname));

		if (nb != -1)
		{
			progname = malloc(nb * sizeof(char) + 1);
			strncpy(progname, buffer, nb);
			progname[nb] = '\0';
			close(fp);
			return (progname);
		}
		close(fp);
	}
	return (NULL);
}

/**
 * error - function that handle the commands errors.
 * @s: the command.
 * @running: the number of command been running.
 */
void error(char *s, int running)
{
	char *progname = program();
	char errun[MAX_NUM];

	_itoa(running, errun);
	write(STDOUT_FILENO, progname, _strlen(progname));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, errun, _strlen(errun));
	write(STDOUT_FILENO, ": ", 2);
	perror(s);
	free(progname);
}