#ifndef _HEAP_NODE_H
#define _HEAP_NODE_H

typedef struct heap_node {
    struct heap_node *left;
    struct heap_node *right;
    long data;
} Heap;

Heap* new_heap(void);
Heap* new_heap_from_array(long *array, unsigned size);
void delete_heap(Heap *h);

void insert_heap(Heap *h);
long extract_min_heap(Heap *h);
long peek_min_heap(Heap *h);


#endif //  _HEAP_NODE_H
