/******Implementation of wc command***********/
#include<stdio.h>
FILE * fileopen(char *,char *);
FILE *fp;
char ch;
main(int argc, char **argv)
{
 
 
   switch(argc)
   {
     case 2:
 	 fp=fileopen(argv[1],"r");
         line();
  	 word();
	 character();
	 break;
     case 3:
 	fp=fileopen(argv[2],"r");
	if(strcmp(argv[1],"-l")==0)
 	line();
	else if(strcmp(argv[1],"-w")==0)
	word();
	else if(strcmp(argv[1],"-c")==0)
	character();
	break;
     default:
	printf("Enter as  wc [option(-l/-w/-c)] [filename]\n\n");
        exit(0);
   }
   printf("\n");
   exit(0);
 
}

// linecount
line()
{
  int linecount=0;

 while((ch=fgetc(fp))!=EOF)
  {
	if(ch=='\n')
        linecount++;
  }
   printf("lines: %d  ",linecount);
  
}

// wordcount
 word()
{
 rewind(fp);
 int state=1, wordcount=0;
 while((ch=fgetc(fp))!=EOF)
 {
       if(ch==' ' || ch=='\n' ||ch=='\t')
   	state=1;
       else if(state==1)
             {
		state=0;
		wordcount++;
 	     }
 }
   printf("words: %d  ",wordcount);
}

//charactercount
character()
{
  rewind(fp);
  int charactercount=0;
  while((ch=fgetc(fp))!=EOF)
  {
    	charactercount++;
  }
  printf("characters:%d  ",charactercount);
}
//fileopen
FILE * fileopen(char *s1, char *s2)
{
   fp=fopen(s1,s2);
   if(fp==NULL)
  {
    printf("File not found\n");
    exit(0);
  }
  return(fp);
}
