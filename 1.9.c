#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
  printf("uid = %d, gid = %d\n", getuid(), getgid());
  printf("euid = %d, egid = %d\n", geteuid(), getegid());
  return 0;
}
