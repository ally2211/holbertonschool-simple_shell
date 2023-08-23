#include "main.h"

/*
 * handle_execs - Function to execute tokenized string
 * @tokens: tokenized string
 *
 * Return: 1 for SUCCESS
 */
int handle_execs(char *tokens[])
{
	struct stat file_info;

	/* Use stat() to check if file exists and is executable */
	if (stat(tokens[0], &file_info) < 0)
	{	
		perror("stat");
		return (1);
    	}

	/* Check if the file is a regular file and has execute permissions*/
	if (!S_ISREG(file_info.st_mode) || !(file_info.st_mode & S_IXUSR)) 
	{
		printf("File is not executable\n");
		return (1);
	}

	/* Use access() to check if the current user has execute permissions*/
	if (access(tokens[0], X_OK) < 0)
	{
		perror("access");
		return (1);
	}

	/* Use execve to execute the file */
	if (execve(tokens[0], tokens, NULL) < 0)
	{
		perror("execve");
		return (1);
	}

	/* If execve succeeds, this line won't be reached*/
	return (0); 
}
