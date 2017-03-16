/* demonstrates tmpnam and tmpfile */
#include <stdio.h>

#define MAXLINE 1024

int main()
{
  char name[L_tmpnam], line[MAXLINE];
  FILE *fp;

  printf("%s\n", tmpnam(NULL));

  tmpnam(name);
  printf("%s\n", name);

  if((fp = tmpfile()) == NULL)
    {
      printf("tmpfile error!\n");
      return -1;
    }

  fputs("one line of output\n", fp);

  rewind(fp);
  if(fgets(line, sizeof(line), fp) == NULL)
    {
      printf("fgets error\n");
      return -1;
    }
  fputs(line, stdout);

  return 0;
}
