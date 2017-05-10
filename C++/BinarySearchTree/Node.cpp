#include <iostream>
#include "Node.h"

using namespace std;

Node::Node() {
    this->data = 0;
    left = nullptr;
    right = nullptr;
}

Node::Node(int data) {
    this->data = data;
    left = nullptr;
    right = nullptr;
}

int Node::getData() {
    return this->data;
}

Node* Node::getLeft() {
    return this->left;
}

Node* Node::getRight() {
    return this->right;
}

void Node::print() const {
    cout << this->data;
}

void Node::setData(int data) {
    this->data = data;
}

void Node::setLeft(Node* left) {
    this->left = left;
}

void Node::setRight(Node* right) {
    this->right = right;
}

int add(int data) {
    return 0;
}
