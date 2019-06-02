//
// Created by ������ on 2019-05-21.
//

#include "HeapSort.h"
#include "swap.h"

#define leftChild(x) 2*x+1
#define rightChild(x) 2*x+2
#define parent(x) x/2

void buildHeap(int *pInt, int i, int size);


void HeapSort(int *arr, int size);


//�����󶥶�
void buildHeap(int *arr, int index, int size) {
    /*
     * parent��ʾ�����������Ϊ���ڵ���α�
     * child��ʾparent�µĺ��ӣ�����Ϊ����Ҳ�������Һ���
     */
    //��¼��ʼ״̬�µ�parentֵ
    int parent = index;
    //������ѭ����ÿ�ζ����ȶ�λ��parent������
    for (int child = leftChild(parent); child < size; child = leftChild(parent)) {
        //������ҽڵ㣬�����ҽڵ��ֵ������ѡ���ҽڵ�
        if (child + 1 < size && arr[child] < arr[child + 1]) {
            child++;
        }
        //������ӽڵ��ֵ�ȸ��׽ڵ��ֵ��Ҫ��
        //�򽻻������ڵ㣬�൱�ڰѺ��ӽڵ�����
        //������˵���Ѿ����������½�������ֹѭ��
        if (arr[parent] < arr[child]) {
            swap(&arr[parent],&arr[child]);
            parent = child;
        } else {
            break;
        }
    }
}

void HeapSort(int *arr, int size) {

    //�����󶥶�
    for (int i = size / 2 - 1; i >= 0; --i) {
        buildHeap(arr, i, size);
    }
    //ÿ�γ�ȡ��һ��Ԫ��������Ԫ�ؽ���
    for (int i = size - 1; i > 0; --i) {
        swap(&arr[0], &arr[i]);
        buildHeap(arr, 0, i);
    }

}


