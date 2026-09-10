#include <iostream>
#include <vector>
using namespace std;

int first(vector<int>& nums, int target){
    int n = nums.size();
    int low = 0;
    int high = n - 1;

    while(low <= high){
        int mid = (low + high) / 2;
        if(nums[mid] >= target){
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return low;
}

int last(vector<int>& nums, int target){
    int n = nums.size();
    int low = 0;
    int high = n - 1;

    while(low <= high){
        int mid = (low + high) / 2;

  
        if(nums[mid] <= target){
            low = mid + 1;
        }
        else high = mid - 1;
    }

    return high;
}

// FIX 4: Added '&' to pass by reference
vector<int> firstandlastoccourance(vector<int>& nums, int target){
    int n = nums.size();
    int first_num = first(nums, target);
    
    if(first_num == n || nums[first_num] != target){
        return {-1, -1};
    }
    
    int last_num = last(nums, target);

    return {first_num, last_num};
}

int main() {
    // Test Array: 8 appears twice
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    
    vector<int> result = firstandlastoccourance(nums, target);
    
    cout << "First Occurrence: " << result[0] << "\n";
    cout << "Last Occurrence: " << result[1] << "\n";
    // Expected output: 3 and 4
    
    return 0;
}