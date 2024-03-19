#include "shell.h"

/**
 * without_comment - Removes comments from the input string.
 * @in: Input string possibly containing a comment.
 * Return: Modified input string with comments removed,
 * or NULL if the whole line is a comment.
 */
char *without_comment(char *in)
{
	int i, up_to;

	up_to = 0;
	for (i = 0; in[i]; i++)
	{
		if (in[i] == '#')
		{
			if (i == 0)
			{
				free(in);
				return (NULL); /*Return NULL if the whole line is a comment*/
			}
			if (in[i - 1] == ' ' || in[i - 1] == '\t' || in[i - 1] == ';')
				up_to = i; /*Store the position of the last character before the comment*/
		}
	}

	if (up_to != 0)
	{
		in = _realloc(in, i, up_to + 1);
		in[up_to] = '\0';
	}

	return (in); /*Return the modified input string*/
}

/**
 * shell_loop - Main loop for the shell program.
 * @datash: Pointer to the data_shell struct.
 *
 * This function repeatedly prompts the user for input, reads the input,
 * processes it, and executes commands until the user exits the shell.
 */
void shell_loop(data_shell *datash)
{
	int loop, i_eof;
	char *input;

	loop = 1;
	while (loop == 1)
	{
		write(STDIN_FILENO, "$ ", 3); /*Print the prompt*/
		input = read_line(&i_eof); /*Read input from the user*/
		if (i_eof != -1)
		{
			input = without_comment(input); /*Remove comments from the input*/
			if (input == NULL)
				continue; /*Continue to the next iteration if the input line is a comment*/

			if (check_syntax_error(datash, input) == 1)
			{
				datash->status = 2; /*Set status to indicate syntax error*/
				free(input); /*Free memory allocated for input*/
				continue; /*Continue to the next iteration*/
			}
			input = rep_var(input, datash); /*Replace variables in the input*/
			loop = split_commands(datash, input); /*Split and execute commands*/
			datash->counter += 1; /*Increment command counter*/
			free(input); /*Free memory allocated for input*/
		}
		else
		{
			loop = 0; /*Set loop flag to exit the loop*/
			free(input); /*Free memory allocated for input*/
		}
	}
}

