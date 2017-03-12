/* creates two fils: one with a umask of 0 and one with a umask that disables all the group and other permission bits. */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int main()
{
  umask(0);
  if (creat("bin/foo", RWRWRW) < 0)
    {
      printf("create foo error!\n");
      return 1;
    }

  umask(S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
  if (creat("bin/bar", RWRWRW) < 0)
    {
      printf("create bar error!\n");
      return 1;
    }
}
