#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/stat.h>
void print_k(const char *format);
void *execute_cmd(char **argv);
int forking(char **new_argv);
char *get_path(char *cmd);
char **exitt(char **argv, char *c);
char **tokenizing(char **argv, char *c, size_t n);
void print_env(char *env[]);
char *remove_space(char *str);
#endif
