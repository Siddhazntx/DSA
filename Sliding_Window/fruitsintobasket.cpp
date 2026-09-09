#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int fruitsintobasket(vector<int> &nums){
    int n = nums.size();
    if( n == 0) return 0;
    unordered_map<int,int>freq;
     int left = 0;
     int maxfruits = 0;

     for(int right = 0;right<n;right++){
        freq[nums[right]]++;

        while(freq.size() > 2){
            freq[nums[left]]--;
            if(freq[nums[left]] == 0){
                freq.erase(nums[left]);
            }
            left++;
        }
        maxfruits = max(maxfruits, right-left+1);
     }
     return maxfruits;
}

int main() {
    vector<int> fruits = {1, 2, 1, 3, 2, 2}; 
    cout << "Maximum fruits we can collect: " << fruitsintobasket(fruits) << "\n";

    
    vector<int> fruits2 = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    cout << "Test 2: " << fruitsintobasket(fruits2) << "\n"; 
    

    return 0;
}