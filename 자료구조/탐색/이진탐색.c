#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int list[SIZE]; //단, 배열은 정렬되어있어야 한다.

int binary_search(int key,int low,int high) {
    int mid;
    if (low<=high) {
        mid = (low + high) / 2;
        if (key==list[mid]) return mid;
        else if (key<list[mid]) return binary_search(key,low,mid-1); //함수를 계속 호출하므로 비효율적임.
        else return binary_search(key,mid+1,high);
    }
}

int binary_search(int key,int low,int high) {
    int mid;
    while (low<=high) {
        mid = (low + high) / 2;
        if (key==list[mid]) return mid;
        else if (key>list[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
