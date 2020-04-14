#include "holberton.h"
/**
* main - Short description, single line
* @ac: number of args
* @av: args
* @env: current enviroment
* Return: Description of the returned value
*/

int main(int ac, char *av[], char *env[])
{
int bytesRead, i/*, x = 0;*/, t = 0;
size_t buffsize;
char *buffer = NULL, **tokens = NULL, **commands;
h_t *head = NULL;
(void)ac;
	signal(SIGINT, siggy);
	while (1)
	{
		t = 0;
	if (isatty(STDIN_FILENO))
	_puts("$ ");
	bytesRead = getline(&buffer, &buffsize, stdin);
	if (bytesRead == -1)
		break;
	buffer[bytesRead - 1] = '\0';
	if (*buffer == '\0')
	continue;
	if (isbuiltin(buffer, env, &head) == 4)
	continue;
	if (isbuiltin(buffer, env, &head) == 1)
	continue;
	if (isbuiltin(buffer, env, &head) == 2)
	free(buffer), exit(1);
	commands = make_command(buffer, ";");
	if (testspace(commands) == 0)
	for (i = 0 ; commands[i] ; i++)
	{
	tokens = make_command(commands[i], " ");
	exec_command(av, tokens, buffer, env, commands, t);
	if (tokens)
	free(tokens);
	}
	else
	{
	t = 1, exec_command(av, tokens, buffer, env, commands, t);
	} free(commands);
	}
free(buffer);
return (0);
}
