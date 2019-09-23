#include"myheader.h"
extern struct student *head;
sort()
{
 int troll;
 char tname[30];
 struct student *prev=head, *next;
 if(head==0)
 printf("\nLoad file first...!\n");
 else
 while(prev->link!=0)
 {
     next=prev->link;
   while(next)
   {
    if(prev->roll > next->roll)
    {
     troll=prev->roll;
     prev->roll=next->roll;
     next->roll=troll;
     strcpy(tname, prev->name);
     strcpy(prev->name, next->name);
     strcpy(next->name, tname);
    }
    next=next->link;
   }
   prev=prev->link;
 }
 print(); 
 printf("\n\tSorted successfully...!\n");
}
