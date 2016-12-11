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
  if(1){// insert code to check semaphone
    // insert code to read from file
    int fd = open( "text.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    // read using size of last line
    // write new info
    //update shared memory with length of new line
  return 0;
}
