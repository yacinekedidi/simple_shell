#include "holberton.h"

/**
 * pathfinder - Short description, single line
 * @s1: Description of parameter xe
(* @env: Desription
 * @cmdpath: Des
* Return: Description of the returned value
*/
void pathfinder(char *s1, char **env, char *cmdpath)
{
int i = 0;
char *buf = NULL;
char *s = NULL;
struct stat sta;

	while (env[i])
	{
		if (env[i][0] == 'P' && env[i][1] == 'A'
		&& env[i][2] == 'T' && env[i][3] == 'H')
		buf = env[i];
	i++;
	}

	while (*(++buf) != '/')
	;

	s = strtok(buf, ":");
	while (s)
	{
	_strcpy(cmdpath, s);
	_strcat(strcat(cmdpath, "/"), s1);
	/*printf("%s\n", _strcat(strcat(cmdpath, "/"), s1));*/
		if (stat(cmdpath, &sta) == 0)
		break;
	s = strtok(NULL, ":");
	}

	if (s == NULL)
	*cmdpath = '\0';

}
