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


/**
 * print_env - prints the environment
 * @env: array of environment variables
 *
 * Description: iteraite the evironment variable and print it
*/
void print_env(char *env[])
{
	int i = 0;

	for (i = 0; env[i] != NULL; i++)
	{
		print_k(env[i]);
		print_k("\n");
	}
}

/**
 * remove_space - remove the spaces outside the string
 * @str: string
 *
 * return: modified string without spaces
*/
char *remove_space(char *str)
{
	int i, j;
	int k = 0;

	for (i = 0, j = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '\"')
		{
			k = !k;
		}
		else if (!isspace(str[i]) || k)
		{
			str[j++] = str[i];
			if (!isspace(str[i]) && !k && (isspace(str[i + 1]) || str[i + 1] == '\0'))
			{
				str[j++] = ' ';
			}
		}
	}
	str[j] = '\0';
	return (str);
}
