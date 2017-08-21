/* refer to http://www.tuicool.com/articles/yayeIbe */
#include <iostream>
#include <stdio.h>
#include <string.h>

#define GETNEXT
#define GETNEXTOPTIMIZED

using namespace std;
void printArray(int *, int);
void printIndex(const char *);
void outputStr(const char *);
void printMaster(char, int);
void getNext(const char *, int *);
void getNextOptimized(const char *, int *);
int subSearch(const char *, const char *, int *);

int main(int argc, const char *argv[]) {
    const char *str = "BBCABCDABABCDABCDABDET";
    const char *pattern = "BCDABDE";
    const int len = strlen(pattern);
    int *next = new int[len];
    getNext(pattern, next);

    /* print original string */
    cout << "Original Pattern: " << pattern << endl;
    cout << "Original String:  " << str << endl;
#ifdef GETNEXT
    cout << "Next Array: ";
    printArray(next, len);
#endif
#ifdef GETNEXTOPTIMIZED
    getNextOptimized(pattern, next);
    cout << " Optimized: ";
    printArray(next, len);
#endif
    cout << endl;

    int index = subSearch(str, pattern, next);
    /* good output format */
    if (index >= 0) {
        printIndex(str);
        cout << "       [ index = " << index << " ]" << endl;
        outputStr(str);
        printMaster(' ', index);
        outputStr(pattern);
    } else {
        cout << "Sorry, Not Found." << endl;
    }

    delete next;
    return 0;
}

inline void printArray(int *nums, int N) {
    for (int i = 0; i < N; ++i) {
        printf("%3d", nums[i]);
    }
    cout << endl;
    return;
}

inline void printMaster(char ch, int gap) {
    if (gap > 0) {
        while (gap--) {
            cout << ch;
        }
    }
    return;
}

inline void printIndex(const char *str) {
    int len = strlen(str);
    int i = 0;
    while (i < len) {
        cout << (i++) % 10;
    }
    return;
}

inline void outputStr(const char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; ++i) {
        cout << str[i];
    }
    cout << endl;
}

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

