#include "main.h"
/**
 * main - check the code
 * @argc: number of arguments
 * @argv: pointer to array of strings
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	char *prompt = "karim&khalil$ ", *buff = NULL, *cmd_path;
	char **tokens;
	size_t buff_size = 0;
	ssize_t ret_getline;

	(void)argc, (void)argv;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			print_k(prompt);
		ret_getline = getline(&buff, &buff_size, stdin);
		if (ret_getline == -1 || strcmp(buff, "exit\n") == 0)
		{
			free(buff);
			exit(ret_getline == -1 ? EXIT_FAILURE : EXIT_SUCCESS);
		}
		buff[ret_getline - 1] = '\0';
		tokens = split_it(buff);
		if (tokens)
		{
			cmd_path = get_path(tokens[0]);
			execute_cmd(cmd_path ? cmd_path : tokens[0], tokens);
			for (int i = 0; tokens[i] != NULL; i++)
			{
				free(tokens[i]);
			}
			free(tokens), free(cmd_path);
		}
		free(buff);
		buff = NULL, buff_size = 0;
	}
	return (0);
}
