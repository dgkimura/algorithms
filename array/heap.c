#include <string.h>

#include "heap.h"

#define SWAP(x, y) x ^= y; y ^= x; x ^= y;

#define LCHILD_INDEX(i) ((i) + 1) * 2 - 1
#define RCHILD_INDEX(i) ((i) + 1) * 2

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

/*
 * Delete minimum value in the heap.
 *
 * Return 1 on success and 0 on failure.
 */
int
heap_delete_minimum(struct heap *h)
{
    int lchild, rchild, index;

    if (h->size <= 0)
    {
        return 0;
    }

    /*
     * Move the greatest element into the root node which we will then
     * percolate down as far as we can.
     */
    h->elements[0] = h->elements[h->size];
    h->size -= 1;

    for (index=0; index < h->size;)
    {
        if (h->size >= LCHILD_INDEX(index))
        {
            lchild = h->elements[LCHILD_INDEX(index)];
            if (lchild < h->elements[(index)])
            {
                /*
                 * If left child is less than current element then we need to
                 * percolate the value down.
                 */
                SWAP(h->elements[(index)], h->elements[LCHILD_INDEX(index)]);
                index = LCHILD_INDEX(index);
            }
            else
            {
                break;
            }
        }
        else if (h->size >= RCHILD_INDEX(index))
        {
            rchild = h->elements[RCHILD_INDEX(index)];
            if (rchild < h->elements[RCHILD_INDEX(index)])
            {
                /*
                 * If right child is less than current element then we need to
                 * percolate the value down.
                 */
                SWAP(h->elements[(index)], h->elements[RCHILD_INDEX(index)]);
                index = RCHILD_INDEX(index);
            }
            else
            {
                break;
            }
        }
        else
        {
            /*
             * If there is no left child or right child then we're done.
             */
            break;
        }

    }

    return 1;
}
