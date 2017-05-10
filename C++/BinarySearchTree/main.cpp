#include <iostream>
#include "BST.h"

using namespace std;

int main() {
    vector<int> arr = {50, 40, 100, 20, 120, 500, 0, -100, 32, 57, 250, 150, 246};
    BST bst(arr);
    bst.print();
}
