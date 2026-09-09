#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

vector<vector<int>> mergeintervals(vector<vector<int>>& nums){
    int n = nums.size();
    if(n == 0) return {};

    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;

    for(int i=0;i<n;i++){
        if(ans.empty() || nums[i][0] > ans.back()[1]){
            ans.push_back(nums[i]);
        }
        else{
            ans.back()[1] = max(ans.back()[1], nums[i][1]);
        }
    }
    return ans;
}

int main() {

    vector<vector<int>> nums = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    vector<vector<int>> merged = mergeintervals(nums);

    cout << "Merged Intervals: \n";
    for(int i = 0; i < merged.size(); i++){
        cout << "[" << merged[i][0] << ", " << merged[i][1] << "] ";
    }
    cout << "\n";

    return 0;
}