#include "main.h"

void print_k(const char *format)
{
    write(STDOUT_FILENO,format,strlen(format));
}

char **split_it(char *str)
{
    char *token;
    char **tokens = NULL;
    int i = 0;                

    token = strtok(str," \t\n");
    while(token != NULL)
    {
        i++;
        tokens = realloc(tokens, i * sizeof(char *));
        if (tokens == NULL)
        {
            perror("realloc");
            exit(EXIT_FAILURE);
        }
        tokens[i - 1] = token;

        token = strtok(NULL," \n\t");
    }
    tokens[i] = NULL;
    return tokens;
}