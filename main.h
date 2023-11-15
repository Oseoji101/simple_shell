#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
extern char **environ;
void deletememmory(char **arg);
void handle_env(char **env);
void process_cmd(char **arg, char *p);
void handle_colon(char *ptr);
void process_cmd2(char **arg, char *p);
void process_cmd_file(char **arg, char *p);
void exit_shell(char **cmd, char *ptr);
int checkstatus(char *num);
void handlefile(char *filename);

#endif
