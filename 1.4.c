#include <stdio.h>
#include <unistd.h>
#define BUFFERSIZE 4096

int main()
{
  int n=0;
  char buff[BUFFERSIZE];
  while((n=read(STDIN_FILENO, buff, BUFFERSIZE)) > 0)
    {
      if(write(STDOUT_FILENO, buff, n) != n)
        {
          printf("write error!\n");
          return 1;
        }
    }

  if(n < 0)
    {
      printf("read error!\n");
      return 1;
    }
  return 0;
}
