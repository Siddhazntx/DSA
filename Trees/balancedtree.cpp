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

int checkheight(Node* root){
    if(root == NULL) return 0;

    int lh = checkheight(root->left);
    int rh = checkheight(root->right);

    if(lh == -1) return -1;
    if(rh == -1) return -1;

    if(abs(rh-lh) > 1) return -1;

    return 1+max(lh,rh);
}

bool checkbalancedtree(Node* root){
    return checkheight(root) != -1;
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->left = new Node(5);

    cout << "Is tree balanced? " << (checkbalancedtree(root) ? "Yes" : "No") << "\n";
    // Expected output: No
    
    return 0;
}