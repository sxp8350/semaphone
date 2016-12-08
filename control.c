#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>

union semun{
  int val;
  struct semid_ds *buff;
  unsigned long *buffer;
  struct seminfo *_buf;
};

int create(){
  int sd;
  int semid;
  int key = ftok("makefile" , 22);
  int sc;
  sd = shmget(24601, 5000, IPC_CREAT | 0664);
  semid = semget(key, 1, IPC_CREAT | IPC_EXCL |0644); 
  return 0;
  
}

int remov(){
  return 0;
}


int main(int argc, char *argv[]){
  if (strncmp(argv[1], "-c", strlen(argv[1])) == 0){
    create();
  }
  if (strncmp(argv[1], "-r", strlen(argv[1])) == 0){
    remov();
  }
  return 0;
}
