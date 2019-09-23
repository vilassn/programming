#include"myheader.h"
extern struct student *head;
//by reversing the link direction
reverse()
{
 struct student *temp=head, *next;
 if(head!=0)
 {
   head=head->link;
   temp->link=0;
   while(head->link!=0)
   {
    next=head->link;
    head->link=temp;
    temp=head;
    head=next;
   }
   head->link=temp;
   print();
   printf("\n\tList is successfully reversed...!\n");
 }
 else
 
  printf("\nLoad file first...!\n");
}
  
  
  
