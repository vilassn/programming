#include"myheader.h"
extern struct student *head;
void print()
{
 struct student *temp=head;
 printf("-----------------------------\n");
 if(head==0)
 {
  printf("Load file first...!\n");
  return;
 }
  else 
  {
   printf(" Roll | Name\n");
   while(temp)
   {
     printf("| %d  | %s\n",temp->roll, temp->name);
     temp=temp->link;
   }
  }
 printf("-----------------------------\n");
}
