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

vector<int> topview(Node* root){
    vector<int>ans;
    if(root == NULL) return ans;
    map<int,int>mpp;
    queue<pair<Node*,int>>q;

    q.push({root,0});

    while(!q.empty()){
        auto it = q.front();
        q.pop();

        Node* first = it.first;
        int horizontal_dist = it.second;

        if(mpp.find(horizontal_dist) == mpp.end()){
            mpp[horizontal_dist] = first->val;
        }
        if(first->left != NULL) q.push({first->left, horizontal_dist-1});
        if(first->right != NULL) q.push({first->right, horizontal_dist+1});
    }
    for(auto it:mpp){
        ans.push_back(it.second);
    }
    return ans;
}


int main() {
    // Example test case:
    //      1
    //    /   \
    //   2     3
    //    \   
    //     4  
    //      \
    //       5
    //        \
    //         6
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);

    vector<int> result = topview(root);
    
    cout << "Top view: ";
    for(int val : result) {
        cout << val << " ";
    }
    // Output should be: 2 1 3 6
    
    return 0;
}