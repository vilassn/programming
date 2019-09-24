#include<stdio.h>
main() {
	int dd, mm, yy, i, oyear, omonth = 0, oday, y, yr, cen;
	int m[12] = { 3, 0, 3, 2, 3, 2, 3, 3, 2, 3, 2, 3 };
	system("clear");
	printf("Enter dd mm yyyy to find day of that date\n"); //3/10/1987
	scanf("%d%d%d", &dd, &mm, &yy);
	y = yy % 400; //387
	cen = y / 100; //3
	if (cen == 0)
		oyear = 0;
	if (cen == 1)
		oyear = 5;
	if (cen == 2)
		oyear = 3;
	if (cen == 3)
		oyear = 1;
	y = y % 100; //87
	yr = (y - 1) / 4; // (87-1)/4=86/4=21
	oyear = oyear + (yr * 2) + (y - 1 - yr); //1+(21*2)+(87-1-21)*1=1+42+65=108
	if ((yy % 4 == 0 && yy % 100 != 0) || yy % 400 == 0) //m[1]=0 since yy not leap year
		m[1] = 1;
	for (i = 0; i < mm - 1; i++)
		omonth = omonth + m[i]; //21
	oday = (oyear + omonth + dd) % 7; //(108+21+3)%7=6
	switch (oday) {
	case 0:
		printf("Sunday");
		break;
	case 1:
		printf("Monday");
		break;
	case 2:
		printf("Tuesday");
		break;
	case 3:
		printf("Wednesday");
		break;
	case 4:
		printf("Thursday");
		break;
	case 5:
		printf("Friday");
		break;
	case 6:
		printf("Saturday");
		break;
	}
}
