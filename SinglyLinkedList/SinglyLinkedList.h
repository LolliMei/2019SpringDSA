//
// Created by ������ on 2019-02-23.
//

#ifndef INC_2019SPRINGDSA_SINGLYLINKEDLIST_H
#define INC_2019SPRINGDSA_SINGLYLINKEDLIST_H

#include <stdlib.h>
#include <stdbool.h>

#define ElementType void*
typedef struct __SinglyNode
{
    ElementType* data;
    struct __SinglyNode* next;
}*SinglyNode;

typedef struct __SinglyLinkedList
{
    SinglyNode head;
    int size;
}*SinglyLinkedList;

//��ʼ��������
SinglyLinkedList InitLinkedList();

//�ж��Ƿ�Ϊ��
bool LinkedListEmpty(SinglyLinkedList linkedList);

//���ɽڵ�
SinglyNode internalCreateSingleNode(ElementType element);

//�����ݲ�������
void LinkedListInsert(SinglyLinkedList linkedList,ElementType element);

//��ѯ�����Ƿ����������
bool LinkedListContains(SinglyLinkedList linkedList,ElementType element);

//�����ݴ��������Ƴ�
void LinkedListRemove(SinglyLinkedList linkedList,ElementType element);

//�Ƴ�ȫ���ڵ�
void LinkedListClear(SinglyLinkedList linkedList);

//�õ��ڵ�
SinglyNode LinkedListGetNode(SinglyLinkedList linkedList,ElementType element);

#endif //INC_2019SPRINGDSA_SINGLYLINKEDLIST_H
