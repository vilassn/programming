#include<stdio.h>
main() {

	int hours, minutes;
	printf("Enter the hours and minutes: ");
	scanf("%d%d", &hours, &minutes);

	hours = hours * 30 + (float) 0.5 * minutes;
	if (hours == 360)
		hours = 0;

	minutes = minutes * 6;
	if (minutes == 360)
		minutes = 0;

	printf("Angle is %d", abs(hours - minutes));
}
