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


int main(){
  int sd;
  int semid;
  
  int key = ftok("makefile" , 22);
  int key2 = ftok("num" , 22);

  sd = shmget(key2, 4, 0);
  semid = semget(key, 1,0);

  //if(1 == semctl(semid, 0, GETVAL)){// insert code to check semaphone    
  struct sembuf sb;
  sb.sem_num = 0;
  sb.sem_flg = SEM_UNDO;
  //downs the semaphore, because its now in use
  sb.sem_op = -1;
  semop(semid, &sb, 1);
  printf("a\n");
  char a [256];
  // insert code to read from file
  int fd = open( "text.txt",  O_RDWR, 0644);
  printf("b\n");
  int k = shmat(sd,0,0);
  printf("c\n");
  printf("shared memory value: %d\n", k);
  printf("d\n");
  lseek(fd, -1 *k, SEEK_END);
  printf("e\n");
  // read using size of last line
  char prev[k + 1];
  printf("f\n");
  read(fd, prev, k);
  printf("g\n");
  printf("previous line is: %s \n", prev);
  printf("h\n");
  printf("Enter new line: \n");
  fgets(a,sizeof(a),stdin);


  lseek(fd, 0, SEEK_END);
  // write new info
  if(strstr(a,"\n")){
    *(strstr(a,"\n")) = 0;
  }
   
  k = strlen(a); //update shared memory with length of new line
  write(fd,a,k );
  shmctl(sd,0,0);
  printf("%d \n", k);
  close(fd);
  sb.sem_op = 1;
  semop(semid, &sb, 1); // restore value
  // }
  return 0;
}
