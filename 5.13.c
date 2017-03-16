/* this program show how to use (and how not to use) the mkstemp function */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

void make_temp(char *template);

int main()
{
  char good_template[] = "/tmp/dirXXXXXX"; /* right way */
  char *bad_template = "/tmp/dirXXXXXX"; /* wrong way */

  printf("tring to create first temp file...\n");
  make_temp(good_template);
  printf("tring to create second temp file...\n");
  make_temp(bad_template);
  return 0;
}

void make_temp(char *template)
{
  int fd;
  struct stat sbuf;
  if((fd = mkstemp(template)) < 0)
    {
      printf("mkstemp error\n");
      exit(-1);
    }
  close(fd);

  printf("temp name = %s\n", template);

  if(stat(template, &sbuf) != 0)
    {
      if (errno == ENOENT)
        printf("file doesn't exist\n");
      else
        {
          printf("stat error\n");
          exit(-1);
        }
    }
  else
    {
      printf("file exists\n");
      unlink(template);
    }
}
