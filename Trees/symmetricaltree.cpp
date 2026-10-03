#include <iostream>
#include <vector>
#include<queue>
#include<map>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    
    // Constructor
    Node(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

bool checksymm(Node* left, Node* right){
    if(left == NULL && right == NULL) return true;
    if(left == NULL || right == NULL) return false;

    if(left->val != right->val) return false;

    return checksymm(left->left, right->right) &&
           checksymm(left->right, right->left);
}
bool isSymmetrical(Node* root){
    return root == NULL || checksymm(root->left, root->right);
}

int main() {
    // ---------------------------------------------------
    // Test Case 1: A Symmetric Tree
    //        1
    //      /   \
    //     2     2
    //    / \   / \
    //   3   4 4   3
    // ---------------------------------------------------
    Node* root1 = new Node(1);
    
    root1->left = new Node(2);
    root1->right = new Node(2);
    
    root1->left->left = new Node(3);
    root1->left->right = new Node(4);
    
    root1->right->left = new Node(4);
    root1->right->right = new Node(3);

    if (isSymmetrical(root1)) {
        cout << "Tree 1 is Symmetrical." << endl;
    } else {
        cout << "Tree 1 is NOT Symmetrical." << endl;
    }

    // ---------------------------------------------------
    // Test Case 2: An Asymmetric Tree
    //        1
    //      /   \
    //     2     2
    //      \     \
    //       3     3
    // ---------------------------------------------------
    Node* root2 = new Node(1);
    
    root2->left = new Node(2);
    root2->right = new Node(2);
    
    root2->left->right = new Node(3);
    root2->right->right = new Node(3); // To be symmetric, this should be left child

    if (isSymmetrical(root2)) {
        cout << "Tree 2 is Symmetrical." << endl;
    } else {
        cout << "Tree 2 is NOT Symmetrical." << endl;
    }

    return 0;
}