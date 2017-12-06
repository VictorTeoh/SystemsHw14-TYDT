#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>

void create_semaphore(char * buffer){
  semget( KEY, 1, IPC_CREAT);
  if(){
    //set value
    printf("semaphore created: %d", i);
  }
  else{
    printf("semaphore already exists");
  }
}

void current_value( ){
  semget( KEY, 1, IPC_CREAT);
  //semctl

}

void remove_sempahore(){
  

}

int main(){
  int KEY = 12323;
  char buffer[255];
  while(1){
    fgets(buffer, sizeof(buffer), stdin);
    if(strncmp(buffer, "-c ", sizeof("-c "))){
      create_semaphore(buffer);
    }
  }
}
