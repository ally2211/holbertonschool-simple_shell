#include "main.h"

int token_count = 0;
Command built_in_commands[2] = {
	{"exit", handle_exit},
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
	unsigned long int j;
	int i;

	token = strtok(lineptr, delimiter);
	while (token != NULL)
	{
		new_token = strdup(token);
		tokens = realloc(tokens, (token_count + 1) * sizeof(char *));
		if (tokens == NULL)
		{
			perror("Memory allocation error");
			exit(1);
		}
		tokens[token_count] = new_token;
		token_count++;
		token = strtok(NULL, delimiter);
	}
	tokens = realloc(tokens, (token_count + 1) * sizeof(char *));
	tokens[token_count] = NULL;
	if (strcmp(tokens[0], "env") == 0)
	{
		print_env(env);
		built_in_found = true;
	}
	for (j = 0; j < sizeof(built_in_commands) / sizeof(Command); ++j)
	{
		if (strncmp(tokens[0], built_in_commands[j].name,
				strlen(built_in_commands[j].name)) == 0)
		{
			built_in_found = true;
			built_in_commands[j].handler(tokens);
		}
	}
	if (!built_in_found)
		handle_execs(tokens, env);
	for (i = 0; i < token_count; i++)
		free(tokens[i]);
	free(tokens);
	return (0);
}
