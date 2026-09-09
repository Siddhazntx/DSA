#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

int maxconsecutiveonesIII(vector<int>& nums, int k){
    int n = nums.size();
    if(n == 0) return 0;
    int left = 0;
    int maxones = 0;
    int zeros = 0;

    for(int right=0;right<n;right++){
        if(nums[right] == 0){
            zeros++;
        }

        while(zeros > k){
            if(nums[left] == 0){
                zeros--;
            }
            left++;
        }
        maxones = max(maxones, right-left+1);
    }
    return maxones;
}

int main() {
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;
    
    cout << maxconsecutiveonesIII(nums, k) << "\n"; 
    
    return 0;
}