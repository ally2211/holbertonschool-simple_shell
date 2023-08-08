#include "main.h"
/**
 * main - Entry point of the shell program
 * @ac: The number of command-line arguments (unused)
 * @av: An array of command-line arguments (unused)
 * @env: The array of environment variables
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av, char **env)
{
	char *prompt = "($) ";
	char *lineptr;
	int status;
	bool is_interactive;
	pid_t pid;
	size_t n;
	int nchars_read;

	n = 0;
	lineptr = NULL;
	if (isatty(STDIN_FILENO)) /* Determine if it's interactive*/
	{
		printf("%s", prompt);
		is_interactive = true;
		fflush(stdout);
	}
	else
		is_interactive = false;
	while (1)
	{
		nchars_read = getline(&lineptr, &n, stdin);
		if (nchars_read == -1) /*check failed*/
		{
			printf("Exiting shell....\n");
			 exit(-1);
		}
		pid = fork(); /* Create a child process */
		if (pid < 0) /* fork failed */
			return (1);
		else if (pid == 0)
		{ /* Child process */
			handle_tokens(lineptr, env);
			exit(0);
		}
		else
		{ /* Parent process - wait for the child process to finish */
			wait(&status);
			if (is_interactive)
			{
				printf("%s", prompt);
				fflush(stdout);
			}
			else
				exit;
		}
	}
	free(lineptr);
	return (0);
}
