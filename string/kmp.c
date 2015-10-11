#include <stdlib.h>
#include <string.h>

#include "kmp.h"


/*
 * Allocates a prefix table for the given substring pattern.
 */
static int *
create_prefix_table(char *substring, int length)
{
    int i, j, k, *table = malloc(sizeof(int) * length);
    memset(table, 0, sizeof(int) * length);
    i = 0, j = 1;
    k = 0;
    while (j < length) {
        if (substring[i] == substring[j]) {
            k += 1;
            table[j] = k;
            j += 1;
            i += 1;
        } else {
            if (i > 0) {
                i = table[i-1];
                k = table[i];
            } else
            {
                j += 1;
            }
        }
    }
    return table;
}



/*
 * Searches for the given substring inside the given string.
 *
 * Return index of first instance of substring inside string.
 * Return -1 if substring was not found.
 */
int
search(char *substring, char *string) {
    int i, j, index, length;
    length = strlen(substring);
    int *prefix_table = create_prefix_table(substring, length);

    i = 0, j=0, index=-1;
    while (j < strlen(string)) {
        if (substring[i] == string[j]) {
            if (i == length-1) {
                return j - length + 1;
            }
            i += 1, j += 1;
        } else {
            if (i > 0) {
                i = prefix_table[i-1];
            } else {
                j += 1;
            }
        }
    }
    return index;
}
