//
// Created by ������ on 2019-06-02.
//

#include "InsertionSort.h"

void InsertionSort(int *arr, int size) {
    //����[1,size-1]����
    for (int i = 1; i < size; ++i) {
        //[0,i-1]�����������,��i-1��ʼ���бȽ�
        int val = arr[i];
        int j = i - 1;
        //��������valС���Ǹ���ʱ���˳�ѭ��
        while (j >=0 && arr[j] > val) {
            arr[j + 1] = arr[j];

            j--;
        }
        //��ʱ��jָ��ľ����Ǹ���valС������[0,j]������ģ���Ҫ������j+1���ڵĿ�λ
        arr[j + 1] = val;

    }
}
