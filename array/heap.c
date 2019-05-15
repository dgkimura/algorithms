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
 *
 * Return 1 on success and 0 on failure.
 */
int
heap_insert(struct heap *h, int value)
{
    int parent, child, index;

    if (h->size + 1 > MAX_HEAP_SIZE)
    {
        return 0;
    }

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
    return 1;
}

int
heap_delete_minimum(struct heap *h)
{
    if (h->size <= 0)
    {
        return 0;
    }

    h->elements[0] = h->elements[h->size];
    h->size -= 1;

    return 1;
}
