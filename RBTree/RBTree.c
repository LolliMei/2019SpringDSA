//
// Created by ������ on 2019-02-15.
//
#include "RBTree.h"
#include <stdbool.h>
#include <stdlib.h>



//�ж��Ƿ�Ϊ��ɫ�ڵ�
static bool TreeNodeIsRed(RBTreeNode* node)
{
    if (node == NULL) return BLACK;
    return node->Color;
}

//����
static RBTreeNode* leftRotate(RBTreeNode* node)
{
    RBTreeNode* x = node->right;
    node->right = x->left;
    x->left = node;

    //��ɫ����
    x->Color = node->Color;
    node->Color = RED;

    return x;
}

//����
static RBTreeNode* rightRotate(RBTreeNode* node)
{
    RBTreeNode* x = node->left;
    node->left = x->right;
    x->right = node;

    //��ɫ����
    x->Color = node->Color;
    node->Color = RED;

    return x;

}

//��ɫ��ת
static void flipColors(RBTreeNode* node)
{
    node->Color = RED;
    node->left->Color = BLACK;
    node->right->Color = BLACK;
}

//������
RedBlackTree InitializeTreeMap() {
    RedBlackTree tree = malloc(sizeof(struct __RBT));
    tree->size = 0;
    tree->root = NULL;
    return tree;
}

static RBTreeNode* createNode(KeyType key, ValueType val)
{
    RBTreeNode* newNode = malloc(sizeof(RBTreeNode));
    newNode->key = key;
    newNode->value = val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->Color = RED;
    return newNode;
}

static RBTreeNode* NodeAdd(const RedBlackTree tree,RBTreeNode* node,KeyType key,ValueType val)
{
    //�����������
    if (node == NULL)
    {
        tree->size++;
        return createNode(key,val);
    }

    if(key < node->key)
    {
        node->left = NodeAdd(tree,node->left,key,val);
    }
    else if(key > node->key)
    {
        node->right = NodeAdd(tree,node->right,key,val);
    }else
    {
        node->value = val;
    }

    //����ƽ������
    if (TreeNodeIsRed(node->right) && !TreeNodeIsRed(node->left))
        node = leftRotate(node);

    if (TreeNodeIsRed(node->left) && TreeNodeIsRed(node->left->left))
        node = rightRotate(node);

    if(TreeNodeIsRed(node->left) && TreeNodeIsRed(node->right))
        flipColors(node);

    return node;

}

//���ؽ�������
void TreeMapPut(RedBlackTree tree,KeyType key,ValueType value)
{
    (tree)->root = NodeAdd((tree),(tree)->root,key,value);
    (tree)->root->Color = BLACK;
}

static ValueType get(RBTreeNode* node,KeyType key)
{
    //�ڵ�Ϊ�գ�����NULL
    if(node == NULL) return NULL;

    if(node->key < key)
    {
        return get(node->right,key);
    }
    else if(node->key > key)
    {
        return get(node->left,key);
    }
    else
    {
        return node->value;
    }

}

//���ҽڵ�,����ʧ�ܷ���NULL
ValueType TreeMapGet(RedBlackTree tree,KeyType key)
{
    return get(tree->root,key);
}

//��ѯ�Ƿ����ָ��key�ļ�ֵ��
bool TreeMapContains(RedBlackTree tree,KeyType key)
{

    RBTreeNode* node = tree->root;
    while(node != NULL)
    {
        if(node->key == key) return true;
        if(key < node->key) node = node->left;
        if(key > node->key) node = node->right;
    }

    return false;



}


static RBTreeNode* internalMinimum(RBTreeNode* node)
{
    if(node->left == NULL) return node;
    return internalMinimum(node->left);
}

static RBTreeNode* internalRemoveMinimum(RedBlackTree tree,RBTreeNode* node)
{
    if(node->left == NULL)
    {
        RBTreeNode* rightNode = node->right;
        node->right = NULL;
        tree->size --;
        return rightNode;
    }
    node->left = internalRemoveMinimum(tree,node->left);
    return node;
}

//ɾ������
RBTreeNode* internalRemove(RedBlackTree tree,RBTreeNode* node,KeyType key)
{
    if(node == NULL) return NULL;

    if(key < node->key)
    {
        node->left = internalRemove(tree,node->left,key);
        return node;
    }

    if(key > node->key)
    {
        node->right = internalRemove(tree,node->right,key);
        return node;
    }
    else
    {
        if(node->left == NULL)
        {
            RBTreeNode* rightNode = node->right;
            node->right = NULL;
            tree->size --;
            return rightNode;
        }

        if(node->right == NULL)
        {
            RBTreeNode* leftNode = node->right;
            node->left = NULL;
            tree->size --;
            return leftNode;
        }

        RBTreeNode* succ = internalMinimum(node->right);
        succ->right = internalRemoveMinimum(tree,node->right);
        succ->left = node->left;
        node->left = node->right = NULL;
        return succ;
    }

}

RBTreeNode* internalGetNode(RBTreeNode* node,KeyType key)
{
    if(node == NULL) return NULL;

    if(key == node->key) return node;
    else if(key < node->key) return internalGetNode(node->left,key);
    else return internalGetNode(node->right,key);
}

//�Ӻ�������Ƴ�һ��Ԫ��
ValueType TreeMapRemove(RedBlackTree tree,KeyType key)
{
    RBTreeNode* node = internalGetNode(tree->root,key);
    if(node != NULL)
    {
        tree->root = internalRemove(tree,tree->root,key);
        return node->value;
    }
    return NULL;
}






