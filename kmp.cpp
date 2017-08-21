#include <stdio.h>
#include "kmp.h"

int subSearch(const char *str, const char *pattern, int *next) {
    const int M = strlen(str);
    const int N = strlen(pattern);
    if (M < N) return -1;
    int i = 0, j = 0;
    while (j < N && i < M) {
        if (j == -1 || str[i] == pattern[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    if (j == N) {
        return i - N;
    }
    return -1;
}

void getNext(const char *pattern, int *next) {
    const int len = strlen(pattern);

    int k = -1;
    int j = 0;
    next[0] = -1;
    while (j < len - 1) {
        if (k == -1 || pattern[j] == pattern[k]) {
            next[++j] = ++k; 
        } else {
            k = next[k];
        }
    }
    return;
}

void getNextOptimized(const char *pattern, int *next) {
    const int len = strlen(pattern);

    int k = -1;
    int j = 0;
    next[0] = -1;
    while (j < len - 1) {
        if (k == -1 || pattern[j] == pattern[k]) {
            if (pattern[++j] == pattern[++k]) {
                next[j] = next[k];
            } else {
                next[j] = k;
            }
        } else {
            k = next[k];
        }
    }
    return;
}

