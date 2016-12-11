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


int main(){
  char a [256];
  if(1){// insert code to check semaphone
    // insert code to read from file
    int fd = open( "text.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    int k = 0; // placeholder. want k = to negative shared memory
    lseek(fd,k, SEEK_END);
    // read using size of last line
    printf("previous line is: \n");
    printf("Enter new line: \n");
    fgets(a,sizeof(a),stdin);
    // write new info
     if(strstr(a,"\n")){
       *(strstr(a,"\n")) = 0;
     }
    int f = strlen(a); //update shared memory with length of new line
    printf("%d \n", f);
    
  }
  return 0;
}
