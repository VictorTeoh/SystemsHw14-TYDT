#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>
#define KEY 32551455

void create_semaphore(char * val  ){
  int sd;
  sd = semget( KEY, 1, IPC_CREAT | IPC_EXCL);
  if(sd != -1){
    //set value
    //extract the number from buffer with string manipulation
    int N = (int)val;
    semctl(sd, 0, SETVAL, N);
    printf("semaphore created: %d\n", KEY);
    printf("value set: %d\n", val);
  }
  else{
    printf("semaphore already exists\n");
  }
}

void current_value( ){
  int sd;
  sd = semget( KEY, 1, IPC_CREAT);
  printf("%d\n", sd);
  printf("semaphore value : %d", semctl( sd, 0, GETVAL, 0));
  //semctl
}

void remove_sempahore(){
  
  
}

int main(int argc, char *argv[]){
  //int KEY = 12323;
  char buffer[255];
  if(argc > 1){
    /*
    printf("%s\n", argv[1]);
    printf("%s\n", argv[2]);
    */
    if(strncmp(argv[1], "-c", sizeof("-c")) == 0){
      create_semaphore(argv[2]);
    }
    
    if(strncmp(argv[1], "-v", sizeof("-v")) == 0){
      current_value();
    }
  }
  /* while(1){
    fgets(buffer, sizeof(buffer), stdin);
    if(strncmp(buffer, "-c ", sizeof("-c ")) >= 0){
      create_semaphore(buffer);
    }
  }
  */
}
