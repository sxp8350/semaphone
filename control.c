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
