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


void InitQueue(struct Queue* Q)
{
	Q->head = NULL;
	Q->tail = NULL;
	Q->size = 0;
}

int PopFront(struct Queue* Q)
{
	if (Q->head != NULL)
	{
		struct Node* temp = Q->head;
		Q->head = Q->head->next;
		Q->size -= 1;
		if (Q->size = 0)
		{
			Q->head = NULL;
			Q->tail = NULL;
		}
		return temp->value;
	}
	return -1;
}

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
