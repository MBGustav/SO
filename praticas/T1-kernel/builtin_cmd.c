#include "include/builtin_cmd.h"


//#TODO como melhorar este "dicionario"?
char *builtin_list[] =
{
    "cd", 
    "exit",
    "help"
};


int builtin_execute(char **args){
/*Funcao seletora de funcao de comandos internos 
    In: comando de entrada
    out:
    (-1) == erro sem entrada valida
    0: success
    1: fail
*/

    //Apenas para seguir o padrao seguido anteriormente..
    char *command = args[0];
    int i = 0;

        if(command !=NULL){
        for(;i < sizeof(builtin_list) / sizeof(char *); i++){
            //Para apenas quando encontramos o valor de i ou nao encontra
            if(strcmp(command, builtin_list[i]) == 0){
                break;
            }
        }
        switch (i)
        {
        case 0: return cmd_cd(args);
        case 1: return cmd_exit(args);
        case 2: return cmd_help(args);

        default: return 0;
        }

    }
    return -1;
}


int cmd_cd(char **args){
    if(args[1] == NULL){
        fprintf(stderr, "Argumento faltante em \"cmd_cd\"..\n");
    }else{
        if(chdir(args[1]) !=0)
            perror("erro em cmd_cd: mudanca de diretorio\n");   
    }
    return (-1);
}

int cmd_exit(char **args){

    if(args != NULL){
        return atoi(args[1]);
    } 
    //else..
    return 0;   
}


int cmd_help(char **args){
//Implementação -- descreve as funcoes internas que teremos (cmd_cd, cmd_exit, ....)
    return -1;
}

