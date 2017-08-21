#include <iostream>
#include <string.h>
using namespace std;

static int myStr(const char *, const char *);

int main(int argc, const char *argv[]) {
    const char *str = "corsair";
    const char *pattern = "rk";
    cout << "index is: " << myStr(str, pattern) << endl;

    return 0;
}

int myStr(const char *str, const char *pattern) {
    const int m = strlen(str);
    const int n = strlen(pattern);
    for (int i = 0; i <= m - n + 1; ++i) {
        if (str[i] == pattern[0]) {
            for (int j = 0; j < n; ++j) {
                if (i + j >= m || str[i + j] != pattern[j]) {
                    return -1;
                }
            }
            return i;
        }
    }
    return -1;
}

