#include"myheader.h"
extern struct student *head;
void delete()
{
 char choice;
 system("clear");
 if(head==0)
  {
   printf("Please first load the file...!");
   return;
  }
else
{
 while(1)
 {
  printf("\n\t*************************Delete Record*************************\n");
  printf("\t|R: Delete by roll no. ");
  printf("|A: Delete all record ");
  printf("|N: Delete by name ");
  printf("|C: Cancel |");
  printf("\n\t************************************************************\n");
  printf("\t\t\t\tEnter: ");
  scanf(" %c",&choice);
  switch(choice)
   {
    case 'r': deletebyroll();break;
    //case 'n': deletebyname();break;
    case 'a': deleteall();break;
    case 'c': system("clear"); return;
    default :printf("Invalid Choice\n");
   }
 }
} 
}

void deletebyroll()
{
 int roll;
 struct student *temp=head,*prevtemp;
 printf("Enter the roll no. to delete record: \n");
 scanf("%d",&roll);
   if(temp->roll==roll)
   {
    free(temp);
    temp=temp->link;
    head=temp;
   } 
   else
   { 
    while((temp->link!=0) && (temp->roll!=roll))
    {
     prevtemp=temp;
     temp=temp->link;
    }
 
     if(temp->roll==roll)
     {
      if(temp->link==0)
      {
         prevtemp->link=0;
         free(temp);
      }
     else
      {
       prevtemp->link=temp->link;      
       free(temp);
      }
     }
     else
      printf("Not found Entered entry to delete...!");
   }
  }
 
//delete all record
deleteall()
{
 FILE *fp;
 int epass, spass=12345;
 char choice;
 while(1)
{
 printf("Are you sure to delete all record...(y/n)?\n");
 scanf(" %c",&choice);
 system("clear");
 switch(choice)
 {
  case 'y':printf("Enter the password: \n");
           scanf("%d",&epass);
           if(epass==spass)
           {
            fp=fopen("Student.db","w");
            head=0;
            fclose(fp);
            printf("Successfully deleted all record...!\n");
           }
           else
           {
           printf("Wrong password..!\n");
           break;
           }
  case 'n': return;
  default : printf("You have entered invalid choice...!\n");
 }
}
}


//delete by name
