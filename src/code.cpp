#include <queue>
#include "code.h"

using std::queue;

int foo(int param) {
    if (param) {
        return 1;
    } else {
        return 0;
    }
}

void bubbleSort(int* data, int size) {
    if(size <= 1) {
        return;
    }

    for(int i=0; i<size-1; i++) {
        for(int j=1; j<size; j++) {
            if(data[j-1] > data[j]) {
                int dataTmp = data[j-1];
                data[j-1] = data[j];
                data[j] = dataTmp;
            }
        }
    }
}

bool insert(BT* root, int value) {
    BT* node = root;
    while(1) {
        if(value < node->x) {
            if(node->l != nullptr) {
                node = node->l;
            } else {
                node->l = new BT;

                node = node->l;
                node->x = value;
                node->l = nullptr;
                node->r = nullptr;

                return true;
            }
        } else if(value > node->x) {
            if(node->r != nullptr) {
                node = node->r;
            } else {
                node->r = new BT;
                
                node = node->r;
                node->x = value;
                node->l = nullptr;
                node->r = nullptr;

                return true;
            }
        } else {
            return false;
        }
    }
}

int nodesBetween(BT* root, int min, int max) {
    int nodeNum = 0;
    queue<BT*> nodes;

    nodes.push(root);

    while(nodes.size()) {
        BT* node = nodes.front();
        nodes.pop();

        if(node->x > min && node->x < max) {
            nodeNum++;

            if(node->l != nullptr) {
                nodes.push(node->l);
            }
            if(node->r != nullptr) {
                nodes.push(node->r);
            }
        } else if(node->x <= min) {
            if(node->x == min) {
                nodeNum++;
            }

            if(node->r != nullptr) {
                nodes.push(node->r);
            }
        } else if(node->x >= max) {
            if(node->x == max) {
                nodeNum++;
            }

            if(node->l != nullptr) {
                nodes.push(node->l);
            }
        }
    }

    return nodeNum;
}

