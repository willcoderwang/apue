/* demonstrates the fork function, showing how changes to variables in a child process do not affect the value of the variables in the parent process. */

#include <stdio.h>
#include <unistd.h>


int globvar = 6;        /* external variable in initialized data */
char buf[] = "a write to stdout\n";

int main(void)
{
  int var;           /* automatic variable on the stack */
  pid_t pid;

  var = 88;
  if(write(STDOUT_FILENO, buf, sizeof(buf)-1) != sizeof(buf)-1)
    {
      printf("write error!\n");
      return -1;
	}
  printf("befor fork\n");      /* we don't flush stdout */

  if((pid = fork()) < 0)
    {
      printf("fork error!\n");
      return -1;
}
  else if (pid == 0)          /* child */
    {
      ++globvar;
      ++var;
    }
  else
    {
      sleep(2);             /* parent */
    }
  printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);
  return 0;
}
