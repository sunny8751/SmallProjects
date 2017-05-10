#ifndef BST_H

#define BST_H

#include "Node.h"
#include <vector>

class BST {
public:
    BST();
    BST(std::vector<int> arr);
    void print() const;
    void add(int data);
    void remove(int data);
private:
    Node* root;
    int size;
    Node* addHelper(int data, Node* node);
    Node* removeHelper(int data, Node* node);
    void inorderTraversal(Node* node) const;
};
#endif
