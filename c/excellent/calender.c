/* Printing Calender - Written by Vilas Ninawe (B46 -V6) */
#include<stdio.h>

int m[12] = { 3, 0, 3, 2, 3, 2, 3, 3, 2, 3, 2, 3 };

main() {

	int dd, mm, yy, day, firstday;
	char shift;

	system("clear");

	do {
		printf("\nEnter the dd/mm/yy to find day of that date: "); //28/11/2009
		scanf("%d%d%d", &dd, &mm, &yy);
	} while (checkval(dd, mm, yy));

	prevnext: checkval(dd, mm, yy);
	day = dayfind(dd, mm, yy);
	firstday = dayfind(1, mm, yy);
	printf("\nDay of entered date: %d of this month is: ", dd);
	printday(day);
	printcalender(firstday, mm, yy);
	chance: printf("Previous Month <= p       End       n => Next Month\n");
	printf(
			"Backward Year  <= b        e        f => Forward Year\n\n\t\t\t" "Enter:");
	scanf(" %c", &shift);
	system("clear");
	switch (shift) {
	case 'n':
		mm++;
		if (mm == 13) {
			mm = 1;
			yy++;
		}
		goto prevnext;
	case 'p':
		mm--;
		if (mm == 0) {
			mm = 12;
			yy--;
		}
		goto prevnext;
	case 'b':
		yy--;
		goto prevnext;
	case 'f':
		yy++;
		goto prevnext;
	case 'e':
		return 0;
	default:
		printf("\nYou have entered invalid choice\n\n");
		goto chance;
	}
}

/* to find day of entered date */
int dayfind(int dd, int mm, int yy) {
	int i, oyear, omonth = 0, oday, y, yr, cen;
	y = yy % 400; //9
	cen = y / 100; //0
	if (cen == 0)
		oyear = 0;
	if (cen == 1)
		oyear = 5;
	if (cen == 2)
		oyear = 3;
	if (cen == 3)
		oyear = 1;
	y = y % 100; //9
	yr = (y - 1) / 4; // 8/4 = 2
	oyear = oyear + (yr * 2) + (y - 1 - yr); //0+(2*2)+(9-1-2)=10
	for (i = 0; i < mm - 1; i++)
		omonth = omonth + m[i]; //24
	oday = (oyear + omonth + dd) % 7; //(10+24+28)%7=6
	return oday;
}

/* to check entered Date is valid or not */
int checkval(int dd, int mm, int yy) {
	int ret = 0;
	if ((yy % 4 == 0 && yy % 100 != 0) || yy % 400 == 0) //m[1]=0
		m[1] = 1;
	else
		m[1] = 0;

	if (mm > 12 || mm < 1) {
		printf("You have entered Invalid month\n");
		ret = 1;
	} else if (dd > m[mm - 1] + 28) {
		printf("You have entered Invalid day\n");
		printf("Bcoz entered month have %d days\n", (m[mm - 1] + 28));
		ret = 1;
	}
	return ret;
}

/* to print the calender */
printcalender(int fd, int mm, int yy) {
	int i, count = 0, state = 1;
	//  printf("value of fd=%d\n", fd);
	printf("\t\t   ");
	printmonth(mm);
	printf("%d\n\n", yy);
	printf("Sun     Mon    Tue     Wed     Thu     Fri     Sat\n");
	for (i = 0; i < fd; i++)
		printf("\t ");
	for (i = 1; i <= (m[mm - 1] + 28); i++) {
		printf("%d\t", i);
		fd++;
		if (fd == 7) {
			fd = 0;
			printf("\n");
		}
	}
	printf("\n\n\n");
}

/* to print the name of day */
printday(int day) {
	switch (day) {
	case 0:
		printf("Sunday\n\n");
		break;
	case 1:
		printf("Monday\n\n");
		break;
	case 2:
		printf("Tuesday\n\n");
		break;
	case 3:
		printf("Wednesday\n\n");
		break;
	case 4:
		printf("Thursday\n\n");
		break;
	case 5:
		printf("Friday\n\n");
		break;
	case 6:
		printf("Saturday\n\n");
		break;
	}
}

/* to printd the name of the month */
printmonth(int month) {
	switch (month) {
	case 1:
		printf("January, ");
		break;
	case 2:
		printf("February, ");
		break;
	case 3:
		printf("March, ");
		break;
	case 4:
		printf("April, ");
		break;
	case 5:
		printf("May, ");
		break;
	case 6:
		printf("June, ");
		break;
	case 7:
		printf("July, ");
		break;
	case 8:
		printf("August, ");
		break;
	case 9:
		printf("September, ");
		break;
	case 10:
		printf("Octomber, ");
		break;
	case 11:
		printf("November, ");
		break;
	case 12:
		printf("December, ");
		break;
	}
}

