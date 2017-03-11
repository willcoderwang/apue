#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main()
{
  int fd;
  if( (fd = creat("bin/file.hole", FILE_MODE)) < 0)
    {
      printf("creat error!\n");
      return 1;
    }
  if( write(fd, buf1, 10) != 10 )
    {
      printf("buf1 write error!\n");
      return 1;
    }
  if( lseek(fd, 16384, SEEK_SET) == -1)
    {
      printf("lseek error!\n");
      return 1;
    }
  if( write(fd, buf2, 10) != 10 )
    {
      printf("buf2 write error!\n");
      return 1;
    }
  return 0;
}
