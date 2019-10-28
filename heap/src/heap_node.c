#include "heap_node.h"

void sift_down(Heap *h) {
    long left = h->left->data;
    long right = h->right->data;
    long d = h->data;
    long smallest;
    if(left < d)
        smallest = left;
    if(right < d)
        smallest = right;
    if(smallest != i) {
        Top temp = arr[i];
        arr[i] = arr[biggest];
        arr[biggest] = temp;
        sift_down(arr, biggest, size);
    }
}

void make_heap(Top *arr, unsigned size) {
    for (long i = size / 2 - 1; i >= 0; i--) {
        sift_down(arr, i, size);
    }
}

Top extract_max(Top *arr, unsigned *size) {
    Top result = arr[0];
    arr[0] = arr[--*size];
    sift_down(arr, 0, *size);
    return result;
}
