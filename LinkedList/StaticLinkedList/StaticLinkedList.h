//
// Created by ������ on 2019-03-14.
//

#ifndef INC_2019SPRINGDSA_STATICLINKEDLIST_H
#define INC_2019SPRINGDSA_STATICLINKEDLIST_H

#define ElemType int
#define MAXSIZE 100

#include <stdlib.h>

typedef struct node
{
    ElemType data;
    int link;
}StaticNode;

typedef struct __StaticLinkedList
{
    //����һ���ڴ�����
    StaticNode Nodes[MAXSIZE];
    //����һ�����Է�����ڴ�ռ�
    int newPtr;
}*StaticLinkedListSpace;

//��ʼ����̬�ռ�
void InitStaticLinkedListSpace(StaticLinkedListSpace * space)
{
    //��ʼ����̬����ռ�
    *space = (StaticLinkedListSpace)malloc(sizeof(struct __StaticLinkedList));
    //����λ��Ϊ0
    (*space)->newPtr = 0;
    //��ʼ��ÿһ���ڵ����Ϣ
    for (int i = 0; i < MAXSIZE - 1; ++i) {
        (*space)->Nodes[i].link = i + 1;
    }
    (*space)->Nodes[MAXSIZE - 1].link = -1;
}

void InitStaticLinkedList()
{

}

void DestroyStaticLinkedList(StaticLinkedListSpace space,int* SlinkEntry)
{
    int node = *SlinkEntry;
    int delNode = node;
    //�ڵ㲻Ϊ��
    while(node != -1)
    {

    }

}

void InsertStaticLinkedList(StaticLinkedListSpace space,int* Slink,int i,ElemType data)
{
    int j = 0;

}


#endif //INC_2019SPRINGDSA_STATICLINKEDLIST_H
