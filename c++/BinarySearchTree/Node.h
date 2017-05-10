#ifndef NODE_H

#define NODE_H
class Node {
public:
    Node();
    Node(int data);
    int getData();
    Node* getLeft();
    Node* getRight();
    void print() const;
    void setData(int data);
    void setLeft(Node* left);
    void setRight(Node* right);
private:
    int data;
    Node* left;
    Node* right;
};
#endif
