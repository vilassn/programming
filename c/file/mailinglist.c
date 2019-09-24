/* A simple mailing list example using an array of structures. */
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct addr {
	char name[30];
	char street[40];
	char city[20];
	char state[3];
	unsigned long int zip;
} addr_list[MAX];

void init_list(void), enter(void);
void delete(void), list(void);
void load(void), save(void);
int menu_select(void), find_free(void);

int main(void) {
	char choice;
	init_list(); /* initialize the structure array */
	for (;;) {
		choice = menu_select();
		switch (choice) {
		case 1:
			enter();
			break;
		case 2:
			delete();
			break;
		case 3:
			list();
			break;
		case 4:
			save();
			break;
		case 5:
			load();
			break;
		case 6:
			exit(0);
		}
	}
	return 0;
}
/* Initialize the list. */
void init_list(void) {
	register int t;
	for (t = 0; t < MAX; ++t)
		addr_list[t].name[0] = '\0';
}
/* Get a menu selection. */
int menu_select(void) {
	char s[80];
	int c;
	printf("1. Enter a name\n");
	printf("2. Delete a name\n");
	printf("3. List the file\n");
	printf("4. Save the file\n");
	printf("5. Load the file\n");
	printf("6. Quit\n");
	do {
		printf("\nEnter your choice: ");
		scanf("%s", s);
		c = atoi(s);
	} while (c < 0 || c > 6);
	return c;
}
/* Input addresses into the list. */
void enter(void) {
	int slot;
	char s[80];
	slot = find_free();
	if (slot == -1) {
		printf("\nList Full");
		return;
	}
	printf("Enter name: ");
	gets(addr_list[slot].name);
	printf("Enter street: ");
	gets(addr_list[slot].street);
	printf("Enter city: ");
	gets(addr_list[slot].city);
	printf("Enter state: ");
	gets(addr_list[slot].state);
	printf("Enter zip: ");
	gets(s);
	addr_list[slot].zip = strtoul(s, '\0', 10);
}
/* Find an unused structure. */
int find_free(void) {
	register int t;
	for (t = 0; addr_list[t].name[0] && t < MAX; ++t)
		;
	if (t == MAX)
		return -1; /* no slots free */
	return t;
}
/* Delete an address. */
void delete(void) {
	register int slot;
	char s[80];
	printf("enter record #: ");
	gets(s);
	slot = atoi(s);
	if (slot >= 0 && slot < MAX)
		addr_list[slot].name[0] = '\0';
}
/* Display the list on the screen. */
void list(void) {
	register int t;
	for (t = 0; t < MAX; ++t) {
		if (addr_list[t].name[0]) {
			printf("%s\n", addr_list[t].name);
			printf("%s\n", addr_list[t].street);
			printf("%s\n", addr_list[t].city);
			printf("%s\n", addr_list[t].state);
			printf("%lu\n\n", addr_list[t].zip);
		}
	}
	printf("\n\n");
}
/* Save the list. */
void save(void) {
	FILE *fp;
	register int i;
	if ((fp = fopen("maillist", "wb")) == NULL) {
		printf("Cannot open file.\n");
		return;
	}
	for (i = 0; i < MAX; i++)
		if (*addr_list[i].name)
			if (fwrite(&addr_list[i], sizeof(struct addr), 1, fp) != 1)
				printf("File write error.\n");
	fclose(fp);
}
/* Load the file. */
void load(void) {
	FILE *fp;
	register int i;
	if ((fp = fopen("maillist", "rb")) == NULL) {
		printf("Cannot open file.\n");
		return;
	}
	init_list();
	for (i = 0; i < MAX; i++)
		if (fread(&addr_list[i], sizeof(struct addr), 1, fp) != 1) {
			if (feof(fp))
				break;
			printf("File read error.\n");
		}
	fclose(fp);
}

