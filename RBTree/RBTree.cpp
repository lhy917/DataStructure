//
// Created by lihongyi on 2/26/18.
//

#include "RBTree.h"
#include "RBTreeUtil.h"

void RBTree::rotateLeft(Node *&root, Node *&pt) {
    Node *pt_right = pt->right;

    pt->right = pt_right->left;

    if (pt->right != nullptr) {
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
    pt->left = pt_left->right;

    if (pt->left != nullptr) {
        pt->left->parent = pt;
    }

    pt_left->parent = pt->parent;

    if (pt->parent == nullptr) {
        root = pt_left;
    }
    else if (pt == pt->parent->left) {
        pt->parent->left = pt_left;
    }
    else {
        pt->parent->right = pt_left;
    }

    pt_left->right = pt;
    pt->parent = pt_left;
}

void RBTree::fixViolation(Node *&root, Node *&pt) {
    Node *parent_pt = nullptr;
    Node *grand_parent_pt = nullptr;

    while ((pt != root) && (pt->color != Color::BLACK) && (pt->parent->color == Color::RED)) {
        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;

        if (parent_pt == grand_parent_pt->left) {
            Node *uncle_pt = grand_parent_pt->right;

            if (uncle_pt != nullptr && uncle_pt->color == Color::RED) {
                grand_parent_pt->color= Color::RED;
                parent_pt->color = Color::BLACK;
                uncle_pt->color = Color::BLACK;
                pt = grand_parent_pt;
            }
            else {
                if (pt == parent_pt->right) {
                    rotateLeft(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                rotateRight(root, grand_parent_pt);
                std::swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        } else {
            Node *uncle_pt = grand_parent_pt->left;

            if ((uncle_pt != nullptr) && (uncle_pt->color == Color::RED)) {
                grand_parent_pt->color = Color::RED;
                parent_pt->color = Color::BLACK;
                uncle_pt->color = Color::BLACK;
                pt = grand_parent_pt;
            } else {
                if (pt == parent_pt->left) {
                    rotateRight(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                rotateLeft(root, grand_parent_pt);
                std::swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }
    }

    root->color = Color::BLACK;
}

void RBTree::insert(const int &data) {
    Node *pt = new Node(data);

    root = BSTInsert(root, pt);
    fixViolation(root, pt);
}

void RBTree::inorder() { inorderHelper(root); }

void RBTree::levelOrder() { levelOrderHelper(root); }