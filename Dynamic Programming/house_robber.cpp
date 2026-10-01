#include <iostream>
#include <vector>
using namespace std;


int solve (vector<int>& nums, int ind){
    int n = nums.size();
    vector<int>dp(n,-1);
    if(ind < 0) return 0;
    if (n == 1) return nums[0];
    
    dp[0] = nums[0];
    dp[1] = max(nums[0],nums[1]);

    for(int i = 2;i < n;i++){
        int skip = dp[i-1];
        int take = nums[i] + dp[i-2];

        dp[i] = max(skip,take);
    }
    return dp[n-1];
}

int rob(vector<int>& nums) {
    if (nums.empty()) return 0;
    return solve(nums, nums.size() - 1);
}

int main() {
    // Test Case 1
    // Rob house 1 (money = 1) and then rob house 3 (money = 3).
    // Total amount you can rob = 1 + 3 = 4.
    vector<int>houses1 = {1, 2, 3, 1};
    cout << "Maximum robbed for [1, 2, 3, 1]: " << rob(houses1) << endl;

    // Test Case 2
    // Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
    // Total amount you can rob = 2 + 9 + 1 = 12.
    vector<int>houses2 = {2, 7, 9, 3, 1};
    cout << "Maximum robbed for [2, 7, 9, 3, 1]: " << rob(houses2) << endl;

    // Test Case 3 (Single house)
    vector <int>houses3 = {5};
    cout << "Maximum robbed for [5]: " << rob(houses3) << endl;

    return 0;
}