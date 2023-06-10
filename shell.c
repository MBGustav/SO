#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 100  // Define o tamanho máximo do comando
#define MAX_ARGS 10  // Define o número máximo de argumentos

void executeCommand(char *command, char **args, int background) {
    pid_t pid = fork();  // Cria um novo processo filho

    if (pid < 0) {  // Se ocorrer um erro ao criar o processo filho
        perror("Erro ao criar um novo processo");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Processo filho

        // Executa o comando fornecido
        execvp(command, args);

        // Se o execvp retornar, ocorreu um erro na execução do comando
        perror("Erro ao executar o comando");
        exit(EXIT_FAILURE);
    } else {
        // Processo pai

        // Se o comando não for executado em segundo plano, espera pelo filho
        if (!background)
            waitpid(pid, NULL, 0);
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];  // Variável para armazenar o comando digitado pelo usuário
    char *args[MAX_ARGS];  // Array de ponteiros para armazenar os argumentos
    char *token;  // Variável para armazenar cada token do comando
    int background = 0;  // Variável que indica se o comando deve ser executado em segundo plano

    while (1) {
        printf("$ ");  // Exibe o prompt do shell
        fgets(command, MAX_COMMAND_LENGTH, stdin);  // Lê o comando digitado pelo usuário
        command[strcspn(command, "\n")] = '\0';  // Remove a quebra de linha do final

        // Verifica se o comando deve ser executado em segundo plano
        if (command[strlen(command) - 1] == '&') {
            background = 1;
            command[strlen(command) - 1] = '\0';
        } else {
            background = 0;
        }

        // Divide o comando em tokens separados por espaços
        int i = 0;
        token = strtok(command, " ");  // Obtém o primeiro token
        while (token != NULL && i < MAX_ARGS - 1) {  // Enquanto houver tokens e não ultrapassar o limite de argumentos
            args[i] = token;  // Armazena o token no array de argumentos
            token = strtok(NULL, " ");  // Obtém o próximo token
            i++;
        }
        args[i] = NULL;  // O último elemento do array de argumentos deve ser NULL

        // Verifica se o comando é "exit" para encerrar o shell
        if (strcmp(args[0], "exit") == 0)
            break;

        // Executa o comando
        executeCommand(args[0], args, background);
    }

    return 0;
}
