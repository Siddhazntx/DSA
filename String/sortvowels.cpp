#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

bool isVowel(char ch){
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
           ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
}
string sortvowels(string s){
    vector<int> vowels;

    for(char ch : s){
        if(isVowel(ch)) vowels.push_back(ch);
    }

    sort(vowels.begin(), vowels.end());
    int index = 0;
    for(int i=0;i<s.size();i++){
        if(isVowel(s[i])){
            s[i] = vowels[index];
            index++;
        }
    }
    return s;
}


int main() {
    // Test Case 1: Mixed case with consonants (LeetCode 2785 example)
    // Expected: "lEOtcede" (Uppercase vowels sort before lowercase)
    string s1 = "lEetcOde";
    cout << "Original: " << s1 << "\n";
    cout << "Sorted:   " << sortvowels(s1) << "\n\n";

    // Test Case 2: No vowels
    // Expected: "crypt"
    string s2 = "crypt";
    cout << "Original: " << s2 << "\n";
    cout << "Sorted:   " << sortvowels(s2) << "\n\n";

    // Test Case 3: All vowels, out of order
    // Expected: "OUaei"
    string s3 = "UOiea";
    cout << "Original: " << s3 << "\n";
    cout << "Sorted:   " << sortvowels(s3) << "\n\n";

    return 0;
}