#define MAX_HEAP_SIZE 256

struct heap
{
    int size;
    int elements[MAX_HEAP_SIZE];
};

int heap_insert(struct heap *h, int value);
int heap_delete(struct heap *h, int value);
