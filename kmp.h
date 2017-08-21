#ifndef _KMP_H_
#define _KMP_H_

#include <iostream>
#include <stdio.h>
#include <string.h>

void getNext(const char *, int *);
void getNextOptimized(const char *, int *);
int subSearch(const char *, const char *, int *);

#endif

