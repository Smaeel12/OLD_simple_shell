#include "shell.h"
/**
 * exit
 */
void end(char **cmd)
{
	free(cmd);
	exit(EXIT_SUCCESS);
}
