#include "shell.h"
/**
 * main - run the program.
 * Return: 0 always.
 */
int main(int ac, char **av)
{
	(void)ac;
	if (isatty(STDIN_FILENO) == 1)
	{
		interactive_mode(av[0]);
	}
	else
	{
		non_interactive_mode(av[0]);
	}
	return (0);
}
