//
// Created by lihongyi on 2/26/18.
//

#include "RBTree.h"

void RBTree::rotateLeft(Node *&root, Node *&pt) {
    Node *pt_right = pt->right;

    pt->right = pt_right->left;

    if (pt->right!= nullptr) {
        pt->right->parent = pt;
    }

    pt_right->parent = pt->parent;

    if (pt->parent == nullptr) {
        root = pt_right;
    }
    else if (pt == pt->parent->left) {
        pt->parent->left = pt_right;
    }
    else {
        pt->parent->right = pt->right;
    }

    pt->right->left = pt;
    pt->parent = pt_right;
}

void RBTree::rotateRight(Node *&root, Node *&pt) {
    Node *pt_left = pt->left;
    pt->left = pt_left = pt_left->right;

    if (pt->left != nullptr) {
        pt->left->parent = pt;
    }

    pt->left->parent = pt->parent;

    if (pt->parent == nullptr) {
        root = pt_left;
    }
    else if (pt->parent->left) {
        pt->parent->left = pt_left;
    }
    else {
        pt->parent->left = pt_left;
    }

    pt_left->right = pt;
    pt->parent = pt_left;
}

void RBTree::fixViolation(Node *&root, Node *&pt) {
    Node *parent_pt = nullptr;
    Node *grand_parent_pt = nullptr;
}

