#ifndef SHELL_FUNCTIONS_H
#define SHELL_FUNCTIONS_H

#include "shell.h"

int novo_processo(char **args, int bg){

    pid_t pid;
    int status;

    pid = fork();

    if(pid == 0)
    { // Processo filho (em caso de sucesso)
        if(execvp(args[0], args) == -1){
            fprintf(stderr,"error no processo nº %d", (int)getpid());
        }
    }

    if( pid < 0 )
    { // Falha em fork()
        perror("Erro no processo de fork");
    } 
    else { // Processo pai (aguarda resultado de filhos)

    if(bg == 0){
        do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    else {
        //oque devo fazer para executar em segundo plano ? 
    }

    return (-1);
}






#endif //SHELL_FUNCTIONS_H