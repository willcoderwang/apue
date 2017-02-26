#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAXLINE 1024

int main()
{
  char buf[MAXLINE];
  pid_t pid;
  int status;

  printf("%% ");
  while( fgets(buf, MAXLINE, stdin) != NULL)
    {
      if(buf[strlen(buf) -1] == '\n')
        buf[strlen(buf) - 1] = 0;

      if( (pid=fork()) < 0)
        {
          printf("fork error!\n");
          return 1;
        }
      else if(pid == 0)
        {
          execlp(buf, buf, (char *)0);
          printf("execlp error!\n");
          return 1;
        }
      if (waitpid(pid, &status, 0) < 0)
        {
          printf("waitpid error!\n");
          return 1;
        }
      printf("%% ");
    }

  if( ferror(stdin) )
    {
      printf("input error!\n");
      return 1;
    }
  return 0;
}
