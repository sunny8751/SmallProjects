#include <iostream>
#include "BST.h"

using namespace std;

BST::BST() {
    root = nullptr;
    size = 0;
}

BST::BST(vector<int> arr) {
    root = nullptr;
    size = 0;
    for (int i = 0; i < arr.size(); i++) {
        add(arr[i]);
    }
}

void BST::print() const {
    inorderTraversal(root);
    cout << endl;
}

void BST::add(int data) {
    root = addHelper(data, root);
}

Node* BST::addHelper(int data, Node* node) {
    if (node == nullptr) {
        size++;
        return new Node(data);
    }
    if (data < node->getData()) {
        node->setLeft(addHelper(data, node->getLeft()));
        return node;
    } else if (data > node->getData()) {
        node->setRight(addHelper(data, node->getRight()));
        return node;
    }
    return nullptr;
}

void BST::remove(int data) {
    root = removeHelper(data, root);
}

Node* BST::removeHelper(int data, Node* node) {
    if (node == nullptr) {
        cout << "Could not remove " << data << endl;
        return nullptr;
    }
    if (data < node->getData()) {
        node->setLeft(removeHelper(data, node->getLeft()));
        return node;
    } else if (data > node->getData()) {
        node->setRight(removeHelper(data, node->getRight()));
        return node;
    } else {
        if (node->getLeft() == nullptr && node->getRight() == nullptr) {
            delete node;
            size--;
            return nullptr;
        } else if (node->getLeft() != nullptr && node->getRight() != nullptr) {
            //both children
            Node* successor = node->getRight();
            while (successor->getLeft() != nullptr) {
                successor = successor->getLeft();
            }
            Node* newNode = new Node(successor->getData());
            newNode->setRight(removeHelper(successor->getData(), node->getRight()));
            newNode->setLeft(node->getLeft());
            delete node;
            size--;
            return newNode;
        } else if (node->getLeft() != nullptr) {
            Node* ptr = node->getLeft();
            delete node;
            size--;
            return ptr;
        } else {
            Node* ptr = node->getRight();
            delete node;
            size--;
            return ptr;
        }
    }
}

void BST::inorderTraversal(Node* node) const {
    if (node == nullptr) {
        return;
    }
    inorderTraversal(node->getLeft());
    cout << node->getData() << " ";
    inorderTraversal(node->getRight());
}
