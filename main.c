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
	size_t buff_size = 0, i = 0;
	ssize_t ret_getline;

	(void)argc, (void)argv;
	while (1)
	{
		i = 0;
		buff = NULL, tokens = NULL, cmd_path = NULL;
		if (isatty(STDIN_FILENO))
			print_k(prompt);
		ret_getline = getline(&buff, &buff_size, stdin);
		if (ret_getline == -1 || strcmp(buff, "exit\n") == 0)
		{
			free(buff);
			exit(EXIT_FAILURE);
		}
		buff[ret_getline - 1] = '\0';
		tokens = split_it(buff);
		if (tokens)
		{
			cmd_path = get_path(tokens[0]);
			if (cmd_path != NULL)
			{
				execute_cmd(cmd_path, tokens);
			}
			else
				execute_cmd(tokens[0], tokens);
			while (tokens[i] != NULL)
			{
				free(tokens[i]);
				i++;
			}
			free(tokens[i]);
		}
		free(tokens), free(buff), free(cmd_path);
	}
	return (0);
}
