//starting of the program
#include"myheader.h"
struct student *head = 0;
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
