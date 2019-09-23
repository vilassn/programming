#include"myheader.h"
extern struct student *head;
load()
{
 char filename[20];
 system("clear");
 struct student onestu,*new,*temp;
 FILE *fp;
 system("ls *.db");
 printf("Enter the name of database file: ");
 scanf("%s",filename);
 fp=fopen(filename,"ab+");
 if(fp==0)
 {
  printf("File can not be accessed\n");
  return;
 }
  while(fread(&onestu,sizeof(struct student)-4,1,fp))
  {
   new=malloc(sizeof(struct student));
   if(head==0)
    {
        new->roll=onestu.roll;
        strcpy(new->name, onestu.name);
  	new->link=0;
	head=new;
        temp=head;
     }
 //assigning new  node to last of link
    else
    { 
     temp->link=new;
     temp=new;
     temp->roll=onestu.roll;
     strcpy(new->name, onestu.name);
     temp->link=0;
    }
  }
    if(head)
    {
     print();
     printf("\t\t\t\tLoaded Successfully..!");
    }
    else
     printf("File is empty...!\n");
 fclose(fp);
}
