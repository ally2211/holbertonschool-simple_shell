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
int handle_tokens(char *lineptr, char *env[] __attribute__((unused)))
{
	char *token, *new_token, **tokens = NULL;
	const char delimiter[] = " \t\n";
	bool built_in_found = false;
	long unsigned int j;
	int i;

	token = strtok(lineptr, delimiter);
	while (token != NULL)
	{
		/*printf("my token is %s\n",token);*/
		new_token = strdup(token);
		if (new_token == NULL)
		{
			perror("Memory allocation error");
			exit(1);
		}
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
	for (j = 0; j < sizeof(built_in_commands) / sizeof(Command); ++j) 
	{
        	if (strncmp(tokens[0], built_in_commands[j].name, strlen(built_in_commands[j].name)) == 0) 
		{
			built_in_found = true;
			built_in_commands[j].handler(tokens);
		}
	}

	if (!built_in_found)
		handle_execs(tokens);

	for (i = 0; i < token_count; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
	return (0);
}
