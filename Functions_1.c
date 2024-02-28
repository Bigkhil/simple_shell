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
	char *token = NULL, *str_copy1 = strdup(str), *str_copy2 = strdup(str);
	char **tokens = NULL;
	int num_tokens = 0, i;

	if (str_copy1 == NULL)
	{
		free(str_copy1), free(str_copy2), exit(EXIT_FAILURE);
	}
	if (str_copy2 == NULL)
	{
		free(str_copy2), free(str_copy1), exit(EXIT_FAILURE);
	}
	token = strtok(str_copy1, " ");
	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, " ");
	}
	tokens = malloc(sizeof(char *) * (num_tokens + 1));
	if (tokens == NULL)
	{
		free(str_copy1), free(str_copy2);
		return (NULL);
	}
	token = NULL;
	token = strtok(str_copy2, " ");
	for (i = 0 ; i < num_tokens; i++)
	{
		tokens[i] = strdup(token);
		token = strtok(NULL, " ");
	}
	tokens[i] = NULL;
	free(str_copy1);
	free(str_copy2);
	return (tokens);
}
