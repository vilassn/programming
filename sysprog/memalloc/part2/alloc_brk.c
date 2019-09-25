/* Shows how to use sbrk sys call
Version : 1.0
Author : Team -C
*/

#include <unistd.h>

void *last_valid_address,*old_break;
void main()
{
	int ret;
	int *p;

	/* grab the last valid address from the OS */

	last_valid_address = sbrk(0);
	old_break = last_valid_address;

	printf("\n %p \n", last_valid_address);
	getchar();

	/* change the location of the program break using brk */
	brk(last_valid_address + 100);
	last_valid_address = sbrk(0);
	printf("\n %p \n", last_valid_address);
	getchar();

	/* restore the old location of the program break using brk */
	brk(old_break);
	last_valid_address = sbrk(0);
	printf("\n %p \n", last_valid_address);
	getchar();

}
