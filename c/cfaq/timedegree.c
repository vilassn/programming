#include<stdio.h>

int main() {

	int hours, minutes;

	printf("Enter the hours and minutes: ");
	scanf("%d%d", &hours, &minutes);

	// In 60 min, hr hand move 30 degree
	// so, in 1min, hr hand move 0.5 degree
	hours = hours * 30 + (float) 0.5 * minutes;
	if (hours == 360)
		hours = 0;

	minutes = minutes * 6;
	if (minutes == 360)
		minutes = 0;

	printf("Angle is %d", abs(hours - minutes));

	return 0;
}

