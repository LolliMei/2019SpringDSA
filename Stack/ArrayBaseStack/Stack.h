//
// Created by ������ on 2019-02-24.
//

#ifndef INC_2019SPRINGDSA_STACK_H
#define INC_2019SPRINGDSA_STACK_H

#include <stdlib.h>
#include <stdbool.h>
#define ElementType int
#define DEFAULTSIZE 10
typedef struct __Stack
{
    ElementType* arr;
    int top;
    int capacity;
}*Stack;

//��ʼ���Զ�����ջ
Stack InitStack()
{
    Stack stack = (Stack)malloc(sizeof(struct __Stack));
    stack->arr = (ElementType*)malloc(sizeof(ElementType) * DEFAULTSIZE);
    stack->top = -1;
    stack->capacity = DEFAULTSIZE;
    return stack;
}

//��ӽ�ջ
void StackPush(Stack s, ElementType element)
{
    if(s->top + 1 == s->capacity)
    {
        ElementType* newarr = (ElementType*)malloc(sizeof(ElementType) * 2 * s->capacity);
        for (int i = 0; i < s->top + 1; ++i) {
            newarr[i] = s->arr[i];
        }
        s->arr = newarr;
        s->capacity *= 2;
    }
    s->arr[++ s->top] = element;

}

//��������Ԫ��
ElementType StackPop(Stack s)
{
    return s->arr[s->top --];
}

//�鿴����Ԫ��
ElementType StackTop(Stack s)
{
    return s->arr[s->top];
}









#endif //INC_2019SPRINGDSA_STACK_H
