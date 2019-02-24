//
// Created by ������ on 2019-02-23.
//

#ifndef INC_2019SPRINGDSA_STRING_H
#define INC_2019SPRINGDSA_STRING_H

#include <stdlib.h>
#include <memory.h>

typedef struct __string
{
    char* str;
    int len;
    int free;
}*string;

//�ڲ�API,���ַ�������
int internalStrlen(char* str)
{
    int len = 0;
    char* p = str;
    while(p != '\0')
    {
        len++;
        p++;
    }
    return len;
}

//��ָ����char*��ʼ���ַ���
string InitString(char* str)
{
    string newStr = (string)malloc(sizeof(struct __string));
    int _len = internalStrlen(str);
    memcpy(newStr->str,str, (_len + 1)* sizeof(char));
    newStr->str[_len] = '\0';
    newStr->len = _len;
    newStr->free = 0;
    return newStr;
}

//ָ���������ַ���
string InitStringBySize(char* str,int capacity)
{
    string newStr = (string)malloc(sizeof(struct __string));
    int _len = internalStrlen(str);
    //����ָ�����ȵ��ַ���
    memcpy(newStr->str,str, capacity* sizeof(char));
    newStr->len = _len;
    newStr->free = capacity - _len;
    return newStr;
}

//׷���ַ���
string StrAppend(string source,string append)
{

}

//���ַ������ȵĺ���
int StrLength(string str)
{
    return str->len;
}


#endif //INC_2019SPRINGDSA_STRING_H
