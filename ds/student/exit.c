#include"myheader.h"
stop()
{
 char choice;
 system("clear");
 while(1)
 {
  system("clear");
  printf("\n\t\t*********************** Exit ***********************\n");
  printf("\t\t|S: Save n Exit ");
  printf("|E: Exit without saving ");
  printf("|C: Cancel |");
  printf("\n\t\t****************************************************\n");
  printf("\t\t\t\tEnter: ");
  scanf(" %c",&choice);
  switch(choice)
  {
   case 's':save();exit(0);
   case 'e':exit(0);
   case 'c':return;
   default:printf("Invalid Choice\n");
  }
 }
} 
