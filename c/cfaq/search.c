#include <stdio.h>

int main()
{
 int i;
 int query;
 int total;
 int nums[20];
 enum ch {LINEAR=-1, BINARY};
 enum ch choice;
 //int choice;

 printf("Enter the no. of inputs, MAX 20\n");
 scanf("%d", &total);

 printf("Enter the numbers\n");
 for(i=0; i<total; i++)
   scanf("%d", &nums[i]);

 printf("size of enum ch %d\n", sizeof (enum ch));
 printf("size of enum ch choice %d\n", sizeof (choice));

 printf("Searching choice: %d. Linear, %d. Binary\n", LINEAR, BINARY);
 scanf("%d", &choice);

 printf("\nEnter Query to search: ");
 scanf("%d", &query);

 if(choice == LINEAR)
   linear(nums, total, query);
 else
   binary(nums, total, query);//works only on sorted array
}

linear(int nums[], int total, int query)
{
 printf("In %s search\n", __func__);

 int i;
 printf("Inputs =>");
 for(i=0; i<total; i++)
  printf(" %d\t", nums[i]);
 printf("\n");

 for(i=0; i<total; i++)
 {
  if(nums[i]==query)
   printf("Query:%d found at index %d\n", query, i);
 }  
}

binary(int nums[], int total, int query)
{
 printf("In %s search\n", __func__);

 int i;
 printf("Inputs =>");
 for(i=0; i<total; i++)
  printf(" %d\t", nums[i]);
 printf("\n");

 int first=0, last=total-1, middle;
 while(first<=last)
 {
  middle=(first+last)/2;
  printf("first %d, last %d, middle %d\n", first, last, middle);

  if(nums[middle]==query)
  {
   printf("Query:%d found at index %d\n", query, middle);
   break;
  }
  else if(nums[middle]<query)
   first=middle+1;
  else
   last=middle-1;
 } 
}
