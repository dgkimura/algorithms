#include <string.h>

#include "heap.h"

#define SWAP(x, y) x ^= y; y ^= x; x ^= y;

void
heap_init(struct heap *h)
{
    memset(h, 0, sizeof(struct heap));
}

int
heap_minimum(struct heap *h)
{
    return h->elements[0];
}

/*
 * Insert a value into the heap.
 */
int
heap_insert(struct heap *h, int value)
{
    int lchild, rchild, index;

    index = 0;

    for (;;)
    {
        if (index >= h->size)
        {
            h->elements[index] = value;
            break;
        }

        if (value < h->elements[index])
        {
            SWAP(h->elements[index], value)
        }

        lchild = h->elements[index * 2];
        rchild = h->elements[index * 2 + 1];

        /*
         * Decide whether to traverse down the left or right child.
         */
        index = lchild < rchild ? index * 2 : index * 2 + 1;
    }

    h->size += 1;
    return value;
}

int
heap_delete_minimum(struct heap *h)
{
    return 0;
}
