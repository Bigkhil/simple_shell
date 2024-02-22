#include "main.h"

void execute_cmd(const char *cmd, char *const argv[], char *const env[])
{
    int status;

    pid_t child_process = fork();

    if(child_process == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if(child_process == 0)
    {
        //executing the child process
        if(execve(cmd,argv,env) == -1)
        {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    }
    else{
        //the parent process will wait till child process ends
        do{
            waitpid(child_process,&status,WUNTRACED);
        }while(!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}