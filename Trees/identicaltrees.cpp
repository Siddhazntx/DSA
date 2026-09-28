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

bool identicalTrees(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL) return true;
    if(root1 == NULL || root2 == NULL) return false;

    return (root1->val == root2->val) &&
           identicalTrees(root1->left,root2->left) &&
           identicalTrees(root1->right,root2->right);
}


int main() {
    // Build Tree 1
    //       1
    //      / \
    //     2   3
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    // Build Tree 2 (Identical to Tree 1)
    //       1
    //      / \
    //     2   3
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);

    // Build Tree 3 (Structurally same, different value)
    //       1
    //      / \
    //     2   4
    Node* root3 = new Node(1);
    root3->left = new Node(2);
    root3->right = new Node(4);

    // Test the trees
    if (identicalTrees(root1, root2)) {
        cout << "Tree 1 and Tree 2 are identical." << endl;
    } else {
        cout << "Tree 1 and Tree 2 are not identical." << endl;
    }

    if (identicalTrees(root1, root3)) {
        cout << "Tree 1 and Tree 3 are identical." << endl;
    } else {
        cout << "Tree 1 and Tree 3 are not identical." << endl;
    }

    return 0;
}