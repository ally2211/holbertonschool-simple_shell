#include "main.h"

/**
 * handle_exit - Handle the "exit" built-in command.
 * @tokens: An array of tokens from the input string.
 *
 * Return: true
 */
bool handle_exit(char *tokens[])
{
	bool is_interactive;

        printf("Exiting the shell.\n");
        exit(0);
        is_interactive = false;
	return (true);
}

/**
 * handle_env - Handle the "env" built-in command.
 * @tokens: An array of tokens from the input string.
 *
 * Return:  true
 */
bool handle_env(char *tokens[]) {
    printf("Environment variables:\n");
    char* envp[] = { NULL };
    for (int i = 0; envp[i] != NULL; i++) {
        printf("%s\n", envp[i]);
    }
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
//	int token_count;

	/* Skip the "echo" token and print the rest of the tokens */
	printf("in echo %s \n", tokens[1]);
	for (int i = 1; i < token_count; i++)
	{
		printf("%s ", tokens[i]);
	}
	printf("\n");
	return (true);
}

/**
 * handle_cd - Handle the "cd" built-in command.
 * @tokens: An array of tokens from the input string.
 *
 * Return:  true
 */
bool handle_cd(char *tokens[]) {
	if (tokens[1] == NULL)
		chdir(getenv("HOME"));
	else 
	{
        	if (chdir(tokens[1]) == -1)
			perror("cd");
		else
			chdir(tokens[1]);
	}
	return (true);
}
