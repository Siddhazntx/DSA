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

vector<int> rightview(Node* root){
    vector<int> ans;
    if(root == NULL) return ans;
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();

        for(int i=0;i<size;i++){
            Node* top = q.front();
            q.pop();

            if(i == size-1){
                ans.push_back(top->val);
            }
            if(top->left != NULL) q.push(top->left);
            if(top->right != NULL) q.push(top->right);
        }
    }
    return ans;
}

int main() {
    // Constructing this binary tree:
    //         1
    //       /   \
    //      2     3
    //       \     \
    //        5     4
    //       /
    //      6   <-- This should be visible from the right!
    
    Node* root = new Node(1);
    
    // Level 1
    root->left = new Node(2);
    root->right = new Node(3);
    
    // Level 2
    root->left->right = new Node(5);
    root->right->right = new Node(4);
    
    // Level 3
    root->left->right->left = new Node(6);

    // Call your function
    vector<int> result = rightview(root);

    // Print the results
    cout << "Right View of the binary tree is: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Expected Output: 1 3 4 6
    return 0;
}