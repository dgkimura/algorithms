#include <stdlib.h>
#include <string.h>

#include "kmp.h"


/*
 * Allocates a prefix table for the given substring pattern.
 */
int *
create_prefix_table(const char *substring, const int length)
{
    int i, j, *table = (int *)malloc(sizeof(int) * length);
    memset(table, 0, sizeof(int) * length);

    j = 0;
    for (i = 1; i < length; i++) {
        while (j > 0 && substring[i] != substring[j]) {
            j = table[j-1];
        }
        if (substring[i] == substring[j]) {
            j += 1;
        }
        table[i] = j;
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
FindSubStringIndex(const char *substring, const char *string) {
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
