#include "shell.h"

/**
 * exec_line - Executes a command line.
 *
 * @datash: Pointer to the data_shell struct.
 * Return: Returns 1 upon successful execution or an error code otherwise.
 */
int exec_line(data_shell *datash)
{
	int (*builtin)(data_shell *datash);

	if (datash->args[0] == NULL)
		return (1);

	builtin = get_builtin(datash->args[0]);

	if (builtin != NULL)
		return (builtin(datash));

	return (cmd_exec(datash));
}
