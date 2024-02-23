#include "main.h"
/**
 * print_k - print
 * @format: string
 * Return: void
 */
void print_k(const char *format)
{
	write(STDOUT_FILENO, format, strlen(format));
}
/**
 * split_it - tokenize the string
 *@str: string
 * Return: array of tokens
 */
char **split_it(char *str)
{
	char *token = NULL, *str_copy = NULL;
	char **tokens = NULL;
	int num_tokens = 0, i;

	str_copy = malloc(sizeof(char) * strlen(str));
	strcpy(str_copy, str);
	token = strtok(str, " \n");
	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, " \n");
	}
	tokens = malloc(sizeof(char *) * num_tokens);
	if (tokens == NULL)
	{
		perror("couldn't allocate memory for tokens");
		exit(-1);
	}
	token = NULL;
	token = strtok(str_copy, " \n");
	for (i = 0 ; i < num_tokens ; i++)
	{
		tokens[i] = malloc(sizeof(char) * strlen(token));
		if (tokens[i] == NULL)
		{
			perror("couldn't allocate memory for tokens[i]");
			exit(-1);
		}
		strcpy(tokens[i], token);
		token = strtok(NULL, " \n");
	}
	free(str_copy);
	return (tokens);
}
