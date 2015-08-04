#include <queue>
#include "code.h"
#include <iostream>

using std::queue;
using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
    foo(0);

    int data[] = {1, 2, 7, 3, 8, 4, 5, 8, 1, 0, 9, 2};
    int size = sizeof(data)/sizeof(int);
    bubbleSort(data, size);

    for(int i=0; i<size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
    
    BT* root;
    root = new BT;
    root->x = 29;
    root->l = nullptr;
    root->r = nullptr;

    insert(root, 18);
    insert(root, 37);
    insert(root, 12);
    insert(root, 19);
    insert(root, 30);
    insert(root, 41);
    
    queue<BT*> nodes;
    nodes.push(root);
    while(nodes.size()) {
        BT* node = nodes.front();
        nodes.pop();

        cout << node->x << " ";
    
        if(node->l != nullptr) {
            nodes.push(node->l);
        }
        if(node->r != nullptr) {
            nodes.push(node->r);
        }
    }
    cout << endl;

    int nodeNum = nodesBetween(root, 12, 19);
    cout << nodeNum << endl;
    
    return 0;
}

