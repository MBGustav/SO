#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


void term_hand(int signo)
{
    if(signo == SIGINT)
        printf("SIGINT %d recebido... Vou terminar...\n",signo);
    if(signo == SIGTSTP)
        printf("SIGSTOP");
  
  exit(0);
}

int main()
{
   pid_t pid;
   int cont = 0;

   if((pid=fork())==-1) {
      printf("Erro na execucao do fork\n");
      return 0;
   }
   if(pid==0) { // filho 
      while(1) { // Até ser interrompido...
         printf("%d ",++cont);
         fflush(stdout);  // apenas para forçar a exibição no terminal
         sleep(1);
      }
   }else { // pai 
    //   sleep(2);
    //   kill(pid, SIGSTOP);  // Qual é o efeito no processo filho?
    //   sleep(2);
    //   kill(pid, SIGCONT);  // Qual é o efeito no processo filho?
    //   sleep(2);
    do {
      printf("."); sleep (0.5);
    signal(SIGINT, term_hand);
    signal(SIGTSTP, term_hand);
    // sleep(2);
    }while(1);
    // kill(pid, SIGTERM);  // Qual é o efeito no processo filho?
   }

   return 0;
}
// O que será que vai acontecer com esse processo se for digitado <ctrl><C> durante sua execução?

// E se for usado o comando kill para enviar um sinal padrão (15) para o pid deste processo?

// Por quê a execução termina ao clicarmos no botão de execução da janela de execução abaixo?
