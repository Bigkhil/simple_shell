#include "main.h"
/**
 * main - check the code
 * @argc: number of arguments
 * @argv: pointer to array of strings
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	int i = 0;
	char *input = NULL, **new_argv = NULL;
	size_t len = 0;
	ssize_t nums = 0;
	(void)argc;

	while (1)
	{
		nums = getline(&input, &len, stdin);
		if (nums == EOF)
		{
			free(input);
			return (0);
		}
		new_argv = tokenizing(argv, input, nums);
		if (new_argv == NULL)
		{
			free(input);
			return (0);
		}
		if (forking(new_argv) < 0)
		{
			free(input);
			free(new_argv);
			return (0);
		}
		for (i = 0; new_argv[i] != NULL; i++)
		{
			free(new_argv[i]);
		}
		free(new_argv);
		argv = new_argv;
	}
	free(input), free(argv);
	return (0);
}
