#include "main.h"
/**
 * main - check the code
 * @argc: number of arguments
 * @argv: pointer to array of strings
 * @env: pointer to array of strings
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	char *prompt = "karim & khalil Shell$ ", *buff = NULL, *cmd_path;
	char **tokens;
	size_t buff_size = 0;
	ssize_t ret_getline;

	(void)argc, (void)argv;
	while (1)
	{
		buff = NULL, tokens = NULL, cmd_path = NULL;
		print_k(prompt);
		ret_getline = getline(&buff, &buff_size, stdin);
		if (ret_getline == -1)
		{
			free(buff);
			exit(-1);
		}
		buff[ret_getline - 1] = '\0';
		tokens = split_it(buff);
		cmd_path = get_path(tokens[0]);
		if (cmd_path != NULL)
		{
			execute_cmd(cmd_path, tokens);
		}
		else
			execute_cmd(tokens[0], tokens);
		free(tokens), free(buff), free(cmd_path);
	}
	return (0);
}
