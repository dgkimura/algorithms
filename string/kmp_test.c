#include <stdio.h>

#include "kmp.h"


void
test_search(char *substring, char *string, int index)
{
    printf("%s\n", search(substring, string)==index ? "PASS" : "FAIL");
}


/*
 * Test: gcc kmp_test.c kmp.c
 */
int
main(char *argv[], int argc)
{
    // substring not in string
    test_search("aaaa", "aabaaabaabaaa", -1);

    // substring is in string
    test_search("aabaabaaa", "aabaaabaabaaa", 4);

    // substring equals string
    test_search("aabaabaaa", "aabaabaaa", 0);
}
