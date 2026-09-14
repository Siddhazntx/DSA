#include <iostream>
#include <vector>
using namespace std;


bool checkifrotated(string s, string goal){
    int n = s.size();
    if(s.size() != goal.size()) return false;

    string temp = s+s;

    for(int i=0;i<s.size();i++){
        if(temp.substr(i, goal.size()) == goal){
            return true;
        }
    }
    return false;
}


int main() {
    // Test Case 1: Valid rotation (shifted left by 2)
    string s1 = "abcde";
    string goal1 = "cdeab";
    
    cout << "String: " << s1 << " | Goal: " << goal1 << "\n";
    cout << "Is rotated? " << (checkifrotated(s1, goal1) ? "True" : "False") << "\n\n";
    // Expected output: True

    // Test Case 2: Same characters, but invalid order
    string s2 = "abcde";
    string goal2 = "abced";
    
    cout << "String: " << s2 << " | Goal: " << goal2 << "\n";
    cout << "Is rotated? " << (checkifrotated(s2, goal2) ? "True" : "False") << "\n\n";
    // Expected output: False

    // Test Case 3: Different lengths
    string s3 = "abc";
    string goal3 = "abcd";
    
    cout << "String: " << s3 << " | Goal: " << goal3 << "\n";
    cout << "Is rotated? " << (checkifrotated(s3, goal3) ? "True" : "False") << "\n";
    // Expected output: False
    
    return 0;
}