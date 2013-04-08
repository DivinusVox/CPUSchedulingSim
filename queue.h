typedef struct
{
  int value;
  Node *next;
} Node;

typedef struct
{
  Node *head;
  Node *tail;
  int size;
} Queue;

int PopFront(Queue* Q)
{
  Node* temp = Q->head;
  Q->Head = Q->next;
  Q->size -= 1;
  return temp->value;
}

void PushBack(Queue* Q, int insert_me)
{
  Node* temp;
  temp->value = insert_me;
  temp->next = NULL;
  Q->tail->next = temp;
  Q->tail = temp;
  Q->size += 1;
}
