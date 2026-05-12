#include <bits/stdc++.h>
#include "BST.h"
using namespace std;

int BST::getHeight(Node* node) {
    if (node == nullptr) return 0;
    return 1 + max(getHeight(node->left), getHeight(node->right));
}

Node* BST::insert(Node* node, Book book) {
    if (node == nullptr)
        return new Node(book);

    if (book.id < node->book.id)
        node->left = insert(node->left, book);

    else if (book.id > node->book.id)
        node->right = insert(node->right, book);

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    return node;
}

Node* BST::minValue(Node* node) {
    while (node && node->left != nullptr)
        node = node->left;
    return node;
}

Node* BST::deleteNode(Node* node, int key) {

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

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    return node;
}

Node* BST::search(Node* node, int key, int& steps) {
    steps++;
    if (node == nullptr || node->book.id == key)
        return node;

    if (key < node->book.id)
        return search(node->left, key, steps);

    return search(node->right, key, steps);
}


void BST::printNode(Node* node) {
    cout << "ID: " <<node->book.id
    << " | Title: " << node->book.title
    << " | Author: " << node->book.author << endl;
}

void BST::inorder(Node* node) {
    if (node != nullptr) {
        inorder(node->left);
        printNode(node);
        inorder(node->right);
    }
}

void BST::printRange(Node* node, int low, int high) {
    if (node == nullptr)
        return;

    if (low < node->book.id)
        printRange(node->left, low, high);

    if (node->book.id >= low && node->book.id <= high) {
        printNode(node);
    }

    if (high > node->book.id)
        printRange(node->right, low, high);
}

Node* BST::findClosest(Node* node, int target) {
    if (node == nullptr)
        return nullptr;

    Node* closest = node;

    while (node != nullptr) {

        if (abs(node->book.id - target) <
            abs(closest->book.id - target)) {

            closest = node;
            }

        if (target < node->book.id)
            node = node->left;

        else if (target > node->book.id)
            node = node->right;

        else
            return node;
    }

    return closest;
}