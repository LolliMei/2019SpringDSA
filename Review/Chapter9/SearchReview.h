//
// Created by ������ on 2019-06-23.
//

#ifndef INC_2019SPRINGDSA_SEARCHREVIEW_H
#define INC_2019SPRINGDSA_SEARCHREVIEW_H


/*
 * ˳�����
 */

int seq_search(int *arr, int size, int e) {

    int i;
    for (i = 0; i < size && arr[i] != e; ++i);
    if (i >= 0 && i <= size - 1)
        return i;

    return -1;

}

/*
 * ���ֲ���
 */

int bin_search(const int *arr, int size, int e) {

    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] < e)
            high = mid - 1;
        else if (arr[mid] > e)
            low = mid + 1;
        else
            return mid;

    }

    return -1;

}

/*
 * ��ֵ����
 */

int insert_search(const int *arr, int size, int key) {

    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = (key - arr[low]) / (arr[high] - arr[low]) * (high - low);

        if (arr[mid] < key)
            low = mid + 1;
        else if (arr[mid] > key)
            high = mid - 1;
        else
            return mid;
    }

    return -1;
}

/*
 * �ֿ����
 */

typedef struct Block {
    int maxval;
    int start;
    int end;
} Block;

typedef struct BlockArray {
    Block *block;
    int blocksize;
    int *data;
    int arrsize;

} *BlockArray;


int block_search(BlockArray blockArray, int key) {
    //��λ������ĳ����
    int segment = 0;
    while (key > blockArray->block[segment].maxval) segment++;

    //�ڿ��в���
    int i = blockArray->block[segment].start;
    while (i <= blockArray->block[segment].end
           && key != blockArray->data[i]) {
        i ++;
    }

    //��鷵��ֵ�ĺϷ���
    if(i<= blockArray->block[segment].end)
        return i;
    return -1;
}

/*
 *
 */
#endif //INC_2019SPRINGDSA_SEARCHREVIEW_H
