
#ifndef BST_H
#define BST_H

#include <bits/stdc++.h>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
};

struct Node {
    Book book;
    Node* left;
    Node* right;
    int height = 1;

    Node(Book book) {
        this->book = book;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    virtual ~BST() = default;

    Node* root;

    BST() {
        root = nullptr;
    }

    int getHeight(Node* node);

    // Insert
    virtual Node* insert(Node* node, Book book);

    // Find minimum node
    static Node* minValue(Node* node);

    virtual Node* deleteNode(Node* node, int key);

    Node* search(Node* node, int key, int& steps);

    void printNode(Node* node);

    void inorder(Node* node);

    void printRange(Node* node, int low, int high);

    Node* findClosest(Node* node, int target);

};


#endif //BST_H
