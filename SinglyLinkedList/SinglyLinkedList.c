//
// Created by ������ on 2019-02-23.
//

#include <stdlib.h>
#include <stdbool.h>
#include "SinglyLinkedList.h"


//��ʼ��������
SinglyLinkedList InitLinkedList()
{
    SinglyLinkedList linkedList = (SinglyLinkedList)malloc(sizeof(struct __SinglyLinkedList));
    linkedList->size = 0;
    linkedList->head = (SinglyNode)malloc(sizeof(struct __SinglyNode));
    return linkedList;
}

//�ж��Ƿ�Ϊ��
bool LinkedListEmpty(SinglyLinkedList linkedList)
{
    return linkedList->size == 0;
}

//���ɽڵ�
SinglyNode internalCreateSingleNode(ElementType element)
{
    SinglyNode newNode = (SinglyNode)malloc(sizeof(struct __SinglyNode));
    newNode->data = element;
    newNode->data = NULL;
    return newNode;
}

//�����ݲ�������
void LinkedListInsert(SinglyLinkedList linkedList,ElementType element)
{
    //ͷ�巨
    SinglyNode newNode = internalCreateSingleNode(element);
    newNode->next = linkedList->head;
    linkedList->head = newNode;
    linkedList->size ++;
}

//��ѯ�����Ƿ����������
bool LinkedListContains(SinglyLinkedList linkedList,ElementType element)
{
    SinglyNode node = linkedList->head->next;
    while(node != NULL)
    {
        if(node->data == element) return true;
        node = node->next;
    }
    return false;
}

//�����ݴ��������Ƴ�
void LinkedListRemove(SinglyLinkedList linkedList,ElementType element)
{
    SinglyNode prev = linkedList->head;
    SinglyNode node = linkedList->head->next;
    while (node != NULL)
    {
        if(node == element) break;
        prev = prev->next;
        node = node->next;
    }
    SinglyNode next = node->next;

    prev->next = next;
    free(node);

    linkedList->size --;
}

//�Ƴ�ȫ���ڵ�
void LinkedListClear(SinglyLinkedList linkedList)
{
    SinglyNode node = linkedList->head->next;
    while(node != NULL)
    {
        SinglyNode delNode = node;
        node = node->next;
        free(delNode);
    }
    linkedList->head = NULL;
    linkedList->size = 0;
}

//�õ��ڵ�
SinglyNode LinkedListGetNode(SinglyLinkedList linkedList,ElementType element)
{
    SinglyNode node = linkedList->head->next;
    while(node != NULL)
    {
        if(node->data == element) return node;
        node = node->next ;
    }
    return NULL;
}
