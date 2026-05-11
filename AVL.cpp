//
// Created by a on 5/11/2026.
//

#include "AVL.h"
#include <bits/stdc++.h>
using namespace std;

int AVL::getBalance(Node* node) {
    if (node == nullptr) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

Node* AVL::rightRotate(Node* x) {
    Node* y = x->left;
    Node* T2 = y->right;

    y->right = x;
    x->left = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node* AVL::leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node* AVL::insert(Node* node, Book book) {
    if (node == nullptr)
        return new Node(book);

    if (book.id < node->book.id)
        node->left = insert(node->left, book);

    else if (book.id > node->book.id)
        node->right = insert(node->right, book);

    else
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    if (balance > 1 && book.id < node->left->book.id)
        return rightRotate(node);
    if (balance < -1 && book.id > node->right->book.id)
        return leftRotate(node);
    if (balance > 1 && book.id > node->left->book.id) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && book.id < node->right->book.id) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node* AVL::deleteNode(Node* node, int key) {

    if (node == nullptr)
        return node;

    // Search
    if (key < node->book.id)
        node->left = deleteNode(node->left, key);

    else if (key > node->book.id)
        node->right = deleteNode(node->right, key);

    else {

        // Case 1: No child
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        }

        // Case 2: One child
        else if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        // Case 3: Two children
        // replace by the successor
        Node* successor = minValue(node->right);

        node->book = successor->book;

        node->right = deleteNode(node->right, successor->book.id);
    }

    if (node == nullptr) return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    if (balance > 1 && getBalance(node->left) >= 0)
        return rightRotate(node);
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && getBalance(node->right) <= 0)
        return leftRotate(node);
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}