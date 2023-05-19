#include "shell.h"
/**
 * excut_cmd - 
 */
void excut_cmd(char *path, char **cmd)
{
	int status;
	pid_t pid = fork();

	if (pid == 0)
	{
		execve(path, cmd, environ);
		perror("execve");
		exit(1);
	}
	else if (pid < 0)
	{
		perror("fork");
	}
	else
	{
		do {
		waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
/**
 * access_path -
 */
int access_path(const char *cmd)
{
	int result = access(cmd, X_OK);
	if (result == 0)
	{
		return (0);
	}
	return (1);
}
/**
 * find_excut - function that look for commands.
 * @cmd: the command.
 * Return: the path to the command if it exist, and NULL if its not.
 */
char *find_command_path(const char *cmd)
{
	char *path = _getenv("PATH");
	char *path_copy = _strdup(path);
	char *dir;
	char *excutable;
	int result;

	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		excutable = malloc(_strlen(dir) + _strlen(cmd) + 2);
		sprintf(excutable, "%s/%s", dir, cmd);
		result = access_path(excutable);
		if (result == 0)
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

/**
 * excutcmd - function that excut the commands.
 * @cmd: the commands.
 * @running: number of commands been running.
 */
void excutcmd(char **cmd, int running)
{
	char *path;
	int i;
	built_in builtin_cmds[] = {
		{"exit", end},
		{NULL, NULL}
		};

	/* check if its a builtin command */
	for (i = 0; builtin_cmds[i].name != NULL; i++)
	{
		i = _strncmp(cmd[0], builtin_cmds[i].name, _strlen(builtin_cmds[i].name));
		if (i == 0)
		{
			builtin_cmds[i].f(cmd);
		}
		else
		{
			break;
		}
	}

	/* the path of the command */
	if (cmd[0][0] == '/')
	{
		int result = access_path(cmd[0]);
		if (result != 1)
		{
			path = cmd[0];
			excut_cmd(path, cmd);
		}
		else
		{
			error(cmd[0], running);
		}
	}
	else
	{
		path = find_command_path(cmd[0]);
		if (path != NULL)
		{
			excut_cmd(path, cmd);
		}
		else
		{
			error(cmd[0], running);
		}
	}

}
