#include "shell.h"

/**
 * cmp_env_name - Compares the name of an environment
 * variable with a given name.
 * @nenv: Pointer to the environment variable string.
 * @name: Pointer to the name to compare.
 * Return: Returns the number of characters matched up to
 * the '=' character if the names match, otherwise 0.
 */
int cmp_env_name(const char *nenv, const char *name)
{
	int i;

	for (i = 0; nenv[i] != '='; i++)
	{
		if (nenv[i] != name[i])
		{
			return (0);
		}
	}

	return (i + 1);
}

/**
 * _getenv - Retrieves the value of an environment variable.
 * @name: Name of the environment variable.
 * @_environ: Pointer to the environment variables array.
 * Return: Returns a pointer to the value of the environment variable.
 */
char *_getenv(const char *name, char **_environ)
{
	char *ptr_env;
	int i, mov;

	ptr_env = NULL;
	mov = 0;

	for (i = 0; _environ[i]; i++)
	{
		mov = cmp_env_name(_environ[i], name);
		if (mov)
		{
			ptr_env = _environ[i];
			break;
		}
	}

	return (ptr_env + mov);
}

/**
 * _env - Displays all environment variables.
 * @datash: Pointer to the data_shell struct.
 * Return: Always returns 1.
 */
int _env(data_shell *datash)
{
	int i, j;

	for (i = 0; datash->_environ[i]; i++)
	{
		for (j = 0; datash->_environ[i][j]; j++)
			;

		write(STDOUT_FILENO, datash->_environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;

	return (1);
}

