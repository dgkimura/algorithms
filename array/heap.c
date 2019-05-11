#include <string.h>

#include "heap.h"

#define SWAP(x, y) x ^= y; y ^= x; x ^= y;

void
heap_init(struct heap *h)
{
    memset(h, 0, sizeof(struct heap));
    h->size = -1;
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
    int parent, child, index;

    index = h->size + 1;
    h->elements[index] = value;

    for (;;)
    {
        child = h->elements[index];
        parent = h->elements[(index - 1) / 2];

        if (index == 0 || parent < child)
        {
            /*
             * If we have reached the root or parent is less than child then
             * there is no more work to do.
             */
            break;
        }

        if (child < parent)
        {
            /*
             * If child is less than parent then we need to percolate the value
             * up.
             */
            SWAP(h->elements[index], h->elements[(index - 1) / 2]);
        }
        index /= 2;
    }

    h->size += 1;
    return value;
}

int
heap_delete_minimum(struct heap *h)
{
    return 0;
}
