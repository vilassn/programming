#include "myheader.h"
extern struct student *head;
save()
{
 char filename[20];
 system("clear");
 struct student *temp=head;
 FILE *fp;
 if(head==0)
  {
   printf("Nothing to Save..!\n\tFirst Create records..!\n");
  }
 else
 { 
   system("ls *.db");
   printf("Enter the database file name: ");
   scanf("%s",filename); 
   fp=fopen(filename,"wb");
   if(fp==0)
   {
    printf("File can not be opened\n");
    return;
   }
   while(temp)
   {
     fwrite(temp,sizeof(struct student)-4, 1, fp);
     temp=temp->link;
   }
   printf("\t\t\t\tSaved Successfully...!\n");
   fclose(fp);
 }
}
   
