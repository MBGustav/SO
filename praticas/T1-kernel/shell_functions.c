#include "include/shell.h"
pid_t pid, pid_fg;

int novo_processo(char **args, int bg, pidManager *pidM){

    int status;

    pid = fork();

    if(pid == 0)
    { // Processo filho (em caso de sucesso)
        if(execvp(args[0], args) != -1){
            fprintf(stderr,"error no processo nº %d", (int)getpid());
        }
    }

    if( pid < 0 )
    { // Falha em fork()
        perror("Erro no processo de fork");
    } 
    else 
    { // Processo pai (aguarda resultado de filhos)

        if(bg == 0)
        {
            do{
                //aguarda pelo resultado
                waitpid(pid, &status, WUNTRACED);
                // waitpid(pid, &status, WNOHANG);
                

                //finaliza por teclado
                // kill(pid, SIGINT); 

            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
        else 
        {
            waitpid(-1,&status, WNOHANG);
            
        }

    }
    return (0);
}


//criacao de pid 
pidManager* new_pidM(){

    //alloc memory for pid in accord to NUM_PID
    pidManager *p = (pidManager*) malloc(sizeof(pidManager));
    p->array = (int*) malloc(sizeof(int)* NUM_PID);
    p->counter = 0;


    return p;
}
//destruicao de pid
// void kill_pidM(pidManager *p){
//     int status;
//     for(int n_pid = 0; n_pid < NUM_PID; n_pid++){
//         if(n_pid != 0){

//             while(waitpid(-1, &status, WNOHANG) >0)

//             //seria este comando?
//             kill(p->array[n_pid], SIGTERM);
//         }
//     }
//     free(p->array);
//     free(p);
// }


//checagem de dead process
void check_dead_process(pidManager *pidM){
    
    int status;
    for(int i = 0; i < NUM_PID; i++){
        if(pidM->array[i] != 0){

            //check status
            waitpid(pidM->array[i],&status, WNOHANG);
            // check for pid-status and kill function
            if(status==0) kill(pidM->array[i], SIGKILL);
        }
    }

}

void sig_term(int signo)
{
    if (signo == SIGINT){
        printf("received SIGINT\n");
        kill(pid, SIGINT);
    }
    pid_fg;
    if(signo == SIGTSTP){
        exit(0);

    }
}



