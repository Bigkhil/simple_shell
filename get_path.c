#include "main.h"
/**
 * get_path - get the path for the gicen cmd
 * @cmd: number of arguments
 * Return: string
 */
char *get_path(char *cmd)
{
	char *env_path = NULL, *dir = NULL, *full_path = NULL, *env_path_cpy = NULL;
	int command_len = 0;
	struct stat st;

	env_path = getenv("PATH");
	if (env_path)
	{
			env_path_cpy = strdup(env_path);
			command_len = strlen(cmd);
			dir = strtok(env_path_cpy, ":");
			while (dir)
			{
				int dir_len = strlen(dir);

				full_path = malloc(command_len + dir_len + 2);
				if (!full_path)
				{
					free(env_path_cpy);
					return (NULL);
				}
				strncpy(full_path, dir, dir_len);
				full_path[dir_len] = '/';
				strncpy(full_path + dir_len + 1, cmd, command_len + 1);
				if (stat(full_path, &st) == 0)
				{
					free(env_path_cpy);
					return (full_path);
				}
				free(full_path);
				dir = strtok(NULL, ":");
			}
			free(env_path_cpy);
			if (stat(cmd, &st) == 0)
			{
				return (strdup(cmd));
			}
	}
	return (NULL);
}

/**
 * exitt - exit function
 * @argv: argv
 * @c: c
 * 
 * Return: this function returns NULL
*/

char **exitt(char **argv, char *c)
{
	int i = 0;

	for ( i = 0; argv[i] != NULL; i++)
	{
		free(argv[i]);
	}
	free(argv);
	free(c);

	return (NULL);
}

/**
 * tokenizig - tokens the string
 * @argv: argv
 * @c: string
 * @n: size
 * 
 * Return: argv pointer
*/
extern char **environ;
char **tokenizing(char **argv, char *z, size_t n)
{
	char *zi = NULL, *token = NULL, *delim = " \n";
	int tokens = 0, i = 0;
	(void)n;

	z = remove_space(z);
	zi = strdup(z);
	token = strtok(z, delim);

	while(token != NULL)
	{
		tokens++;
		token = strtok(NULL, delim);
	}
	argv = malloc(sizeof(char *) * (tokens + 1));
	if (argv == NULL)
	{
		free(zi);
		return (NULL);
	}
	token = strtok(zi,delim);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = strdup(token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	if (strcmp(argv[0],"exit") == 0)
	{
		return (exitt(argv, zi));
	}
	else if (strcmp(argv[0], "env") == 0)
	{
		print_env(environ);
	}
	free(zi);
	return (argv);
}