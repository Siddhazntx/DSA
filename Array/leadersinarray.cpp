#include <iostream>
#include <vector>
using namespace std;

vector<int> leadersinarray(vector<int>& nums){
    int n = nums.size();
    vector<int>ans;

    ans.push_back(nums[n-1]);

    for(int i= n-2;i>=0;i--){
        if(nums[i] > ans.back()){
            ans.push_back(nums[i]);
        }
    }
    return ans;
}

int main() {
  
    vector<int> nums = {16, 17, 4, 3, 5, 2};
    
    vector<int> leaders = leadersinarray(nums);
    
    cout << "Leaders: ";
    for(int i = 0; i < leaders.size(); i++){
        cout << leaders[i] << " ";
    }
    cout << "\n"; // Expected output: 2 5 17
    
    return 0;
}