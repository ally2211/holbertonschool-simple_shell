#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <string.h>

void handle_builtin(char *lineptr);
int handle_tokens(char *lineptr, char *env[]);
bool handle_exit(char *tokens[]);
bool handle_env(char *tokens[]);
bool handle_echo(char *tokens[]);
bool handle_cd(char *tokens[]);
void handle_PATH(char *tokens[], char *env[]);

typedef bool (*CommandHandler)(char**);

typedef struct {
    char *name;
    CommandHandler handler;
} Command;

extern Command built_in_commands[];
extern int token_count;
extern bool is_interactive;

#endif