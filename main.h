#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/stat.h>
void print_k(const char *format);
char **split_it(char *str);
void execute_cmd(const char *cmd, char **cmd_arr);
#endif
