#include <iostream>
#include <vector>
#include <queue> 

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

int maxdepth(Node* root){
    if(root == NULL) return 0;
    Node* node = root;

    int lh = maxdepth(node->left);
    int rh = maxdepth(node->right);

    return 1+max(lh,rh);
}

int main() {

    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    
    cout << "Max Depth of tree is: " << maxdepth(root) << "\n"; 
    // Expected output: 4
    
    return 0;
}