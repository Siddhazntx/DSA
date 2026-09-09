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

vector<int> levelorder(Node* root) {
    vector<int> ans;
    if(root == NULL) return ans;
    queue<Node*>q;
    q.push(root); 
    
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        ans.push_back(curr->val);

        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }

    
    return ans;
}

int main() {

    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    // Call your function
    vector<int> result = levelorder(root);
    
    // Print the result
    cout << "Level Order Output: ";
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << "\n"; // Expected output: 1 2 3 4 5 6 7
    
    return 0;
}