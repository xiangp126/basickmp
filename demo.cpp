#include <iostream>
#include "kmp.h"
#include "demo.h"

#define GETNEXT
#define GETNEXTOPTIMIZED

using namespace std;

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

