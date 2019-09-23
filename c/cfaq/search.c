#include <stdio.h>

void linear(int nums[], int total, int query) {
	printf("In %s search\n", __func__);

	int i;
	printf("Inputs =>");
	for (i = 0; i < total; i++)
		printf(" %d\t", nums[i]);
	printf("\n");

	for (i = 0; i < total; i++) {
		if (nums[i] == query)
			printf("Query:%d found at index %d\n", query, i);
	}
}

// query = 3
// array: 0 1 2 3 4 5
// index: 0 . . . . 5
// pass 1: start=0, end=5, med=2, query>med[2]
// pass 2: start=med+1=3, end=5, med=4, query<med[4]
// pass 3: start=3, end=med-1=3, med=3, query==med[3]
void binary(int nums[], int size, int query) {

	printf("Inputs are: ");
	for (int i = 0; i < size; i++)
		printf("%d ", nums[i]);

	int start = 0;
	int end = size - 1;
	while (start <= end) {

		int median = (start + end) / 2;

		if (query == nums[median]) {
			printf("query found at %d, start=%d, end=%d\n", median, start, end);
			break;
		} else if (query < nums[median])
			end = median - 1;
		else
			start = median + 1;
	}
}

int main() {

	int i;
	int query;
	int total;
	int nums[20];
	enum ch {
		LINEAR = 0, BINARY
	};
	enum ch choice;
	//int choice;

	printf("Enter the no. of inputs, MAX 20\n");
	scanf("%d", &total);

	printf("Enter the numbers\n");
	for (i = 0; i < total; i++)
		scanf("%d", &nums[i]);

	printf("Searching choice: %d. Linear, %d. Binary\n", LINEAR, BINARY);
	scanf("%d", &choice);

	printf("\nEnter Query to search: ");
	scanf("%d", &query);

	if (choice == LINEAR)
		linear(nums, total, query);
	else
		binary(nums, total, query); //works only on sorted array
}
