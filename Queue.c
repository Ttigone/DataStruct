#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int E;

typedef struct Queue
{
    E * array;
    int capacity;
    int front, rear;
} * ArrayQueue;

_Bool initQueue(ArrayQueue queue);
_Bool offerQueue(ArrayQueue queue, E element);
E popQueue(ArrayQueue queue);
_Bool isempty(ArrayQueue queue);
void printQueue(ArrayQueue queue);

int main(void)
{
    struct Queue qline;
    initQueue(&qline);
    int i = 1;
    while(i <= 3 && offerQueue(&qline, i)){
        i++;
    }
    printQueue(&qline); 
    for(int j = 1; j <= 3; j++)
        printf("%d ", popQueue(&qline));
    system("pause");
    return 0;
}

_Bool initQueue(ArrayQueue queue)
{
    queue->capacity = 10;
    E * Applyarray = (E * )malloc(sizeof(E) * queue->capacity);
    if(Applyarray == NULL)
        return false;
    queue->array = Applyarray;
    queue->front = queue->rear = 0;
    return true;
}

_Bool offerQueue(ArrayQueue queue, E element)
{
    int tem = (queue->rear + 1) % queue->capacity;queue->rear;
    if(tem == queue->front)
        return false;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = element;
    return true;
}

E popQueue(ArrayQueue queue)
{
    if(isempty(queue)){
        printf("╤сапн╙©у\n");
    }
    queue->front = (queue->front + 1) % queue->capacity;
    return queue->array[queue->front];
}

_Bool isempty(ArrayQueue queue)
{
    if(queue->front == queue->rear)
        return true;
    return false;
}

void printQueue(ArrayQueue queue)
{
    for(int i = queue->front + 1; i <= queue->rear; i++){
        printf("%d ", queue->array[i]);
    }
}

