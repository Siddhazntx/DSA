#include <iostream>
#include <vector>
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

int heightoftree(Node* root){
    if(root == NULL) return 0;

    int lefth = heightoftree(root->left);
    int righth = heightoftree(root->right);

    return 1+max(lefth,righth);
}


int main() {
   
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6); // Deepest node

    cout << "Height of the tree: " << heightoftree(root) << "\n";

    return 0;
}