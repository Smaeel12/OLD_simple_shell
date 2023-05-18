#include "shell.h"
/**
 * _strdup - function that returns a pointer to a newly allocated space
 * in memory, which contains a copy of the string given as a parameter.
 * @str: string given as a parameter.
 * Return: NULL if str = NULL and On success returns a pointer to
 * the duplicated string. It returns NULL if insufficient memory was available
 */
char *_strdup(char *str)
{
	char *newstr;
	int len;
	int i;


	if (str == NULL)
	{
		return (NULL);
	}
	else
	{
		len = strlen(str);
		newstr = malloc((sizeof(char) * len) + 1);
		if (newstr == NULL)
			return (NULL);
		for (i = 0; i < len; i++)
			newstr[i] = str[i];
		newstr[len] = '\0';
		return (newstr);
	}
}

/**
 * _strlen - function that returns the length of a string.
 * @s: string.
 * Return: length of a string
 */
int _strlen(const char *s)
{
	int len = 0;

	while (s[len] != 0)
		len++;
	return (len);
}

/**
 * _strncmp - function that compares two strings tell a specific index.
 * @str1: first string
 * @str2: second string
 * @n: index
 * Return: return 0 if strings are equal, and -1 if its not.
 */
int _strncmp(const char *str1, const char *str2, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (str1[i] == str2[i])
		{
			continue;
		}
		else
		{
			return (-1);
		}
	}
	return (0);
}

/**
 * _getenv - function that searches  the environment list to
  * find the environment variable name, and returns a pointer to
  * the corresponding value string.
 * @name: the environment variable name.
 * Return: a pointer to the corresponding value string.
 */
char *_getenv(const char *name)
{
	char **env;
	int len = _strlen(name);

	for (env = environ; *env != NULL; ++env)
	{
		if (_strncmp(*env, name, len) == 0)
			return (&(*env)[len + 1]);
	}
	return (NULL);
}

/**
 * _itoa - function that converts an int to a string pointed to by str.
 * @str: The converted value.
 * @num: the number to convert.
 */
void _itoa(int num, char *str)
{
	int i, j;
	char tmp;

	for (i = 0; num != 0; i++)
	{
		str[i] = '0' + (num % 10);
		num /= 10;
	}
	for (j = 0; j < i / 2; j++)
	{
		tmp = str[j];
		str[j] = str[i - j - 1];
		str[i - j - 1] = tmp;
	}
	str[i] = '\0';
}
