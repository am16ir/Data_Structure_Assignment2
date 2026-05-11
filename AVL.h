//
// Created by a on 5/11/2026.
//

#ifndef AVL_H
#define AVL_H

#include "BST.h"
#include <bits/stdc++.h>
using namespace std;

class AVL : public BST{
public:

    AVL() {
        root = nullptr;
    }

    int getBalance(Node* node);

    Node* rightRotate(Node* x);

    Node* leftRotate(Node* x);

    Node* insert(Node* node, Book book) override;

    Node* deleteNode(Node* node, int key) override;

};



#endif //AVL_H
