#include "main.h"
void execute (char **tok_arg)
{
	pid_t child = fork();
	if (child == 0)
	{
		if ((execve(tok_arg[0], tok_arg, NULL)) == -1)
			perror("error in executing the command");
	}
	wait(NULL);
}
/**
 * main - check the code
 *@argc: number of arguments
 *@argv: pointer to array of strings
 * Return: Always 0.
 */
int main(int argc, char *argv[], char *env[])
{
	while(1)
	{
		char *prompt = "$khalil ", *command = NULL, *command_copy = NULL, *token = NULL;
		char **token_arr = NULL;
		int i, tokens = 1;
		size_t n = 0;
		ssize_t command_bytes;
		printf("%s", prompt);
		command_bytes = getline(&command, &n, stdin);
		if (command_bytes == -1)
			return (-1);
		command_copy = malloc(sizeof(char) * command_bytes);
		if (command_copy == NULL)
		{
			perror("failed to allocate\n");
			return(-1);
		}
		strcpy(command_copy, command);
		token = strtok(command, " \n");
		while (token != NULL)
		{
			tokens++;
			token = strtok(NULL, " \n");
		}
		token_arr = malloc(sizeof(char *) * tokens);
		if (token_arr == NULL)
		{
			perror("failed to allocate\n");
			return(-1);
		}
		token = NULL;
		token = strtok(command_copy, " \n");
		for (i = 0 ; i < (tokens - 1) ; i++)
		{
			token_arr[i] = malloc(sizeof(char) * strlen(token));
			if (token_arr[i] == NULL)
			{
				perror("failed to allocate\n");
				return(-1);
			}
			strcpy(token_arr[i], token);
			token = strtok(NULL, " \n");
		}
		execute(token_arr);
		free(command_copy);
		free(token_arr);
		free(command);
	}
    return (0);
}
