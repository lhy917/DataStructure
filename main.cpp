//
// Created by lihongyi on 2/26/18.
//

#include <iostream>
#include "RBTree/RBTree.h"

int main() {
    std::cout << "Hello Test!" << std::endl;

    // Test: Red-Black Tree
    RBTree tree;

    tree.insert(7);
    tree.insert(6);
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);

    std::cout << "Inoder Traversal of Created Tree\n";
    tree.inorder();

    std::cout << "\n\nLevel Order Traversal of Created Tree\n";
    tree.levelOrder();

    return 0;
}