//
// Created by lihongyi on 2/26/18.
//

#ifndef DATASTRUCTURE_RBTREE_H
#define DATASTRUCTURE_RBTREE_H

enum class Color {RED, BLACK};

struct Node {
    int data;
    bool color;
    Node *left, *right, *parent;

    Node(int data) {
        this->data = data;
        left = right = parent = nullptr;
    }
};

class RBTree {
private:
    Node *root;

protected:
    void rotateLeft(Node *&, Node *&);
    void rotateRight(Node *&, Node *&);
    void fixViolation(Node *&, Node *&);

public:
    RBTree() { root = nullptr; }
    void insert(const int &n);
    void inorder();
    void levelOrder();
};

#endif //DATASTRUCTURE_RBTREE_H
