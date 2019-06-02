//
// Created by ������ on 2019-02-25.
//

#include "QuickSort.h"


static inline int Partition(int arr[],int low, int high){

    //���ñ��λ
    int pivot = arr[low];
    while(low < high){

        while(low < high && arr[high] >= pivot) high--;
        arr[low] = arr[high];

        while(low < high && arr[low] <= pivot) low++;
        arr[high] = arr[low];

    }
    arr[low] = pivot;
    return low;
}

void QuickSort(int arr[],int low,int high)
{
    //�ݹ��
    if(low > high)
        return;
    int partition = Partition(arr,low,high);
    QuickSort(arr,low, partition - 1);
    QuickSort(arr,partition + 1, high);

}