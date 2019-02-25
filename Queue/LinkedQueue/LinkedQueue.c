//
// Created by ������ on 2019-02-25.
//

#include "LinkedQueue.h"

ElementType LinkedQueueDequeue(LinkedQueue queue, ElementType data) {
    //����β�ŷ�
    QueueNode* prevNode = queue->tail->prev;
    QueueNode* delNode = queue->tail;

    //����ǰһ�ڵ��nextָ��
    prevNode->next = NULL;

    //������¼��β�ڵ�
    queue->tail = prevNode;

    //�ͷ��ڴ�ռ��
    free(delNode);

}

LinkedQueue InitLinkedQueue() {
    LinkedQueue linkedQueue = (LinkedQueue)malloc(sizeof(struct __QueueNode));
    linkedQueue->head = internalCreateQueueNode(NULL);
    linkedQueue->tail = linkedQueue->head;
    linkedQueue->head->next = linkedQueue->head;
    linkedQueue->head->prev = linkedQueue->head;
    linkedQueue->size = 0;
    return linkedQueue;
}

QueueNode *internalCreateQueueNode(ElementType data) {
    QueueNode* node = (QueueNode*)malloc(sizeof(struct __QueueNode));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void LinkedQueueEnqueue(LinkedQueue queue, ElementType data) {
    //���ͷ�巨,��ѭ����ʽ
    QueueNode* node = internalCreateQueueNode(data);
    //����ͷ�ڵ����һ��
    queue->head->next = node;
    //node������
    node->next = NULL;
    node->prev = queue->head;
    //�������û�и��ٹ�β�ڵ�,�ͼ�¼β�ڵ�
    if(queue->tail == queue->head)
    {
        queue->tail == node;
    }
    queue->size ++;

}
