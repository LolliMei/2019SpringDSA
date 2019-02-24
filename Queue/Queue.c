//
// Created by ������ on 2019-02-24.
//

#include "Queue.h"

Queue InitQueue() {
    Queue queue = (Queue)malloc(sizeof(struct __Queue));
    queue->size = 0;
    queue->arr = malloc(sizeof(ElementType) * DEFAULTSIZE);
    queue->front = 0;
    queue->rear = -1;
    queue->capacity = DEFAULTSIZE;
    return queue;
}

int QueueIndex(Queue queue, int index) {
    return index % queue->capacity;
}

void EnQueue(Queue queue,ElementType element) {
    //����ݻ�����
    if(queue->size == queue->capacity)
    {
        int* newarr = malloc(sizeof(ElementType) * 2 * queue->capacity);
        //��������
        for (int i = queue->front, index = 0; i <= queue->rear - queue->front; ++i, ++index) {
            newarr[index] = queue->arr[QueueIndex(queue,i)];
        }
        queue->front = 0;
        queue->rear = queue->size - 1;
        queue->capacity = 2 * queue->capacity;
        //�滻ԭ��������
        free(queue->arr);
        queue->arr = newarr;

    }
    queue->arr[QueueIndex(queue, ++ queue->rear)] = element;
    queue->size ++;
}

int QueueSize(Queue queue) {
    return queue->size;
}

void *QueueFront(Queue queue) {
    return queue->arr[QueueIndex(queue,queue->front)];
}

void *DeQueue(Queue queue) {
    ElementType ret = queue->arr[QueueIndex(queue,queue->rear)];
    queue->front ++;
    queue->size --;
    return ret;
}

void *QueueRear(Queue queue) {
    return queue->arr[QueueIndex(queue,queue->rear)];
}

void Print(Queue queue) {
    printf("[");
    //printf("%d",queue->arr[0]);
    for (int i = queue->front; i <=queue->rear; ++i) {
        printf(", %d",queue->arr[i]);
    }
    printf("]\n");
}
