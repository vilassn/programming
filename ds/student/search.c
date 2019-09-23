#include"myheader.h"
extern struct student *head;
search()
{
 int roll, status=0;
 struct student *temp=head;
 system("clear");
 if(head==0)
 {
  printf("Load file first...!\n");
  return;
 }
 printf("Enter the roll number to be search\n");
 scanf("%d",&roll);
 while(temp)
 {
  if(temp->roll==roll)
   {
    status=1;
   }
   temp=temp->link;
 }
 if(status) 
   printf("Entered Roll Number: %d is found\n",roll);
 else
   printf("Entered Roll Number: %d is not found\n",roll);
}
