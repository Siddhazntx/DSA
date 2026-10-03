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

vector<int> bottomview(Node* root){
    vector<int>ans;
    if(root == NULL) return ans;
    map<int,int>mpp;
    queue<pair<Node*,int>>q;
    q.push({root,0});

    while(!q.empty()){
        auto it = q.front();
        q.pop();

        Node* first = it.first;
        int second = it.second;

        mpp[second] = first->val;
        if(first->left != NULL) q.push({first->left, second-1});
        if(first->right != NULL) q.push({first->right, second+1});
    }

    for(auto it:mpp){
        ans.push_back(it.second);
    }
    return ans;
}