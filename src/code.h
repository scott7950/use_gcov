#ifndef __CODE_H__
#define __CODE_H__
struct BT {
    int x;
    BT* l;
    BT* r;
};

int foo(int);
void bubbleSort(int*, int);
bool insert(BT*, int);
int nodesBetween(BT*, int, int);

#endif

