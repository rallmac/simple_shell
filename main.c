#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void execute_command(char *command);

/**
 * main - fork & wait example and interactive command execution
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t child_pid;
	int status;
	char buffer[BUFFER_SIZE];
	char *command;
	char *argv[] = {"/bin/ls", "-1", "/usr/", NULL};

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child_pid == 0)
	{
		printf("Wait for me, wait for me\n");
		sleep(3);

		printf("Before execve\n");
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error:");
		}
		printf("After execve\n");
	}
	else
	{
		wait(&status);
		printf("Oh, it's all better now\n");
	}

	while (1)
	{
		printf("$ ");
		if (!fgets(buffer, BUFFER_SIZE, stdin))
	{
		printf("\n");
		break;
	}

	command = strtok(buffer, "\n");
	if (!command)
		continue;

	execute_command(command);
	}

	return (0);
}
