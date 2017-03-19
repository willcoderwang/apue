#include <stdio.h>
#include <stdlib.h>

void exit_handler1();
void exit_handler2();

int main()
{
  if(atexit(exit_handler2) != 0)
    {
      printf("cannot register exit_hander2\n");
      return -1;
    }

  if(atexit(exit_handler1) != 0)
    {
      printf("cannot register exit_hander1\n");
      return -1;
    }

  if(atexit(exit_handler1) != 0)
    {
      printf("cannot register exit_hander1\n");
      return -1;
    }
  printf("main done\n");
  return 0;
}

void exit_handler1()
{
  printf("first exit handler\n");
}

void exit_handler2()
{
  printf("second exit handler\n");
}
