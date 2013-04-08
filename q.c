
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "queue.h"

int main()
{
	struct Queue Q;
	InitQueue(&Q);

	printf("Queue size: %d\n", Q.size);

	PushBack(&Q, 5);
	PushBack(&Q, 1);
	PushBack(&Q, 9);
	
	printf("In queue: %d\n", Q.head->value);

	printf("Queue size: %d\n", Q.size);
	
	printf("%d\n", PopFront(&Q));
	printf("%d\n", PopFront(&Q));
	printf("%d\n", PopFront(&Q));
	printf("%d\n", PopFront(&Q));

	printf("Hi\n");
}
