#ifndef _SHELL_H_
#define _SHELL_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>


//Builtin - Library Declarations
// #include "shell_functions.h"
#include "builtin_cmd.h"


//DEFINES
#define NUM_PID 10
#define MAX_COMMAND_LENGTH 100  // Define o tamanho máximo do comando
#define MAX_ARGS 10  // Define o número máximo de argumentos


//struct pid_manager
typedef struct pidManager{
    int *array;
    int counter;
}pidManager;


int novo_processo(char **args, int bg, pidManager *pidM);

pidManager* new_pidM();

// void kill_pidM(pidManager *p);

void check_dead_process(pidManager *pidM);

void sig_term(int signo);

#endif // _SHELL_H_