#include <bits/stdc++.h>
#include "AVL.h"
#include "BST.h"

using namespace std;

int main() {
    BST bst_tree;
    insertFromFile("RandomBooks.txt", bst_tree);
    BST::inorder(bst_tree.root);
    cout << "BST height: " << bst_tree.getHeight(bst_tree.root) << endl;
    cout << "--------------------------------------------------------" <<endl;
    AVL avl_tree;
    insertFromFile("RandomBooks.txt", avl_tree);
    BST::inorder(avl_tree.root);
    cout << "AVL height: " << avl_tree.getHeight(avl_tree.root) << endl;
    return 0;
}