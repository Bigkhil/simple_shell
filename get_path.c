#include "main.h"
/**
 * get_path - get the path for the gicen cmd
 * @cmd: number of arguments
 * Return: string
 */
char *get_path(char *cmd)
{
	char *env_path = NULL, *dir = NULL, *full_path = NULL, *env_path_cpy = NULL;
	struct stat st;

	env_path = getenv("PATH");
	if (env_path)
	{
		env_path_cpy = strdup(env_path);
		dir = strtok(env_path_cpy, ":");
		while (dir != NULL)
		{
			full_path = NULL, full_path = malloc(strlen(dir) + strlen(cmd) + 2);
			if (full_path == NULL)
			{
				free(full_path);
				exit(EXIT_FAILURE);
			}
			strcpy(full_path, dir);
			strcat(full_path, "/");
			strcat(full_path, cmd);
			strcat(full_path, "\0");
			if (stat(full_path, &st) == 0)
			{
				free(env_path_cpy);
				return (full_path);
			}
			free(full_path);
			dir = strtok(NULL, ":");
		}
		free(env_path_cpy);
		return (NULL);
	}
	return (NULL);
}
