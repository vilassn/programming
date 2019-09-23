#include"myheader.h"
extern struct student *head;
void add()
{
 char choice;
 system("clear");
 while(1)
 {
  printf("\n\t*************************Add Record*************************\n");
  printf("\t|B: Add at Begin ");
  printf("|S: Add by Sort ");
  printf("|N: Add at End ");
  printf("|C: Cancel |");
  printf("\n\t************************************************************\n");
  printf("\t\t\t\tEnter: ");
  scanf(" %c",&choice);
  switch(choice)
   {
    case 'b': addatbeg();break;
    case 's': addsort();break;
    case 'n': addatend();break;
    case 'c': system("clear"); return;
    default :printf("Invalid Choice\n");
   }
 }
} 


void addatbeg()
{
 int flag=0;
 system("clear");
 struct student *new;
 int lroll;
 char name[30];
 new=malloc(sizeof(struct student));
 printf("Enter new roll number & name: ");
 scanf("%d %[^\n]s",&lroll, name);
 flag=check(lroll);
 if(flag)
 printf("Roll no. already exist...!\n");
 else
 { 
	 if(head==0)
 	{
  	new->roll=lroll;
        strcpy(new->name, name);
  	new->link=0;
	  head=new;
 	}
	 else
 	{
  	new->roll=lroll;
        strcpy(new->name, name);
  	new->link=head;
	  head=new;
 	}
   	print();
 }

}
 
void addsort()
{
 int flag=0;
 system("clear");
 struct student *new, *temp;
 int lroll;
 char name[30];
 new=malloc(sizeof(struct student));
 printf("Enter the roll number & name ");
 scanf("%d %[^\n]s",&lroll, name);
 flag=check(lroll);
 if(flag)
  printf("Roll no. already Exist...!\n");
 else
 {
 	if(head==0)
  	{
	  new->roll=lroll; 
        strcpy(new->name, name);
	  new->link=0;
	  head=new;
 	}
     else
     {
   	 temp=head;
   	 while((temp->link)!=0 && ((temp->link->roll)<lroll))
    	 {
     		temp=temp->link;
   	 }
    	if((temp->link)==0)
    	{
     	new->roll=lroll;
        strcpy(new->name, name);
     	new->link=0;
     	temp->link=new;
    	}
    	else
    	{
     	new->roll=lroll;
        strcpy(new->name, name);
     	new->link=temp->link;
     	temp->link=new; 
    	}
     }
   print();
 }
}

 
void addatend()
{
 int flag=0;
 system("clear"); 
 struct student *new, *temp;
 int lroll;
 char name[30];
 new=malloc(sizeof(struct student));
 printf("Enter roll number & name ");
 scanf(" %d %[^\n]s",&lroll, name);
 //assigning first node to the head
flag=check(lroll);
if(flag)
 printf("Roll no. already exist...!\n");
else
 {
 	if(head==0)
  	{
  	 new->roll=lroll;
         strcpy(new->name, name);
  	 new->link=0;
  	 head=new;
 	}
        //assigning new  node to last of link
 	else
	{ 
 	temp=head;
 	while(temp->link!=0)
      	temp=temp->link;
 	 new->roll=lroll;
        strcpy(new->name, name);
  	new->link=0;
  	temp->link=new;
	}
   print();
 }
}

//check availability of roll no.
int check(int roll)
{
 struct student *temp=head;
 while(temp)
 {
  if(temp->roll==roll)
   return 1;
  temp=temp->link;
 }
 return 0;
} 








