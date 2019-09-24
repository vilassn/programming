#include<stdio.h>

int main() {

	int num;
	printf("Enter no. of elements to be entered: ");
	scanf("%d", &num);

	int *a = (int *) malloc(num * 4);
	printf("Enter %d elements: ", num);
	for (int i = 0; i < num; i++)
		scanf("%d", &a[i]);

	//logic for sorting
	// it is selection sort
	int i = 0, j = 1;
	while (1) {

		//outer loop of selection sort is managed here
		if (j == num) {

			j++;
			i++;

			if (i == (num - 1))
				break;
		}

		if (a[i] > a[j]) {

			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}

		j++;
	}

	//print sorted array
	for (i = 0; i < num; i++)
		printf("%d ", a[i]);

	return 0;
}

