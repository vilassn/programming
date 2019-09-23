#include <stdio.h>

struct student {
	int rollno;
	char name[10];
	struct student *next;
};

struct student *head = NULL;
enum opt {
	ADD_START, ADD_END, ADD_SORT, SORT, REVERSE, DELETE, PRINT, EXIT
}

main() {

	while (1) {
		int choice;
		printf(
				"Enter choice: Add_Start %d, Add_End %d, Add_sort %d, Sort %d, Reverse %d, Delete %d, Print %d, Exit %d \n",
				ADD_START, ADD_END, ADD_SORT, SORT, REVERSE, DELETE, PRINT,
				EXIT);
		scanf("%d", &choice);

// enum opt arg;
// arg = ADD; // arg=choice also possible
// printf("enum vaiable arg size %d\n", sizeof arg); //4-bytes
// printf("enum size %d\n", sizeof( enum opt));	//4-bytes

		switch (choice) {
		case ADD_START:
			add_start();
			break;

		case ADD_END:
			add_end();
			break;

		case ADD_SORT:
			add_sort();
			break;

		case SORT:
			sort();
			break;

		case REVERSE:
			reverse();
			break;

		case DELETE:
			delete();
			break;

		case PRINT:
			print();
			break;

		case EXIT:
			exit(0);
			break;

		default:
			printf("Invalid choice\n");
		}
	}
}

add_start() {
	printf("In %s\n", __func__);

	struct student *stu = malloc(sizeof(struct student));

	printf("Enger Name & Roll No.\n");
	scanf("%s %d", stu->name, &stu->rollno);
	stu->next = head;
	head = stu;
}

add_end() {
	printf("In %s\n", __func__);

	struct student *stu = malloc(sizeof(struct student));

	printf("Enger Name & Roll No.\n");
	scanf("%s %d", stu->name, &stu->rollno);
	stu->next = NULL;

	if (!head) {
		head = stu;
	} else {
		struct student *temp = head;
		while (temp->next != NULL)
			temp = temp->next;

		temp->next = stu;
	}
}

add_sort() {
	printf("In %s\n", __func__);

	struct student *stu = malloc(sizeof(struct student));

	printf("Enger Name & Roll No.\n");
	scanf("%s %d", stu->name, &stu->rollno);
	stu->next = NULL;

	if (!head) {
		head = stu;
	} else {
		struct student *temp = head, *prev = 0;
		while (temp) {
			//for first or middle
			if (temp->rollno > stu->rollno) {
				stu->next = temp;
				if (prev == 0)
					head = stu;
				else
					prev->next = stu;
				break;
			}

			//for end
			if (!temp->next) {
				temp->next = stu;
				break;
			}

			prev = temp;
			temp = temp->next;
		}
	}
}

sort() {
	printf("In %s\n", __func__);
}

reverse() {
	printf("In %s\n", __func__);
}

delete() {
	printf("In %s\n", __func__);
}

print() {
	if (head != 0) {
		struct student *temp = head;
		while (temp) {
			printf("%s %d\n", temp->name, temp->rollno);
			temp = temp->next;
		}
	}
}
