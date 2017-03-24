/* avoid zombie processes by calling fork twice */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
  pid_t pid;
  if ((pid=fork()) < 0)
    {
      printf("fork error\n");
      return -1;
    }
  else if (pid == 0)  /* child */
    {
      if ((pid=fork()) < 0)
        {
          printf("fork error\n");
          return -1;
        }
      else if (pid == 0) /* second child */
        {
          sleep(2);
          printf("second child, parent pid = %ld\n", (long)getppid());
          exit(0);
        }
      else    /* parent of the second fork */
        exit(0);
    }

  else /* parent of the first fork */
    {
      if(waitpid(pid, NULL, 0) != pid)
        {
          printf("wait error!\n");
          return -1;
        }
      exit(0);
    }
  return 0;
}
