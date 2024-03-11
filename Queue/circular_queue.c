#include <stdio.h>
#include <stdlib.h>
#define max 4

void insert_cq(int *cq, int *rear, int *count)
{
    int elem;
    if (*count == max)
    {
        printf("\nQueue is full.");
        return;
    }
    printf("\nenter element:");
    scanf("%d", &elem);
    (*rear) = ((*rear) + 1) % max;
    cq[*rear] = elem;
    (*count)++;
}

void delete_cq(int *cq, int *front, int *count)
{
    int elem;
    if (*count == 0)
    {
        printf("\nUnderflow condition.");
        return;
    }
    elem = cq[*front];
    printf("\n %d is deleted", elem);
    (*front) = ((*front) + 1) % max;
    (*count)--;
}

void display(int *cq, int front, int count)
{
    if (count == 0)
    {
        printf("No element");
        return;
    }
    for (int i = 0; i < count; i++)
    {
        printf("\n %d ", cq[front]);
        front = (front + 1) % max;
    }
}

int main()
{
    int cq[max], front = 0, rear = max - 1, count = 0;
    int ch;
    while (1)
    {
        printf("\nEnter 1.inser \n 2.delete \n 3.display \n 4.exit \n");
        printf("enter choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert_cq(cq, &rear, &count);
            break;
        case 2:
            delete_cq(cq, &front, &count);
            break;
        case 3:
            display(cq, front, count);
            break;
        default:
            exit(0);
        }
    }
}
/*
                    dynamic circular queue by copilot
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int front, rear, size;
    unsigned capacity;
    int* array;
} Queue;

Queue* createQueue(unsigned capacity)
{
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(Queue* queue)
{  return (queue->size == queue->capacity);  }

int isEmpty(Queue* queue)
{  return (queue->size == 0); }

void enqueue(Queue* queue, int item)
{
    if (isFull(queue)) {
        queue->capacity *= 2;
        queue->array = realloc(queue->array, queue->capacity * sizeof(int));
    }
    queue->rear = (queue->rear + 1)%queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("%d enqueued to queue\n", item);
}

int dequeue(Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)%queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int front(Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

int rear(Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}

int main()
{
    Queue* queue = createQueue(10);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("%d dequeued from queue\n", dequeue(queue));

    return 0;
}
*/