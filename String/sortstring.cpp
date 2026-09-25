#include <iostream>
#include <vector>
using namespace std;


class Sort{
public:
    string sortstring(string s){
        vector<int> freq(26,0);

        for(char ch : s){
            freq[ch-'a']++;
        }

        string ans = "";
        for(int i=0;i<26;i++){
            while(freq[i] > 0){
                ans += char(i+'a');
                freq[i]--;
            }
        }
        return ans;
    }
};


int main() {
    Sort sol;
    
    // Test Case 1: Simple reverse string
    string s1 = "edcba";
    cout << "Original: " << s1 << "\n";
    cout << "Sorted:   " << sol.sortstring(s1) << "\n\n";
    
    // Test Case 2: String with duplicate characters
    string s2 = "programming";
    cout << "Original: " << s2 << "\n";
    cout << "Sorted:   " << sol.sortstring(s2) << "\n\n";

    // Test Case 3: Already sorted string
    string s3 = "abcde";
    cout << "Original: " << s3 << "\n";
    cout << "Sorted:   " << sol.sortstring(s3) << "\n\n";

    return 0;
}