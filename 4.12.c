/* modifies the mode of ./bin/foo and ./bin/bar */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
  struct stat statbuf;

  /* turn on set_group_ID and turn off group_execute */
  if (stat("bin/foo", &statbuf) != 0)
    {
      printf("stat for bin/foo error!\n");
      return 1;
    }
  if(chmod("bin/foo", (statbuf.st_mode & ~S_IXGRP) | S_ISGID) != 0)
    {
      printf("chmod for bin/foo error!\n");
      return 1;
    }

  /* set absolute mode to "rw-r--r--" */
  if(chmod("bin/bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) != 0)
    {
      printf("chmod for bin/bar error!\n");
      return 1;
    }
  return 0;
}
