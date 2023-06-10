#ifndef _BUILTIN_CMD_H_
#define _BUILTIN_CMD_H_

#include "shell.h"

//Prototypes for builtin commands


//Execucao das funcoes internas
int builtin_execute(char **args);


// change directory - cd
int cmd_cd(char **args);

//Help for use
int cmd_help(char **args);


//Exit sistem
int cmd_exit(char **args);

#endif // _BUILTIN_CMD_H_