//
// Created by ������ on 2019-02-25.
//

#include "SelectionSort.h"

void InsertionSort(int arr[], int size) {
    //����������ʼ����������
    int index = size - 1;
    //��֤��ÿһ��Ԫ�ض������˲���
    for (int i = 0; i < size; ++i) {
        int maxIndex = 0;
        //��������Ԫ��
        for (int j = 0; j < size - i; ++j) {
            if(arr[j] > arr[maxIndex])
                maxIndex = j;
        }
        //����д��λ�ú����Ԫ������Ԫ�ص�λ��
        int t = arr[index];
        arr[index] = arr[maxIndex];
        arr[maxIndex] = t;
        index --;
    }
}
