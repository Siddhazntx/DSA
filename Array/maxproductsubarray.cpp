#include <iostream>
#include <vector>
#include<climits>
using namespace std;

int maxproductsubarray(vector<int>& nums){
    int n = nums.size();
    int ans = INT_MIN;
    int pref = 1;
    int suff = 1;

    for(int i=0;i<n;i++){
        if(pref == 0) pref = 1;
        if(suff == 0) suff = 1;
        pref = pref*nums[i];
        suff = suff*nums[n-i-1];

        ans = max(ans, max(pref,suff));
    }
    return ans;
}


int main() {
    // Test Case 1: Standard case with negatives
    // Prefix gets ruined by -2, but suffix catches the max product (4)
    // Wait, actually the max is 2 * 3 = 6.
    vector<int> nums1 = {2, 3, -2, 4};
    cout << "Max product for [2, 3, -2, 4]: " << maxproductsubarray(nums1) << endl; 
    // Expected Output: 6

    // Test Case 2: Array with a zero
    // Without resetting, the output would incorrectly be -2. 
    // With resetting, it correctly evaluates -1 and 0 independently.
    vector <int>nums2 = {-2, 0, -1};
    cout << "Max product for [-2, 0, -1]: " << maxproductsubarray(nums2) << endl; 
    // Expected Output: 0

    // Test Case 3: All negatives (even count)
    vector<int> nums3 = {-2, -3, -4, -5};
    cout << "Max product for [-2, -3, -4, -5]: " << maxproductsubarray(nums3) << endl; 
    // Expected Output: 120

    return 0;
}