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

vector<vector<int>> zigzagtraversal(Node* root){
    vector<vector<int>>ans;
    if(root == NULL) return ans;

    queue<Node*>q;
    bool flag = true;

    while(!q.empty()){
        int size = q.size();
        vector<int>level(size);
        

        for(int i=0;i<size;i++){
            Node* node = q.front();
            q.pop();
            int index;

            if(flag) index = i;
            else index = size-1-i;

            level[index] = node->val;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);

        }
        flag!=flag;
        ans.push_back(level);
    }
    return ans;
}