//
// Created by lihongyi on 2/26/18.
//

#ifndef DATASTRUCTURE_RBTREEUTIL_H
#define DATASTRUCTURE_RBTREEUTIL_H


#include "RBTree.h"

void inorderHelper(Node *root) {
    if (root == nullptr) {
        return ;
    }

    inorderHelper(root->left);
    std::cout << root->data << " ";
    inorderHelper(root->right);
}

Node* BSTInsert(Node *root, Node *pt) {
    if (root == nullptr) {
        return pt;
    }

    if (pt->data < root->data) {
        root->left = BSTInsert(root->left, pt);
        root->left->parent = root;
    }
    else if (pt->data > root->data) {
        root->right = BSTInsert(root->right, pt);
        root->right->parent = root;
    }

    return root;
}

void levelOrderHelper(Node *root) {
    if (root == nullptr) {
        return;
    }

    std::queue<Node *> q;
    q.push(root);

    while (!q.empty()) {
        Node *tmp = q.front();
        std::cout << tmp->data << " ";
        q.pop;

        if (tmp->left != nullptr) {
            q.push(tmp->left);
        }

        if (tmp->right != nullptr) {
            q.push(tmp->right);
        }
    }
}

#endif //DATASTRUCTURE_RBTREEUTIL_H
