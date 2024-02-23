#include "main.h"
/**
 * main - check the code
 * @argc: number of arguments
 * @argv: pointer to array of strings
 * @env: pointer to array of strings
 * Return: Always 0.
 */
int main(int argc, char *argv[], char *env[])
{

	char *prompt = "karim & khalil Shell$ ", *buff = NULL;
	int i = 0;
	char **tokens = NULL;
	size_t buff_size = 0;
	ssize_t ret_getline;

	while (1)
	{
		buff = NULL;
		print_k(prompt);
		ret_getline = getline(&buff, &buff_size, stdin);
		if (ret_getline == -1)
		{
			free(buff);
			exit(-1);
		}
		buff[ret_getline - 1] = '\0';
		tokens = split_it(buff);
		execute_cmd(tokens[0], tokens);
		free(tokens);
		free(buff);
	}
	return (0);
}
