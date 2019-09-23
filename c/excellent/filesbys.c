 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 int main(void)
 {
   char str[80];
   FILE *fp;
   if((fp = fopen("TEST", "w+"))==NULL)
 {
     printf("Cannot open file.\n");
     exit(1);
  }
    //write to the file
  do
 {
     printf("Enter a string (CR to quit):\n");
     gets(str);
     strcat(str, "\n"); /* add a newline */
     fputs(str, fp);
   } while(*str!='\n');

  /* now, read and display the file */
  rewind(fp); /* reset file position indicator to
                  start of the file. */
  while(!feof(fp))
 {
    fgets(str, 79, fp);
    printf(str);
  }

   return 0;
 }

