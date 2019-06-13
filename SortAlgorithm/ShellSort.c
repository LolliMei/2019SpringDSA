//
// Created by ������ on 2019-06-02.
//

#include "ShellSort.h"

void ShellSort(int *arr, int size) {

    //��С����ȡ[len / 2, len / 2 / 2, ... 1]
    for (int delta = size / 2; delta >= 1; delta = delta / 2) {

        //���������н��в�������
        //����[delta ,size]Ϊ��ͷ����,���Ƕ����Գ�Ϊ�����������еķǿ�ͷ��Ԫ��
        for (int i = delta; i < size; ++i) {

            //����������ƶ�����
            int j = i;
            int val = arr[j];
            while (j - delta >= 0 && arr[j - delta] > val) {
                arr[j] = arr[j - delta];
                j -= delta;
            }
            arr[j] = val;

        }
    }

}
