//
// Created by ������ on 2019-02-25.
//
#include "MergeSort.h"
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//������Ϊn����������
void reverse(int *arr, int n)
{
    int i = 0,j = n - 1;
    while(i < j)
    {
        swap(&arr[i], &arr[j]);
        i ++;
        j --;
    }
}

//����������ѭ����λi��λ��
void exchange(int *arr, int n, int i)
{
    reverse(arr, i);
    reverse(arr + i, n - i);
    reverse(arr, n);
}

//ԭ�غϲ���������
void inplace_Merge(int* arr, int l, int mid, int r)
{
    int i = l, j = mid, k = r;
    // J in [l,r], j = (l + r) / 2, j closer to r, it can be equal to r
    while(i < j && j <= r)
    {
        int step = 0;
        while(i < j && arr[i] <= arr[j])
            ++ i;
        while(j <= k && arr[j] <= arr[i])
        {
            ++ j;
            ++ step;
        }
        exchange(arr + i, j - i, j - i - step);
        i = i + step;
    }
}

//ԭ�ع鲢����ָ������
void inplace_MergeSortSection(int* arr,int l,int r)
{
    if(l >= r) return;
    int mid = (l + r) / 2;
    inplace_MergeSortSection(arr, l, mid);
    inplace_MergeSortSection(arr, mid + 1, r);
    inplace_Merge(arr, l, mid + 1, r);
}

//ԭ�ع鲢�����㷨
void inplace_mergesort(int* arr,int size)
{
    inplace_MergeSortSection(arr, 0, size - 1);
}

//����ռ�ĺϲ��㷨
void extraspace_merge(int *arr,int l, int mid, int r)
{
    //[l,r]�����ϵĹ鲢
    //��Ϊ[l,mid]&[mid+1,r]
    int leftIndex = l;
    int rightIndex = mid + 1;
    int arrIndex = 0;
    int* newarr = (int*)malloc(sizeof(int) * (r - l + 1));
    while(leftIndex <= mid && rightIndex <= r)
    {
        newarr[arrIndex++] = arr[leftIndex] < arr[rightIndex] ? arr[leftIndex++] : arr[rightIndex++];
    }

    while(leftIndex <= mid)
        newarr[arrIndex++] = arr[leftIndex++];
    while(rightIndex <= r)
        newarr[arrIndex++] = arr[rightIndex++];

    for (int i = l, t = 0; i <=r ; ++i, ++t) {
        arr[i] = newarr[t];
    }

}

//����ռ������鲢�����㷨
void mergesort_section(int* arr, int l, int r)
{
    if( l >= r) return;
    int mid = (l + r) / 2;
    mergesort_section(arr, l, mid);
    mergesort_section(arr, mid + 1, r);
    extraspace_merge(arr, l, mid, r);
}

//����ռ�Ĺ鲢�����㷨
void merge_sort(int *arr, int size) {
    mergesort_section(arr, 0, size - 1);
}
