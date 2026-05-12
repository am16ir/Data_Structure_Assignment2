#include <bits/stdc++.h>
#include "AVL.h"
#include "BST.h"

using namespace std;

void insertFromFile(string filename, BST& tree) {
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

int main() {
    int BSTSteps = 0, AvlSteps = 0;
    BST bst_tree1;
    AVL avl_tree1;
    insertFromFile("RandomBooks.txt", bst_tree1);
    insertFromFile("RandomBooks.txt", avl_tree1);

    cout<<"Random IDs"<<endl;
    cout << "BST height: " << bst_tree1.getHeight(bst_tree1.root) << endl;
    bst_tree1.search(bst_tree1.root, 8, BSTSteps);
    cout << "Number of steps finding 8: " << BSTSteps << endl;

    cout << "--------------------------------------------------------" <<endl;

    cout << "AVL height: " << avl_tree1.getHeight(avl_tree1.root) << endl;
    avl_tree1.search(avl_tree1.root, 8, AvlSteps);
    cout << "Number of steps finding 8: " << AvlSteps << endl;

    cout<<"===================================================================\n";

    int BST1Steps = 0, Avl1Steps = 0;
    BST bst_tree2;
    AVL avl_tree2;
    insertFromFile("SortedBooks.txt", bst_tree2);
    insertFromFile("SortedBooks.txt", avl_tree2);

    cout<<"Sorted IDs"<<endl;
    cout << "BST height: " << bst_tree2.getHeight(bst_tree2.root) << endl;
    bst_tree2.search(bst_tree2.root, 65, BST1Steps);
    cout << "Number of steps finding 65: " << BST1Steps << endl;

    cout << "--------------------------------------------------------" <<endl;

    cout << "AVL height: " << avl_tree2.getHeight(avl_tree2.root) << endl;
    avl_tree2.search(avl_tree2.root, 65, Avl1Steps);
    cout << "Number of steps finding 65: " << Avl1Steps << endl;

    return 0;
}