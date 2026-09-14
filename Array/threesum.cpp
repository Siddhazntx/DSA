#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

vector<vector<int>> threesum(vector<int>& nums){
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());

    for(int i=0;i<n;i++){
        if(i>0 && nums[i] == nums[i-1]) continue;
        int j = i+1;
        int k = n-1;

        while(j<k){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum < 0) j++;
            else if(sum > 0) k--;
            else{

                    vector<int>temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                
                j++,k--;
            }
            while(j < k && nums[j] == nums[j-1]) j++;
            while(j < k && nums[k] == nums[k+1]) k--;
        }
    }
    return ans;
}

int main() {
    // Test Case: Contains multiple duplicate triplets
    vector<int> nums = {-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4};
    
    vector<vector<int>> result = threesum(nums);
    
    cout << "Unique Triplets that sum to 0:\n";
    for(int i = 0; i < result.size(); i++){
        cout << "[ ";
        for(int x = 0; x < result[i].size(); x++){
            cout << result[i][x] << " ";
        }
        cout << "]\n";
    }
    
    return 0;
}