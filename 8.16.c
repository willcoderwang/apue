#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char *env_init[] = {"USER=unkown", "PATH=/tmp", NULL};

int main()
{
  pid_t pid;
  if ((pid=fork()) < 0)
    {
      printf("fork error!\n");
      return -1;
    }
  else if(pid == 0)  /* child */
    {
      if (execle("/home/will/git/apue/bin/8.17", "8.17", "myarg1",
                 "MY ARG2", (char *)0, env_init) < 0)
        {
          printf("execle error!\n");
          return -1;
        }
      return 0;
    }

  if ((pid=fork()) < 0)
    {
      printf("fork error!\n");
      return -1;
    }
  else if(pid == 0)  /* child */
    {
      if (execlp("8.17", "8.17", "only 1 arg", (char *)0) < 0)
        {
          printf("execle error!\n");
          return -1;
        }
      return 0;
    }


  return 0;
}
