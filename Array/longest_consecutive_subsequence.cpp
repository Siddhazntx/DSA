#include <iostream>
#include <vector>
#include<set>
#include<unordered_set>
using namespace std;


    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int longest = 1;
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(auto it : st){
            if(st.find(it-1) == st.end()){
                int cnt = 1;
                int x = it;
                while(st.find(x+1)!=st.end()){
                    x = x+1;
                    cnt = cnt+1;
                }
                longest = max(longest,cnt);
            }
        }
        return longest;
    }

int main(){
    int n;
    vector<int> nums = {1,2,3,4,5,6,7,11,12,13,14,15,16,17,18,19,20};
    longestConsecutive(nums);
    
}



