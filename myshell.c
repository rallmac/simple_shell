#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

/**
 * execute_command - this function executes the command
 * given to the shell
 *
 * @command: the command given to the function
 * Return: the executed command
 */
void execute_command(char *command)
{
	pid_t pid;
	int status;
	char *args[2];
	args[0] = command;
	args[1] = NULL;

	pid = fork();
	if (pid < 0)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("execvp failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, WUNTRACED);
	}
}
