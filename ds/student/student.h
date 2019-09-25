#include<stdio.h>
#include<stdlib.h>
struct student {
	int roll;
	char name[30];
	struct student *link;
};

