#include "main.h"
#define NUM_BUILT_IN_COMMANDS 4 
int token_count = 0;

Command built_in_commands[NUM_BUILT_IN_COMMANDS] =
{
        {"exit", handle_exit},
        {"env", handle_env},
        {"echo", handle_echo},
        {"cd", handle_cd}
};

/* handle_tokens - Procedure to tokenize the input string
 * @lineptr: input string
 * @env: environ
 *
 * Return: void
 */
int handle_tokens(char* lineptr, char *env[])
{
	char *token;
	char *new_token;
	char **tokens = NULL;
	const char delimiter[] = " \t\n";
	bool built_in_found = false;

	/* tokenize the input string */
	token = strtok(lineptr, delimiter);
	
	while (token != NULL)
	{
		/* Dynamically allocate memory for each token */
		char *new_token = strdup(token);
		if (new_token == NULL)
		{
			perror("Memory allocation error");
			exit(1);
		}

		/* Resize the tokens array to accommodate the new token */
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
printf("im before the for\n");
	/* Execute built-in command if found */
	for (int i = 0; i < 4, built_in_found == false; i++)
    	{
		if (strcmp(tokens[0], built_in_commands[i].name) == 0)
		{
			built_in_commands[i].handler(tokens);
			built_in_found = true;
		}
	}

printf("im outsid the for\n");	
	if (built_in_found == false)
		printf("Executing other command: %s\n", tokens[0]);

	built_in_found == true;
	/* Free the dynamically allocated memory for each token */
	for (int i = 0; i < token_count; i++)
	{
		free(tokens[i]);
	}

	/* Free the dynamically allocated memory for the tokens array*/
	free(tokens);
	return (0);
}
