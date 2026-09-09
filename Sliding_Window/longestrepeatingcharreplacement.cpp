#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

int longestcharrepeating(string s, int k){
    if(s.size() == 0) return 0;
    unordered_map<char,int> freq;

    int left = 0;
    int maxlen = 0;
    int maxcnt = 0;

    for(int right = 0;right<s.size();right++){
        freq[s[right] - 'A']++;

        maxcnt = max(maxcnt, freq[s[right] - 'A']);
        while((right-left+1) - maxcnt > k){
            freq[s[left]-'A']--;
            left++;
        }
        maxlen = max(maxlen,right-left+1);
    }
    return maxlen;
}

int main() {
    string s = "AABABBA";
    int k = 1;

    int result = longestcharrepeating(s, k);

    cout << "Longest substring length: " << result << endl;

    return 0;
}