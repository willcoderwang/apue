/* simple program to catch SIGUSR1 and SIGUSR2 */
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

static void sig_usr(int);

static void sig_usr(int signo)
{
  if(signo == SIGUSR1)
    printf("received SIGUSR1\n");
  else if (signo == SIGUSR2)
    printf("received SIGUSR2\n");
  else if (signo == SIGINT)
    printf("received SIGINT\n");
  else
    printf("received signal %d\n", signo);
}

int main()
{
  if(signal(SIGUSR1, sig_usr) == SIG_ERR)
    {
      printf("cannot catch SIGUSR1\n");
      return -1;
    }
  if(signal(SIGUSR2, sig_usr) == SIG_ERR)
    {
      printf("cannot catch SIGUSR2\n");
      return -1;
    }
  if(signal(SIGINT, sig_usr) == SIG_ERR)
    {
      printf("cannot catch SIGINT\n");
      return -1;
    }
  for( ; ; )
    pause();
  return 0;
}
