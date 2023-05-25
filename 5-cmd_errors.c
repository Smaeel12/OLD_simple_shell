#include "shell.h"
/**
 * error - function that handle the commands errors.
 * @status: status value.
 * @s: the command.
 * @running: the number of command been running.
 * Description: the status value define the error should prompt
   * 1: command errors (command not found...)
   * 2:	exit errors (illegal number...)
 */
void error(char *progname, int status, char **s, int running)
{
	char errun[MAX_NUM];

	_itoa(running, errun);
	write(STDOUT_FILENO, progname, _strlen(progname));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, errun, _strlen(errun));
	write(STDOUT_FILENO, ": ", 2);

	if (status == 1)
	{
		char err[] = ": not found";

		write(STDOUT_FILENO, s[0], _strlen(s[0]));
		write(STDOUT_FILENO, err, _strlen(err));
		write(STDOUT_FILENO, "\n", 1);
	}
	else if (status == 2)
	{
		char exit_err[] = "exit: Illegal number: ";

		write(STDOUT_FILENO, exit_err, _strlen(exit_err));
		write(STDOUT_FILENO, s[1], _strlen(s[1]));
		write(STDOUT_FILENO, "\n", 1);
	}

}
