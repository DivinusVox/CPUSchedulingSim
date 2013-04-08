#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int value;
	struct Node *next;
};

struct Queue
{
	struct Node* head;
	struct Node* tail;
	int size;
};

/* InitQueue
 * Purpose: Initialize structure with default values.
 */
void InitQueue(struct Queue* Q)
{
	Q->head = NULL;
	Q->tail = NULL;
	Q->size = 0;
}

/* PopFront
 * Purpose: Remove first element of Queue.
 * Returns: Int value contained by Queue or -1 on failure.
 */
int PopFront(struct Queue* Q)
{
	if (Q->head != NULL)
	{
		struct Node* temp = Q->head;
		Q->head = Q->head->next;
		Q->size -= 1;
		if (Q->size == 0)
		{
			Q->head = NULL;
			Q->tail = NULL;
		}
		return temp->value;
	}
	return -1;
}

/* PushBack
 * Purpose: Adds given value to a Node in the rear of the Queue.
 * Parameters: Integer, positive.
 */
void PushBack(struct Queue* Q, int insert_me)
{
	struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
	temp->value = insert_me;
	temp->next = NULL;

	if (Q->size == 0)
	{
		Q->head = temp;
		Q->tail = temp;
	}
	else
	{
		Q->tail->next = temp;
		Q->tail = temp;
	}

	Q->size += 1;
}
