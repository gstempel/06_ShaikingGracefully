#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>

static void sighandler(int signo){
  if(signo == SIGINT){
    printf("Program has exited because of SIGINT signal\n");
    exit(-1);
  }
  if(signo == SIGUSR1){
    printf("The parent pid is: %i\n", getppid());
  }
}
  

int main(){
  int x = 1;
  while(x){
    printf("pid: %i\n", getpid());
    sleep(1);
    signal(SIGINT, sighandler);
    signal(SIGUSR1, sighandler);
  }
  return 1;
}
