#include "main.h"
/**
 * main - check the code
 *@argc: number of arguments
 *@argv: pointer to array of strings
 * Return: Always 0.
 */
int main(int argc, char *argv[], char *env[])
{
	char *prompt = "$khalil ", *buff;
	size_t buff_size = 0;
	int read;
	ssize_t ret_getline;

	while (1)
	{
		printf("%s", prompt);
		ret_getline = getline(&buff, &buff_size, stdin);
		if (ret_getline == -1)
		{
			free(buff);
			exit(-1);
		}
		printf("%s", buff);
		free(buff);
		buff = NULL;
	}
    return (0);
}
