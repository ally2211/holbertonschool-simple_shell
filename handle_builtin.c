#include "main.h"
/**
 * handle_exit - Handle the "exit" built-in command.
 * @tokens: An array of tokens from the input string.
 *
 * Return: true
 */
bool handle_exit(char *tokens[])
{
	if (strcmp(tokens[0], "exit") == 0)
		kill (pid, SIGTERM);
	return (true);
}

/**
 * print_env - Handle the "env" built-in command.
 * @env: env var
 *
 * Return:  true
 */
void print_env(char *env[])
{
        int i;

	for (i = 0; env[i] != NULL; i++)
        {
                printf("%s\n", env[i]);
        }
}
/**
 * handle_echo - Handle the echo built-in command.
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

