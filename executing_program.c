#include "main.h"

/**
 * execute_cmd - execute command
 * @argv: array of strings
 * Return: void
 */
void *execute_cmd(char **argv)
{
	char *line = NULL, *ret_line = NULL;

	if (!argv)
	{
		return (NULL);
	}
	line = argv[0];
	ret_line = get_path(line);

	if (!ret_line)
	{
		free(line);
		return (NULL);
	}

	if (execve(ret_line, argv, NULL) == -1)
	{
		perror("execve");
	}
	free(ret_line);
	return (NULL);
}

/**
 * forking - to create a child for the process
 * @new_argv: string represent the command
 * Return: int value represents the id of child process
*/
int forking(char **new_argv)
{
	pid_t child_process = fork();
	int status = 0;

	if (child_process == -1)
	{
		return (-1);
	}
	if (child_process == 0)
	{
		execute_cmd(new_argv);
		return (-1);
	}
	else
	{
		wait(&status);
	}
	return (0);
}
