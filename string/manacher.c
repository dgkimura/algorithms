#include <stdlib.h>
#include <string.h>

#define MIN(a, b) (a) < (b) ? (a) : (b)

const char *
FindLongestSubStringPalindrome(const char *string) {
    int i, P[strlen(string)];
    memset(P, 0, sizeof(int) * strlen(string));

    int C=0, R=0;
    for (i=1; i<strlen(string); i++) {
        int ii = C - (i - C);
        P[i] = (i < R) ? MIN(R - i, P[ii]) : 0;

        while (string[i + 1 + P[i]] == string[i - 1 - P[i]]) {
            P[i] += 1;
        }

        if (i + P[i] < R) {
            C = i;
            R = i + P[i];
        }
    }

    int maxCenterIndex = 0;
    int maxLength = 0;
    for (i=0; i<strlen(string); i++) {
        if (P[i] > maxLength) {
            maxLength = P[i];
            maxCenterIndex = i;
        }
    }
    char* result = (char *)malloc(sizeof(char) * maxLength * 2 + 1);
    for (i=0; i<maxLength*2+1; i++) {
        result[i] = string[maxCenterIndex - maxLength + i];
    }
    result[maxLength * 2 + 1] = '\0';
    return result;
}
