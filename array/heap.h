#define MAX_HEAP_SIZE 256

struct heap
{
    int size;
    int elements[MAX_HEAP_SIZE];
};

void heap_init(struct heap *h);
int heap_minimum(struct heap *h);
int heap_insert(struct heap *h, int value);
int heap_delete_minimum(struct heap *h);
