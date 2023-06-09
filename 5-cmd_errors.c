#include "shell.h"
/**
 * nim_error - function that handle the non interactive mode commands errors.
 * @progname: program name.
 * @status: status value.
 * @line: command line.
 * @s: the command.
 * @running: the number of command been running.
 * Description: the status value define the error should prompt
   * 1: command errors (command not found...)
   * 2: exit errors (illegal number...)
 */
void nim_error(char *progname, int status, char *line, char **s, int running)
{
	if (status == 1)
	{
		free(line);
		free(s);
		exit(2);
	}
	if (status == 2 || status == 3)
	{
		char errun[MAX_NUM];

		_itoa(running, errun);
		write(STDERR_FILENO, progname, _strlen(progname));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, errun, _strlen(errun));
		write(STDERR_FILENO, ": ", 2);
		if (status == 2)
		{
			char err[] = ": not found";

			write(STDERR_FILENO, s[0], _strlen(s[0]));
			write(STDERR_FILENO, err, _strlen(err));
			write(STDERR_FILENO, "\n", 1);
			free(line);
			free(s);
			exit(127);
		}
		if (status == 3)
		{
			char exit_err[] = "exit: Illegal number: ";

			write(STDERR_FILENO, exit_err, _strlen(exit_err));
			write(STDERR_FILENO, s[1], _strlen(s[1]));
			write(STDERR_FILENO, "\n", 1);
			free(line);
			free(s);
			exit(2);
		}
	}
}
/**
 * im_error - function that handle the commands errors.
 * @progname: program name.
 * @status: status value.
 * @s: the command.
 * @running: the number of command been running.
 * Description: the status value define the error should prompt
   * 1: command errors (command not found...)
   * 2:	exit errors (illegal number...)
 */
void im_error(char *progname, int status, char **s, int running)
{
	char errun[MAX_NUM];

	if (status == 1)
	{
		errno = 2;
	}
	if (status == 2 || status == 3)
	{
	_itoa(running, errun);
	write(STDERR_FILENO, progname, _strlen(progname));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, errun, _strlen(errun));
	write(STDERR_FILENO, ": ", 2);
	if (status == 2)
	{
		char err[] = ": not found";

		write(STDERR_FILENO, s[0], _strlen(s[0]));
		write(STDERR_FILENO, err, _strlen(err));
		write(STDERR_FILENO, "\n", 1);
		errno = 127;
	}
	else if (status == 3)
	{
		char exit_err[] = "exit: Illegal number: ";

		write(STDERR_FILENO, exit_err, _strlen(exit_err));
		write(STDERR_FILENO, s[1], _strlen(s[1]));
		write(STDERR_FILENO, "\n", 1);
		errno = 2;
	}
	}
}
