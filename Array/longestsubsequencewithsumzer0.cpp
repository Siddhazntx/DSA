#include <iostream>
#include <vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int subseqwithsumzero(vector<int> nums){
    int n = nums.size();
    unordered_map<int,int>mpp;
    int left = 0;
    int maxlen = 0;
    int sum = 0;

    for(int right = 0;right<n;right++){
        sum += nums[right];

        if(sum == 0) maxlen = right+1;

        if(mpp.find(sum) != mpp.end()){
            maxlen = max(maxlen, right - mpp[sum]);
        }
        else mpp[sum] = right;
    }
    return maxlen;
}

int main() {

    vector<int> nums = {9, -3, 3, -1, 6, -5};

    int result = subseqwithsumzero(nums);

    cout << "Length of longest subarray with sum 0: "
         << result << endl;

    return 0;
}