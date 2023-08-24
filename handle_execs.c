#include "main.h"

/*
 * handle_execs - Function to execute tokenized string
 * @tokens: tokenized string
 *
 * Return: 1 for SUCCESS
 */
int handle_execs(char *tokens[], char *env[])
{
	struct stat buf;

	/* handle failure - need to get PATH*/
	if (stat(tokens[0], &buf) != 0)
	{
		handle_PATH(tokens, env);
		return (1);
	}

	/* Use execve to execute the file */
	if (execve(tokens[0], tokens, env) < 0)
	{
		perror("execve");
		return (1);
	}	
	return (0); 
}
