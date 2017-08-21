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

void getNext(const char *str, int *next) {
    const int len = strlen(str);
    int j = 0, k = -1;
    next[0] = -1;
    while (j < len - 1) {
        if (-1 == k || str[j] == str[k]) {
            next[++j] = ++k;
        } else {
            k = next[k];
        }
    }

    return;
}

int subSearch(const char *str, const char *pattern, int *next) {
    int lenStr = strlen(str);
    int lenPat = strlen(pattern);
    int i = 0, j = 0;
    while (i < lenStr && j < lenPat) {
        if (-1 == j || str[i] == pattern[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    if (j == lenPat) {
        return i - j;
    }
    return -1;
}

void getNextOptimized(const char *str, int *next) {
    int len = strlen(str);
    int j = 0, k = -1;
    next[0] = -1;
    while (j < len - 1) {
        if (k == -1 || str[j] == str[k]) {
            if (str[++j] == str[++k]) {
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
