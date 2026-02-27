#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT 1024
#define MAX_ARGS  128

extern char input_string[MAX_INPUT];
extern char prompt_string[64];
extern int status;

void scan_input(void);
char *get_command(void);
int check_command_type(char *command);
void execute_internal_commands(char *cmd);

#endif
