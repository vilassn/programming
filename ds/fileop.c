load() {

	char filename[20];
	struct student onestu, *new, *temp;

	printf("Enter the name of database file: ");
	scanf("%s", filename);

	FILE *fp = fopen(filename, "ab+");
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
		} else { ////assigning new  node to last of link
			temp->link = new;
			temp = new;
			temp->roll = onestu.roll;
			strcpy(new->name, onestu.name);
			temp->link = 0;
		}
	}

	fclose(fp);
}

save() {

	char filename[20];
	struct student *temp = head;

	printf("Enter the database file name: ");
	scanf("%s", filename);

	FILE *fp = fopen(filename, "wb");
	if (fp == 0) {
		printf("File can not be opened\n");
		return;
	}

	while (temp) {
		fwrite(temp, sizeof(struct student) - 4, 1, fp);
		temp = temp->link;
	}

	fclose(fp);
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
	}
}
