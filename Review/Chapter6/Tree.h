//
// Created by ������ on 2019-06-23.
//

#ifndef INC_2019SPRINGDSA_TREE_H
#define INC_2019SPRINGDSA_TREE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct treenode {
    int data;
    struct treenode *left;
    struct treenode *right;
    int leftThread, rightThread;
} node, *Tree;


Tree init_tree() {
    Tree t = (Tree) malloc(sizeof(node));
    t->left = NULL;
    t->right = NULL;
    t->leftThread = 0;
    t->leftThread = 1;

    return t;
}

void preorder_nonrecursive(Tree t) {

    node *p = t;
    node **stack = (node **) malloc(sizeof(node *) * 100);
    int top = -1;

    stack[++top] = t;

    while (p || top != -1) {

        //ǰ�����,��������������������һ·�ߵ���
        while (p != NULL) {
            stack[++top] = p;
            printf("��ǰ����%d\n", p->data);
            p = p->left;
        }

        //��ʱ�Ѿ��ߵ��������ĵ��ˣ���ʼ��ջ������������
        p = stack[top--];
        p = p->right;
    }
}

void inorder_nonrecursive(Tree t) {
    node *p = t;
    node **stack = (node **) malloc(sizeof(node *) * 100);
    int top = -1;

    stack[++top] = p;

    while (p || top != -1) {

        //�Ƚ�����������һ·�ߵ���
        while (p) {
            stack[++top] = p;
            p = p->left;
        }

        //��ջ֮����ʽڵ�
        p = stack[top--];
        printf("��ǰ���ʽڵ�:%d\n", p->data);
        //Ȼ��ת��������
        p = p->right;

    }
}

Tree forest_to_tree(Tree *forest, int size) {

    //������һ������Ϊ��
    Tree t = init_tree();

    //������������
    for (int i = 0; i < size; ++i) {

        //��ÿһ��������ȡ��α���

        //�����ҷ�֧�洢����
        t->right = forest[i];
        //TODO::δ�����


    }

}

node *pre;

void inoreder_thread(Tree t) {

    //���������ֹ����
    if (t == NULL) return;

    //�ݹ����������������
    if (t->left != NULL && t->leftThread != 1)
        inoreder_thread(t->left);

    //���ʵ�ǰ�ڵ�

    //����������
    if (t->left == NULL) {
        t->left = pre;
        t->leftThread = 1;
    }
    //����������
    if (pre != NULL && pre->right == NULL) {
        pre->right = t;
        pre->rightThread = 1;
    }
    pre = t;


    if (t->right != NULL && t->rightThread != 1)
        inoreder_thread(t->right);

}

void preorder_thread(Tree t) {

    //���������ֹ����
    if (t == NULL)
        return;

    //������ʸ��ڵ�
    //�������������ӹ�ϵ
    if (t->left == NULL) {
        t->left = pre;
        t->leftThread = 1;
    }

    //�������������ӹ�ϵ
    if (pre != NULL && pre->right == NULL) {
        pre->right = t;
        pre->rightThread = 1;
    }
    pre = t;

    //�ݹ�������
    if (t->left != NULL && t->leftThread != 1)
        preorder_thread(t->left);

    //�ݹ�������
    if (t->right != NULL && t->rightThread != 1)
        preorder_thread(t->right);

}

void inorder_thread_traverse(Tree t) {

    /*
     * �ټǷ��� ���������������(����)���޺�����
     *
     * �������
     * 1.�������󣨽������������������ʣ�
     * 2.���ʽڵ�
     * 2.������� (ģ��ݹ����)
     * 3.�޺����� (����������������ͽ���)
     *
     */

    node *p = t;

    while (p != NULL) {
        //��������
        while (p->leftThread != 1) {
            p = p->left;
        }
        //���ʵ�ǰ�ڵ�
        printf("��ǰ����%d\n", p->data);
        //������Ԫ�أ������Ԫ�ز����������Ľڵ�
        //����ζ������ڵ����ҽڵ㣬��ô�Ϳ��ܴ���������
        while (p->right != NULL && p->rightThread == 1) {
            p = p->right;
            printf("��ǰ����%d\n", p->data);
        }
        //����������
        p = p->right;
    }
}

void preorder_thread_tarverse(Tree t){

    /*
     * �ټǷ��� ��������(����)����������޺�����
     */

    node* p = t;
    while(p != NULL){
        //��������
        while (p->left != NULL && p->leftThread == 0)
        {
            printf("��ǰ����%d",p->data);
            p = p->left;
        }

        //�������
        while (p->rightThread == 1 && p->right != NULL){
            p = p->right;
            printf("��ǰ����%d",p->data);
        }

        //�޺�����
        p = p->right;


    }

}


#endif //INC_2019SPRINGDSA_TREE_H
