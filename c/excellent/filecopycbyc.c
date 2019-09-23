// copy a file
#include<stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
  FILE *in, *out;
  char ch;
  if(argc!=3)
  {
    printf("You forgot to enter a filename.\n");
    exit(1);
  }
  if((in=fopen(argv[1], "rb"))==NULL)
 {
    printf("Cannot open source file.\n");
    exit(1);
  }
  if((out=fopen(argv[2], "wb")) == NULL)
 {
    printf("Cannot open destination file.\n");
    exit(1);
  }
  /* This code actually copies the file. */
 while(!feof(in)) // feof return true if end of file occur
 {
    ch = getc(in);
    if(!feof(in)) 
    putc(ch, out);
  }
  fclose(in);
  fclose(out);
  return 0;
}

