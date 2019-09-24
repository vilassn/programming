/****** Student Record System ******* Written By Vilas ********/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dir.h>
#include<dos.h>
#include<string.h>
struct student {
	int roll;
	char name[30];
	int marks;
	struct student *link;
};
struct student *head = 0;
char recordname[20];
//int savestatus;
main() {
	char choice;
	clrscr();
	welcome();
	delay(700);
	printf(
			"\n\n\n\n\n\n\n\n\n\nWritten By Vilas Ninawe\
	 \n\n\t[vilas_1987@yahoo.com]");
	printf("\n\n\t   Press any key to continue...");
	getch();
	/*set video mode :- text mode, 80x25, 16 colors */
	asm mov ah, 0x00;
	asm mov al, 0x03;
	asm int 0x10;
	clrscr();
	while (1) {
		printf(
				"\n*************************** Student Record Management *************************");
		printf("\n  1:Open Record ");
		printf("2:List Records ");
		printf("3:Create Record ");
		printf("4:Manage Records ");
		printf("5:Help ");
		printf("6:Quit ");
		printf(
				"\n*******************************************************************************");
		choice = getch();
		switch (choice) {
		case '1':
			openRecord();
			break;
		case '2':
			listRecord();
			break;
		case '3':
			createRecord();
			break;
		case '4':
			manageRecord();
			break;
		case '5':
			help();
			break;
		case '6':
			quit();
			break;
		default:
			clrscr();
			printf("You have entered invalid choice\n");
		} //switch
	} //while
} //main

welcome() {
	int i = 0;
	char c;
	/*set video mode :- text mode, 40x25, 16 colors */
	asm mov ah, 0x00;
	asm mov al, 0x13;
	asm int 0x10;
	printf("  \t       Welcome\n\n\n\n\t\t  To");
	delay(500);
	while (1) {
		delay(75);
		c = "\n\n\n\n\n\n\tSTUDENT RECORD MANAGEMENT"[i];
		if (c == 0)
			break;
		putchar(c);
		i++;
	}
	return 0;
}

openRecord() {
	char enteredname[20];
	printf("\nEnter the name of your Record to open (without extension): ");
	scanf("%s", enteredname);
	strcat(enteredname, ".db");
	if (findnopen(enteredname))
		editRecord();
	return 0;
}

findnopen(char *enteredname) {
	FILE *fp;
	struct ffblk ffblk;
	struct student onestu, *newstu, *temp;
	int done, present = 1;
	done = findfirst("*.db", &ffblk, 0);
	while (!done) {
		if ((present = stricmp(enteredname, ffblk.ff_name)) == 0)
			break;
		done = findnext(&ffblk);
	}
	if (present == 0) {
		strcpy(recordname, enteredname);
		//open record which is existing
		fp = fopen(recordname, "ab+");
		if (fp == 0) {
			printf("\nError in opening record...!\n");
			return 0;
		}
		while (fread(&onestu, sizeof(struct student) - 2, 1, fp)) {
			newstu = malloc(sizeof(struct student));
			if (head == 0) {
				newstu->roll = onestu.roll;
				strcpy(newstu->name, onestu.name);
				newstu->marks = onestu.marks;
				newstu->link = 0;
				head = newstu;
				temp = head;
			}
			//assigning newstu  node to last of link
			else {
				temp->link = newstu;
				temp = newstu;
				temp->roll = onestu.roll;
				strcpy(newstu->name, onestu.name);
				temp->marks = onestu.marks;
				temp->link = 0;
			}
		} //while
		if (head) {
			clrscr();
			printf("\n\t\tLoaded Successfully...!");
		} else
			printf("\nRecord is empty...!\n");
		return 1;
	} //if of record_existance

	else {
		clrscr();
		printf("\nRecord is not found");
	}
	fclose(fp);
	return 0;
}

listPrint() {
	int done;
	struct ffblk ffblk;
	//print list of record
	clrscr();
	done = findfirst("*.db", &ffblk, 0);
	printf("\nRecord name");
	printf("\n+++++++++++++++++");
	if (!done) {
		while (!done) {
			printf("\n%s", ffblk.ff_name);
			done = findnext(&ffblk);
		}
		printf("\n+++++++++++++++++");

		return 1;
	} else
		printf("\nStill No record is created...!\n");
	return 0;
}
listRecord() {
	head = 0;
	printf("\n************** List of Recods *************");
	if (listPrint())
		openRecord();
	return 0;
}
createRecord() {
	FILE *fp;
	printf("\nEnter the name of record to be created: ");
	scanf("%s", recordname);
	strcat(recordname, ".db");
	clrscr();
	//create file which is not existing
	fp = fopen(recordname, "wb");
	if (fp == 0) {
		printf("\nRecord can not be Created\n");
		return 0;
	}
	head = 0;
	editRecord();
	fclose(fp);
	return 0;
}

manageRecord() {
	char choice;
	char oldname[20], newname[20];
	while (1) {
		listPrint();
		printf("\n***************** Manage Records ***********");
		printf("\n 1:delete record   2:rename record   3:back");
		printf("\n********************************************");
		choice = getch();
		switch (choice) {
		case '1':
			printf("\nEnter the record name to delete: ");
			scanf("%s", oldname);
			strcat(oldname, ".db");
			clrscr();
			if (remove(oldname) == 0)
				printf("\nRecord is deleted successfully...!");
			else
				printf("\nNo such record found...?");
			getch();
			break;
		case '2':
			printf("\nEnter the old name of record: ");
			scanf("%s", oldname);
			strcat(oldname, ".db");
			printf("\nEnter the new name of record: ");
			scanf("%s", newname);
			strcat(newname, ".db");
			clrscr();
			if (rename(oldname, newname) == 0)
				printf("\nRecord is renamed successfully...!");
			else
				printf("\nError in renaming the record...?");
			getch();
			break;
		case '3':
			clrscr();
			return 0;
		default:
			clrscr();
			printf("\nYou have entered Wrong Choice...?");
		}
	}
}

help() {
	clrscr();
	printf(
			"\n*************************** Help to Use *****************************");
	printf(
			"\n\n\tThis software is specifically build for schools and colleges to store\n\n\
 the records of different classes.\
 \n\n\t Following  are the facilities provided by it:-");
	printf(
			"\n\n1: Open record is to open existing records by entering name directly\
 \n\n2: List record print the list of existing records & ask to open any\
 \n\n3: Create record creates the new record\
 \n\n4: Manage record is to delete or rename the record\
 \n\n5: Help is to print this information\
 \n\n6: Quit is to close software");
	printf(
			"\n********************************************************************");
	printf("\n\n\n\t\t\t\t Press any key to continue....");
	getch();
	clrscr();
	return 0;
}

quit() {
	char choice;
	clrscr();
	while (1) {
		printf("\n\t\t*********** Quit **************");
		//if(savestatus==1)
		//printf("\n\t\t    2:Exit           3:Back ");
		//else
		printf("\n\t\t 1:Save n Exit  2:Exit  3:Back");
		printf("\n\t\t*******************************");
		choice = getch();
		switch (choice) {
		case '1':
			saveEntry();
			exit(0);
		case '2':
			exit(0);
		case '3':
			clrscr();
			return 0;
		default:
			clrscr();
			printf("\nYou have entered Wrong choice");
		}   //switch
	}   //while
}

editRecord() {
	char choice;
	while (1) {
		print();
		printf(
				"\n\t*********************** Edit Record **************************");
		printf(
				"\n\t 1:Add  2:Delete  3:Reverse  4:Search  5:Sort  6:Save  7:Back");
		printf(
				"\n\t**************************************************************");
		choice = getch();
		switch (choice) {
		case '1':
			addEntry();
			break;
		case '2':
			deleteEntry();
			break;
		case '3':
			reverseEntries();
			break;
		case '4':
			searchEntry();
			break;
		case '5':
			sortEntry();
			break;
		case '6':
			saveEntry();
			break;
		case '7':
			clrscr();
			return 0;
		default:
			clrscr();
			printf("\nYour have entered Wrong Choice....?");
		}   //switch
	}   //while
}   //editRecord

addEntry() {
	int flag = 0;
	struct student *newstu, *temp;
	int lroll = 0;
	int marks = 0;
	char name[30];
	newstu = malloc(sizeof(struct student));
	printf("\nEnter Roll Number: ");
	scanf("%d", &lroll);
	printf("Enter Name: ");
	scanf(" %[^\n]s", name);
	printf("Enter Marks: ");
	scanf("%d", &marks);
	clrscr();
	flag = check(lroll);
	if (flag)
		printf("Roll no. already Exist...!\n");
	else {
		if (head == 0) {
			newstu->roll = lroll;
			strcpy(newstu->name, name);
			newstu->marks = marks;
			newstu->link = 0;
			head = newstu;
		}
		//assigning new  node to last of link
		else {
			temp = head;
			while (temp->link != 0)
				temp = temp->link;
			newstu->roll = lroll;
			strcpy(newstu->name, name);
			newstu->marks = marks;
			newstu->link = 0;
			temp->link = newstu;
		}
	}   //else
	return 0;
}   //addentry

int check(int roll) {
	struct student *temp = head;
	while (temp) {
		if (temp->roll == roll)
			return 1;
		temp = temp->link;
	}
	return 0;
}

deleteEntry() {
	char choice;
	clrscr();
	while (1) {
		print();
		printf("\n*******************Delete Record*******************");
		printf("\n 1: Delete by roll no.  2: Delete by name  3: Back");
		printf("\n***************************************************");
		choice = getch();
		switch (choice) {
		case '1':
			deletebyroll();
			break;
		case '2':
			deletebyName();
			break;
		case '3':
			clrscr();
			return 0;
		default:
			clrscr();
			printf("\nInvalid Choice...!\n");
		}   //switch
	}   //while
}

deletebyroll() {
	int roll;
	struct student *temp = head, *prevtemp;
	printf("\nEnter the roll no. to delete entry: ");
	scanf("%d", &roll);
	clrscr();
	if (roll < 0)
		printf("\nInvalid Roll Number...!");
	else {
		if (head) {
			if (temp->roll == roll) {
				if (temp->link == 0) {
					head = 0;
					free(temp);
				} else {
					head = temp->link;
					free(temp);
				}
			} else {
				while ((temp->link != 0) && (temp->roll != roll)) {
					prevtemp = temp;
					temp = temp->link;
				}

				if (temp->roll == roll) {
					if (temp->link == 0) {
						prevtemp->link = 0;
						free(temp);
					} else {
						prevtemp->link = temp->link;
						free(temp);
					}

				} else
					printf("\nEntered Roll no.:%d is not found...!", roll);
			}
		}   //if
		else
			printf("\nNothing to delete...!");
	}
	flushall();
	return 0;
}

deletebyName() {
	char name[30];
	struct student *temp = head, *prevtemp;
	printf("\nEnter the Name of Student to delete entry: ");
	scanf(" %[^\n]s", name);
	clrscr();
	if (head) {
		if (stricmp(temp->name, name) == 0) {
			if (temp->link == 0) {
				head = 0;
				free(temp);
			} else {
				head = temp->link;
				free(temp);
			}
		} else {
			while ((temp->link != 0) && (stricmp(temp->name, name) != 0)) {
				prevtemp = temp;
				temp = temp->link;
			}

			if (stricmp(temp->name, name) == 0) {
				if (temp->link == 0) {
					prevtemp->link = 0;
					free(temp);
				} else {
					prevtemp->link = temp->link;
					free(temp);
				}

			} else
				printf("\nEntered Student Name:%s is not found...!", name);
		}
	} else
		printf("\nNothing to Delete......!");
	return 0;
}

reverseEntries() {
	struct student *temp = head, *next;
	clrscr();
	if (head == 0) {
		printf("\nList is Empty....!");
		return 0;
	} else if (head->link) {
		head = head->link;
		temp->link = 0;
		while (head->link != 0) {
			next = head->link;
			head->link = temp;
			temp = head;
			head = next;
		}
		head->link = temp;
		printf("\n\tList is successfully reversed...!\n");
	} else if (head)
		printf("\nOnly one Entry....!");
	return 0;
}

sortEntry() {
	int troll;
	int tmarks;
	char tname[30];
	struct student *prev = head, *next;
	clrscr();
	if (head == 0) {
		printf("\nList is empty....!");
		return 0;
	} else if (head->link == 0) {
		printf("\nOnly one Entry....!");
		return 0;
	} else {
		while (prev->link != 0) {
			next = prev->link;
			while (next) {
				if (prev->roll > next->roll) {
					troll = prev->roll;
					prev->roll = next->roll;
					next->roll = troll;
					tmarks = prev->marks;
					prev->marks = next->marks;
					next->marks = tmarks;
					strcpy(tname, prev->name);
					strcpy(prev->name, next->name);
					strcpy(next->name, tname);
				}   //if
				next = next->link;
			}   //while
			prev = prev->link;
		}   //while
		printf("\n\tSorted successfully...!\n");
	}   //else
	return 0;
}

searchEntry() {
	int roll, status = 0;
	struct student *temp = head;
	clrscr();
	print();
	printf("\nEnter the roll number to be search\n");
	scanf(" %d", &roll);
	clrscr();
	if (roll < 0)
		printf("\nInavalid Roll Number....!");
	else {
		clrscr();
		while (temp) {
			if (temp->roll == roll) {
				status = 1;
			}
			temp = temp->link;
		}
		if (status)
			printf("\nEntered Roll Number: %d is found\n", roll);
		else
			printf("\nEntered Roll Number: %d is not found\n", roll);
	}
	flushall();
	return 0;
}

saveEntry() {
	struct student *temp = head;
	FILE *fp;
	clrscr();
	//savestatus=1;
	fp = fopen(recordname, "wb");
	while (temp) {
		fwrite(temp, sizeof(struct student) - 2, 1, fp);
		temp = temp->link;
	}
	printf("\n\t\tSaved Successfully...!\n");
	fclose(fp);
	return 0;
}

print() {
	struct student *temp = head;
	printf("\n\t\tRecord Name : %s", recordname);
	printf("\n\t\t++++++++++++++++++++++++++++++++++++++++++++++");
	if (head == 0) {
		printf("\nStill Record is empty...!\n");
		return 0;
	} else {
		printf("\n\t\t Roll\tName\t              \t\tMarks");
		printf("\n\t\t----------------------------------------------");
		while (temp) {
			printf("\n\t\t %d\t%s              \t\t%d\n", temp->roll,
					temp->name, temp->marks);
			temp = temp->link;
		}
	}
	printf("\n\t\t++++++++++++++++++++++++++++++++++++++++++++++\n");
	return 0;
}
