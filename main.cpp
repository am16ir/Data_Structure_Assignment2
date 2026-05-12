#include <bits/stdc++.h>
#include "AVL.h"
#include "BST.h"

using namespace std;

int main() {
    int s=0, t=0;
    BST bst_tree;
    insertFromFile("RandomBooks.txt", bst_tree);
    BST::inorder(bst_tree.root);
    cout << "BST height: " << bst_tree.getHeight(bst_tree.root) << endl;
    BST::search(bst_tree.root, 8, s);
    cout << "Number of steps: " << s << endl;
    cout << "--------------------------------------------------------" <<endl;
    AVL avl_tree;
    insertFromFile("RandomBooks.txt", avl_tree);
    BST::inorder(avl_tree.root);
    cout << "AVL height: " << avl_tree.getHeight(avl_tree.root) << endl;
    BST::search(avl_tree.root, 8, t);
    cout << "Number of steps: " << t << endl;
    return 0;
}