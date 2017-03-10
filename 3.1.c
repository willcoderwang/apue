#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

/* this programm tests its standard input to see whether it is capable of seeking */

int main()
{
  if( lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
    printf("cannot seek\n");
  else
    printf("seek OK\n");
  return 0;
}
