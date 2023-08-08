#include "main.h"
int token_count = 0;
Command built_in_commands[3] = {
	{"exit", handle_exit},
	{"env", handle_env},
	{"echo", handle_echo}
};
/**
 * handle_tokens - Procedure to tokenize the input string
 * @lineptr: input string
 * @env: environ
 *
 * Return: int success is 1
 */
int handle_tokens(char *lineptr, char *env[])
{
	char *token, *new_token, **tokens = NULL;
	const char delimiter[] = " \t\n";
	bool built_in_found = false;

	token = strtok(lineptr, delimiter); /* tokenize the input string */
	while (token != NULL)
	{
		new_token = strdup(token);/* allocate memory for each token*/
		if (new_token == NULL)
		{
			perror("Memory allocation error");
			exit(1);
		}
		tokens = realloc(tokens, (token_count + 1) * sizeof(char *));/* Resize*/
		if (tokens == NULL)
		{
			perror("Memory allocation error");
			exit(1);
		}
		tokens[token_count] = new_token;
		token_count++;
		token = strtok(NULL, delimiter);
	}
		for (int i = 0; i < 4, built_in_found == false; i++) /* Execute built-in*/
		{
			if (strcmp(tokens[0], built_in_commands[i].name) == 0)
			{
				built_in_commands[i].handler(tokens);
				built_in_found = true;
			}
		}
		if (built_in_found == false)
			printf("Executing other command: %s\n", tokens[0]);
		built_in_found == true;
		for (int i = 0; i < token_count; i++)
		{
			free(tokens[i]);
		}
		free(tokens);
		return (0);
}
