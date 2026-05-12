
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

    static Node* search(Node* node, int key, int& steps);

    static int get_steps(Node* node);

    static void printNode(Node* node);

    static void inorder(Node* node);

    static void printRange(Node* node, int low, int high);

    static Node* findClosest(Node* node, int target);

};

inline void insertFromFile(string filename, BST& tree) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string idStr, title, author;

        getline(ss, idStr, ',');
        getline(ss, title, ',');
        getline(ss, author);

        Book book;
        book.id = stoi(idStr);
        book.title = title;
        book.author = author;
        tree.root = tree.insert(tree.root, book);
    }
}

#endif //BST_H
