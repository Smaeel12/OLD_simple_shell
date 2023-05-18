#include "shell.h"
/**
*/
char *find_excut(const char *cmd)
{
	char *path = _getenv("PATH");
	char *path_copy = _strdup(path);
	char *dir;
	char *excutable;
	
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		excutable = malloc(_strlen(dir) + _strlen(cmd) + 2);
		sprintf(excutable, "%s/%s", dir, cmd);

		if (access(excutable, X_OK) == 0)
		{
			free(path_copy);
			return (excutable);
		}
		free(excutable);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
void excutcmd(char **cmd)
{
	pid_t pid;
	int status;
	char *excut;
	if (cmd[0][0] == '/')
	{
		excut = cmd[0];
	}
	else
	{
		excut = find_excut(cmd[0]);
	}
	if (excut != NULL)
	{
		pid = fork();
		/* child process */
		if (pid == 0)
		{
			execve(excut, cmd, environ);
			free(excut);
			perror("execve: ");
			exit(1);
		}
		/* error forking */
		else if (pid < 0)
		{
			perror("fork: ");
		}
		else
		{
			do {
			waitpid(pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	}
	else
	{
		error("excut");
	}
}
