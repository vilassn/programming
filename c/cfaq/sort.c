#include <stdio.h>

int main() {
	int i;
	int total;
	int nums[20];

	enum ch {
		SELECTION = -1, BUBBLE
	};

	enum ch choice;
	//int choice;

	printf("Enter the no. of inputs, MAX 20\n");
	scanf("%d", &total);

	printf("Enter the numbers\n");
	for (i = 0; i < total; i++)
		scanf("%d", &nums[i]);

	printf("size of enum ch %d\n", sizeof(enum ch));
	printf("size of enum ch choice %d\n", sizeof(choice));

	printf("Sorting choice: %d. Selection, %d. Bubble\n", SELECTION, BUBBLE);
	scanf("%d", &choice);
	if (choice == SELECTION)
		selection(nums, total); //lower nums collected at start
	else
		bubble(nums, total); //higher nums collected at end
}

selection(int nums[], int total) {
	printf("In %s sort\n", __func__);

	int i, j;

	printf("Inputs =>");
	for (i = 0; i < total; i++)
		printf(" %d\t", nums[i]);

	printf("\n");

	for (i = 0; i < total - 1; i++) {
		for (j = i + 1; j < total; j++) {
			if (nums[i] > nums[j]) {
				nums[i] = nums[i] + nums[j];
				nums[j] = nums[i] - nums[j];
				nums[i] = nums[i] - nums[j];
			}
		}

		int k;
		printf("Pass:%d =>", i);
		for (k = 0; k < total; k++)
			printf(" %d\t", nums[k]);

		printf("\n");
	}
}

bubble(int nums[], int total) {
	printf("In %s sort\n", __func__);

	int i, j;
	printf("Inputs =>");
	for (i = 0; i < total; i++)
		printf(" %d\t", nums[i]);

	printf("\n");

	for (i = 0; i < total - 1; i++) {
		for (j = 0; j < total - 1 - i; j++) {
			if (nums[j] > nums[j + 1]) {
				nums[j] = nums[j] + nums[j + 1];
				nums[j + 1] = nums[j] - nums[j + 1];
				nums[j] = nums[j] - nums[j + 1];
			}
		}

		int k;
		printf("Pass:%d =>", i);
		for (k = 0; k < total; k++)
			printf(" %d\t", nums[k]);

		printf("\n");
	}
}
