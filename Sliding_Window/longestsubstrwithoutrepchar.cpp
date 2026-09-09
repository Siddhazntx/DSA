#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

int longestsubstr(vector<string>& arr){
    int n = arr.size();
    if(n == 0) return 0;

    unordered_map<string,int>lastseen;
    int left = 0;
    int maxlen = 0;

    for(int i = 0;i<n;i++){
        if(lastseen.find(arr[i]) != lastseen.end() && lastseen[arr[i]] >= left){
            left = lastseen[arr[i]] + 1;
        }
        lastseen[arr[i]] = i;
        maxlen = max(maxlen, i-left+1);
    }

    return maxlen;

}

int main() {
    // Test Case 1: Standard case with duplicates
    vector<string> arr1 = {"apple", "banana", "apple", "cherry", "banana", "date"};
    // The longest unique sequence is {"apple", "cherry", "banana", "date"} -> Length 4
    cout << "Test Case 1: " << longestsubstr(arr1) << "\n";

    // Test Case 2: All identical elements
    vector<string> arr2 = {"hello", "hello", "hello"};
    // The longest unique sequence is {"hello"} -> Length 1
    cout << "Test Case 2: " << longestsubstr(arr2) << "\n";

    // Test Case 3: All unique elements
    vector<string> arr3 = {"cat", "dog", "bird"};
    // The longest unique sequence is {"cat", "dog", "bird"} -> Length 3
    cout << "Test Case 3: " << longestsubstr(arr3) << "\n";

    return 0;
}