#include "main.h"
/**
 * execute_cmd - execute command
 * @cmd: string
 * @cmd_arr: array of strings
 * Return: void
 */
void execute_cmd(const char *cmd, char **cmd_arr)
{
	int status;
	pid_t child_process = fork();

	if (child_process == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_process == 0)
	{
		if (execve(cmd, cmd_arr, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	wait(NULL);
}
