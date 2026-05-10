#include <algorithm>
#include <iostream>

using namespace std;

struct Node {
    int id;
    string title;
    string author;
    Node* left;
    Node* right;
    int height;

    Node(int value, string book_title, string author_name) {
        this->id = value;
        this->title = book_title;
        this->author = author_name;
        left = right = nullptr;
        height = 1;
    }
};

class AVL {
public:
    Node* root;

    AVL() {
        root = nullptr;
    }

    int getHeight(Node* node) {
        if (node == nullptr) return 0;
        return node->height;
    }

    int getBalance(Node* node) {
        if (node == nullptr) return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    Node* rightRotate(Node* x) {
        Node* y = x->left;
        Node* T2 = y->right;

        y->right = x;
        x->left = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    Node* insert(Node* node, int key, string book_title, string author_name) {

        if (node == nullptr)
            return new Node(key, book_title, author_name);

        if (key < node->id)
            node->left = insert(node->left, key, book_title, author_name);
        else if (key > node->id)
            node->right = insert(node->right, key, book_title, author_name);
        else
            return node;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalance(node);

        if (balance > 1 && key < node->left->id)
            return rightRotate(node);
        if (balance < -1 && key > node->right->id)
            return leftRotate(node);
        if (balance > 1 && key > node->left->id) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && key < node->right->id) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node* minValue(Node* node) {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int key) {

        if (node == nullptr)
            return node;

        if (key < node->id)
            node->left = deleteNode(node->left, key);
        else if (key > node->id)
            node->right = deleteNode(node->right, key);
        else {
            if (node->left == nullptr || node->right == nullptr) {
                Node* temp = node->left ? node->left : node->right;

                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }
                delete temp;
            }
            else {
                Node* temp = minValue(node->right);
                node->id = temp->id;
                node->right = deleteNode(node->right, temp->id);
            }
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

    Node* search(Node* node, int key) {
        if (node == nullptr || node->id == key)
            return node;

        if (key > node->id)
            return search(node->right, key);

        return search(node->left, key);
    }

    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << "ID: " << node->id << ", Title: " << node->title << ", Author: " << node->author << endl;
            inorder(node->right);
        }
    }
};

void findRange(Node* node, int min, int max) {
    if (node == nullptr) return;
    if (node->id > min) findRange(node->left, min, max);
    if (node->id >= min && node->id <= max) cout << "ID: " << node->id << ", Title: " << node->title << ", Author: " << node->author << endl;
    if (node->id < max) findRange(node->right, min, max);
}

int main() {

    AVL library;
    int n;
    cout << "Enter the number of books: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        string l, m;
        cout << "Enter book id: ";
        cin >> k;
        cin.ignore();
        cout << "Enter book title: ";
        getline(cin, l);
        cout << "Enter author: ";
        getline(cin, m);
        cout <<"=================================================="<< endl;
        library.root = library.insert(library.root, k, l, m);
    }
    findRange(library.root, 3, 7);
    cout << endl << "Height of AVL: " << library.getHeight(library.root)<< endl;

    return 0;
}