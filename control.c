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
#include <sys/shm.h>

union semun{
  int val;
  struct semid_ds *buff;
  unsigned long *buffer;
  struct seminfo *_buf;
  };



/// shared memory for how long file 

int main(int argc, char *argv[]){
  int sd;
  int semid;
  int key = ftok("makefile" , 22);
  int key2 = ftok("num" , 22);
  int sc;
  if (strncmp(argv[1], "-c", strlen(argv[1])) == 0){
    //file
    umask(0);;
    int fd = open( "text.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    
    //shared memory
    sd = shmget(key2, 4, IPC_CREAT |IPC_EXCL |0664);
    
    //semaphore creation and initalization 
    semid = semget(key, 1, IPC_CREAT | IPC_EXCL | 0644);
    union semun su;
    su.val = 1;
    semctl(semid, 0, SETVAL, su);
  }
  else if (strncmp(argv[1], "-v", strlen(argv[1])) == 0){
    int fd = open( "text.txt", O_RDONLY);
    int arr[10000];
    read( fd, arr, sizeof(arr)); 
    printf("%s", arr);
    close(fd);
  }
  else if(strncmp(argv[1], "-r", strlen(argv[1])) == 0){
    //removes semaphore
    semid = semget(key, 1, 0);
    sc = semctl(semid,IPC_RMID,0);

    // removes shared memory 
    //struct shmid_ds buf;
    sd = shmget(key2,4, 0);
    shmctl(sd, IPC_RMID, &buf);

    printf("semaphore and shared memory removed: %s\n", sc);

    //prints story
    int fd = open( "text.txt", O_RDONLY);
    int arr[10000];
    read( fd, arr, sizeof(arr)); 
    printf("%s", arr);
    close(fd);
  }
  return 0;
}
