#include <iostream>
#include <vector>
#include <queue> 
#include<algorithm>

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

bool isleaf(Node* node){
    return node->left == NULL && node->right == NULL;
}

void addleftboundry(Node* root, vector<int>& ans){
    Node* curr = root->left;
    while(!isleaf(curr)){
    ans.push_back(curr->val);
    if(curr->left != NULL) curr = curr->left;
    else curr = curr->right;
    }
}

void addleaf(Node* root, vector<int>& ans){
    if(root == NULL) return;
    Node* curr = root;
    if(isleaf(curr)){
        ans.push_back(curr->val);
        return;
    } 
    addleaf(root->left, ans);
    addleaf(root->right, ans);
}

void addrightboundry(Node* root, vector<int>& ans){
    Node* curr = root->right;
    vector<int>temp;
    while(!isleaf(curr)){
    temp.push_back(curr->val);
    if(curr->right !=NULL) curr = curr->right;
    else curr = curr->left;
    }

    reverse(temp.begin(),temp.end());
    for(int x:temp){
        ans.push_back(x);
    }
}
vector<int> boundry_traversal(Node* root){
    vector<int> ans;
    if(root == NULL) return ans;
    if(!isleaf(root)) ans.push_back(root->val);
    addleftboundry(root,ans);
    addleaf(root,ans);
    addrightboundry(root,ans);

    return ans;
}

int main() {

    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(8);
    root->right->right = new Node(6);
    
    vector<int> result = boundry_traversal(root);
    
    cout << "Boundary Traversal: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << "\n";
    // Expected output: 1 2 4 7 8 6 3
    
    return 0;
}