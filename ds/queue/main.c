#include <stdio.h>
#include "queue.h"

int main()
{
 Queue *q = alloc_queue();

 printf("q=%p, current_size %d\n", q, q->current_size);
 push(q, (void*)"vilas");
 void *p = pop(q);

 printf("%s is popped\n", (char*)p);
 printf("current_size %d\n", q->current_size);

 return 0;
}
