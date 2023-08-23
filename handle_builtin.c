#include "main.h"
/**
 * handle_exit - Handle the "exit" built-in command.
 * @tokens: An array of tokens from the input string.
 *
 * Return: true
 */
bool handle_exit(char *tokens[])
{
	exit(0);
	return (true);
}

/**
 * handle_env - Handle the "env" built-in command.
 * @tokens: An array of tokens from the input string.
 * @env: env var
 *
 * Return:  true
 */
bool handle_env(char *tokens[])
{
	//for (int i = 0; env[i] != NULL; i++)
	//{
	//	printf("%s\n", env[i]);
	//}
	return (true);
}

/**
 * handle_echo - Handle the "echo" built-in command.
 * @tokens: An array of tokens from the input string.
 *
 * Return: true
 */
bool handle_echo(char *tokens[])
{
	int i;

	for (i = 1; i < token_count; i++)
	{
		printf("%s ", tokens[i]);
	}
	printf("\n");
	return (true);
}
