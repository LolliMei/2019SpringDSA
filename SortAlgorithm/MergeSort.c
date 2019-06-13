//
// Created by ������ on 2019-06-02.
//

#include "MergeSort.h"
#include "swap.h"
#include <stdlib.h>
#include <memory.h>

void merge_sort(int *arr, int start, int end) {

    //�ݹ���ֹ����
    //�������ֻ��һ��Ԫ�أ����������
    if (start == end)
        return;
        //�������������Ԫ�أ����������������
    else if (start - end == 1) {
        if (arr[start] > arr[end])
            swap(&arr[start], &arr[end]);
        return;
    }

    //�ݹ鲿��
    int mid = (start + end) / 2;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);

    //��������ĵݹ�󣬳������������������
    //�ֱ���[start,mid],[mid + 1,end]
    int *temp = (int *) malloc(sizeof(int) * (end - start + 1));
    int mergeIndex = 0, leftIndex = start, rightIndex = mid + 1;
    while (leftIndex <= mid && rightIndex <= end)
        temp[mergeIndex++] = arr[leftIndex] < arr[rightIndex] ? arr[leftIndex++] : arr[rightIndex++];
    while (leftIndex <= mid)
        temp[mergeIndex++] = arr[leftIndex++];
    while (rightIndex <= end)
        temp[mergeIndex++] = arr[rightIndex++];

    //���ƹ鲢�����鵽ԭʼ�����鵱��
    memcpy(&arr[start],temp,sizeof(int) * (end - start + 1));
}


void MergeSort(int *arr, int size) {
    merge_sort(arr, 0, size - 1);
}
