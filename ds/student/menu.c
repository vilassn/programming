//starting of the program
#include"student.h"
struct student *head = 0;

void print() {
	struct student *temp = head;
	printf("-----------------------------\n");
	if (head == 0) {
		printf("Load file first...!\n");
		return;
	} else {
		printf(" Roll | Name\n");
		while (temp) {
			printf("| %d  | %s\n", temp->roll, temp->name);
			temp = temp->link;
		}
	}
	printf("-----------------------------\n");
}

stop() {
	char choice;
	system("clear");
	while (1) {
		system("clear");
		printf("\n\t\t*********************** Exit ***********************\n");
		printf("\t\t|S: Save n Exit ");
		printf("|E: Exit without saving ");
		printf("|C: Cancel |");
		printf("\n\t\t****************************************************\n");
		printf("\t\t\t\tEnter: ");
		scanf(" %c", &choice);
		switch (choice) {
		case 's':
			save();
			exit(0);
		case 'e':
			exit(0);
		case 'c':
			return;
		default:
			printf("Invalid Choice\n");
		}
	}
}

load() {
	char filename[20];
	system("clear");
	struct student onestu, *new, *temp;
	FILE *fp;
	system("ls *.db");
	printf("Enter the name of database file: ");
	scanf("%s", filename);
	fp = fopen(filename, "ab+");
	if (fp == 0) {
		printf("File can not be accessed\n");
		return;
	}
	while (fread(&onestu, sizeof(struct student) - 4, 1, fp)) {
		new = malloc(sizeof(struct student));
		if (head == 0) {
			new->roll = onestu.roll;
			strcpy(new->name, onestu.name);
			new->link = 0;
			head = new;
			temp = head;
		}
		//assigning new  node to last of link
		else {
			temp->link = new;
			temp = new;
			temp->roll = onestu.roll;
			strcpy(new->name, onestu.name);
			temp->link = 0;
		}
	}
	if (head) {
		print();
		printf("\t\t\t\tLoaded Successfully..!");
	} else
		printf("File is empty...!\n");
	fclose(fp);
}

save() {
	char filename[20];
	system("clear");
	struct student *temp = head;
	FILE *fp;
	if (head == 0) {
		printf("Nothing to Save..!\n\tFirst Create records..!\n");
	} else {
		system("ls *.db");
		printf("Enter the database file name: ");
		scanf("%s", filename);
		fp = fopen(filename, "wb");
		if (fp == 0) {
			printf("File can not be opened\n");
			return;
		}
		while (temp) {
			fwrite(temp, sizeof(struct student) - 4, 1, fp);
			temp = temp->link;
		}
		printf("\t\t\t\tSaved Successfully...!\n");
		fclose(fp);
	}
}

sort() {
	int troll;
	char tname[30];
	struct student *prev = head, *next;
	if (head == 0)
		printf("\nLoad file first...!\n");
	else
		while (prev->link != 0) {
			next = prev->link;
			while (next) {
				if (prev->roll > next->roll) {
					troll = prev->roll;
					prev->roll = next->roll;
					next->roll = troll;
					strcpy(tname, prev->name);
					strcpy(prev->name, next->name);
					strcpy(next->name, tname);
				}
				next = next->link;
			}
			prev = prev->link;
		}
	print();
	printf("\n\tSorted successfully...!\n");
}

reverse() {
	struct student *temp = head, *next;
	if (head != 0) {
		head = head->link;
		temp->link = 0;
		while (head->link != 0) {
			next = head->link;
			head->link = temp;
			temp = head;
			head = next;
		}
		head->link = temp;
		print();
		printf("\n\tList is successfully reversed...!\n");
	} else

		printf("\nLoad file first...!\n");
}

search() {
	int roll, status = 0;
	struct student *temp = head;
	system("clear");
	if (head == 0) {
		printf("Load file first...!\n");
		return;
	}
	printf("Enter the roll number to be search\n");
	scanf("%d", &roll);
	while (temp) {
		if (temp->roll == roll) {
			status = 1;
		}
		temp = temp->link;
	}
	if (status)
		printf("Entered Roll Number: %d is found\n", roll);
	else
		printf("Entered Roll Number: %d is not found\n", roll);
}

main() {
	char choice;
	system("clear");

	while (1) {
		printf(
				"\n   ******************************* Student Record Management ******************************\n");
		printf("   |A: Add ");
		printf("|D: Delete ");
		printf("|T: Sort ");
		printf("|P: Print ");
		printf("|R: Reverse ");
		printf("|S: Search ");
		printf("|V: Save ");
		printf("|L: Load ");
		printf("|E: Exit|\n");
		printf(
				"   ****************************************************************************************\n");
		printf("\t\t\t\t\tEnter: ");
		scanf(" %c", &choice);
		switch (choice) {
		case 'a':
			add();
			break;
		case 'd':
			delete();
			break;
		case 't':
			sort();
			break;
		case 'r':
			reverse();
			break;
		case 'p':
			print();
			break;
		case 's':
			search();
			break;
		case 'v':
			save();
			break;
		case 'l':
			load();
			break;
		case 'e':
			stop();
			break;
		default:
			printf("You have entered invalid choice\n");
		} //switch
	} //while
} //main
