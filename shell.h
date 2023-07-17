#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;
void sigint_handler(int sigint_code);
void prompt(void);
void print_env(char **cmd);
char *_getenv(const char *name);
void print_counter(int num);
int _puts(const char *str);
int _puts_err(const char *str);
int _putchar(char c);
int _putchar_err(char c);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strlen(const char *str);
int _strncmp(const char *str1, const char *str2, size_t n);
int word_count(char *s);
/*void central(char *str);*/
char **tokenize(char *str);
void execute(char *cmd, char **av);
char **path_list(char *path, char *cmd);
void free_malloc(char **str);
char *test_path(char **paths, char **cmd_list);
void cmd_not_found(char **av, int counter, char **cmd_list, char **paths);
void built_in(char **cmd, char *str);
void getline_err(char *user_input);

#endif
